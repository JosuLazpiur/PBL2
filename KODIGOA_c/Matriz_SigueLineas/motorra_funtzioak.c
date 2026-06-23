#include "motorra_funtzioak.h"

void hasieratu()
{
    if (gpioInitialise() < 0)
    {
        fprintf(stderr, "Error al inicializar pigpio.\n"); //ERROR
    }
    //GPIO-KO IRTEERAK
    gpioSetMode(FL_F, PI_OUTPUT);
    gpioSetMode(FL_B, PI_OUTPUT);
    gpioSetMode(FR_F, PI_OUTPUT);
    gpioSetMode(FR_B, PI_OUTPUT);
    gpioSetMode(BL_F, PI_OUTPUT);
    gpioSetMode(BL_B, PI_OUTPUT);
    gpioSetMode(BR_F, PI_OUTPUT);
    gpioSetMode(BR_B, PI_OUTPUT);

    // GPIO-AK HASIERATU 0 ABIADURAN
    gpioPWM(FL_F, 0);
    gpioPWM(FL_B, 0);
    gpioPWM(FR_F, 0);
    gpioPWM(FR_B, 0);
    gpioPWM(BL_F, 0);
    gpioPWM(BL_B, 0);
    gpioPWM(BR_F, 0);
    gpioPWM(BR_B, 0);
}

void aurrera()  //ERRUBERA GUZTIAK AURRERA, ABIADURA = 200 EZARRI DOGU
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
void atzera() //ERRUBERA GUZTIAK ATZERA, ABIADURA = 150 EZARRI DOGU
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
void eskubi_tanke() //ESKUINERA GIRATZEKO, EZKERREKO ERRUBERAK AURRERA ETA ESKUINEKOAK ATZERA
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
void ezker_tanke() //EZKERRERA GIRATZEKO, EZKERREKO ERRUBERAK ATZERA ETA ESKUINEKOAK AURRERA
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

void amaitu()//ERRUBERA GUZTIAK GELDITU, ABIADURA 0-RA EZARRIZ
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
