#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/select.h>
#include <termios.h>
#include <softPwm.h>

#include "SigueLineas.h"
#include "motorra_funtzioak.h"

void SigueLineas() {

    int bukatu = 0;

    if (gpioInitialise() < 0)
    {
        fprintf(stderr, "Error al inicializar pigpio.\n");
        return;
    }

    while (bukatu == 0)
    {
       //ERABILITAKO SENSOREAK ZURIA DETEKTATZEKO EZARRI DIRA, IBILBIDE BELTZA ERDIAN EUKINDA.   O || O   ( O ) = ERABILITAKO SENSOREA  ( || ) = IBILBIDE BELTZA
       //SENSOREAK 1 EDO 0 DIREN IKUSI (BELTZA (1) EDO ZURIA (0) )

        int sensor_izq = gpioRead(SENSOR_IZQ_PIN);
        int sensor_der = gpioRead(SENSOR_DER_PIN);

        if (sensor_izq == 0 && sensor_der == 0) //SENSORE BIAK ZURIA DETEKTATZEAN, AURRERA EGINGO DAU
        {
            aurrera();
        }
        else if (sensor_izq == 1 && sensor_der == 0) //SENSORE BAT BELTZA DETEKTATZEAN, GIRATUKO DAU, KASU HONETAN EZKERRERANTZ

        {
            ezker_tanke(); //KOTXEA EZKERRERA GIRATZEKO
        }
        else if (sensor_izq == 0 && sensor_der == 1) //SENSORE BAT BELTZA DETEKTATZEAN, GIRATUKO DAU, KASU HONETAN ESKUINERANTZ

        {
            eskubi_tanke();//KOTXEA ESKUINERANTZ GIRATZEKO
        }
        else if (sensor_izq == 1 && sensor_der == 1) //SENSORE BIAK BELTZA DETEKTATZEAN, KOTXEA GELDITUKO DA
        {
            amaitu();  //KOTXEA GELDITZEKO
            bukatu = 1;
        }
    }

    return;
}

void PasarNodo() { //IKUSI NODOTIK PASATZEN DEN

    int sensor_izq = 1, sensor_der = 1;

    do
    {
        sensor_izq = gpioRead(SENSOR_IZQ_PIN);
        sensor_der = gpioRead(SENSOR_DER_PIN);

        aurrera();

    } while (sensor_izq == 1 && sensor_der == 1); //BI SENTSOREAK 1 BADIRA NODOTIK PASATU DA

}
