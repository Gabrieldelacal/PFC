clc
clear all

g=9.81;
m=0.468;        % masa total del Q
Ixx=0.004856;      % Inercias
Iyy=0.004856;
Izz=0.008801;

l=0.225;        % Longitud de cada brazo    

syms x y z Phi Theta Psi        % Variables de posici�n lineales y angulares
syms w1 w2 w3 w4                % Velocidades angulares de cada motor
II=[[Ixx 0 0];
    [0 Iyy 0];
    [0 0 Izz]]

Ax=0.25;
Ay=0.25;
Az=0.25;

Xi=[x; y; z]
Eta=[Phi; Theta; Psi]
Q=[Xi ;Eta]

% Matriz de transformaci�n de velocidades angulares del Inertial Frame al Body Frame
Weta=[[1 0 -sin(Theta)];
      [0 cos(Phi) cos(Theta)*sin(Phi)];
      [0 -sin(Phi) cos(Theta)*cos(Phi)]]
  
J=transpose(Weta)*II*Weta
  
k=0.00000298;       % constante de sustentaci�n de los motores: f=k*omega^2
b=1.14E-7;       % cosntante de rozamiento

% Matriz de rotaci�n del Body Frame a Inertial Frame --> inv(R) = R'
R=[[cos(Psi)*cos(Theta) cos(Psi)*sin(Theta)*sin(Phi)-sin(Psi)*cos(Phi) cos(Psi)*sin(Theta)*cos(Phi)+sin(Psi)*sin(Phi)];
   [sin(Psi)*cos(Theta) sin(Psi)*sin(Theta)*sin(Phi)+cos(Psi)*cos(Phi) sin(Psi)*sin(Theta)*cos(Phi)-cos(Psi)*sin(Phi)];
   [-sin(Theta) cos(Theta)*sin(Phi) cos(Theta)*cos(Phi)]]

% syms T

% T=k*(w1^2+w2^2+w3^2+w4^2)       % Empuje total 
% TB=[0; 0; T]                    

% TauB=[[l*k*(w4^2-w2^2)];
%       [l*k*(w3^2-w1^2)];
%       [b*(w1^2+w3^2-w2^2-w4^2)]]

% syms vx vy vz p q r

% VB=[vx; vy; vz]                 % Velocidades lineal en el Body Frame
% Ipsilon=[p; q; r]               % Velocidades angulares en el Body Frame




