function [dydt] = f(t,y, Tau)
%%
% This function evaluates a programmed function: 
%    Uses numerical values of f and/or t as input and return 
%    corresponding value of the function at that point
%
% Author: R.Estrada, FH JOANNEUM
% Date:   May 2014
%%

% Param definition        

% Function evelution
dydt = -y/Tau;
