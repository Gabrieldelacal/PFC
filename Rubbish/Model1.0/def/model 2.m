clc
clear all

% syms x(t) y(t) z(t) Phi(t) Theta(t) Psi(t)
syms x y z Phi Theta Psi
syms dx dy dz dPhi dTheta dPsi
syms w1 w2 w3 w4
syms Ixx Iyy Izz
syms Ax Ay Az 
syms k m g l b
% syms vx(x) vy(y) vz(z) p q r
% syms Ipsilon

Xi=[x; y; z]
% dXi=diff(Xi,t)
dXi=[dx; dy; dz]

Eta=[Phi; Theta; Psi]
% dEta=diff(Eta,t)
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

R=[[cos(Psi)*cos(Theta) cos(Psi)*sin(Theta)*sin(Phi)-sin(Psi)*cos(Phi) cos(Psi)*sin(Theta)*cos(Phi)+sin(Psi)*sin(Phi)];
   [sin(Psi)*cos(Theta) sin(Psi)*sin(Theta)*sin(Phi)+cos(Psi)*cos(Phi) sin(Psi)*sin(Theta)*cos(Phi)-cos(Psi)*sin(Phi)];
   [-sin(Theta) cos(Theta)*sin(Phi) cos(Theta)*cos(Phi)]]

C11=0;
C12=(Iyy-Izz)*(dTheta*cos(Phi)*sin(Phi)+dPsi*sin(Phi)*sin(Phi)*cos(Theta))+(Izz-Iyy)*dPsi*cos(Phi)*cos(Phi)*cos(Theta)-Ixx*dPsi*cos(Theta);
C13=(Izz-Iyy)*dPsi*cos(Phi)*sin(Phi)*(cos(Theta)^2);

% C21=(Izz-Iyy)*(dTheta*cos(Phi)*sin(Phi)+dPsi*(sin(Phi)^2)*cos(Theta))+(Izz-Iyy)*dPsi*(cos(Phi)^2)*cos(Theta)-Ixx*dPsi*cos(Theta);
C21=(Izz-Iyy)*(dTheta*cos(Phi)*sin(Phi)+dPsi*sin(Phi)*cos(Theta))+(Iyy-Izz)*dPsi*cos(Phi)*cos(Phi)*cos(Theta)+Ixx*dPsi*cos(Theta);
C22=(Izz-Iyy)*dPhi*cos(Phi)*sin(Phi);
C23=-Ixx*dPsi*sin(Theta)*cos(Theta)+Iyy*dPsi*sin(Phi)*sin(Phi)*sin(Theta)*cos(Theta)+Izz*dPsi*cos(Phi)*cos(Phi)*sin(Theta)*cos(Theta);

C31=(Iyy-Izz)*dPsi*cos(Theta)*cos(Theta)*sin(Phi)*cos(Phi)-Ixx*dTheta*cos(Theta);
C32=(Izz-Iyy)*(dTheta*cos(Phi)*sin(Phi)*sin(Theta)+dPhi*sin(Phi)*sin(Phi)*cos(Theta))+(Iyy-Izz)*dPhi*cos(Phi)*cos(Phi)*cos(Theta)+Ixx*dPsi*sin(Theta)*cos(Theta)-Iyy*dPsi*sin(Phi)*sin(Phi)*sin(Theta)*cos(Theta)-Izz*dPsi*cos(Phi)*cos(Phi)*sin(Theta)*cos(Theta);
C33=(Iyy-Izz)*dPhi*cos(Phi)*sin(Phi)*cos(Theta)*cos(Theta)-Iyy*dTheta*sin(Phi)*sin(Phi)*cos(Theta)*sin(Theta)-Izz*dTheta*cos(Phi)*cos(Phi)*cos(Theta)*sin(Theta)+Ixx*dTheta*cos(Theta)*sin(Theta);

Cm=[[C11 C12 C13];
   [C21 C22 C23];
   [C31 C32 C33]];

% test=inv(J)*(Tau)

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
% F=diff(diff(L,Q),t)+diff(L,Q)
L1=transpose(jacobian(L,Q))
L2=transpose(jacobian(L,dQ))

syms x(t) y(t) z(t) Phi(t) Theta(t) Psi(t) dx(t) dy(t) dz(t) dPhi(t) dTheta(t) dPsi(t)

L1 =[ 0; 0; -g*m; dPsi*(Iyy*cos(Phi)*cos(Theta)*((dTheta*cos(Phi))/2 + (dPsi*cos(Theta)*sin(Phi))/2) - Izz*cos(Phi)*cos(Theta)*((dTheta*cos(Phi))/2 + (dPsi*cos(Theta)*sin(Phi))/2) - Iyy*cos(Theta)*sin(Phi)*((dTheta*sin(Phi))/2 - (dPsi*cos(Phi)*cos(Theta))/2) + Izz*cos(Theta)*sin(Phi)*((dTheta*sin(Phi))/2 - (dPsi*cos(Phi)*cos(Theta))/2)) - dTheta*(Iyy*cos(Phi)*((dTheta*sin(Phi))/2 - (dPsi*cos(Phi)*cos(Theta))/2) - Izz*cos(Phi)*((dTheta*sin(Phi))/2 - (dPsi*cos(Phi)*cos(Theta))/2) + Iyy*sin(Phi)*((dTheta*cos(Phi))/2 + (dPsi*cos(Theta)*sin(Phi))/2) - Izz*sin(Phi)*((dTheta*cos(Phi))/2 + (dPsi*cos(Theta)*sin(Phi))/2)); - dPsi*(Ixx*cos(Theta)*(dPhi/2 - (dPsi*sin(Theta))/2) - Izz*cos(Phi)*sin(Theta)*((dTheta*sin(Phi))/2 - (dPsi*cos(Phi)*cos(Theta))/2) + Iyy*sin(Phi)*sin(Theta)*((dTheta*cos(Phi))/2 + (dPsi*cos(Theta)*sin(Phi))/2) - (Ixx*dPsi*cos(Theta)*sin(Theta))/2 + (Izz*dPsi*cos(Phi)^2*cos(Theta)*sin(Theta))/2 + (Iyy*dPsi*cos(Theta)*sin(Phi)^2*sin(Theta))/2) - dTheta*((Iyy*dPsi*cos(Phi)*sin(Phi)*sin(Theta))/2 - (Izz*dPsi*cos(Phi)*sin(Phi)*sin(Theta))/2) - (Ixx*dPhi*dPsi*cos(Theta))/2; 0]
 
L2 =[ dx*m; dy*m; dz*m; (Ixx*dPhi)/2 + Ixx*(dPhi/2 - (dPsi*sin(Theta))/2) - (Ixx*dPsi*sin(Theta))/2; dTheta*((Iyy*cos(Phi)^2)/2 + (Izz*sin(Phi)^2)/2) + dPsi*((Iyy*cos(Phi)*cos(Theta)*sin(Phi))/2 - (Izz*cos(Phi)*cos(Theta)*sin(Phi))/2) + Iyy*cos(Phi)*((dTheta*cos(Phi))/2 + (dPsi*cos(Theta)*sin(Phi))/2) + Izz*sin(Phi)*((dTheta*sin(Phi))/2 - (dPsi*cos(Phi)*cos(Theta))/2); dPsi*((Ixx*sin(Theta)^2)/2 + (Izz*cos(Phi)^2*cos(Theta)^2)/2 + (Iyy*cos(Theta)^2*sin(Phi)^2)/2) + dTheta*((Iyy*cos(Phi)*cos(Theta)*sin(Phi))/2 - (Izz*cos(Phi)*cos(Theta)*sin(Phi))/2) - Ixx*sin(Theta)*(dPhi/2 - (dPsi*sin(Theta))/2) - (Ixx*dPhi*sin(Theta))/2 - Izz*cos(Phi)*cos(Theta)*((dTheta*sin(Phi))/2 - (dPsi*cos(Phi)*cos(Theta))/2) + Iyy*cos(Theta)*sin(Phi)*((dTheta*cos(Phi))/2 + (dPsi*cos(Theta)*sin(Phi))/2)]
 
F=diff(L2,t)-L1

pretty(F)