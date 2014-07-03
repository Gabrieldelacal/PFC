#include <stdio.h> 			// printf
#include <sys/time.h> 			// timeval
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <wiringPi.h> 		
#include<fcntl.h>			// para poder usar 0_RDWR
#include<math.h>			// atan2(x,y)
#include<wiringPiI2C.h>
#include<stdint.h>

/*############################################
### CONFIGURACION CONEXION PINES Rx-->RPi: ###
##########     & RPi-->ESC's     #############
##############################################

Orden conectados:

	CH5	P1-13
	RUD	P1-11
	THR	P5-6
	ELE	P1-15
	AIL	P1-7

##############################################

	f4-25 (P1-22)
	-----
	f3-24 (P1-18)
	f2-23 (P1-16)   f1-22  (P1-15)	
	-----	        CH5-2  (P1-13)
	ELE-1 (P1-12)   RUD-0  (P1-11)	 THR-20(P5-6)
		        I2C-GND (P1-9)
	 	        AIL-7   (P1-7)
		        I2C-SCL (P1-5)
		        I2C-SDA (P1-3)
		        I2C-3V3 (P1-1)		
#############################################*/ 

#define mgmt_1 0x6b		// direccion registro del oscilador
#define mgmt_2 0x6c		
#define accel_config 0x1c 	// direccion registro config acc.
#define gyro_config 0x1b	// direccion  registro config gyro.
#define PI 3,14159265

//definicion de los pines a usar 

/*
//#define PIN4 2          // pin P1-13 c5 
#define PIN0 0          // pin P1-11 Rudder 
#define PIN1 1          // pin P1-12 Aileron 
//#define PIN2 4          // pin P1-16 throttle 
#define PIN3 3          // pin P1-15 elevator 
#define PIN20 20	// pin P2-6 throttle 
*/

#define PIN1 1		// pin P1-12 		ELE
#define PIN2 2		// pin P1-13		THR
#define PIN0 0		// pin P1-11		RUD
#define PIN7 7		// pin P1-7		AIL	
#define PIN20 20	// pin P5-6		CH5


static volatile int c5;         // state of c5 (up or down) 
int  diff_c5;         // time on up (diff time) 

static volatile int throttle;   // state of throttle (up or down) 
//double diff_throttle[6]={0.0,0.0,0.0,0.0,0.0,0.0};   	// time on up (diff time) through a COMPLEMENTARY FILTER
int diff_throttle[11]={0,0,0,0,0,0,0,0,0,0,0}; 

static volatile int elevator;   // state of elevator (up or down) 
int diff_elevator;    // time on up (diff time) 

static volatile int aileron;    // state of aileron (up or down) 
int diff_aileron;     // time on up (diff time) 

static volatile int rudder;     // state of aileron (up or down) 
int diff_rudder;      // time on up (diff time) 

struct timeval last_change,kal_last;
struct timeval now; 

double dt;

double Q_angle=0.001;
double Q_2=0.003;
double R_measure=0.03;

double xangle, yangle;
// double xbias;
double roll,pitch;
double xvel, yvel;
double Px[2][2],Py[2][2];

double read_word_2c(adr,reg){

        uint8_t high=wiringPiI2CReadReg8(adr,reg);
        uint8_t low=wiringPiI2CReadReg8(adr,reg);
        uint16_t val=(high<<8)+low;     // lectura de dos palabras
        if(val>=0x8000){                        // complemento a dos si es necesario
                return(double)(-((65535-val)+1));
        }else{
                return(double)(val);
        }
}

double kalman(double angle, double newangle, double *vel, double acc, double dt, double P[2][2]){

        double S,k0,k1,y;
        angle+=dt*((*vel)+dt*acc/2);

        (*vel)+=dt*acc;
        
//	printf("%g\t",dt*((*vel)+dt*acc/2));

        P[0][0] += dt * (dt*P[1][1] + P[0][1] + P[1][0] + Q_angle);
        P[0][1] += dt * P[1][1];
        P[1][0] += dt * P[1][1];
        P[1][1] += Q_2*dt;

        S=P[0][0]+R_measure;

        k0=P[0][0]/S;
        k1=P[1][0]/S;

	y=newangle-angle;

        angle+=k0*y;
        (*vel)+=k1*y;

        P[0][0] -= k0 * P[0][0];
        P[0][1] -= k0 * P[0][1];
        P[1][0] -= k1 * P[0][0];
        P[1][1] -= k1 * P[0][1];

        return angle;
}

int pwm2deg(double a){
	double N,K;
	K=80.0;
	N=1500.0-K/2.0;
	return(((a-N)/K)*2);
}

void handle_throttle(void) { 
 
        gettimeofday(&now, NULL); 

/*	diff_throttle[0]=diff_throttle[1];
	diff_throttle[1]=diff_throttle[2];
	diff_throttle[2]=diff_throttle[3];
	diff_throttle[3]=diff_throttle[4];
	diff_throttle[4]=now.tv_usec-last_change.tv_usec;
	diff_throttle[5]=((diff_throttle[1]+diff_throttle[2]+diff_throttle[3]+diff_throttle[4]+diff_throttle[0])/5.0)/10-104; */

	diff_throttle[0]=diff_throttle[1];
	diff_throttle[1]=diff_throttle[2];
	diff_throttle[2]=diff_throttle[3];
	diff_throttle[3]=diff_throttle[4];
	diff_throttle[4]=diff_throttle[5];
	diff_throttle[5]=diff_throttle[6];
	diff_throttle[6]=diff_throttle[7];
	diff_throttle[7]=diff_throttle[8];
	diff_throttle[8]=diff_throttle[9];
	diff_throttle[9]=(int)((now.tv_usec-last_change.tv_usec)/10.0);


//	diff_throttle[4]=(int)((now.tv_usec-last_change.tv_usec)/10.0);
	diff_throttle[10]=(diff_throttle[0]+diff_throttle[1]+diff_throttle[2]+diff_throttle[3]+diff_throttle[4]+diff_throttle[5]+diff_throttle[6]+diff_throttle[7]+diff_throttle[8]+diff_throttle[9])/100-10; 

        if (!throttle) { 
//              printf("THR %d   ",(int)diff_throttle[5]);
	//	printf("THR %d  \n ",diff_throttle[5]);
        } 
        throttle = !throttle; 
        last_change = now; 
} 

void handle_elevator(void){ 

        gettimeofday(&now, NULL); 
        diff_elevator=pwm2deg(now.tv_usec-last_change.tv_usec); 
        if(elevator){ 
  //              printf("ELE %d   ",diff_elevator); 
        } 
        elevator=!elevator; 
        last_change=now; 
} 

void handle_aileron(void){ 
        
        gettimeofday(&now, NULL); 
        diff_aileron=pwm2deg(now.tv_usec-last_change.tv_usec); 
        if(aileron){ 
    //            printf("AIL %d   ",diff_aileron); 
        } 
        aileron=!aileron; 
        last_change=now; 
} 

void handle_rudder(void){ 
        
        gettimeofday(&now, NULL); 
        diff_rudder=pwm2deg(now.tv_usec-last_change.tv_usec); 
        if(rudder){ 
 //               printf("RUD %d    angX %d    angY %d \n",diff_rudder,(int)xangle,(int)yangle); 	
        } 
        rudder=!rudder; 
        last_change=now; 
} 


void handle_c5(void){ 
 
        gettimeofday(&now, NULL); 
        diff_c5=pwm2deg(now.tv_usec-last_change.tv_usec); 
        if(c5){ 
//                printf("CH5 %lu   \%d \n",diff_c5,(int)xangle); 
//		printf("CH5 %d   ",diff_c5);
        } 
        c5=!c5; 
        last_change=now; 
} 

void writefile(int i, double f){
	FILE *file;		// file de salida a los ESC
	// f(PWM)=119.0*PWM-613.0 --> PWM=(f(PWM)+613.0)/119.0

	/*	f1 --> P1-15 --> 22
		f2 --> P1-16 --> 23
		f3 --> P1-18 --> 24
		f4 --> P1-22 --> 25	*/

	file=fopen("/dev/pi-blaster","wb");
	fprintf(file,"%d=%g\n",i+21,(f+613.0)/11900);
	fclose(file);
}
int main(void) { 
	
	double pwm=0.0;

        int fd;         	// file direction
        double ax,ay,az;
        double gx,gy,gz;

	double f1=0.0;
	double f2=0.0;
	double f3=0.0;
	double f4=0.0;		

	double K[4][4]={{0.0,0.0,-0.0224,-0.0322},{-0.0224,-0.0328,0.0,0.0},{0.0,0.0,0.0224,0.0322},{0.0224,0.0328,0.0,0.0}};
	
        xangle=0.0;
	yangle=0.0;


	diff_c5=0.0;
//	diff_throttle=0.0;
	diff_rudder=0.0;
	diff_aileron=0.0;
	diff_elevator=0.0;        

        Px[0][0]=0.0;
        Px[0][1]=0.0;
        Px[1][0]=0.0;
        Px[1][1]=0.0;
	
        Py[0][0]=0.0;
        Py[0][1]=0.0;
        Py[1][0]=0.0;
        Py[1][1]=0.0;

	diff_throttle[0]=0.0;
	diff_throttle[1]=0.0;
	diff_throttle[2]=0.0;
	diff_throttle[3]=0.0;
	diff_throttle[4]=0.0;
	diff_throttle[5]=0.0;		

        wiringPiSetup(); 
        fd=wiringPiI2CSetup(0x68);

        wiringPiI2CWriteReg8(fd,mgmt_1,0);
        wiringPiI2CWriteReg8(fd,gyro_config,3);
        wiringPiI2CWriteReg8(fd,accel_config,3);

        /*pinMode(PIN0, INPUT); 
        pinMode(PIN1, INPUT); 
        pinMode(PIN4, INPUT); 
	pinMode(PIN20,INPUT);
        pinMode(PIN3, INPUT); 
        pinMode(PIN2, INPUT);*/

	pinMode(PIN1,INPUT); 
	pinMode(PIN2,INPUT); 
	pinMode(PIN0,INPUT); 
	pinMode(PIN7,INPUT); 
	pinMode(PIN20,INPUT); 
	
	    writefile(1,5.0);
        writefile(2,5.0);
        writefile(3,5.0);
        writefile(4,5.0);
        sleep(5);

	
/*
//      wiringPiISR(PIN4, INT_EDGE_BOTH, &handle_throttle); 
//      wiringPiISR(PIN0, INT_EDGE_BOTH, &handle_rudder); 
//      wiringPiISR(PIN2, INT_EDGE_BOTH, &handle_c5);   
        wiringPiISR(PIN1, INT_EDGE_BOTH, &handle_aileron); 
//      wiringPiISR(PIN3, INT_EDGE_BOTH, &handle_elevator); 

//      wiringPiISR(PIN4, INT_EDGE_FALLING, &handle_throttle); 
	wiringPiISR(PIN20,INT_EDGE_FALLING, &handle_throttle);
        wiringPiISR(PIN0, INT_EDGE_FALLING, &handle_rudder); 
        wiringPiISR(PIN2, INT_EDGE_FALLING, &handle_c5);        
//        wiringPiISR(PIN1, INT_EDGE_FALLING, &handle_aileron); 
        wiringPiISR(PIN3, INT_EDGE_FALLING, &handle_elevator); 
*/
// 	###################################################
//      wiringPiISR(PIN4, INT_EDGE_BOTH, &handle_throttle); 
//      wiringPiISR(PIN0, INT_EDGE_BOTH, &handle_rudder); 
//      wiringPiISR(PIN2, INT_EDGE_BOTH, &handle_c5);   
        wiringPiISR(PIN7, INT_EDGE_BOTH, &handle_aileron); 
//      wiringPiISR(PIN3, INT_EDGE_BOTH, &handle_elevator); 

//      wiringPiISR(PIN4, INT_EDGE_FALLING, &handle_throttle); 
	wiringPiISR(PIN20,INT_EDGE_FALLING, &handle_throttle);
        wiringPiISR(PIN0, INT_EDGE_FALLING, &handle_rudder); 
        wiringPiISR(PIN2, INT_EDGE_FALLING, &handle_c5);        
//      wiringPiISR(PIN1, INT_EDGE_FALLING, &handle_aileron); 
        wiringPiISR(PIN1, INT_EDGE_FALLING, &handle_elevator); 

        gettimeofday(&last_change, NULL); 
        kal_last=last_change;

        ax=(read_word_2c(fd,0x3b))/16384.0;
        ay=(read_word_2c(fd,0x3d))/16384.0;
        az=(read_word_2c(fd,0x3f))/16384.0;

        roll=-atan2(ay,az)*180/PI;
        xangle=roll;
	pitch=-atan2(ax,az)*180/PI;
	yangle=pitch;
	
        while(1){

                ax=(read_word_2c(fd,0x3b))/16384.0;
                ay=(read_word_2c(fd,0x3d))/16384.0;
                az=(read_word_2c(fd,0x3f))/16384.0;

                gx=(read_word_2c(fd,0x43))/131.0;
                gy=(read_word_2c(fd,0x45))/131.0;
                gz=(read_word_2c(fd,0x47))/131.0;

                gettimeofday(&now,NULL);
                dt=(double)(now.tv_usec-kal_last.tv_usec)*0.000001;
                kal_last=now;       

                roll=atan2(ay,az)*180/PI;
		pitch=-atan2(ax,az)*180/PI;

                xangle=kalman(xangle,roll,&xvel,ay,dt,Px);
	  	yangle=kalman(yangle,pitch,&yvel,ax,dt,Py);
		
		/*
			K=       0         0   -0.0224   -0.0322
			   -0.0224   -0.0328         0         0
			         0         0    0.0224    0.0322
		            0.0224    0.0328         0         0
		*/
/*					
		f1=(K[0][2]*(yangle+(double)diff_elevator)+K[0][3]*(gy))*102.0+(double)diff_throttle[5]*50.0;	
  	        f2=(K[1][0]*(xangle+(double)diff_rudder)+K[1][1]*(gx))*102.0+(double)diff_throttle[5]*50.0;				 
     		f3=(K[2][2]*(yangle+(double)diff_elevator)+K[2][3]*(gy))*102.0+(double)diff_throttle[5]*50.0;
 	        f4=(K[3][0]*(xangle+(double)diff_rudder)+K[3][1]*(gx))*102.0+(double)diff_throttle[5]*50.0;		*/			 
	
		
		f1=(K[0][2]*(-yangle+(double)diff_elevator)-K[0][3]*(gy))*102.0+(double)diff_throttle[10]*40.0;	
  	        f2=(K[1][0]*(-xangle+(double)diff_rudder)-K[1][1]*(gx))*102.0+(double)diff_throttle[10]*40.0;				 
     		f3=(K[2][2]*(-yangle+(double)diff_elevator)-K[2][3]*(gy))*102.0+(double)diff_throttle[10]*40.0;
 	        f4=(K[3][0]*(-xangle+(double)diff_rudder)-K[3][1]*(gx))*102.0+(double)diff_throttle[10]*40.0;					 
	
		// f(PWM)=119.0*PWM-613.0 --> PWM=(f(PWM)+613.0)/119.0
		printf("diff_throttle: %d \t pwm1: %g \t pwm2: %g \t pwm3: %g \t pwm4: %g \n",diff_throttle[10]*40,(f1+613.0)/119.0,(f2+613.0)/119.0,(f3+613.0)/119.0,(f4+613.0)/119.0);		
	
//		printf("xangle: %f \t gx: %f \t yangle: %f \t gy: %f \t f1: %f \t f2: %f \t f3: %f \t f4: %f \n",xangle,gx,yangle,gy,f1,f2,f3,f4); 

     		writefile(1,f1);
		writefile(2,f2);
		writefile(3,f3);
		writefile(4,f4);    

		

	}
        return(0); 
} 

