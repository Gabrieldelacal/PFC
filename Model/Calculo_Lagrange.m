clear all
clc

%%% Para usar la funci�n Laplace en el archivo Laplace.m se deben declarar
%%% las variables de esta manera:

syms x dx ddx y dy ddy z dz ddz Phi dPhi ddPhi Theta dTheta ddTheta Psi dPsi ddPsi
syms f1 f2 f3 f4 m1 m2 m3 m4
% syms w1 w2 w3 w4
syms Ixx Iyy Izz
syms Ax Ay Az 
syms k m g l b

 l=0.165
 Ixx=0.007931
 Iyy=0.007667
 Izz=0.009741
 m=0.85
 b=1.2*10^-7
 k=3*10^-6

 g=9.81
 
 Ax=0
 Ay=0
 Az=0
 

%%% El vector de variables que se usar�n

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
   
%Weta=[[1 0 -sin(Theta)];
%      [0 cos(Phi) cos(Theta)*sin(Phi)];
%      [0 -sin(Phi) cos(Theta)*cos(Phi)]]

Weta=[[1 0 sin(Theta)];
      [0 cos(Phi) -cos(Theta)*sin(Phi)];
      [0 sin(Phi) cos(Theta)*cos(Phi)]];  
  
J=transpose(Weta)*II*Weta  
  
L=m/2*transpose(dXi)*dXi+(1/2)*transpose(dEta)*transpose(Weta)*II*Weta*dEta-m*g*z

%%% Aqu� se obtiene con el Lagrangiano el vector de fuerzas F seg�n
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


%%% "Intentando" tenerlo en funci�n de las velocidades:

%%% collect(CdEta,dEta);

% collectCdEta=[((Izz*sin(2*Phi)*cos(Theta)^2)/2 - (Iyy*sin(2*Phi)*cos(Theta)^2)/2)*dPsi^2 + (Izz*cos(2*Phi)*cos(Theta) - Iyy*cos(2*Phi)*cos(Theta) - Ixx*cos(Theta))*dPsi*dTheta + ((Iyy*sin(2*Phi))/2 - (Izz*sin(2*Phi))/2)*dTheta^2;
%         dPsi^2*(Izz*cos(Phi)^2*cos(Theta)*sin(Theta) - Ixx*cos(Theta)*sin(Theta) + Iyy*cos(Theta)*sin(Phi)^2*sin(Theta)) - ddTheta*(Iyy*cos(Phi)^2 + Izz*sin(Phi)^2) - ddPsi*(Iyy*cos(Phi)*cos(Theta)*sin(Phi) - Izz*cos(Phi)*cos(Theta)*sin(Phi)) + Iyy*ddTheta*cos(Phi)^2 + Izz*ddTheta*sin(Phi)^2 - dPhi*dTheta*(2*Iyy*cos(Phi)*sin(Phi) - 2*Izz*cos(Phi)*sin(Phi)) + dPhi*dPsi*(Ixx*cos(Theta) + Iyy*cos(Phi)^2*cos(Theta) - Izz*cos(Phi)^2*cos(Theta) - Iyy*cos(Theta)*sin(Phi)^2 + Izz*cos(Theta)*sin(Phi)^2) + Iyy*ddPsi*cos(Phi)*cos(Theta)*sin(Phi) - Izz*ddPsi*cos(Phi)*cos(Theta)*sin(Phi);
%         Ixx*ddPsi*sin(Theta)^2 - ddPsi*(Izz*cos(Phi)^2*cos(Theta)^2 + Iyy*cos(Theta)^2*sin(Phi)^2 + Ixx*sin(Theta)^2) - ddTheta*(Iyy*cos(Phi)*cos(Theta)*sin(Phi) - Izz*cos(Phi)*cos(Theta)*sin(Phi)) - dTheta^2*(Iyy*cos(Phi)*sin(Phi)*sin(Theta) - Izz*cos(Phi)*sin(Phi)*sin(Theta)) - dPsi*dTheta*(2*Izz*cos(Phi)^2*cos(Theta)*sin(Theta) - 2*Ixx*cos(Theta)*sin(Theta) + 2*Iyy*cos(Theta)*sin(Phi)^2*sin(Theta)) - dPhi*dTheta*(Ixx*cos(Theta) - Iyy*cos(Phi)^2*cos(Theta) + Izz*cos(Phi)^2*cos(Theta) + Iyy*cos(Theta)*sin(Phi)^2 - Izz*cos(Theta)*sin(Phi)^2) + dPhi*dPsi*(2*Iyy*cos(Phi)*cos(Theta)^2*sin(Phi) - 2*Izz*cos(Phi)*cos(Theta)^2*sin(Phi)) + Izz*ddPsi*cos(Phi)^2*cos(Theta)^2 + Iyy*ddPsi*cos(Theta)^2*sin(Phi)^2 + Iyy*ddTheta*cos(Phi)*cos(Theta)*sin(Phi) - Izz*ddTheta*cos(Phi)*cos(Theta)*sin(Phi)]

%%% Hasta aqu� tengo el producto Coriolis(Eta,dEta)*dEta. Pero como matlab
%%% no elimina las aceleraciones se hace a mano, y queda:

%CdEta = [(Iyy*dTheta^2*sin(2*Phi))/2 - (Izz*dTheta^2*sin(2*Phi))/2 - Ixx*dPsi*dTheta*cos(Theta) - (Iyy*dPsi^2*sin(2*Phi)*cos(Theta)^2)/2 + (Izz*dPsi^2*sin(2*Phi)*cos(Theta)^2)/2 - Iyy*dPsi*dTheta*cos(2*Phi)*cos(Theta) + Izz*dPsi*dTheta*cos(2*Phi)*cos(Theta);
%          dPhi*(Ixx*dPsi*cos(Theta) - 2*Iyy*dTheta*cos(Phi)*sin(Phi) + 2*Izz*dTheta*cos(Phi)*sin(Phi) + Iyy*dPsi*cos(Phi)^2*cos(Theta) - Izz*dPsi*cos(Phi)^2*cos(Theta) - Iyy*dPsi*cos(Theta)*sin(Phi)^2 + Izz*dPsi*cos(Theta)*sin(Phi)^2)  - Ixx*dPsi^2*cos(Theta)*sin(Theta) + Iyy*dPsi^2*cos(Theta)*sin(Phi)^2*sin(Theta)  + Izz*dPsi^2*cos(Phi)^2*cos(Theta)*sin(Theta);
%          -dPhi*(Ixx*dTheta*cos(Theta) - Iyy*dTheta*cos(Phi)^2*cos(Theta) + Izz*dTheta*cos(Phi)^2*cos(Theta) + Iyy*dTheta*cos(Theta)*sin(Phi)^2 - Izz*dTheta*cos(Theta)*sin(Phi)^2 - 2*Iyy*dPsi*cos(Phi)*cos(Theta)^2*sin(Phi) + 2*Izz*dPsi*cos(Phi)*cos(Theta)^2*sin(Phi)) - Iyy*dTheta^2*cos(Phi)*sin(Phi)*sin(Theta) + Izz*dTheta^2*cos(Phi)*sin(Phi)*sin(Theta) + 2*Ixx*dPsi*dTheta*cos(Theta)*sin(Theta) - 2*Izz*dPsi*dTheta*cos(Phi)^2*cos(Theta)*sin(Theta) - 2*Iyy*dPsi*dTheta*cos(Theta)*sin(Phi)^2*sin(Theta)]
 
CdEta=[(Iyy*dTheta^2*sin(2*Phi))/2 - (Izz*dTheta^2*sin(2*Phi))/2 + Ixx*dPsi*dTheta*cos(Theta) - (Iyy*dPsi^2*sin(2*Phi)*cos(Theta)^2)/2 + (Izz*dPsi^2*sin(2*Phi)*cos(Theta)^2)/2 + Iyy*dPsi*dTheta*cos(2*Phi)*cos(Theta) - Izz*dPsi*dTheta*cos(2*Phi)*cos(Theta);
       - dPhi*(Ixx*dPsi*cos(Theta) + 2*Iyy*dTheta*cos(Phi)*sin(Phi) - 2*Izz*dTheta*cos(Phi)*sin(Phi) + Iyy*dPsi*cos(Phi)^2*cos(Theta) - Izz*dPsi*cos(Phi)^2*cos(Theta) - Iyy*dPsi*cos(Theta)*sin(Phi)^2 + Izz*dPsi*cos(Theta)*sin(Phi)^2)  - Ixx*dPsi^2*cos(Theta)*sin(Theta) + Iyy*dPsi^2*cos(Theta)*sin(Phi)^2*sin(Theta) + Izz*dPsi^2*cos(Phi)^2*cos(Theta)*sin(Theta);
       dPhi*(Ixx*dTheta*cos(Theta) - Iyy*dTheta*cos(Phi)^2*cos(Theta) + Izz*dTheta*cos(Phi)^2*cos(Theta) + Iyy*dTheta*cos(Theta)*sin(Phi)^2 - Izz*dTheta*cos(Theta)*sin(Phi)^2 + 2*Iyy*dPsi*cos(Phi)*cos(Theta)^2*sin(Phi) - 2*Izz*dPsi*cos(Phi)*cos(Theta)^2*sin(Phi)) + Iyy*dTheta^2*cos(Phi)*sin(Phi)*sin(Theta) - Izz*dTheta^2*cos(Phi)*sin(Phi)*sin(Theta) + 2*Ixx*dPsi*dTheta*cos(Theta)*sin(Theta) - 2*Izz*dPsi*dTheta*cos(Phi)^2*cos(Theta)*sin(Theta) - 2*Iyy*dPsi*dTheta*cos(Theta)*sin(Phi)^2*sin(Theta)]

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%% SI SE QUISIERA ENCONTRAR LA SOLUCIÓN ANAL�?TICA DE LAS ECUACIONES: 

%%% Redefino las variables para encontrar los puntos de equilibrio con dsolve

% syms x(t) y(t) z(t) Phi(t) Theta(t) Psi(t)  

% Xi=[x; y; z]
% dXi=diff(Eta,t)
% ddXi=diff(dXi,t)

% Eta=[Phi; Theta; Psi]
% dEta=diff(Eta,t)
% ddEta=diff(dEta,t)

% dPhi=dEta(1);
% dTheta=dEta(2);
% dPhi=dEta(3);

% syms DPhi DTheta DPsi

%%% La notación para introducir derivadas en la función dsolve es Dx como derivada de x

% dPhi=DPhi
% dTheta=DTheta
% dPsi=DPsi

% CdEta= ... 

%%% Todas las funciones deben ser redefinidas en cuanto hay un cambio
%%% de variable de por medio

 R=[[cos(Psi)*cos(Theta) cos(Psi)*sin(Theta)*sin(Phi)-sin(Psi)*cos(Phi) cos(Psi)*sin(Theta)*cos(Phi)+sin(Psi)*sin(Phi)];
    [sin(Psi)*cos(Theta) sin(Psi)*sin(Theta)*sin(Phi)+cos(Psi)*cos(Phi) sin(Psi)*sin(Theta)*cos(Phi)-cos(Psi)*sin(Phi)];
    [-sin(Theta)                                    cos(Theta)*sin(Phi)                            cos(Theta)*cos(Phi)]]

 % T=k*(w1^2+w2^2+w3^2+w4^2)
 T=f1+f2+f3+f4
 
 TB=[0; 0; T]

% TauB=[[l*k*(w4^2-w2^2)];                         
%        [l*k*(w3^2-w1^2)];
%        [b*(w1^2+w3^2-w2^2-w4^2)]]

TauB=[l*(f4-f2);
      l*(f3-f1);
      % (m1+m2+m3+m4)]
      b*(f1-f2+f3-f4)]
%%% SOLVE %%%

% sys1=(R*TB-[0; 0; m*g])/m

% sys2=inv(J)*(TauB-CdEta)

%%% a=dsolve('D2x=sys1(1)','D2y=sys1(2)','D2z=sys1(3)','D2Phi=sys2(1)','D2Theta=sys2(2)','D2Psi=sys2(3)')

%%% PERO COMO ÉSTO NO HAY MANERA DE HACERLO, NO SE ENCONTRAR�?N LAS SOLUCIONES ANAL�?TICAS DE LAS ECUACIONES

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%% COMO ALTERNATIVA SE INTENTARAN ENCONTRAR LOS PUNTOS DE EQUILIBRIO

% Se pseudo-representa el sistema en espacio de estados:

% diff(x)=dx
% diff(y)=dy
% diff(z)=dz
% diff(dx)=sys1(1)
% diff(dy)=sys1(2)
% diff(dz)=sys1(3)
% diff(Phi)=dPhi
% diff(Theta)=dTheta
% diff(Psi)=dPsi
% diff(dPhi)=sys2(1)
% diff(dTheta)=sys2(2)
% diff(dPsi)=sys2(3)

% A la hora de encontrar los puntos de equilibrio se obliga a que las
% velocidades sean zero, excepto las de traslación. 

%%% Con los dos monstruos calculados anteriormente:

dPhi=0
dTheta=0
dPsi=0

R=eye(3)

sys1=(R*TB-[0; 0; m*g])/m
sys2=inv(J)*(TauB-CdEta)

% sys1 =
 
%   (k*(sin(Phi)*sin(Psi) + cos(Phi)*cos(Psi)*sin(Theta))*(w1^2 + w2^2 + w3^2 + w4^2))/m
%  -(k*(cos(Psi)*sin(Phi) - cos(Phi)*sin(Psi)*sin(Theta))*(w1^2 + w2^2 + w3^2 + w4^2))/m
%                           -(g*m - k*cos(Phi)*cos(Theta)*(w1^2 + w2^2 + w3^2 + w4^2))/m
  
% sys2 =
 
% ((Iyy*Izz*cos(Phi)^4*cos(Theta)^2 + Ixx*Iyy*cos(Phi)^2*sin(Theta)^2 + Iyy*Izz*cos(Theta)^2*sin(Phi)^4 + Ixx*Izz*sin(Phi)^2*sin(Theta)^2 + 2*Iyy*Izz*cos(Phi)^2*cos(Theta)^2*sin(Phi)^2)*((Izz*dTheta^2*sin(2*Phi))/2 - k*l*(w2^2 - w4^2) + Ixx*dPsi*dTheta*cos(Theta) + (Iyy*dPsi^2*sin(2*Phi)*cos(Theta)^2)/2 - (Izz*dPsi^2*sin(2*Phi)*cos(Theta)^2)/2 + Iyy*dPsi*dTheta*cos(2*Phi)*cos(Theta) - Izz*dPsi*dTheta*cos(2*Phi)*cos(Theta)))/(Ixx*Iyy*Izz*cos(Phi)^4*cos(Theta)^2 + Ixx*Iyy*Izz*cos(Theta)^2*sin(Phi)^4 + 2*Ixx*Iyy*Izz*cos(Phi)^2*cos(Theta)^2*sin(Phi)^2) + (sin(Theta)*(Iyy*cos(Phi)*sin(Phi) - Izz*cos(Phi)*sin(Phi))*(dPhi*(Ixx*dPsi*cos(Theta) - 2*Iyy*dTheta*cos(Phi)*sin(Phi) + 2*Izz*dTheta*cos(Phi)*sin(Phi) + Iyy*dPsi*cos(Phi)^2*cos(Theta) - Izz*dPsi*cos(Phi)^2*cos(Theta) - Iyy*dPsi*cos(Theta)*sin(Phi)^2 + Izz*dPsi*cos(Theta)*sin(Phi)^2) - ddTheta*(Iyy*cos(Phi)^2 + Izz*sin(Phi)^2) + Iyy*ddTheta*cos(Phi)^2 + Izz*ddTheta*sin(Phi)^2 + k*l*(w1^2 - w3^2) - Ixx*dPsi^2*cos(Theta)*sin(Theta) + Iyy*dPsi^2*cos(Theta)*sin(Phi)^2*sin(Theta) + Izz*dPsi^2*cos(Phi)^2*cos(Theta)*sin(Theta)))/(Iyy*Izz*cos(Phi)^4*cos(Theta) + Iyy*Izz*cos(Theta)*sin(Phi)^4 + 2*Iyy*Izz*cos(Phi)^2*cos(Theta)*sin(Phi)^2) + (sin(Theta)*(Iyy*cos(Phi)^2 + Izz*sin(Phi)^2)*(b*(w1^2 - w2^2 + w3^2 - w4^2) + dPhi*(Ixx*dTheta*cos(Theta) - Iyy*dTheta*cos(Phi)^2*cos(Theta) + Izz*dTheta*cos(Phi)^2*cos(Theta) + Iyy*dTheta*cos(Theta)*sin(Phi)^2 - Izz*dTheta*cos(Theta)*sin(Phi)^2 - 2*Iyy*dPsi*cos(Phi)*cos(Theta)^2*sin(Phi) + 2*Izz*dPsi*cos(Phi)*cos(Theta)^2*sin(Phi)) + Iyy*dTheta^2*cos(Phi)*sin(Phi)*sin(Theta) - Izz*dTheta^2*cos(Phi)*sin(Phi)*sin(Theta) - 2*Ixx*dPsi*dTheta*cos(Theta)*sin(Theta) + 2*Izz*dPsi*dTheta*cos(Phi)^2*cos(Theta)*sin(Theta) + 2*Iyy*dPsi*dTheta*cos(Theta)*sin(Phi)^2*sin(Theta)))/(Iyy*Izz*cos(Phi)^4*cos(Theta)^2 + Iyy*Izz*cos(Theta)^2*sin(Phi)^4 + 2*Iyy*Izz*cos(Phi)^2*cos(Theta)^2*sin(Phi)^2)
%                                                                                                                                                                                                          - ((Izz*cos(Phi)^2 + Iyy*sin(Phi)^2)*(dPhi*(Ixx*dPsi*cos(Theta) - 2*Iyy*dTheta*cos(Phi)*sin(Phi) + 2*Izz*dTheta*cos(Phi)*sin(Phi) + Iyy*dPsi*cos(Phi)^2*cos(Theta) - Izz*dPsi*cos(Phi)^2*cos(Theta) - Iyy*dPsi*cos(Theta)*sin(Phi)^2 + Izz*dPsi*cos(Theta)*sin(Phi)^2) - ddTheta*(Iyy*cos(Phi)^2 + Izz*sin(Phi)^2) + Iyy*ddTheta*cos(Phi)^2 + Izz*ddTheta*sin(Phi)^2 + k*l*(w1^2 - w3^2) - Ixx*dPsi^2*cos(Theta)*sin(Theta) + Iyy*dPsi^2*cos(Theta)*sin(Phi)^2*sin(Theta) + Izz*dPsi^2*cos(Phi)^2*cos(Theta)*sin(Theta)))/(Iyy*Izz*cos(Phi)^4 + Iyy*Izz*sin(Phi)^4 + 2*Iyy*Izz*cos(Phi)^2*sin(Phi)^2) - ((Iyy*cos(Phi)*sin(Phi) - Izz*cos(Phi)*sin(Phi))*(b*(w1^2 - w2^2 + w3^2 - w4^2) + dPhi*(Ixx*dTheta*cos(Theta) - Iyy*dTheta*cos(Phi)^2*cos(Theta) + Izz*dTheta*cos(Phi)^2*cos(Theta) + Iyy*dTheta*cos(Theta)*sin(Phi)^2 - Izz*dTheta*cos(Theta)*sin(Phi)^2 - 2*Iyy*dPsi*cos(Phi)*cos(Theta)^2*sin(Phi) + 2*Izz*dPsi*cos(Phi)*cos(Theta)^2*sin(Phi)) + Iyy*dTheta^2*cos(Phi)*sin(Phi)*sin(Theta) - Izz*dTheta^2*cos(Phi)*sin(Phi)*sin(Theta) - 2*Ixx*dPsi*dTheta*cos(Theta)*sin(Theta) + 2*Izz*dPsi*dTheta*cos(Phi)^2*cos(Theta)*sin(Theta) + 2*Iyy*dPsi*dTheta*cos(Theta)*sin(Phi)^2*sin(Theta)))/(Iyy*Izz*cos(Phi)^4*cos(Theta) + Iyy*Izz*cos(Theta)*sin(Phi)^4 + 2*Iyy*Izz*cos(Phi)^2*cos(Theta)*sin(Phi)^2) - (sin(Theta)*(Iyy*cos(Phi)*sin(Phi) - Izz*cos(Phi)*sin(Phi))*((Izz*dTheta^2*sin(2*Phi))/2 - k*l*(w2^2 - w4^2) + Ixx*dPsi*dTheta*cos(Theta) + (Iyy*dPsi^2*sin(2*Phi)*cos(Theta)^2)/2 - (Izz*dPsi^2*sin(2*Phi)*cos(Theta)^2)/2 + Iyy*dPsi*dTheta*cos(2*Phi)*cos(Theta) - Izz*dPsi*dTheta*cos(2*Phi)*cos(Theta)))/(Iyy*Izz*cos(Phi)^4*cos(Theta) + Iyy*Izz*cos(Theta)*sin(Phi)^4 + 2*Iyy*Izz*cos(Phi)^2*cos(Theta)*sin(Phi)^2)
%                                                                                                                                                                             ((Iyy*cos(Phi)^2 + Izz*sin(Phi)^2)*(b*(w1^2 - w2^2 + w3^2 - w4^2) + dPhi*(Ixx*dTheta*cos(Theta) - Iyy*dTheta*cos(Phi)^2*cos(Theta) + Izz*dTheta*cos(Phi)^2*cos(Theta) + Iyy*dTheta*cos(Theta)*sin(Phi)^2 - Izz*dTheta*cos(Theta)*sin(Phi)^2 - 2*Iyy*dPsi*cos(Phi)*cos(Theta)^2*sin(Phi) + 2*Izz*dPsi*cos(Phi)*cos(Theta)^2*sin(Phi)) + Iyy*dTheta^2*cos(Phi)*sin(Phi)*sin(Theta) - Izz*dTheta^2*cos(Phi)*sin(Phi)*sin(Theta) - 2*Ixx*dPsi*dTheta*cos(Theta)*sin(Theta) + 2*Izz*dPsi*dTheta*cos(Phi)^2*cos(Theta)*sin(Theta) + 2*Iyy*dPsi*dTheta*cos(Theta)*sin(Phi)^2*sin(Theta)))/(Iyy*Izz*cos(Phi)^4*cos(Theta)^2 + Iyy*Izz*cos(Theta)^2*sin(Phi)^4 + 2*Iyy*Izz*cos(Phi)^2*cos(Theta)^2*sin(Phi)^2) + ((Iyy*cos(Phi)*sin(Phi) - Izz*cos(Phi)*sin(Phi))*(dPhi*(Ixx*dPsi*cos(Theta) - 2*Iyy*dTheta*cos(Phi)*sin(Phi) + 2*Izz*dTheta*cos(Phi)*sin(Phi) + Iyy*dPsi*cos(Phi)^2*cos(Theta) - Izz*dPsi*cos(Phi)^2*cos(Theta) - Iyy*dPsi*cos(Theta)*sin(Phi)^2 + Izz*dPsi*cos(Theta)*sin(Phi)^2) - ddTheta*(Iyy*cos(Phi)^2 + Izz*sin(Phi)^2) + Iyy*ddTheta*cos(Phi)^2 + Izz*ddTheta*sin(Phi)^2 + k*l*(w1^2 - w3^2) - Ixx*dPsi^2*cos(Theta)*sin(Theta) + Iyy*dPsi^2*cos(Theta)*sin(Phi)^2*sin(Theta) + Izz*dPsi^2*cos(Phi)^2*cos(Theta)*sin(Theta)))/(Iyy*Izz*cos(Phi)^4*cos(Theta) + Iyy*Izz*cos(Theta)*sin(Phi)^4 + 2*Iyy*Izz*cos(Phi)^2*cos(Theta)*sin(Phi)^2) + (sin(Theta)*(Iyy*cos(Phi)^2 + Izz*sin(Phi)^2)*((Izz*dTheta^2*sin(2*Phi))/2 - k*l*(w2^2 - w4^2) + Ixx*dPsi*dTheta*cos(Theta) + (Iyy*dPsi^2*sin(2*Phi)*cos(Theta)^2)/2 - (Izz*dPsi^2*sin(2*Phi)*cos(Theta)^2)/2 + Iyy*dPsi*dTheta*cos(2*Phi)*cos(Theta) - Izz*dPsi*dTheta*cos(2*Phi)*cos(Theta)))/(Iyy*Izz*cos(Phi)^4*cos(Theta)^2 + Iyy*Izz*cos(Theta)^2*sin(Phi)^4 + 2*Iyy*Izz*cos(Phi)^2*cos(Theta)^2*sin(Phi)^2)

% Se fuerza que todas las aceleraciones también las velocidades angulares (no lineales) sean zero

eq1=sym(sys1(1))
eq2=sym(sys1(2))
eq3=sym(sys1(3))

eq4=sym(sys2(1))
eq5=sym(sys2(2))
eq6=sym(sys2(3))

syms dPhi dTheta dPsi

%%% SI SE QUIEREN ENCONTRAR TODOS LOS PUNTOS DE EQUILIBRIO:

% eq1=sym('0=(k*(sin(Phi)*sin(Psi) + cos(Phi)*cos(Psi)*sin(Theta))*(w1^2 + w2^2 + w3^2 + w4^2))/m')
% eq2=sym('0=-(k*(cos(Psi)*sin(Phi) - cos(Phi)*sin(Psi)*sin(Theta))*(w1^2 + w2^2 + w3^2 + w4^2))/m')
% eq3=sym('0=-(g*m - k*cos(Phi)*cos(Theta)*(w1^2 + w2^2 + w3^2 + w4^2))/m')

% eq4=sym('0=((Iyy*Izz*cos(Phi)^4*cos(Theta)^2 + Ixx*Iyy*cos(Phi)^2*sin(Theta)^2 + Iyy*Izz*cos(Theta)^2*sin(Phi)^4 + Ixx*Izz*sin(Phi)^2*sin(Theta)^2 + 2*Iyy*Izz*cos(Phi)^2*cos(Theta)^2*sin(Phi)^2)*((Izz*dTheta^2*sin(2*Phi))/2 - k*l*(w2^2 - w4^2) + Ixx*dPsi*dTheta*cos(Theta) + (Iyy*dPsi^2*sin(2*Phi)*cos(Theta)^2)/2 - (Izz*dPsi^2*sin(2*Phi)*cos(Theta)^2)/2 + Iyy*dPsi*dTheta*cos(2*Phi)*cos(Theta) - Izz*dPsi*dTheta*cos(2*Phi)*cos(Theta)))/(Ixx*Iyy*Izz*cos(Phi)^4*cos(Theta)^2 + Ixx*Iyy*Izz*cos(Theta)^2*sin(Phi)^4 + 2*Ixx*Iyy*Izz*cos(Phi)^2*cos(Theta)^2*sin(Phi)^2) + (sin(Theta)*(Iyy*cos(Phi)*sin(Phi) - Izz*cos(Phi)*sin(Phi))*(dPhi*(Ixx*dPsi*cos(Theta) - 2*Iyy*dTheta*cos(Phi)*sin(Phi) + 2*Izz*dTheta*cos(Phi)*sin(Phi) + Iyy*dPsi*cos(Phi)^2*cos(Theta) - Izz*dPsi*cos(Phi)^2*cos(Theta) - Iyy*dPsi*cos(Theta)*sin(Phi)^2 + Izz*dPsi*cos(Theta)*sin(Phi)^2) + k*l*(w1^2 - w3^2) - Ixx*dPsi^2*cos(Theta)*sin(Theta) + Iyy*dPsi^2*cos(Theta)*sin(Phi)^2*sin(Theta) + Izz*dPsi^2*cos(Phi)^2*cos(Theta)*sin(Theta)))/(Iyy*Izz*cos(Phi)^4*cos(Theta) + Iyy*Izz*cos(Theta)*sin(Phi)^4 + 2*Iyy*Izz*cos(Phi)^2*cos(Theta)*sin(Phi)^2) + (sin(Theta)*(Iyy*cos(Phi)^2 + Izz*sin(Phi)^2)*(b*(w1^2 - w2^2 + w3^2 - w4^2) + dPhi*(Ixx*dTheta*cos(Theta) - Iyy*dTheta*cos(Phi)^2*cos(Theta) + Izz*dTheta*cos(Phi)^2*cos(Theta) + Iyy*dTheta*cos(Theta)*sin(Phi)^2 - Izz*dTheta*cos(Theta)*sin(Phi)^2 - 2*Iyy*dPsi*cos(Phi)*cos(Theta)^2*sin(Phi) + 2*Izz*dPsi*cos(Phi)*cos(Theta)^2*sin(Phi)) + Iyy*dTheta^2*cos(Phi)*sin(Phi)*sin(Theta) - Izz*dTheta^2*cos(Phi)*sin(Phi)*sin(Theta) - 2*Ixx*dPsi*dTheta*cos(Theta)*sin(Theta) + 2*Izz*dPsi*dTheta*cos(Phi)^2*cos(Theta)*sin(Theta) + 2*Iyy*dPsi*dTheta*cos(Theta)*sin(Phi)^2*sin(Theta)))/(Iyy*Izz*cos(Phi)^4*cos(Theta)^2 + Iyy*Izz*cos(Theta)^2*sin(Phi)^4 + 2*Iyy*Izz*cos(Phi)^2*cos(Theta)^2*sin(Phi)^2)')
% eq5=sym('0=- ((Izz*cos(Phi)^2 + Iyy*sin(Phi)^2)*(dPhi*(Ixx*dPsi*cos(Theta) - 2*Iyy*dTheta*cos(Phi)*sin(Phi) + 2*Izz*dTheta*cos(Phi)*sin(Phi) + Iyy*dPsi*cos(Phi)^2*cos(Theta) - Izz*dPsi*cos(Phi)^2*cos(Theta) - Iyy*dPsi*cos(Theta)*sin(Phi)^2 + Izz*dPsi*cos(Theta)*sin(Phi)^2) + k*l*(w1^2 - w3^2) - Ixx*dPsi^2*cos(Theta)*sin(Theta) + Iyy*dPsi^2*cos(Theta)*sin(Phi)^2*sin(Theta) + Izz*dPsi^2*cos(Phi)^2*cos(Theta)*sin(Theta)))/(Iyy*Izz*cos(Phi)^4 + Iyy*Izz*sin(Phi)^4 + 2*Iyy*Izz*cos(Phi)^2*sin(Phi)^2) - ((Iyy*cos(Phi)*sin(Phi) - Izz*cos(Phi)*sin(Phi))*(b*(w1^2 - w2^2 + w3^2 - w4^2) + dPhi*(Ixx*dTheta*cos(Theta) - Iyy*dTheta*cos(Phi)^2*cos(Theta) + Izz*dTheta*cos(Phi)^2*cos(Theta) + Iyy*dTheta*cos(Theta)*sin(Phi)^2 - Izz*dTheta*cos(Theta)*sin(Phi)^2 - 2*Iyy*dPsi*cos(Phi)*cos(Theta)^2*sin(Phi) + 2*Izz*dPsi*cos(Phi)*cos(Theta)^2*sin(Phi)) + Iyy*dTheta^2*cos(Phi)*sin(Phi)*sin(Theta) - Izz*dTheta^2*cos(Phi)*sin(Phi)*sin(Theta) - 2*Ixx*dPsi*dTheta*cos(Theta)*sin(Theta) + 2*Izz*dPsi*dTheta*cos(Phi)^2*cos(Theta)*sin(Theta) + 2*Iyy*dPsi*dTheta*cos(Theta)*sin(Phi)^2*sin(Theta)))/(Iyy*Izz*cos(Phi)^4*cos(Theta) + Iyy*Izz*cos(Theta)*sin(Phi)^4 + 2*Iyy*Izz*cos(Phi)^2*cos(Theta)*sin(Phi)^2) - (sin(Theta)*(Iyy*cos(Phi)*sin(Phi) - Izz*cos(Phi)*sin(Phi))*((Izz*dTheta^2*sin(2*Phi))/2 - k*l*(w2^2 - w4^2) + Ixx*dPsi*dTheta*cos(Theta) + (Iyy*dPsi^2*sin(2*Phi)*cos(Theta)^2)/2 - (Izz*dPsi^2*sin(2*Phi)*cos(Theta)^2)/2 + Iyy*dPsi*dTheta*cos(2*Phi)*cos(Theta) - Izz*dPsi*dTheta*cos(2*Phi)*cos(Theta)))/(Iyy*Izz*cos(Phi)^4*cos(Theta) + Iyy*Izz*cos(Theta)*sin(Phi)^4 + 2*Iyy*Izz*cos(Phi)^2*cos(Theta)*sin(Phi)^2)')
% eq6=sym('0=((Iyy*cos(Phi)^2 + Izz*sin(Phi)^2)*(b*(w1^2 - w2^2 + w3^2 - w4^2) + dPhi*(Ixx*dTheta*cos(Theta) - Iyy*dTheta*cos(Phi)^2*cos(Theta) + Izz*dTheta*cos(Phi)^2*cos(Theta) + Iyy*dTheta*cos(Theta)*sin(Phi)^2 - Izz*dTheta*cos(Theta)*sin(Phi)^2 - 2*Iyy*dPsi*cos(Phi)*cos(Theta)^2*sin(Phi) + 2*Izz*dPsi*cos(Phi)*cos(Theta)^2*sin(Phi)) + Iyy*dTheta^2*cos(Phi)*sin(Phi)*sin(Theta) - Izz*dTheta^2*cos(Phi)*sin(Phi)*sin(Theta) - 2*Ixx*dPsi*dTheta*cos(Theta)*sin(Theta) + 2*Izz*dPsi*dTheta*cos(Phi)^2*cos(Theta)*sin(Theta) + 2*Iyy*dPsi*dTheta*cos(Theta)*sin(Phi)^2*sin(Theta)))/(Iyy*Izz*cos(Phi)^4*cos(Theta)^2 + Iyy*Izz*cos(Theta)^2*sin(Phi)^4 + 2*Iyy*Izz*cos(Phi)^2*cos(Theta)^2*sin(Phi)^2) + ((Iyy*cos(Phi)*sin(Phi) - Izz*cos(Phi)*sin(Phi))*(dPhi*(Ixx*dPsi*cos(Theta) - 2*Iyy*dTheta*cos(Phi)*sin(Phi) + 2*Izz*dTheta*cos(Phi)*sin(Phi) + Iyy*dPsi*cos(Phi)^2*cos(Theta) - Izz*dPsi*cos(Phi)^2*cos(Theta) - Iyy*dPsi*cos(Theta)*sin(Phi)^2 + Izz*dPsi*cos(Theta)*sin(Phi)^2) + k*l*(w1^2 - w3^2) - Ixx*dPsi^2*cos(Theta)*sin(Theta) + Iyy*dPsi^2*cos(Theta)*sin(Phi)^2*sin(Theta) + Izz*dPsi^2*cos(Phi)^2*cos(Theta)*sin(Theta)))/(Iyy*Izz*cos(Phi)^4*cos(Theta) + Iyy*Izz*cos(Theta)*sin(Phi)^4 + 2*Iyy*Izz*cos(Phi)^2*cos(Theta)*sin(Phi)^2) + (sin(Theta)*(Iyy*cos(Phi)^2 + Izz*sin(Phi)^2)*((Izz*dTheta^2*sin(2*Phi))/2 - k*l*(w2^2 - w4^2) + Ixx*dPsi*dTheta*cos(Theta) + (Iyy*dPsi^2*sin(2*Phi)*cos(Theta)^2)/2 - (Izz*dPsi^2*sin(2*Phi)*cos(Theta)^2)/2 + Iyy*dPsi*dTheta*cos(2*Phi)*cos(Theta) - Izz*dPsi*dTheta*cos(2*Phi)*cos(Theta)))/(Iyy*Izz*cos(Phi)^4*cos(Theta)^2 + Iyy*Izz*cos(Theta)^2*sin(Phi)^4 + 2*Iyy*Izz*cos(Phi)^2*cos(Theta)^2*sin(Phi)^2)')

% seq4=sym(subs(eq4,{dPhi,dTheta,dPsi},{0,0,0}))
% seq5=sym(subs(eq5,{dPhi,dTheta,dPsi},{0,0,0}))
% seq6=sym(subs(eq6,{dPhi,dTheta,dPsi},{0,0,0}))

% solve(eq1,eq2,eq3,seq4,seq5,seq6,'x','y','z','Phi','Theta','Psi')

%%% COMO LO QUE SALE ES UN MONSTRUO, SE SUBSTITUYEN LOS sin(a) Y cos(b) POR 0 Y 1 PORQUE SE SUPONE ESTAR CERCA DEL PUNTO DE EQUILIBRIO

seq1=sym(subs(eq1,{dPhi,dTheta,dPsi,sin(Phi),sin(Theta),sin(Psi),cos(Phi),cos(Theta),cos(Psi)},{0,0,0,0,0,0,1,1,1}))
seq2=sym(subs(eq2,{dPhi,dTheta,dPsi,sin(Phi),sin(Theta),sin(Psi),cos(Phi),cos(Theta),cos(Psi)},{0,0,0,0,0,0,1,1,1}))
seq3=sym(subs(eq3,{dPhi,dTheta,dPsi,sin(Phi),sin(Theta),sin(Psi),cos(Phi),cos(Theta),cos(Psi)},{0,0,0,0,0,0,1,1,1}))

seq4=sym(subs(eq4,{dPhi,dTheta,dPsi,sin(Phi),sin(Theta),sin(Psi),cos(Phi),cos(Theta),cos(Psi)},{0,0,0,0,0,0,1,1,1}))
seq5=sym(subs(eq5,{dPhi,dTheta,dPsi,sin(Phi),sin(Theta),sin(Psi),cos(Phi),cos(Theta),cos(Psi)},{0,0,0,0,0,0,1,1,1}))
seq6=sym(subs(eq6,{dPhi,dTheta,dPsi,sin(Phi),sin(Theta),sin(Psi),cos(Phi),cos(Theta),cos(Psi)},{0,0,0,0,0,0,1,1,1}))

syms f1 f2 f3 f4

seq3=sym('0=(f1 + f2 + f3 + f4 - g*m)/m')
seq4=sym('0=-(l*(f2 - f4))/Ixx')
seq5=sym('0=-(l*(f1 - f3))/Iyy')
seq6=sym('0=(b*(f1 - f2 + f3 - f4))/Izz')

sol=solve(seq3,seq4,seq5,seq6,'f1','f2','f3','f4')
sol.f1
sol.f2
sol.f3
sol.f4

% COMO RESULTADO SE DEDUCE QUE EL ÚNICO PUNTO DE EQUILIBRIO ES EL QUE:
%       TIENE TODAS LAS ACELERACIONES Y VELOCIDADES, TANTO LINEALES COMO ANGULARES Y LAS POSICIONES ANGULARES. ES DECIR:
%           (x,y,z,dx,dy,dz,ddx,ddy,ddz,Phi,Theta,Psi,dPhi,dTheta,dPsi,ddPhi,ddTheta,ddPsi,)=(x,y,z, 0,0,0, 0,0,0, 0,0,Psi, 0,0,0, 0,0,0)
%       DONDE LA ENTRADA ES:
%           (f1,f2,f3,f4)=(mg/4,mg/4,mg/4,mg/4)


% BUSCANDO LINEALIZAR EL SISTEMA EN EL PUNTO DE EQUILIBRIO PARA TENER:
%       dX=A·X+B·U
%       Y=C·X

% fx=[dXi; 
%     sys1;
%     dEta;
%     sys2];

% states=[Xi;
%         dXi;
%         Eta;
%         dEta];

fx=[dx;
    eq1;
    dy;
    eq2;
    dz;
    eq3;
    dPhi;
    eq4;
    dTheta;
    eq5;
    dPsi;
    eq6]

states=[x;
        dx;
        y;
        dy;
        z;
        dz;
        Phi;
        dPhi;
        Theta;
        dTheta;
        Psi;
        dPsi]

forces=[f1;
        f2;
        f3;
        f4];    

    
% Substituyendo las variables de estado por lo que corresponde en el punto
% de equilibrio:
 A=jacobian(fx,states)
 Asub=sym(subs(A,{Phi,Theta,Psi,dPhi,dTheta,dPsi},{0,0,0,0,0,0}))

 B=jacobian(fx,forces)
 Bsub=sym(subs(B,{Phi,Theta,Psi,dPhi,dTheta,dPsi},{0,0,0,0,0,0}))
    

A=jacobian(fx,states)
Asub=sym(subs(A,{Phi,Theta,Psi,dPhi,dTheta,dPsi,f1,f2,f3,f4},{0,0,0,0,0,0,m*g/4,m*g/4,m*g/4,m*g/4}))

B=jacobian(fx,forces)
Bsub=sym(subs(B,{Phi,Theta,Psi,dPhi,dTheta,dPsi,f1,f2,f3,f4},{0,0,0,0,0,0,m*g/4,m*g/4,m*g/4,m*g/4}))

% C=[[0 0 0 0 0 0 1 0 0 0 0 0];
%    [0 0 0 0 0 0 0 1 0 0 0 0]]

% COMO LA POSICIÓN Y ORIENTACIÓN ESTÁN DESACOPLADOS EN LA MATRIZ "A", SE
% PUEDEN EXCLUIR DEL SISTEMA LOS ESTADOS (x,dx,y,dy,z,dz). POR LO TANTO QUEDA:

fx=[dPhi;
    eq4;
    dTheta;
    eq5;
    dPsi;
    eq6]

states=[Phi;
        dPhi;
        Theta;
        dTheta;
        Psi;
        dPsi]

disA=jacobian(fx,states);
Asub=sym(subs(disA,{Phi,Theta,Psi,dPhi,dTheta,dPsi},{0,0,0,0,0,0}))

disB=jacobian(fx,forces);
Bsub=sym(subs(disB,{Phi,Theta,Psi,dPhi,dTheta,dPsi},{0,0,0,0,0,0}))    
    
disA=jacobian(fx,states);
Asub=sym(subs(disA,{Phi,Theta,Psi,dPhi,dTheta,dPsi,f1,f2,f3,f4},{0,0,0,0,0,0,m*g/4,m*g/4,m*g/4,m*g/4}))

disB=jacobian(fx,forces);
Bsub=sym(subs(disB,{Phi,Theta,Psi,dPhi,dTheta,dPsi,f1,f2,f3,f4},{0,0,0,0,0,0,m*g/4,m*g/4,m*g/4,m*g/4}))

Ared=Asub(1:4,1:4)
Bred=Bsub(1:4,1:4)

Cred=[[1 0 0 0];[0 0 1 0]]
Dred=[[0 0 0 0];[0 0 0 0]]

% PARA VER QUE EL SISTEMA ES CONTROLABLE Y OBSERVABLE:

co=ctrb(double(Ared),double(Bred))
Controlability=rank(co)

ov=obsv(double(Ared),double(Cred))
Observability=rank(ov)

%            

Q=1*transpose(Cred)*Cred
% Q=eye(4)
R=100*eye(4)

[K,S,E]=lqrd(double(Ared),double(Bred),Q,R,0.02)
