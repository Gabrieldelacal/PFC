#/usr/bin/python

import smbus # This allows to access through the I2C dev interface
import math
import time

# Power management registers
power_mgmt_1 = 0x6b 	# Direccion del registro
power_mgmt_2 = 0x6c	# Direccion del registro 
accel_config = 0x1c	
# giro_config = 0xXX

bus = smbus.SMBus(1) # or bus = smbus.SMBus(1) for Revision 2 boards
address = 0x68       # This is the address value read via the i2cdetect command

# Now wake the 6050 up as it starts in sleep mode
bus.write_byte_data(address, power_mgmt_1, 0) 	# Se usa el oscilador interno de 8MHz
bus.write_byte_data(address, accel_config, 3) 	# Configurado el full range del acelerometro
# bus.write_byte_data(address, gyro_config,X)  	# Configurado el full range del giroscopio 

Q_angle=0.001
Q_bias=0.003
R_measure=0.03

xangle=0 	# == H * x(k,k-1)
xbias=0		# = drift del gyroscopo (=velocidad)
gyrox=0
gyroxrate=0
kalXangle=0
Sx=0

yangle=0
ybias=0
gyroy=0
gyroyrate=0
kalYangle=0
Sy=0

Px=[[0,0],[0,0]]
Py=[[0,0],[0,0]]



def read_byte(adr):	# Lectura de un byte en el registro adr de la direccion address
    return bus.read_byte_data(address, adr) 	

def read_word(adr):	# Lectura de una palabra en el registro adr de la direccion address
    high = bus.read_byte_data(address, adr)
    low = bus.read_byte_data(address, adr+1) 	# Una palabra se compone de dos bytes
    val = (high << 8) + low			# Aqui se tienen 16 bits
    return val

def read_word_2c(adr):	# 0x8000 == 32768 (decimal) 
    val = read_word(adr)
    if (val >= 0x8000):
        return -((65535 - val) + 1)	# Complemento a dos con signo
    else:
        return val

def dist(a,b):		# Distancia entre a y b
    return math.sqrt((a*a)+(b*b))

def get_y_rotation(x,y,z): 	# Descomposicion de la gravedad y obtencion del angulo y == pitch
    radians = math.atan2(x, dist(y,z))
    return -math.degrees(radians)

def get_x_rotation(x,y,z):	# Descomposicion de la gravedad y obtencion del angulo x == roll
    radians = math.atan2(y, dist(x,z))
    return math.degrees(radians)

def get_angle(angle, newAngle, newRate, dt, bias, P):
    
    global Q_angle
    global Q_bias
    global R_measure

    rate=newRate-bias
    angle += dt * rate

    P[0][0] += dt * (dt*P[1][1] - P[0][1] - P[1][0] + Q_angle)
    P[0][1] -= dt * P[1][1]
    P[1][0] -= dt * P[1][1]
    P[1][1] += Q_bias * dt
    
    S = P[0][0] + R_measure

    k0 = P[0][0] / S
    k1 = P[1][0] / S

    y = newAngle - angle

    angle += k0 * y
    bias += k1 * y

    P[0][0] -= k0 * P[0][0]
    P[0][1] -= k0 * P[0][1]
    P[1][0] -= k1 * P[0][0]
    P[1][1] -= k1 * P[0][1]

    return angle

gx = read_word_2c(0x43)
gy = read_word_2c(0x45)
gz = read_word_2c(0x47)

ax = read_word_2c(0x3b)
ay = read_word_2c(0x3d)
az = read_word_2c(0x3f)

timer=time.time()

gxs = gx/131 	# Lecturas del gyro escaladas
gys = gy/131
gzs = gz/131

axs = ax / 16384.0	# Lecturas del acelerometro escaladas
ays = ay / 16384.0
azs = az / 16384.0

roll = get_x_rotation(axs, ays, azs)	# obtencion de x  con las aceleraciones
pitch = get_y_rotation(axs, ays, azs)	# obtencion de y con las aceleraciones

xangle = roll 	# El nuevo angulo x es el leido //anterior = 0
yangle = pitch	# El nuevo angulo y es el leido //anterior = 0
 
# print (timeit.timeit("obtein_accel()")

# if __name__ == '__main':
#     import timeit
#     print timeit.timeit("obtein_accel()", setup="from __main__ import test")

 
# kalXangle = get_angle(xangle, gxs, dt, xbias, Px)
# kalYangle = get_angle(newAngle, gys, dt, ybias, Py)

while 1:
   
    gx = read_word_2c(0x43)
    gy = read_word_2c(0x45)
    gz = read_word_2c(0x47)

    ax = read_word_2c(0x3b)
    ay = read_word_2c(0x3d)
    az = read_word_2c(0x3f)

    dt=time.time()-timer
    timer=time.time()
 
    gxs = gx/131 	# Lecturas del gyro escaladas
    gys = gy/131
    gzs = gz/131

    axs = ax / 16384.0	# Lecturas del acelerometro escaladas
    ays = ay / 16384.0
    azs = az / 16384.0

    roll = get_x_rotation(axs, ays, azs)	# obtencion de x con las aceleraciones
    pitch = get_y_rotation(axs, ays, azs)	# obtencion de y con las aceleraciones
    
    xangle = get_angle(xangle, roll, gxs, dt, xbias, Px)
    yangle = get_angle(yangle, pitch, gys, dt, ybias, Py)
    
    print xangle        
