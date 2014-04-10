clc
clear all

syms x(t) y(t) z(t) Phi(t) Theta(t) Psi(t)
% syms x y z Phi Theta Psi
syms w1 w2 w3 w4
syms Ixx Iyy Izz
syms Ax Ay Az 
syms k m g l b
% syms vx(x) vy(y) vz(z) p q r
% syms Ipsilon

Xi=[x; y; z]
dXi=diff(Xi,t)

Eta=[Phi; Theta; Psi]
dEta=diff(Eta,t)

Q=[Xi; Eta]
dQ=diff(Q,t)

II=[[Ixx 0 0];
    [0 Iyy 0];
    [0 0 Izz]]

A=[[Ax 0 0];
   [0 Ay 0];
   [0 0 Az]]   
   
Weta=[[1 0 -sin(Theta)];
      [0 cos(Phi) cos(Theta)*sin(Phi)];
      [0 -sin(Phi) cos(Theta)*cos(Phi)]]
  
J=transpose(Weta)*II*Weta  

R=[[cos(Psi)*cos(Theta) cos(Psi)*sin(Theta)*sin(Phi)-sin(Psi)*cos(Phi) cos(Psi)*sin(Theta)*cos(Phi)+sin(Psi)*sin(Phi)];
   [sin(Psi)*cos(Theta) sin(Psi)*sin(Theta)*sin(Phi)+cos(Psi)*cos(Phi) sin(Psi)*sin(Theta)*cos(Phi)-cos(Psi)*sin(Phi)];
   [-sin(Theta) cos(Theta)*sin(Phi) cos(Theta)*cos(Phi)]]

T=k*(w1^2+w2^2+w3^2+w4^2);       

TB=[0; 0; T]

TauB=[[l*k*(w4^2-w2^2)];
      [l*k*(w3^2-w1^2)];
      [b*(w1^2+w3^2-w2^2-w4^2)]]

% VB=diff(Xi,x)+diff(Xi,y)+diff(Xi,z)
% VB=[dsolve(Xi,x); dsolve(Xi,y); dsolve(Xi,z)]

% Ipsilon=[p; q; r]

% Lagrangiano: 
L=m/2*transpose(dXi)*dXi+(1/2)*transpose(dEta)*transpose(Weta)*II*Weta*dEta-m*g*z
jacobian(L,t)

