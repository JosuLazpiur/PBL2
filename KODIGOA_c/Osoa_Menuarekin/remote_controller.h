#ifndef REMOTE_CONTROLLER_H_
#define REMOTE_CONTROLLER_H_




typedef enum Remote_order{R_MODE='c', R_FORWARD='w', R_BACKWARD='s', R_RIGHT='d', R_LEFT='a' , R_STOP='f' , R_NONE} REMOTE_ORDER;


int ble_hasieratu();
REMOTE_ORDER read_remote_order();


#endif /* REMOTE_CONTROLLER_H_ */
