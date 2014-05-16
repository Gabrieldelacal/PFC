clear all
clc 

syms Phi Theta Psi

% Xi = [Phi Theta Psi]

%Phi=pi/2
%Theta=pi/2
%Psi=pi/2

Rx1=[[1        0         0];
     [0 cos(Phi) -sin(Phi)];
     [0 sin(Phi)  cos(Phi)]]
 
 
Rx2=[[ cos(Theta) 0  sin(Theta)];
     [          0 1           0];
     [-sin(Theta) 0  cos(Theta)]]
     
      
Rx3=[[cos(Psi) -sin(Psi) 0];
     [sin(Psi)  cos(Psi) 0];
     [     0           0 1]] 
 
v=[1; 0; 1]
 
Rtotal=Rx3*Rx2*Rx1
 

P1=Rx1*v
P2=Rx2*Rx1*v
P3=Rx3*Rx2*Rx1*v