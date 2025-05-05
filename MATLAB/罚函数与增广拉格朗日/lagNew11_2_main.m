clc;
clear;

% 初始化变量
x0 = [1, 2, 0, 4, 0, 1, 1];  % 初始点
lambda0 = ones(1, 4);         % 初始拉格朗日乘子
mu0 = ones(1, 4);             % 初始乘子μ
sigma0 = 2;                   % 初始罚因子
epsilon0 = 1e-6;              % 初始约束违反度常数
eta = 1e-6;                   % 精度常数
alpha = 0.1;                  % α
beta = 0.5;                   % β
rho = 1.2;                    % 罚因子增长倍率
epsilon = epsilon0;           % 约束违反度
eta_k = 1 / rho;              % 子问题求解误差
k = 0;                        % 初始迭代次数

% 目标函数
f = @(x) (x(1) - 10)^2 + 5*(x(2) - 12)^2 + x(3)^4 + 3*(x(4) - 11)^2 + 10*x(5)^6 + 7*x(6)^2 ...
          + x(7)^4 - 4*x(6)*x(7) - 10*x(6) + 8*x(7);

% 约束函数
g1 = @(x) -7*x(1) - 3*x(2) - 10*x(3)^2 - x(4) + x(5) + 282; 
g2 = @(x) -23*x(1) - x(2)^2 - 6*x(6)^2 + 8*x(7) + 196; 
g3 = @(x) -2*x(1)^2 - 3*x(2)^4 - x(3) - 4*x(4)^2 - 5*x(5) + 127;
g4 = @(x) -4*x(1)^2 - x(2)^2 + 3*x(1)*x(2) - 2*x(3)^2 - 5*x(6) - 11*x(7);

% 初始化松弛变量
s0 = [0, 0, 0, 0];             % 初始松弛变量

% 默认值 x_opt
x_opt = x0;  % 初始解为x0

% 增广拉格朗日法
while k < 1000
    % 增广拉格朗日函数
    L = @(x, s, lambda, mu, sigma) f(x) + lambda(1) * (g1(x) + s(1)) + lambda(2) * (g2(x) + s(2)) + lambda(3) * (g3(x) + s(3)) + lambda(4) * (g4(x) + s(4)) ...
                                  + (sigma / 2) * ((g1(x) + s(1))^2 + (g2(x) + s(2))^2 + (g3(x) + s(3))^2 + (g4(x) + s(4))^2);
    
    % 使用 fminunc 求解子问题
    options = optimoptions('fminunc', 'Display', 'off', 'Algorithm', 'quasi-newton');
    [x_k1, fval] = fminunc(@(x) L(x, s0, lambda0, mu0, sigma0), x0, options);
    
    % 计算约束违反度
    omega = norm([g1(x_k1), g2(x_k1), g3(x_k1), g4(x_k1)]);
    
    % 检查精度条件 ||∇L(x^(k+1))|| <= η_k
    grad_L = gradient_L(x_k1, s0, lambda0, mu0, sigma0);  % 计算梯度
    grad_norm = norm(grad_L);
    
    if grad_norm <= eta_k  % 子问题求解误差满足条件
        if omega <= epsilon  % 约束违反度满足条件
            % 更新乘子
            mu0 = lambda0 + sigma0 * [g1(x_k1), g2(x_k1), g3(x_k1), g4(x_k1)];
            sigma0 = sigma0 * rho;
            eta_k = eta_k / rho;
            epsilon = epsilon / rho;
            
            % 更新解
            x_opt = x_k1;  % 最终解
            break;  % 满足精度条件，退出迭代
        else
            % 更新乘子
            mu0 = lambda0 + sigma0 * [g1(x_k1), g2(x_k1), g3(x_k1), g4(x_k1)];
            sigma0 = sigma0 * rho;
            eta_k = eta_k / rho;
            epsilon = epsilon / rho;
        end
    else
        % 罚因子增大，乘子不变
        sigma0 = rho * sigma0;
        eta_k = 1 / rho;
        epsilon = 1 / sigma0;
    end
    
    k = k + 1;  % 迭代次数更新
    x0 = x_k1;  % 更新初始点
end

% 输出最终解和约束函数的值
disp('优化结果：');
disp(x_opt);
disp('目标函数值：');
disp(f(x_opt));

% 输出当前解点下各约束函数的值
disp('最终解点下各约束函数的值：');
disp(['g1(x_opt) = ', num2str(g1(x_opt))]);
disp(['g2(x_opt) = ', num2str(g2(x_opt))]);
disp(['g3(x_opt) = ', num2str(g3(x_opt))]);
disp(['g4(x_opt) = ', num2str(g4(x_opt))]);
