%%
% This script implement Forward Euler method for solving a 
%      ordinary differential equation defined by the function f
%
% Author: R.Estrada, FH JOANNEUM
% Date:   May 2014
%%


%% Cleaning-up
clear all; % Clean of variable-size matrices. Important to avoid "ghost" values
cla;          % Clean active figure  

%% Param definition
y0 = 1;       % Initial condition of y
t0 = 0;       % Initial time  
tfinal = 10;  % Final time

h = 5;        % Step size

%% Main code
% Variable init
t = t0;                 % Actual time 
i = 1;                  % Index counter 
yk1(i,:) = [t0 y0 h];   % Matrix of result (first row)
yk2(i,:) = [t0 y0 h];   %Matrix of 4a
Tau = 2;                %4a Schaue Verhältniss h & Tau
y_start =1;             %4a 
abs_dif(i) = 0;
dif(i) = 0;             %4c


while 1                 % Infinite main loop

    % Forward Euler method (1st order)
    y1 = y0 + h*f(t,y0, Tau);
    
    % Updating values for next iteration
    y0 = y1;            
    i = i + 1;
    t = t + h;
    
    % Storing actual results
    yk1(i,:) = [t y1 h];
    
    %4a
    y_t = y_start*exp(-t/Tau);
    yk2(i,:) = [t y_t h]; 
    
    %4c
    abs_dif(i)  = abs(yk1(i,2)-yk2(i,2));
    dif(i)      = yk1(i,2)-yk2(i,2);
  
    
    
    % Ending condition
    if t > tfinal
        break;
    end    
end

%aav = sum(abs_dif)/(i-1);

%Display of results
figure(1)
plot(yk1(:,1),yk1(:,2),'r');
hold on
plot(yk2(:,1),yk2(:,2), 'x');
axis([t0 tfinal min(yk1(:,2)) max(yk1(:,2))]);
xlabel('Time [sec]')
ylabel('y(t) [unit]')
legend('FE', 'EstVal');
grid
hold off

arr4 = [yk1(:,1), yk1(:,2), yk2(:,2), (yk2(:,2)-yk1(:,2))];
aate4 = sum(abs(arr4(:,4)))/(length(arr4)-1);
rms4 = rms(arr4(2:end,4))
% latex(vpa(sym(array_latex),3));



errors = [0.1, 0.5, 1.5, 2, 3, 5; 0.0048, 0.0243, 0.0796, 0.0968, 0.2799, 2.4003;...
    0.0056, 0.0296, 0.1109, 0.1615, 0.3825, 2.5119];

figure(2)
plot(errors(1,:),errors(2,:),'o-');
hold on
plot(errors(1,:),errors(3,:), 'x-');
axis([0 5 0 2.6]);
xlabel('h [sec]')
ylabel('Error []')
legend('AATE', 'RMS');
grid
hold off
