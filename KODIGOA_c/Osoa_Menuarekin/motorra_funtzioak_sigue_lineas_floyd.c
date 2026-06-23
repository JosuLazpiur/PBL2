#include "motorra_funtzioak_sigue_lineas_floyd.h"
#include "main.h"

void hasieratu_2()
{
  if (gpioInitialise() < 0)
  {
    fprintf(stderr, "Error al inicializar pigpio.\n"); //ERROREA HASIERATZEAN
  }
  //GPIO IRTEERAK DEFINITU
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

void aurrera_2()//KOTXEA AURRERA
{
  gpioPWM(FL_F, 100);
  gpioPWM(FL_B, 0);
  gpioPWM(FR_F, 100);
  gpioPWM(FR_B, 0);
  gpioPWM(BL_F, 100);
  gpioPWM(BL_B, 0);
  gpioPWM(BR_F, 100);
  gpioPWM(BR_B, 0);
}
void atzera_2() //KOTXEA ATZERA
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
void eskuin_tanke_2() //ESKUINERANTZ GIRATU
{
  gpioPWM(FL_F, 250);
  gpioPWM(FL_B, 0);
  gpioPWM(FR_F, 0);
  gpioPWM(FR_B, 250);
  gpioPWM(BL_F, 250);
  gpioPWM(BL_B, 0);
  gpioPWM(BR_F, 0);
  gpioPWM(BR_B, 250);
}
void ezker_tanke_2() //EZKERRERANTZ GIRATU
{
  gpioPWM(FL_F, 0);
  gpioPWM(FL_B, 250);
  gpioPWM(FR_F, 250);
  gpioPWM(FR_B, 0);
  gpioPWM(BL_F, 0);
  gpioPWM(BL_B, 250);
  gpioPWM(BR_F, 250);
  gpioPWM(BR_B, 0);
}

void amaitu_2() //KOTXEA GELDITU
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

