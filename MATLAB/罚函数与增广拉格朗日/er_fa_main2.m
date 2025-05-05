clc;
clear;

% 初始化变量
x0 = [1, 2, 0, 4, 0, 1, 1]; % 初始点
epsilon = 1e-6; % 收敛误差
max_iter = 1000; % 最大迭代次数
sigma = 2; % 惩罚参数
beta = 2; % 惩罚系数增长因子

% 目标函数
f = @(x) (x(1) - 10)^2 + 5*(x(2) - 12)^2 + x(3)^4 + 3*(x(4) - 11)^2 + 10*x(5)^6 + 7*x(6)^2 ...
          + x(7)^4 - 4*x(6)*x(7) - 10*x(6) + 8*x(7);

% 约束函数
g1 = @(x) -7*x(1) - 3*x(2) - 10*x(3)^2 - x(4) + x(5) + 282; 
g2 = @(x) -23*x(1) - x(2)^2 - 6*x(6)^2 + 8*x(7) + 196; 
g3 = @(x) -2*x(1)^2 - 3*x(2)^4 - x(3) - 4*x(4)^2 - 5*x(5) + 127;
g4 = @(x) -4*x(1)^2 - x(2)^2 + 3*x(1)*x(2) - 2*x(3)^2 - 5*x(6) - 11*x(7);

% 惩罚函数法
for k = 1:max_iter
    % 惩罚函数
    P = @(x) f(x) + sigma * (max(0, g1(x))^2 + max(0, g2(x))^2 + max(0, g3(x))^2 + max(0, g4(x))^2);
    
    % 优化问题求解
    options = optimoptions('fminunc', 'Display', 'off', 'Algorithm', 'quasi-newton');
    [x_opt, fval] = fminunc(P, x0, options);
    
    % 检查收敛条件
    if abs(fval - f(x_opt)) < epsilon
        break;
    end
    
    % 增加惩罚参数
    sigma = sigma * beta;
    x0 = x_opt;
end

disp('最终解：');
disp(x_opt);
disp('目标函数值：');
disp(fval);


% 最终输出当前解点下约束函数的值
disp('最终解下各约束函数的值：');
disp(['g1(x_opt) = ', num2str(g1(x_opt))]);
disp(['g2(x_opt) = ', num2str(g2(x_opt))]);
disp(['g3(x_opt) = ', num2str(g3(x_opt))]);
disp(['g4(x_opt) = ', num2str(g4(x_opt))]);
