clc;
clear;

% 初始化变量
x0 = [0, 0, 0, 0]; % 初始点
epsilon = 1e-6; % 收敛误差
max_iter = 1000; % 最大迭代次数

% 目标函数
f = @(x) x(1)^2 + x(2)^2 + 2*x(3)^2 + x(4)^2 - 5*x(1) - 5*x(2) - 21*x(3) + 7*x(4);

% 约束函数
g1 = @(x) -(8 - x(1) + x(2) - x(3) + x(4) - x(1)^2 - x(2)^2 - x(3)^2 - x(4)^2);
g2 = @(x) -(10 + x(1) + x(4) - x(2)^2 - 2*x(3)^2 - 2*x(2)*x(4));
g3 = @(x) -(5 - 2*x(1) + x(4) - 2*x(1)^2 - x(3)^2);


% 拉格朗日乘子初始化
lambda = [0, 0, 0]; % 初始化拉格朗日乘子
mu = 10; % 惩罚因子
beta = 2; % 惩罚因子增大系数

% 增广拉格朗日法
for k = 1:max_iter
    % 增广拉格朗日函数
    L = @(x, lambda) f(x) + lambda(1) * g1(x) + lambda(2) * g2(x) + lambda(3) * g3(x) + ...
                     (mu / 2) * (max(0, g1(x))^2 + max(0, g2(x))^2 + max(0, g3(x))^2);
    
    % 优化问题求解
    options = optimoptions('fminunc', 'Display', 'off', 'Algorithm', 'quasi-newton');
    [x_opt, fval] = fminunc(@(x) L(x, lambda), x0, options);
    
    % 更新拉格朗日乘子
    lambda = lambda + mu * [g1(x_opt), g2(x_opt), g3(x_opt)];
    
    % 检查收敛条件
    if norm([g1(x_opt), g2(x_opt), g3(x_opt)]) < epsilon
        break;
    end
    
    % 增加惩罚因子
    mu = mu * beta;
    x0 = x_opt;
end

disp('优化结果：');
disp(x_opt);
disp('目标函数值：');
disp(fval);

% 输出最终约束函数的值
disp('最终解点下各约束函数的值：');
disp(['g1(x_opt) = ', num2str(g1(x_opt))]);
disp(['g2(x_opt) = ', num2str(g2(x_opt))]);
disp(['g3(x_opt) = ', num2str(g3(x_opt))]);
