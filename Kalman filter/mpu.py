#/usr/bin/python

import smbus # This allows to access through the I2C dev interface
import math
import time

# Power management registers
power_mgmt_1 = 0x6b 	# Direccion del registro
power_mgmt_2 = 0x6c	# Direccion del registro 
accel_config = 0x1c	

Q_angle=0.001
Q_bias=0.003
R_measure=0.03

xangle=0 	# == H * x(k,k-1)
yangle=0

xbias=0		# = drift del gyroscopo (=velocidad)
ybias=0		# = drift del gyroscopo (=velocidad)

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

def get_y_rotation(x,y,z): 	# Descomposicion de la gravedad y obtencion del angulo y
    radians = math.atan2(x, dist(y,z))
    return -math.degrees(radians)

def get_x_rotation(x,y,z):	# Descomposicion de la gravedad y obtencion del angulo x
    radians = math.atan2(y, dist(x,z))
    return math.degrees(radians)

def get_angle(newAngle, newRate, dt):

    rate=newRate-bias
    angle += dt * rate

    P[0][0] += dt * (dt*P[1][1] - P[0][1] - P[1][0] + Q_angle)
    P[0][1] -= dt * P[1][1]
    P[1][0] -= dt * P[1][1]
    P[1][1] += Q_bias * dt
    
    S = P[0][0] + R_measure

    K[0] = P[0][0] / S
    K[1] = P[1][0] / S

    y = newAngle - angle

    angle += k[0] * y
    bias += k[1] * y

    P[0][0] -= k[0] * P[0][0]
    P[0][1] -= k[0] * P[0][1]
    P[1][0] -= k[1] * P[0][0]
    P[1][1] -= k[1] * P[0][1]

    return angle

bus = smbus.SMBus(1) # or bus = smbus.SMBus(1) for Revision 2 boards
address = 0x68       # This is the address value read via the i2cdetect command

# Now wake the 6050 up as it starts in sleep mode
bus.write_byte_data(address, power_mgmt_1, 0) 	# Se usa el oscilador interno de 8MHz
bus.write_byte_data(address, accel_config, 3) 	# Configurado el full range del acelerometro

def obtein_accel():	
    accel_xout = read_word_2c(0x3b)
    accel_yout = read_word_2c(0x3d)
    accel_zout = read_word_2c(0x3f)
	 
    accel_xout_scaled = accel_xout / 16384.0
    accel_yout_scaled = accel_yout / 16384.0
    accel_zout_scaled = accel_zout / 16384.0	

    a=get_x_rotation(accel_xout_scaled, accel_yout_scaled, accel_zout_scaled)
    b=get_y_rotation(accel_xout_scaled, accel_yout_scaled, accel_zout_scaled)

print "gyro data"
print "---------"

gyro_xout = read_word_2c(0x43)
gyro_yout = read_word_2c(0x45)
gyro_zout = read_word_2c(0x47)

print "gyro_xout: ", gyro_xout, " scaled: ", (gyro_xout / 131)
print "gyro_yout: ", gyro_yout, " scaled: ", (gyro_yout / 131)
print "gyro_zout: ", gyro_zout, " scaled: ", (gyro_zout / 131)

print
print "accelerometer data"
print "------------------"

accel_xout = read_word_2c(0x3b)
accel_yout = read_word_2c(0x3d)
accel_zout = read_word_2c(0x3f)

accel_xout_scaled = accel_xout / 16384.0
accel_yout_scaled = accel_yout / 16384.0
accel_zout_scaled = accel_zout / 16384.0

print "accel_xout: ", accel_xout, " scaled: ", accel_xout_scaled
print "accel_yout: ", accel_yout, " scaled: ", accel_yout_scaled
print "accel_zout: ", accel_zout, " scaled: ", accel_zout_scaled

print "x rotation: " , get_x_rotation(accel_xout_scaled, accel_yout_scaled, accel_zout_scaled)
print "y rotation: " , get_y_rotation(accel_xout_scaled, accel_yout_scaled, accel_zout_scaled)


# print (timeit.timeit("obtein_accel()")

# if __name__ == '__main':
#     import timeit
#     print timeit.timeit("obtein_accel()", setup="from __main__ import test")

i=1

while i<=100:
	
    start=time.time()	

    accel_xout = read_word_2c(0x3b)
    accel_yout = read_word_2c(0x3d)
    accel_zout = read_word_2c(0x3f)
 
    accel_xout_scaled = accel_xout / 16384.0
    accel_yout_scaled = accel_yout / 16384.0
    accel_zout_scaled = accel_zout / 16384.0
    
    i=i+1
	
    print "time",time.time()-start, "x" , get_x_rotation(accel_xout_scaled, accel_yout_scaled, accel_zout_scaled), "y" , get_y_rotation(accel_xout_scaled, accel_yout_scaled, accel_zout_scaled)
