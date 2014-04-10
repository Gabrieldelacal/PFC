clear all
clc

%%% Para usar la función Laplace en el archivo Laplace.m se deben declarar
%%% las variables de esta manera:

syms x dx ddx y dy ddy z dz ddz Phi dPhi ddPhi Theta dTheta ddTheta Psi dPsi ddPsi
syms w1 w2 w3 w4
syms Ixx Iyy Izz
syms Ax Ay Az 
syms k m g l b

%%% El vector de variables que se usarán

v=[x dx ddx y dy ddy z dz ddz Phi dPhi ddPhi Theta dTheta ddTheta Psi dPsi ddPsi]

Xi=[x; y; z]
dXi=[dx; dy; dz]

Eta=[Phi; Theta; Psi]
% dEta=diff(Eta,t)                  % En caso de haber declarado: syms Phi(t) Theta(t) Psi(t)
dEta=[dPhi; dTheta; dPsi]

Q=[Xi; Eta]
% dQ=diff(Q,t)
dQ=[dXi; dEta]

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
  
L=m/2*transpose(dXi)*dXi+(1/2)*transpose(dEta)*transpose(Weta)*II*Weta*dEta-m*g*z

%%% Aquí se obtiene con el Lagrangiano el vector de fuerzas F según
%%% F=(d/dt)(dp(L)/dp(dq))-d(L)/dq

F=Lagrange(L,v)

% F=[ ddx*m;
%    ddy*m;
%    ddz*m + g*m;
%    Ixx*ddPhi + (Iyy*dTheta^2*sin(2*Phi))/2 - (Izz*dTheta^2*sin(2*Phi))/2 - Ixx*ddPsi*sin(Theta) - Ixx*dPsi*dTheta*cos(Theta) - (Iyy*dPsi^2*sin(2*Phi)*cos(Theta)^2)/2 + (Izz*dPsi^2*sin(2*Phi)*cos(Theta)^2)/2 - Iyy*dPsi*dTheta*cos(2*Phi)*cos(Theta) + Izz*dPsi*dTheta*cos(2*Phi)*cos(Theta);
%    dPhi*(Ixx*dPsi*cos(Theta) - 2*Iyy*dTheta*cos(Phi)*sin(Phi) + 2*Izz*dTheta*cos(Phi)*sin(Phi) + Iyy*dPsi*cos(Phi)^2*cos(Theta) - Izz*dPsi*cos(Phi)^2*cos(Theta) - Iyy*dPsi*cos(Theta)*sin(Phi)^2 + Izz*dPsi*cos(Theta)*sin(Phi)^2) + Iyy*ddTheta*cos(Phi)^2 + Izz*ddTheta*sin(Phi)^2 - Ixx*dPsi^2*cos(Theta)*sin(Theta) + Iyy*dPsi^2*cos(Theta)*sin(Phi)^2*sin(Theta) + Iyy*ddPsi*cos(Phi)*cos(Theta)*sin(Phi) - Izz*ddPsi*cos(Phi)*cos(Theta)*sin(Phi) + Izz*dPsi^2*cos(Phi)^2*cos(Theta)*sin(Theta);
%    Ixx*ddPsi*sin(Theta)^2 - dPhi*(Ixx*dTheta*cos(Theta) - Iyy*dTheta*cos(Phi)^2*cos(Theta) + Izz*dTheta*cos(Phi)^2*cos(Theta) + Iyy*dTheta*cos(Theta)*sin(Phi)^2 - Izz*dTheta*cos(Theta)*sin(Phi)^2 - 2*Iyy*dPsi*cos(Phi)*cos(Theta)^2*sin(Phi) + 2*Izz*dPsi*cos(Phi)*cos(Theta)^2*sin(Phi)) - Ixx*ddPhi*sin(Theta) + Izz*ddPsi*cos(Phi)^2*cos(Theta)^2 + Iyy*ddPsi*cos(Theta)^2*sin(Phi)^2 + Iyy*ddTheta*cos(Phi)*cos(Theta)*sin(Phi) - Izz*ddTheta*cos(Phi)*cos(Theta)*sin(Phi) - Iyy*dTheta^2*cos(Phi)*sin(Phi)*sin(Theta) + Izz*dTheta^2*cos(Phi)*sin(Phi)*sin(Theta) + 2*Ixx*dPsi*dTheta*cos(Theta)*sin(Theta) - 2*Izz*dPsi*dTheta*cos(Phi)^2*cos(Theta)*sin(Theta) - 2*Iyy*dPsi*dTheta*cos(Theta)*sin(Phi)^2*sin(Theta)]

%%% Derivando a mano se obtiene que TauB=J*ddEta+CdEta 
%%% Y como TauB=[F(4); F(5); F(6)], se tiene que

CdEta=[F(4); F(5); F(6)]-J*[ddPhi; ddTheta; ddPsi]

%%% "Intentando" tenerlo en función de las velocidades:

collect(CdEta,dEta)

% collectCdEta=[((Izz*sin(2*Phi)*cos(Theta)^2)/2 - (Iyy*sin(2*Phi)*cos(Theta)^2)/2)*dPsi^2 + (Izz*cos(2*Phi)*cos(Theta) - Iyy*cos(2*Phi)*cos(Theta) - Ixx*cos(Theta))*dPsi*dTheta + ((Iyy*sin(2*Phi))/2 - (Izz*sin(2*Phi))/2)*dTheta^2;
%         dPsi^2*(Izz*cos(Phi)^2*cos(Theta)*sin(Theta) - Ixx*cos(Theta)*sin(Theta) + Iyy*cos(Theta)*sin(Phi)^2*sin(Theta)) - ddTheta*(Iyy*cos(Phi)^2 + Izz*sin(Phi)^2) - ddPsi*(Iyy*cos(Phi)*cos(Theta)*sin(Phi) - Izz*cos(Phi)*cos(Theta)*sin(Phi)) + Iyy*ddTheta*cos(Phi)^2 + Izz*ddTheta*sin(Phi)^2 - dPhi*dTheta*(2*Iyy*cos(Phi)*sin(Phi) - 2*Izz*cos(Phi)*sin(Phi)) + dPhi*dPsi*(Ixx*cos(Theta) + Iyy*cos(Phi)^2*cos(Theta) - Izz*cos(Phi)^2*cos(Theta) - Iyy*cos(Theta)*sin(Phi)^2 + Izz*cos(Theta)*sin(Phi)^2) + Iyy*ddPsi*cos(Phi)*cos(Theta)*sin(Phi) - Izz*ddPsi*cos(Phi)*cos(Theta)*sin(Phi);
%         Ixx*ddPsi*sin(Theta)^2 - ddPsi*(Izz*cos(Phi)^2*cos(Theta)^2 + Iyy*cos(Theta)^2*sin(Phi)^2 + Ixx*sin(Theta)^2) - ddTheta*(Iyy*cos(Phi)*cos(Theta)*sin(Phi) - Izz*cos(Phi)*cos(Theta)*sin(Phi)) - dTheta^2*(Iyy*cos(Phi)*sin(Phi)*sin(Theta) - Izz*cos(Phi)*sin(Phi)*sin(Theta)) - dPsi*dTheta*(2*Izz*cos(Phi)^2*cos(Theta)*sin(Theta) - 2*Ixx*cos(Theta)*sin(Theta) + 2*Iyy*cos(Theta)*sin(Phi)^2*sin(Theta)) - dPhi*dTheta*(Ixx*cos(Theta) - Iyy*cos(Phi)^2*cos(Theta) + Izz*cos(Phi)^2*cos(Theta) + Iyy*cos(Theta)*sin(Phi)^2 - Izz*cos(Theta)*sin(Phi)^2) + dPhi*dPsi*(2*Iyy*cos(Phi)*cos(Theta)^2*sin(Phi) - 2*Izz*cos(Phi)*cos(Theta)^2*sin(Phi)) + Izz*ddPsi*cos(Phi)^2*cos(Theta)^2 + Iyy*ddPsi*cos(Theta)^2*sin(Phi)^2 + Iyy*ddTheta*cos(Phi)*cos(Theta)*sin(Phi) - Izz*ddTheta*cos(Phi)*cos(Theta)*sin(Phi)]

%%% Hasta aquí tengo el producto Coriolis(Eta,dEta)*dEta

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%% Redefino las variables para encontrar los puntos de equilibrio con dsolve

syms x(t) y(t) z(t) Phi(t) Theta(t) Psi(t)  

Xi=[x; y; z]
dXi=diff(Eta,t)
ddXi=diff(dXi,t)

Eta=[Phi; Theta; Psi]
dEta=diff(Eta,t)
ddEta=diff(dEta,t)

%%% Todas las funciones deben ser redefinidas en cuanto hay un cambio
%%% de variable de por medio

R=[[cos(Psi)*cos(Theta) cos(Psi)*sin(Theta)*sin(Phi)-sin(Psi)*cos(Phi) cos(Psi)*sin(Theta)*cos(Phi)+sin(Psi)*sin(Phi)];
   [sin(Psi)*cos(Theta) sin(Psi)*sin(Theta)*sin(Phi)+cos(Psi)*cos(Phi) sin(Psi)*sin(Theta)*cos(Phi)-cos(Psi)*sin(Phi)];
   [-sin(Theta) cos(Theta)*sin(Phi) cos(Theta)*cos(Phi)]]

T=k*(w1^2+w2^2+w3^2+w4^2)
TB=[0; 0; T]

TauB=[[l*k*(w4^2-w2^2)];
      [l*k*(w3^2-w1^2)];
      [b*(w1^2+w3^2-w2^2-w4^2)]]

%%% SOLVE %%%

ddXi=(R*TB-[0; 0; m*g])/m
ddEta=inv(J)*(TauB-CdEta)

