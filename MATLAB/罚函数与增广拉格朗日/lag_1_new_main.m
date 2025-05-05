clc;
clear;

% 初始化变量
x0 = [0, 0, 0, 0]; % 初始点
epsilon = 1e-6; % 收敛误差
max_iter = 1000; % 最大迭代次数
sigma = 2; % 惩罚因子
mu = ones(3, 1); % 初始拉格朗日乘子
rho = 1.2; % 惩罚因子增长因子

% 目标函数
f = @(x) x(1)^2 + x(2)^2 + 2*x(3)^2 + x(4)^2 - 5*x(1) - 5*x(2) - 21*x(3) + 7*x(4);

% 约束函数
g1 = @(x) (8 - x(1) + x(2) - x(3) + x(4) - x(1)^2 - x(2)^2 - x(3)^2 - x(4)^2);
g2 = @(x) (10 + x(1) + x(4) - x(2)^2 - 2*x(3)^2 - 2*x(2)*x(4));
g3 = @(x) (5 - 2*x(1) + x(4) - 2*x(1)^2 - x(3)^2);

% 增广拉格朗日法
for k = 1:max_iter
    % 增广拉格朗日函数
    L = @(x, mu) f(x) + sum(mu .* max(0, [g1(x), g2(x), g3(x)])') + ...
                 (sigma / 2) * sum(max(0, [g1(x), g2(x), g3(x)]).^2);
    
    % 优化问题求解
    options = optimoptions('fminunc', 'Display', 'off', 'Algorithm', 'quasi-newton');
    [x_opt, fval] = fminunc(@(x) L(x, mu), x0, options);
    
    % 更新拉格朗日乘子
    mu = mu + sigma * max(0, [g1(x_opt), g2(x_opt), g3(x_opt)])';
    
    % 检查收敛条件
    if norm(max(0, [g1(x_opt), g2(x_opt), g3(x_opt)])) < epsilon
        fprintf("迭代次数：%d，满足精度要求\n", k);
        break;  
    end
    
    % 增加惩罚因子
    sigma = sigma * 1.2;
    x0 = x_opt;
end

% 输出优化结果
disp('最终解：');
disp(x_opt);
disp('目标函数值：');
disp(fval);

% 最终输出当前解点下各约束函数的值
disp('最终解下各约束函数的值：');
disp(['g1(x_opt) = ', num2str(g1(x_opt))]);
disp(['g2(x_opt) = ', num2str(g2(x_opt))]);
disp(['g3(x_opt) = ', num2str(g3(x_opt))]);
