#ifndef REMOTE_CONTROLLER_H_
#define REMOTE_CONTROLLER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <pigpio.h>


typedef enum Remote_order{R_MODE='c', R_FORWARD='w', R_BACKWARD='s', R_RIGHT='d', R_LEFT='a' , R_STOP='f' , R_NONE} REMOTE_ORDER;


int init_ble();
REMOTE_ORDER read_remote_order();


int test_ble();

#endif 
