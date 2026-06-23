#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pigpio.h>
#include "main.h"

//FUNTZIOAK
void adelante();
void atras();
void detener();
void giro_tanque_der();
void giro_tanque_izq();

int main_sigue_lineas() //SIGUE-LINEAS PROGRAMA NAGUSIA
{
  if (gpioInitialise() < 0)
  {
    fprintf(stderr, "Error al inicializar pigpio.\n");//ERROREA NOTIFIKATU GPIO HASIERAPENEAN
    return 1;
  }
  //IRTEERAK ETA SARRERAK DEFINITU
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

  //GPIO HASIERATU 0 ABIADURAN
  gpioPWM(FL_F, 0);
  gpioPWM(FL_B, 0);
  gpioPWM(FR_F, 0);
  gpioPWM(FR_B, 0);
  gpioPWM(BL_F, 0);
  gpioPWM(BL_B, 0);
  gpioPWM(BR_F, 0);
  gpioPWM(BR_B, 0);

  while (1)
  {       
    // ERABILITAKO SENSOREAK ZURIA DETEKTATZEKO EZARRI DIRA, IBILBIDE BELTZA ERDIAN EUKINDA.O || O(O) = ERABILITAKO SENSOREA(|| ) = IBILBIDE BELTZA
    int sensor_izq = gpioRead(SENSOR_IZQ_PIN);
    int sensor_der = gpioRead(SENSOR_DER_PIN);

    //SENSOREAK 1 EDO 0 DIREN IKUSI (BELTZA (1) EDO ZURIA (0) )
    if (sensor_izq == 0 && sensor_der == 0) //SENSORE BIAK ZURIA DETEKTATZEAN, AURRERA EGINGO DAU
    {
      adelante(); //KOTXEA AURRERA
    }
    else if (sensor_izq == 1 && sensor_der == 0) //SENSORE BAT BELTZA DETEKTATZEAN, GIRATUKO DAU, KASU HONETAN EZKERRERANTZ
    {
      giro_tanque_izq(); //KOTXEA EZKERRERA GIRATU
    }
    else if (sensor_izq == 0 && sensor_der == 1) //SENSORE BAT BELTZA DETEKTATZEAN, GIRATUKO DAU, KASU HONETAN ESKUINERANTZ
    {
      giro_tanque_der(); //KOTXEA ESKUINERANTZ GIRATU
    }
    else if (sensor_izq == 1 && sensor_der == 1) //SENSORE BIAK BELTZA DETEKTATZEAN, KOTXEA GELDITUKO DA
    {
      detener(); //KOTXEA GELDITU
      return 0;
    }
  }

  gpioTerminate(); //GPIO BUKATU

  return 0;
}

void adelante()
{ //ERRUBERA GUZTIAK AURRERA, ABIADURA = 200 EZARRI DOGU
  gpioPWM(FL_F, 150);
  gpioPWM(FL_B, 0);
  gpioPWM(FR_F, 150);
  gpioPWM(FR_B, 0);
  gpioPWM(BL_F, 150);
  gpioPWM(BL_B, 0);
  gpioPWM(BR_F, 150);
  gpioPWM(BR_B, 0);
}

void atras()
{ //ERRUBERA GUZTIAK ATZERA, ABIADURA = 150 EZARRI DOGU
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
{ //ERRUBERA GUZTIAK GELDITU, ABIADURA 0-RA EZARRIZ
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
{ //EZKERRERA GIRATZEKO, EZKERREKO ERRUBERAK ATZERA ETA ESKUINEKOAK AURRERA; ABIADURA = 200
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
{ //ESKUINERA GIRATZEKO, EZKERREKO ERRUBERAK AURRERA ETA ESKUINEKOAK ATZERA; ABIADURA = 200
  gpioPWM(FL_F, 200);
  gpioPWM(FL_B, 0);
  gpioPWM(FR_F, 0);
  gpioPWM(FR_B, 200);
  gpioPWM(BL_F, 200);
  gpioPWM(BL_B, 0);
  gpioPWM(BR_F, 0);
  gpioPWM(BR_B, 200);
}

