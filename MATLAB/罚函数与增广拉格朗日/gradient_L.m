% function grad = gradient_L(x, s, lambda, mu, sigma)
%     % 目标函数 f(x) 的梯度
%     grad_f = [2*(x(1) - 10), 10*(x(2) - 12), 4*x(3)^3, 6*(x(4) - 11), 60*x(5)^5, 14*x(6)-4*x(7)-10, 4*x(7)^3-4*x(6)+8]';
%     
%     % 约束函数 g1(x) 的梯度
%     grad_g1 = [-7, -3, -20*x(3), -1, 1, 0, 0];
%     
%     % 约束函数 g2(x) 的梯度
%     grad_g2 = [-23, -2*x(2), 0, 0, 0, -12*x(6), 8];
%     
%     % 约束函数 g3(x) 的梯度
%     grad_g3 = [-4*x(1), -12*x(2)^3, -1, -8*x(4), -5, 0, 0];
%     
%     % 约束函数 g4(x) 的梯度
%     grad_g4 = [-8*x(1)+3*x(2), -2*x(2) + 3*x(1), -4*x(3), 0, 0, -5, -11];
%     
%     % 计算增广拉格朗日函数的梯度
%     grad = grad_f + lambda(1)*grad_g1 + lambda(2)*grad_g2 + lambda(3)*grad_g3 + lambda(4)*grad_g4 ...
%            + sigma * (grad_g1 + grad_g2 + grad_g3 + grad_g4);
% end

% 梯度函数
function grad = gradient_L(x, lambda, sigma)
    % 目标函数 f(x) 的梯度
    grad_f = [2*(x(1) - 10), 10*(x(2) - 12), 4*x(3)^3, 6*(x(4) - 11), 60*x(5)^5, 14*x(6)-4*x(7)-10, 4*x(7)^3-4*x(6)+8]';
    
    % 约束函数 g1(x) 的梯度
    grad_g1 = [-7, -3, -20*x(3), -1, 1, 0, 0];
    
    % 约束函数 g2(x) 的梯度
    grad_g2 = [-23, -2*x(2), 0, 0, 0, -12*x(6), 8];
    
    % 约束函数 g3(x) 的梯度
    grad_g3 = [-4*x(1), -12*x(2)^3, -1, -8*x(4), -5, 0, 0];
    
    % 约束函数 g4(x) 的梯度
    grad_g4 = [-8*x(1)+3*x(2), -2*x(2) + 3*x(1), -4*x(3), 0, 0, -5, -11];
    
    % 计算增广拉格朗日函数的梯度
    grad = grad_f + lambda(1)*grad_g1 + lambda(2)*grad_g2 + lambda(3)*grad_g3 + lambda(4)*grad_g4 ...
           + sigma * (grad_g1 + grad_g2 + grad_g3 + grad_g4);
end