n = -4*pi:0.05:4*pi;
x = sinc(n);
figure;
plot(n/pi,x); axis([-4 4 -0.3 1.1]); grid on;
title('sinc function'); xlabel('units of pi'); ylabel('sinc(x)');


x1 = -4*pi:0.05:4*pi;
y1 = zeros(1,length(x1));
for k = 1:length(x1)
    y1(k) = piecewise1(x1(k));
end
figure;
plot(x1/pi,y1); axis([-4 4 -0.3 1.1]); grid on;
title('Truncated sinc function'); xlabel('units of pi'); ylabel('sinc(x)');
