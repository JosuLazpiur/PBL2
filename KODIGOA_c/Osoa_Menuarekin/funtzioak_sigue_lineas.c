
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/select.h>
#include <termios.h>
#include "main.h"

#include "sigue_lineas_floyd.h"
#include "motorra_funtzioak_sigue_lineas_floyd.h"

void Sigue_Lineas()
{

  int bukatu = 0;

  if (gpioInitialise() < 0)
  {
      fprintf(stderr, "[ERROR] Ez da pigpio inizializatu.\n"); //ERROREA NOTIFIKATU HASIERAPENEAN
    return;
  }

  while (bukatu == 0)
  {
    //ERABILITAKO SENSOREAK ZURIA DETEKTATZEKO EZARRI DIRA, IBILBIDE BELTZA ERDIAN EUKINDA.   O || O   ( O ) = ERABILITAKO SENSOREA  ( || ) = IBILBIDE BELTZA
    int sensor_izq = gpioRead(SENSOR_IZQ_PIN);
    int sensor_der = gpioRead(SENSOR_DER_PIN);

    //SENSOREAK 1 EDO 0 DIREN IKUSI (BELTZA (1) EDO ZURIA (0) )
    if (sensor_izq == 0 && sensor_der == 0)//SENSORE BIAK ZURIA DETEKTATZEAN, AURRERA EGINGO DAU
    {
      aurrera_2(); 
    }
    else if (sensor_izq == 1 && sensor_der == 0) //SENSORE BAT BELTZA DETEKTATZEAN, GIRATUKO DAU, KASU HONETAN EZKERRERANTZ
    {
      ezker_tanke_2(); //KOTXEA EZKERRERA GIRATZEKO
    }
    else if (sensor_izq == 0 && sensor_der == 1) //SENSORE BAT BELTZA DETEKTATZEAN, GIRATUKO DAU, KASU HONETAN ESKUINERANTZ
    {
      eskuin_tanke_2(); //KOTXEA ESKUINERANTZ GIRATZEKO
    }
    else if (sensor_izq == 1 && sensor_der == 1) //SENSORE BIAK BELTZA DETEKTATZEAN, KOTXEA GELDITUKO DA
    {
      bukatu = 1;
    }
  }

  return;
}

void Pasatu_Nodoa() //FLOYD-WARSHALL PROGRAMARAKO
{

  int sensor_izq = 1, sensor_der = 1;

  do
  {
    sensor_izq = gpioRead(SENSOR_IZQ_PIN);
    sensor_der = gpioRead(SENSOR_DER_PIN);

    aurrera_2();

  } while (sensor_izq == 1 && sensor_der == 1);

}
