clear all; clc; close all;

%%
% g inverted
m=0.05; g=-9.81; tEngine=0.15; Force=16; vChute=-20; Dt=0.01; 
clear t v h 
n=1; 
t(n)=0; v(n)=0; h(n)=0; t(2)=0;

%%
% Segment 1 
a1=(Force+m*g)/m; 
while (t(n) < tEngine) &&  (n < 50000) 
    n=n+1; 
    t(n)=t(n-1)+Dt; 
    v(n) =a1 *t (n) ; 
    h(n) =0.5*a1*t(n)^2;
end;
v1=v(n); h1=h(n); t1=t(n);

% Segment 2
while v(n)>=vChute && n<50000
n=n+1;
t(n)=t(n-1)+Dt;
v(n)=v1+g*(t(n)-t1);
h(n) =h1+v1 * (t(n)-t1 )+0.5*g* (t (n)-t1)^2;
end
v2=v(n); h2=h(n); t2=t(n);

% Segment 3
while h(n)>0 && n<50000
n=n+1;
t(n)=t(n-1)+Dt;
v(n)=vChute;
h (n) =h2+vChute* (t(n)-t2) ;
end

%%
subplot(1,2,1)
plot(t,h,t2,h2, 'ro', t1, h1, 'r+')
xlabel('Time [s]');
ylabel('Hight [m]');
subplot(1,2,2)
plot(t,v,t2,v2, 'ro', t1, v1, 'r+')
xlabel('Time [s]');
ylabel('Velocity [m]');


%%
% Analysis of the loged datas. 
a = logsout{1}.Values.Data;
v = logsout{2}.Values.Data;
x = logsout{3}.Values.Data;
t_log = logsout{2}.Values.Time;