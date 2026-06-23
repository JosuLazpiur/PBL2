#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pigpio.h>

//DEFINE-AK
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

//FUNTZIOAK
void adelante();
void atras();
void detener();
void giro_tanque_der();
void giro_tanque_izq();

//SIGUE-LINEAS PROGRAMA NAGUSIA
int main()
{
    if (gpioInitialise() < 0)
    {
        fprintf(stderr, "Error al inicializar pigpio.\n"); //ERROREA NOTIFIKATU HASIERAPENEAN
        return 1;
    }

    //GPIO-AK SARRERA EDO IRTEERAK DIRAN DEFINITU
            //IRTEERAK
    gpioSetMode(FL_F, PI_OUTPUT);
    gpioSetMode(FL_B, PI_OUTPUT);
    gpioSetMode(FR_F, PI_OUTPUT);
    gpioSetMode(FR_B, PI_OUTPUT);
    gpioSetMode(BL_F, PI_OUTPUT);
    gpioSetMode(BL_B, PI_OUTPUT);
    gpioSetMode(BR_F, PI_OUTPUT);
    gpioSetMode(BR_B, PI_OUTPUT);

            //SARRERAK
    gpioSetMode(SENSOR_IZQ_PIN, PI_INPUT);
    gpioSetMode(SENSOR_DER_PIN, PI_INPUT);

    // GPIO-AK HASIERATU 0 ABIADURAN
    gpioPWM(FL_F, 0);
    gpioPWM(FL_B, 0);
    gpioPWM(FR_F, 0);
    gpioPWM(FR_B, 0);
    gpioPWM(BL_F, 0);
    gpioPWM(BL_B, 0);
    gpioPWM(BR_F, 0);
    gpioPWM(BR_B, 0);

    int amaitu = 0; 
    while (amaitu == 0)
    {
        //ERABILITAKO SENSOREAK ZURIA DETEKTATZEKO EZARRI DIRA, IBILBIDE BELTZA ERDIAN EUKINDA.   O || O   ( O ) = ERABILITAKO SENSOREA  ( || ) = IBILBIDE BELTZA
        //SENSOREAK 1 EDO 0 DIREN IKUSI (BELTZA (1) EDO ZURIA (0) )
        int sensor_izq = gpioRead(SENSOR_IZQ_PIN);
        int sensor_der = gpioRead(SENSOR_DER_PIN);

        if (sensor_izq == 0 && sensor_der == 0) //SENSORE BIAK ZURIA DETEKTATZEAN, AURRERA EGINGO DAU
        {
            adelante(); //KOTXEA AURRERA EGITEKO
        }
        else if (sensor_izq == 1 && sensor_der == 0) //SENSORE BAT BELTZA DETEKTATZEAN, GIRATUKO DAU, KASU HONETAN EZKERRERANTZ
        {
            giro_tanque_izq(); //KOTXEA EZKERRERA GIRATZEKO
        }
        else if (sensor_izq == 0 && sensor_der == 1) //SENSORE BAT BELTZA DETEKTATZEAN, GIRATUKO DAU, KASU HONETAN ESKUINERANTZ
        {
            giro_tanque_der(); //KOTXEA ESKUINERANTZ GIRATZEKO
        }
        else if (sensor_izq == 1 && sensor_der == 1) //SENSORE BIAK BELTZA DETEKTATZEAN, KOTXEA GELDITUKO DA
        {
            detener(); //KOTXEA GELDITZEKO
            amaitu = 1;
        }
    }

    gpioTerminate(); //GPIO BUKATZEKO

    return 0;
}

void adelante()
{
    //ERRUBERA GUZTIAK AURRERA, ABIADURA = 200 EZARRI DOGU
    gpioPWM(FL_F, 200);
    gpioPWM(FL_B, 0);
    gpioPWM(FR_F, 200);
    gpioPWM(FR_B, 0);
    gpioPWM(BL_F, 200);
    gpioPWM(BL_B, 0);
    gpioPWM(BR_F, 200);
    gpioPWM(BR_B, 0);
}

void atras()
{
    //ERRUBERA GUZTIAK ATZERA, ABIADURA = 150 EZARRI DOGU
    gpioPWM(FL_F, 0);
    gpioPWM(FL_B, 150);
    gpioPWM(FR_F, 0);
    gpioPWM(FR_B, 150);
    gpioPWM(BL_F, 0);
    gpioPWM(BL_B, 150);
    gpioPWM(BR_F, 0);
    gpioPWM(BR_B, 150);
}

void detener()
{
    //ERRUBERA GUZTIAK GELDITU, ABIADURA 0-RA EZARRIZ
    gpioPWM(FL_F, 0);
    gpioPWM(FL_B, 0);
    gpioPWM(FR_F, 0);
    gpioPWM(FR_B, 0);
    gpioPWM(BL_F, 0);
    gpioPWM(BL_B, 0);
    gpioPWM(BR_F, 0);
    gpioPWM(BR_B, 0);
}

void giro_tanque_izq()
{
    //EZKERRERA GIRATZEKO, EZKERREKO ERRUBERAK ATZERA ETA ESKUINEKOAK AURRERA
    gpioPWM(FL_F, 0);
    gpioPWM(FL_B, 200);
    gpioPWM(FR_F, 200);
    gpioPWM(FR_B, 0);
    gpioPWM(BL_F, 0);
    gpioPWM(BL_B, 200);
    gpioPWM(BR_F, 200);
    gpioPWM(BR_B, 0);
}

void giro_tanque_der()
{
    //ESKUINERA GIRATZEKO, EZKERREKO ERRUBERAK AURRERA ETA ESKUINEKOAK ATZERA
    gpioPWM(FL_F, 200);
    gpioPWM(FL_B, 0);
    gpioPWM(FR_F, 0);
    gpioPWM(FR_B, 200);
    gpioPWM(BL_F, 200);
    gpioPWM(BL_B, 0);
    gpioPWM(BR_F, 0);
    gpioPWM(BR_B, 200);
}
