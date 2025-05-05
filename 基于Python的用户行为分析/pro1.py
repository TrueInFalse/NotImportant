import pandas as pd
import numpy as np
import matplotlib
#matplotlib.use('TkAgg')  # 必须放在所有matplotlib导入之前
import matplotlib.pyplot as plt
import seaborn as sns
import datetime
import pickle
import logging

# ====================== 【核心】中文字体配置 ======================
plt.rcParams.update({
    # 全局中文字体（推荐SimHei，Windows/macOS/Linux通用）
    "font.family": "SimHei",
    # 解决负号显示问题（部分中文字体不包含负号）
    "axes.unicode_minus": False,
    # 字体大小（可选）
    "font.size": 12
})
# ==================================================================
# 配置日志记录
logging.basicConfig(level=logging.INFO, format='%(asctime)s - %(levelname)s - %(message)s')


def load_data_with_cache(file_path, cache_file='user_data_cache.pkl'):
    try:
        # 尝试从缓存文件加载数据
        with open(cache_file, 'rb') as f:
            start_time = datetime.datetime.now()
            user_data = pickle.load(f)
            end_time = datetime.datetime.now()
            logging.info(f'从缓存加载数据耗时：{end_time - start_time}s')
            return user_data
    except FileNotFoundError:
        try:
            # 如果缓存文件不存在，则从 CSV 文件读取数据
            start_time = datetime.datetime.now()
            user_data = pd.read_csv(file_path, header=None)
            end_time = datetime.datetime.now()
            logging.info(f'导入数据耗时：{end_time - start_time}s')

            # 将数据保存到缓存文件
            with open(cache_file, 'wb') as f:
                pickle.dump(user_data, f)
            return user_data
        except Exception as e:
            logging.error(f'读取 CSV 文件时出错：{e}')
            return None
    except Exception as e:
        logging.error(f'从缓存加载数据时出错：{e}')
        return None


# 数据文件路径
file_path = r'D:\1A老孙的文件夹\工作\项目\基于Python的淘宝APP用户行为分析\UserBehavior.csv'
# 加载数据
user_data = load_data_with_cache(file_path)

if user_data is not None:
    # 截取数据的前 500000 行
    user_data = user_data[:500000]

    # 设置列名
    user_data.columns = ['user_id', 'item_id', 'category_id', 'behavior', 'time_stamp']

    # 数据类型转换示例
    user_data['user_id'] = user_data['user_id'].astype('int32')
    user_data['item_id'] = user_data['item_id'].astype('int32')
    user_data['category_id'] = user_data['category_id'].astype('int32')

    # 查看数据前 50 行
    # print(user_data.head(10))

    # to_datetime方法比time.localtime感觉更方便，可以不用再转换一次格式。
    user_data['time_stamp'] = pd.to_datetime(user_data['time_stamp'], unit='s')
    # 转化完之后是格林威治时间，而北京时间需要加8小时
    user_data['time_stamp'] = user_data['time_stamp'] + datetime.timedelta(hours=8)

    user_data['date'] = user_data['time_stamp'].dt.date
    user_data['time'] = user_data['time_stamp'].dt.hour
    user_data['time_stamp'] = user_data['time_stamp'].dt.day_name()
    # 没有添加新列，而是在原列上修改，是为了节省内存空间。这就需要把列名修改一下。
    user_data.rename(columns={'time_stamp': 'weekday'}, inplace=True)

    """""
    # 方法二：临时设置（仅对当前操作生效）
    with pd.option_context('display.max_columns', None, 'display.max_colwidth', None):
        print(user_data.head(10))
    """

    # user_data.groupby('behavior').count() 这行代码的作用是
    # 对 user_data 这个 DataFrame 按照 behavior 列进行分组，然后统计每个分组中各列的非缺失值数量。
    # print(user_data.groupby('behavior').count())

    customer = user_data.drop_duplicates('user_id').count()
    # print(customer)#五十万条数据中用户人数

    buy_data = user_data[user_data['behavior'] == 'buy']
    buy_data.drop_duplicates('user_id').count()
    # 筛选出 user_data 中 behavior 列值为 buy（即购买行为）的所有行，将这些行存储在 buy_data 数据框中。
    # 去掉重复的id，确定有多少人进行了购物


    double_user = buy_data.groupby(buy_data['user_id']).count()
    # 根据 user_id 对 buy_data 进行分组，然后统计每个用户的购买记录数量（即每个分组中各列的非缺失值数量），
    # 结果存储在 double_user 数据框中，此时 double_user 的索引是 user_id，每列的值是该用户的购买记录数。

    double_user[double_user['behavior'] >= 2].count()
    # 从 double_user 中筛选出 behavior 列（也就是购买记录数）大于等于 2 的行，
    # 即筛选出购买次数不少于 2 次的用户，然后统计这些用户的数量。

    user_data['behavior'].groupby(by=user_data['date']).value_counts()
    # 先按照 date 列对 user_data 中的 behavior 列进行分组，也就是将每天的行为数据分为一组。
    # 然后对每个分组内的 behavior 列的值进行计数，统计每天不同行为（如 buy、pv、cart 等）的发生次数。

    # 数据准备（根据你的统计结果）
    total_users = user_data['user_id'].nunique()  # 总用户数（等价于customer）
    bought_users = buy_data['user_id'].nunique()  # 至少购买1次的用户数
    repeat_buyers = double_user[double_user['behavior'] >= 2].shape[0]  # 购买≥2次的用户数

    """
    # 创建数据框（方便后续图表标注）
    plot_data = pd.DataFrame({
        '指标': ['总用户数', '购买用户数', '复购用户数'],
        '数量': [total_users, bought_users, repeat_buyers],
        '颜色': ['#4CAF50', '#2196F3', '#FF5722']  # 绿色-总用户，蓝色-首次购买，橙色-复购
    })

    # 绘制条形图
    plt.figure(figsize=(10, 6))  # 设置画布大小
    # 修改此处，指定hue参数并隐藏图例
    sns.barplot(x='指标', y='数量', hue='指标', data=plot_data, palette=plot_data['颜色'].tolist(), edgecolor='black',
                legend=True, width=0.8)

    # 数据标注（显示具体数值）
    for p in plt.gca().patches:
        height = p.get_height()
        plt.text(p.get_x() + p.get_width() / 2., height + 100,  # 数值位置微调
                 '{:,}'.format(int(height)),  # 千位分隔符
                 ha='center', va='bottom', fontsize=12, color='#333')

    # 图表美化
    plt.title('淘宝APP用户购买行为分层（前50万条数据）', fontsize=14, pad=24)
    plt.ylabel('用户数量', fontsize=12)

    # 设置 x 轴刻度位置和标签
    x_positions = range(len(plot_data['指标']))
    plt.xticks(x_positions, plot_data['指标'], fontsize=12)

    #plt.xticks(fontsize=12)
    #plt.grid(axis='y', linestyle='--', alpha=0.7)  # 增加背景网格

    # 增加数据来源注释（根据你的数据时间范围）
    #plt.text(0.8, -0.2, f"数据范围：前50万条记录 | 统计时间：{datetime.datetime.now().strftime('%Y-%m-%d')}",
    #         transform=plt.gca().transAxes, fontsize=10, color='#666')

    plt.annotate(f"数据范围：前50万条记录 | 统计时间：{datetime.datetime.now().strftime('%Y-%m-%d')}",
                 xy=(0.6, -0.11), xycoords='axes fraction',
                 fontsize=10, color='#666')

    # 显示百分比关系（补充业务视角）
    plt.text(0, 1.01,
             f"购买转化率：{bought_users / total_users * 100:.1f}% | 复购率：{repeat_buyers / bought_users * 100:.1f}%",
             transform=plt.gca().transAxes, fontsize=12, color='#2c3e50', weight='bold')

    #plt.tight_layout()
    plt.show()
    #生成图片：淘宝app用户行为分层
    """

    """""
    # 将 weekday 列转换为 category 类型
    user_data['weekday'] = user_data['weekday'].astype('category')

    # 按照 weekday 和 behavior 分组并统计数量，显式指定 observed=True
    behavior_count_by_weekday = user_data.groupby(['weekday', 'behavior'], observed=True).size().unstack(fill_value=0)
    """



    
    """
    # 定义星期的顺序
    weekday_order = ['Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday', 'Saturday', 'Sunday']

    # 将 weekday 列转换为 category 类型，并指定顺序
    user_data['weekday'] = pd.Categorical(user_data['weekday'], categories=weekday_order, ordered=True)

    # 按照 weekday 和 behavior 分组并统计数量，显式指定 observed=True
    behavior_count_by_weekday = user_data.groupby(['weekday', 'behavior'], observed=True).size().unstack(fill_value=0)

    # 定义中文星期名称
    chinese_weekday_order = ['周一', '周二', '周三', '周四', '周五', '周六', '周日']
    behavior_count_by_weekday = behavior_count_by_weekday.reindex(weekday_order)

    # 分离出 pv 行为数据
    pv_data = behavior_count_by_weekday['pv']

    # 去除 pv 后的其他行为数据
    other_behaviors = behavior_count_by_weekday.drop(columns='pv')

    # 绘制其他行为（非 pv）的折线图
    plt.figure(figsize=(12, 6))
    for behavior in other_behaviors.columns:
        plt.plot(other_behaviors.index, other_behaviors[behavior], label=behavior)
    plt.xticks(range(7), ['周一', '周二', '周三', '周四', '周五', '周六', '周日'])
    # 添加图例和标题
    plt.title('一周中buy、cart、fav行为的数量变化')
    plt.ylabel('行为数量')
    plt.legend()
    plt.grid(False)

    # 设置 x 轴刻度位置和标签
    ax = plt.gca()
    ax.set_xticks(range(len(weekday_order)))
    ax.set_xticklabels(chinese_weekday_order)

    # 显示第一个图形
    plt.show()

    # 绘制 pv 行为的折线图
    plt.figure(figsize=(12, 6))
    plt.plot(pv_data.index, pv_data, color='red', label='pv')
    plt.xticks(range(7), ['周一', '周二', '周三', '周四', '周五', '周六', '周日'])
    plt.title('一周中PV行为的数量变化')
    plt.ylabel('行为数量')
    plt.legend()
    plt.grid(False)

    # 设置 x 轴刻度位置和标签
    ax = plt.gca()
    ax.set_xticks(range(len(weekday_order)))
    ax.set_xticklabels(chinese_weekday_order)

    # 显示第二个图形
    plt.show()
    """

    
    '''
    # ====================== 流量时间变化分析 ======================
    # 按小时统计各行为数量
    hourly_behavior = user_data.groupby('time')['behavior'].value_counts().unstack(fill_value=0)

    plt.figure(figsize=(14, 7))
    sns.set_palette("husl")  # 使用和谐色板

# 绘制四条折线
    for behavior in ['pv', 'cart', 'fav', 'buy']:
        plt.plot(hourly_behavior.index, 
                hourly_behavior[behavior], 
                marker='o',
                linewidth=2.5,
                label=f'{behavior.upper()}流量')

# 图表优化
    plt.title('用户行为流量时间趋势（小时粒度）', fontsize=14, pad=20)
    plt.xlabel('时间段（小时）', fontsize=12)
    plt.ylabel('行为数量', fontsize=12)
    plt.xticks(range(0, 24), [f'{i}:00' for i in range(24)], rotation=45)
    plt.grid(axis='y', linestyle='--', alpha=0.7)
    plt.legend(title='行为类型', bbox_to_anchor=(1.02, 1), loc='upper left')

# 标注峰值时间
    max_pv = hourly_behavior['pv'].idxmax()
    plt.annotate(f'浏览高峰 {max_pv}:00', 
                xy=(max_pv, hourly_behavior['pv'].max()),
                xytext=(max_pv+2, hourly_behavior['pv'].max()*0.8),
                arrowprops=dict(arrowstyle="->", color='#2c3e50'))

    plt.tight_layout()
    plt.show()
    '''
    
    
    
    
    
    """
    # ====================== 行为转化漏斗分析 ======================
    #计算各行为独立用户数
    funnel_data = user_data.groupby('behavior')['user_id'].nunique().reindex(['pv', 'cart', 'fav', 'buy'])

    # 计算转化率
    conversion_rates = (funnel_data / funnel_data.iloc[0]).round(3)

    # 创建绘图对象
    fig, ax = plt.subplots(figsize=(10, 6))

    # 绘制漏斗条形图
    bar_width = 0.8
    y_pos = range(len(funnel_data))

# 使用渐变色
    colors = plt.cm.Blues(np.linspace(0.4, 1, len(funnel_data)))

    for i, (behavior, count) in enumerate(funnel_data.items()):
        ax.barh(y_pos[i], count, 
                height=bar_width,
                color=colors[i],
                edgecolor='black')
    
    # 添加数据标签
        ax.text(count*1.02, y_pos[i], 
                f'{count:,}\n({conversion_rates[i]*100:.1f}%)',
                va='center',
                fontsize=10)

# 图表优化
    ax.set_yticks(y_pos)
    ax.set_yticklabels([f'{b.upper()}\n阶段' for b in funnel_data.index])
    ax.invert_yaxis()  # 反转Y轴
    plt.title('用户行为转化漏斗（独立用户数）', fontsize=14, pad=20)
    plt.xlabel('独立用户数量', fontsize=12)
    plt.grid(axis='x', linestyle='--', alpha=0.7)

    plt.tight_layout()
    plt.show()
    """
    
    
    
    
    '''
    # ====================== 头部用户分析（修复版） ======================

# 计算用户购买次数
    user_buy_counts = user_data[user_data['behavior'] == 'buy'].groupby('user_id').size()

# 确定Top 10%阈值（增加空值检查）
    if not user_buy_counts.empty:
        top_threshold = np.percentile(user_buy_counts, 90)
        top_users = user_buy_counts[user_buy_counts >= top_threshold].index
    else:
        top_users = []

# 筛选头部用户行为数据（处理空值情况）
    if len(top_users) > 0:
        top_user_data = user_data[user_data['user_id'].isin(top_users)]
    else:
        top_user_data = pd.DataFrame(columns=user_data.columns)

# 对比分析（修复核心问题：确保行为类型一致）
    all_behaviors = user_data['behavior'].unique()
    comparison = pd.DataFrame({
        '全体用户': user_data['behavior'].value_counts(normalize=True).reindex(all_behaviors, fill_value=0),
        '头部用户': top_user_data['behavior'].value_counts(normalize=True).reindex(all_behaviors, fill_value=0)
    })

# 过滤零值（可选）
    comparison = comparison.loc[comparison.sum(axis=1) > 0]

# 绘制雷达图（修复维度问题）
    categories = comparison.index.tolist()
    N = len(categories)

# 生成角度（重要修复）
    angles = np.linspace(0, 2 * np.pi, N, endpoint=False).tolist()
    angles += angles[:1]  # 闭合圆形

# 创建画布
    plt.figure(figsize=(8, 8))
    ax = plt.subplot(111, polar=True)

# 绘制数据（重要修复）
    for col in comparison.columns:
        values = comparison[col].values.tolist()
        values += values[:1]  # 闭合数据
        ax.plot(angles, values, linewidth=2, linestyle='solid', label=col)
        ax.fill(angles, values, alpha=0.25)

# 设置刻度标签（修复中文显示）
    ax.set_thetagrids(np.degrees(angles[:-1]), categories)
    ax.set_theta_offset(np.pi/2)  # 设置0度位置在顶部
    ax.set_theta_direction(-1)  # 顺时针方向

# 添加图例和标题
    plt.title('头部用户 vs 全体用户行为分布对比', y=1.08, fontsize=14)
    plt.legend(loc='upper right', bbox_to_anchor=(1.3, 1))
    plt.tight_layout()
    plt.show()
    '''
    
    # ====================== 商品转化率分析 ======================
# 计算各商品行为数量
    item_behavior = user_data.groupby(['item_id', 'behavior']).size().unstack(fill_value=0)

# 计算转化率
    item_behavior['buy_pv_ratio'] = item_behavior['buy'] / item_behavior['pv']
    item_behavior['cart_pv_ratio'] = item_behavior['cart'] / item_behavior['pv']

# 筛选销量Top10商品
    top10_items = item_behavior['buy'].nlargest(10).index
    top10_data = item_behavior.loc[top10_items]

# 绘制分组条形图
    fig, ax1 = plt.subplots(figsize=(12, 6))

# 主Y轴：PV和购买量
    ax1.bar(np.arange(len(top10_data))-0.2, top10_data['pv'], 
       width=0.4, label='浏览量(PV)', alpha=0.8)
    ax1.bar(np.arange(len(top10_data))+0.2, top10_data['buy'], 
       width=0.4, label='购买量', alpha=0.8)
    ax1.set_ylabel('绝对数量', fontsize=12)
    ax1.legend(loc='upper left')

# 次Y轴：转化率
    ax2 = ax1.twinx()
    ax2.plot(np.arange(len(top10_data)), 
            top10_data['buy_pv_ratio']*100, 
            color='red', marker='o', linewidth=2,
            label='购买转化率')
    ax2.set_ylabel('转化率 (%)', fontsize=12)
    ax2.legend(loc='upper right')

# 图表优化
    plt.xticks(np.arange(len(top10_data)), 
            [f'商品ID: {i}' for i in top10_data.index], 
            rotation=45)
    plt.title('Top10商品转化率分析', fontsize=14, pad=20)
    fig.tight_layout()
    plt.show()
    