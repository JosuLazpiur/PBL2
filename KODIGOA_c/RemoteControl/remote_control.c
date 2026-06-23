#include "remote_control.h"

//DEFINE-AK
#define NB_ENABLE 1
#define NB_DISABLE 0

#define esc 28

#define SENSOR_IZQ_PIN 4
#define SENSOR_DER_PIN 8

/*
ERRUBERAK : _F = FRONT  _B = BACK
			R_ = RIGHT  L_ = LEFT */
#define FL_F 25
#define FL_B 24
#define FR_F 27
#define FR_B 17
#define BL_F 5
#define BL_B 6
#define BR_F 22
#define BR_B 23

int fd = 0;

int init_ble() {
	struct termios serial;
	char dev[64];
	char str[128];
	printf("Zein pts behar da? (/dev/pts/x)\n\t> "); //BLUETOOTH DIREKTORIOA GALDETU ( /dev/pts/x )
	fgets(str, 128, stdin);
	str[strlen(str) - 1] = '\0';
	strcpy(dev, str);

	printf("Opening %s\n", dev);

	fd = open(dev, O_RDWR | O_NOCTTY | O_NDELAY);

	if (fd == -1) {
		perror(dev);
		return -1;
	}

	if (tcgetattr(fd, &serial) < 0) {
		perror("Getting configuration");
		return -1;
	}

	//SERIAL CONFIGURATION SET UP
	serial.c_iflag = 0;
	serial.c_oflag = 0;
	serial.c_lflag = 0;
	serial.c_cflag = 0;

	serial.c_cc[VMIN] = 0;
	serial.c_cc[VTIME] = 0;

	serial.c_cflag = B115200 | CS8 | CREAD;

	tcsetattr(fd, TCSANOW, &serial); //CONFIGURAZIOA APLIKATU

	printf("%d", fd);

	return fd;
}





REMOTE_ORDER read_remote_order() { //MANDOAREN SEINALEAK IRAKURRI

	REMOTE_ORDER  order;
	char* str = "Hello";
	char buffer[10];
	order = R_STOP;
	int abiaduraL = 0;
	int abiaduraR = 0;
	int abiaduraL_B = 0;
	int abiaduraR_B = 0;
	int time = 30;

	if (gpioInitialise() < 0)

	{

		printf("Error al inicializar PiGPIO.\n");

		return 1;

	}


		//IRTEERAK DEFINITU
	gpioSetMode(FL_F, PI_OUTPUT);

	gpioSetMode(FL_B, PI_OUTPUT);

	gpioSetMode(FR_F, PI_OUTPUT);

	gpioSetMode(FR_B, PI_OUTPUT);

	gpioSetMode(BL_F, PI_OUTPUT);

	gpioSetMode(BL_B, PI_OUTPUT);

	gpioSetMode(BR_F, PI_OUTPUT);

	gpioSetMode(BR_B, PI_OUTPUT);


		//SEINALEEN FREKUENTZIA DEFINITU
	gpioSetPWMfrequency(FL_F, 100);

	gpioSetPWMfrequency(FL_B, 100);

	gpioSetPWMfrequency(FR_F, 100);

	gpioSetPWMfrequency(FR_B, 100);

	gpioSetPWMfrequency(BL_F, 100);

	gpioSetPWMfrequency(BL_B, 100);

	gpioSetPWMfrequency(BR_F, 100);

	gpioSetPWMfrequency(BR_B, 100);

	//ATTEMPT TO SEND AND RECEIVE
	printf("Bidaltzen: %s\n", str);

	int wcount = write(fd, str, strlen(str)); //SEINALEAK BIDALTZEKO
	if (wcount < 0) {
		perror("Write");
		return -1;
	}
	else {
		printf("Sent %d characters\n", wcount);
	}

	int rcount = 0;
	*buffer = 0;
	do { //SEINALEAK ONDO BIDALI DIRAN NOTIFIKATZEKO
		rcount = read(fd, buffer, sizeof(buffer));
		if (rcount < 0) {
			perror("Read");
			return -1;
		}
		else {
			//printf("Jasota %d bytes\n", rcount);
			if (rcount > 0) {
				printf("==============================REMOTE ORDER================================\n");
				printf("RECEIVED %c\n", *buffer);
			}
		}
	} while (*buffer == 0 || rcount == 0);
	//HASIERATZERAKOAN, FUNTZIONAMENDUAN WHILE-A KENDU BEHAR DA

	switch (*buffer) {
	case R_MODE:
		order = R_MODE;
		printf("MODE %c\n", *buffer);
		break;
	case R_FORWARD: //AURRERA
		order = R_FORWARD;
		printf("FORWARD %c\n", *buffer);

		//ABIADURAK
		abiaduraL = 150;
		abiaduraR = 150;
		abiaduraL_B = 0;
		abiaduraR_B = 0;

		gpioPWM(FL_F, abiaduraL);
		gpioPWM(FL_B, abiaduraL_B);
		gpioPWM(FR_F, abiaduraR);
		gpioPWM(FR_B, abiaduraR_B);
		gpioPWM(BL_F, abiaduraL);
		gpioPWM(BL_B, abiaduraL_B);
		gpioPWM(BR_F, abiaduraR);
		gpioPWM(BR_B, abiaduraR_B);

		gpioDelay(time); //PROGRAMA EZ APURTZEKO

		break;
	case R_BACKWARD: //ATZERA
		printf("BACKWARD %c\n", *buffer);
		order = R_BACKWARD;

		//ABIADURAK
		abiaduraL = 0;
		abiaduraR = 0;
		abiaduraL_B = 150;
		abiaduraR_B = 150;

		gpioPWM(FL_F, abiaduraL);
		gpioPWM(FL_B, abiaduraL_B);
		gpioPWM(FR_F, abiaduraR);
		gpioPWM(FR_B, abiaduraR_B);
		gpioPWM(BL_F, abiaduraL);
		gpioPWM(BL_B, abiaduraL_B);
		gpioPWM(BR_F, abiaduraR);
		gpioPWM(BR_B, abiaduraR_B);

		gpioDelay(time); //PROGRAMA EZ APURTZEKO

		break;
	case R_RIGHT: //ESKUINERANTZ
		printf("RIGHT %c\n", *buffer);
		order = R_RIGHT;

		//ABIADURAK
		abiaduraL = 200;
		abiaduraR = 0;
		abiaduraL_B = 0;
		abiaduraR_B = 200;
		
		gpioPWM(FL_F, abiaduraL);
		gpioPWM(FL_B, abiaduraL_B);
		gpioPWM(FR_F, abiaduraR);
		gpioPWM(FR_B, abiaduraR_B);
		gpioPWM(BL_F, abiaduraL);
		gpioPWM(BL_B, abiaduraL_B);
		gpioPWM(BR_F, abiaduraR);
		gpioPWM(BR_B, abiaduraR_B);

		gpioDelay(time); //PROGRAMA EZ APURTZEKO

		break;
	case R_LEFT: //EZKERRERANTZ
		printf("LEFT %c\n", *buffer);
		order = R_LEFT;

		//ABIADURAK
		abiaduraL = 0;
		abiaduraR = 200;
		abiaduraL_B = 200;
		abiaduraR_B = 0;

		gpioPWM(FL_F, abiaduraL);
		gpioPWM(FL_B, abiaduraL_B);
		gpioPWM(FR_F, abiaduraR);
		gpioPWM(FR_B, abiaduraR_B);
		gpioPWM(BL_F, abiaduraL);
		gpioPWM(BL_B, abiaduraL_B);
		gpioPWM(BR_F, abiaduraR);
		gpioPWM(BR_B, abiaduraR_B);

		gpioDelay(time); //PROGRAMA EZ APURTZEKO

		break;
	case R_STOP: //GELDITU
		printf("STOP %c\n", *buffer);
		order = R_STOP;

		//ABIADURAK
		abiaduraL = 0;
		abiaduraR = 0;
		abiaduraL_B = 0;
		abiaduraR_B = 0;

		gpioPWM(FL_F, abiaduraL);
		gpioPWM(FL_B, abiaduraL_B);
		gpioPWM(FR_F, abiaduraR);
		gpioPWM(FR_B, abiaduraR_B);
		gpioPWM(BL_F, abiaduraL);
		gpioPWM(BL_B, abiaduraL_B);
		gpioPWM(BR_F, abiaduraR);
		gpioPWM(BR_B, abiaduraR_B);

		gpioDelay(time); //PROGRAMA EZ APURTZEKO
		break;
	default:
		printf("NO ORDER  %c\n", *buffer);
		order = R_NONE;
	}

	buffer[rcount] = '\0';
	if (order != R_NONE) printf("Jasotakoa: ORDEN %s\n", buffer);


	return order;
}
