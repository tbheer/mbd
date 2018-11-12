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
%FE
y0 = 1;       % Initial condition of y

%MP
yk_mp = 1;      %initial Value
yk_mp1 = 1;     %yk_mp+1

%General
t0 = 0;       % Initial time  
tfinal = 10;  % Final time

h = 5;        % Step size
rtol = 0.1;     %6

%% Main code
% Variable init
t = t0;                 % Actual time 
i = 1;                  % Index counter 
yk1(i,:) = [t0 y0 h];   % Matrix of result (first row)
yk2(i,:) = [t0 y0 h];   %Matrix of 4a
yk3(i,:) = [t0 y0 h];   %6
Tau = 2;                %4a Schaue Verhältniss h & Tau
y_start =1;             %4a 
abs_dif1(i) = 0;        %4a
dif(i) = 0;             %4c
j=0;                    % n loops
h_i(i) = [1];           % stepsize



while 1                 % Infinite main loop
    
    k1 = 0;                 %7
    k2 = 0;                 %7

    while 1
        j = j+1;
        % Forward Euler method (1st order)
        y1 = y0 + h*f(t,y0, Tau);


        
        %MP Mid-Point Method 
        %6
        k1  = f(t,yk_mp, Tau);
        k2  = f(t + h/2, yk_mp + k1*h/2, Tau);  
        yk_mp1 = yk_mp + h * k2;
        
        break;
%         %solve epsilon
%         epsilon = abs(yk_mp1 - y1);
%         
%         if epsilon <= rtol
%             break;
%         else 
%             h = h * sqrt(rtol/epsilon);
%         end      
    end
        
        
        % Updating values for next iteration
        %yk1
        y0 = y1;            
        %yk2
        %yk3      
        yk_mp = yk_mp1;%yk_mp + h * k2;
        %general
        i = i + 1;
        t = t + h;
        
        % Storing actual results
        yk1(i,:) = [t y1 h];
        yk3(i,:) = [t yk_mp1 h];
        h_i(i) = h;
       
        % Correct Value
        %4a
        y_t = y_start*exp(-t/Tau);
        yk2(i,:) = [t y_t h]; 
        
        
        
        %4c
        abs_dif1(i)  = abs(yk1(i,2)-yk2(i,2));
        dif1(i)      = yk1(i,2)-yk2(i,2);

        

%         abs_dif2(i)  = abs(yk3(i,2)-yk2(i,2));
%         dif1(2)      = yk3(i,2)-yk2(i,2);


        % Ending condition
        if t > tfinal
            break;
        end 
    
end

% aav = sum(abs_dif1)/(i-1);
% 
% 
% 
% aav2 = sum(abs_dif2)/(i-1);

% Display of results
plot(yk1(:,1),yk1(:,2),'ro-');
hold on
plot(yk2(:,1),yk2(:,2), 'g--');
plot(yk3(:,1),yk3(:,2), 'b+-');
axis([t0 tfinal min(yk1(:,2)) max(yk1(:,2))]);
xlabel('Time [sec]')
ylabel('y(t) [unit]')
legend('FE', 'Correct Value', 'MP');
grid
hold off


% x = [0.2, 0.1, 0.05, 0.025, 0.0125];
% loops = [11,213,498,1059,2093];
% points = [12,17,37,79,168]
% ax = plotyy(x,loops,x,points)
% ylabel(ax(1), 'Loops [n]');
% ylabel(ax(2), 'Points [n]');
% xlabel('relative tolerance (rtol)');
% grid;