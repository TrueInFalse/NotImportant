# wordcloud_generator_singlefile.py

import jieba
import re
import os
from wordcloud import WordCloud
import matplotlib.pyplot as plt
from collections import Counter
jieba.load_userdict('技能词典.txt')  # 取消注释这行
# 1. 读取单个文本文件
def read_single_file(file_path):
    with open(file_path, 'r', encoding='utf-8') as f:
        return f.read()

# 2. 加载停用词（新增岗位专用停用词）
def load_stopwords(stopwords_path):
    base_stopwords = set()
    if os.path.exists(stopwords_path):
        with open(stopwords_path, 'r', encoding='utf-8') as f:
            base_stopwords = set([line.strip() for line in f])
    # 添加岗位描述专用停用词
    job_stopwords = {'优先', '具备', '具有', '熟悉', '精通', '相关', '要求', '岗位', '能力', '以上'}
    return base_stopwords.union(job_stopwords)

# 3. 增强型文本预处理
def process_text(text, stopwords):
    # 清理特殊字符和数字
    text = re.sub(r'[0-9、（）()【】\[\]\.．·℃%°一二三四五六七八九十]+', ' ', text)
    text = re.sub(r'\d+届|\d+天|\d+个月?', ' ', text)  # 针对性删除编号
    # 统一英文小写
    text = text.lower()
    # 精准分词
    words = jieba.lcut(text)
    # 过滤条件
    return [word for word in words if 
        len(word) > 1 and 
        word not in stopwords]

# 4. 改进词云生成
def generate_wordcloud(keywords):
    wordcloud = WordCloud(
        font_path='msyh.ttc',
        background_color='white',
        max_words=200,
        width=1920,
        height=1080,
        collocations=False,  # 禁用词组
        prefer_horizontal=0.8  # 调整横竖比例
    ).generate(' '.join(keywords))
    
    plt.figure(figsize=(15, 10))
    plt.imshow(wordcloud, interpolation='bilinear')
    plt.axis('off')
    plt.savefig('wordcloud.png', dpi=300, bbox_inches='tight')
    plt.show()

# 5. 主函数
def main():
    # 参数配置
    input_file = '数据岗位JD.txt'  # 你的合并文本文件
    stopwords_file = '停用词.txt'
    
    # 执行流程
    text = read_single_file(input_file)
    stopwords = load_stopwords(stopwords_file)
    keywords = process_text(text, stopwords)
    
    # 词频分析
    keyword_counts = Counter(keywords)
    print("Top 30高频词：")
    for word, count in keyword_counts.most_common(30):
        print(f"{word: <8} | {count: >4}次 | {'█' * (count//5)}")
    
    generate_wordcloud(keywords)

if __name__ == "__main__":
    main()