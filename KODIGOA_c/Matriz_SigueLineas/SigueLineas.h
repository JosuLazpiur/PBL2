#ifndef SIGUELINEAS_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/select.h>
#include <termios.h>
#include <softPwm.h>
#include <pigpio.h>

//DEFINE-AK
#define SENSOR_IZQ_PIN 4
#define SENSOR_DER_PIN 8

#define FL_F 25
#define FL_B 24
#define FR_F 27
#define FR_B 17
#define BL_F 5
#define BL_B 6
#define BR_F 22
#define BR_B 23

//FUNTZIOAK
void SigueLineas();
void PasarNodo();

#endif


