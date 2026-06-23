#include "motorra_funtzioak_floyd.h"
#include "main.h"

void hasieratu_1()
{
  if (gpioInitialise() < 0)
  {
    fprintf(stderr, "Error al inicializar pigpio.\n"); //ERROREA NOTIFIKATU HASIERAPENEAN
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

  //GPIO HASIERATU 0-RA
  gpioPWM(FL_F, 0);
  gpioPWM(FL_B, 0);
  gpioPWM(FR_F, 0);
  gpioPWM(FR_B, 0);
  gpioPWM(BL_F, 0);
  gpioPWM(BL_B, 0);
  gpioPWM(BR_F, 0);
  gpioPWM(BR_B, 0);
}

void aurrera_1() //KOTXEA AURRERA; ABIADURA = 150
{
  gpioPWM(FL_F, 150);
  gpioPWM(FL_B, 0);
  gpioPWM(FR_F, 150);
  gpioPWM(FR_B, 0);
  gpioPWM(BL_F, 150);
  gpioPWM(BL_B, 0);
  gpioPWM(BR_F, 150);
  gpioPWM(BR_B, 0);
}
void atzera_1() //KOTXEA ATZERA; ABIADURA = 150
{
  gpioPWM(FL_F, 0);
  gpioPWM(FL_B, 150);
  gpioPWM(FR_F, 0);
  gpioPWM(FR_B, 150);
  gpioPWM(BL_F, 0);
  gpioPWM(BL_B, 150);
  gpioPWM(BR_F, 0);
  gpioPWM(BR_B, 150);
}
void eskuin_tanke_1() //KOTXEA ESKUINERANTZ; ABIADURA = 200
{
  gpioPWM(FL_F, 200);
  gpioPWM(FL_B, 0);
  gpioPWM(FR_F, 0);
  gpioPWM(FR_B, 200);
  gpioPWM(BL_F, 200);
  gpioPWM(BL_B, 0);
  gpioPWM(BR_F, 0);
  gpioPWM(BR_B, 200);
}
void ezker_tanke_1() //KOTXEA EZKERRERANTZ; ABIADURA = 200
{
  gpioPWM(FL_F, 0);
  gpioPWM(FL_B, 200);
  gpioPWM(FR_F, 200);
  gpioPWM(FR_B, 0);
  gpioPWM(BL_F, 0);
  gpioPWM(BL_B, 200);
  gpioPWM(BR_F, 200);
  gpioPWM(BR_B, 0);
}

void amaitu_1() //KOTXEA GELDITU
{
  gpioPWM(FL_F, 0);
  gpioPWM(FL_B, 0);
  gpioPWM(FR_F, 0);
  gpioPWM(FR_B, 0);
  gpioPWM(BL_F, 0);
  gpioPWM(BL_B, 0);
  gpioPWM(BR_F, 0);
  gpioPWM(BR_B, 0);
}

