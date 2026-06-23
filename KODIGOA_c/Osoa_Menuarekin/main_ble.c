#include <stdio.h>

#include "main.h"

#include "remote_controller.h"




int main_remoto(int argc, char* argv[])
{
	int status=0;
		
	REMOTE_ORDER r_order=1;
	if (argc == 1) {
		printf("Usage: %s [device]\n\n", argv[0]);
		return -1;
	}

	printf("Opening %s\n", argv[1]);
	status = ble_hasieratu();
	if (status <= 0 ) printf("[ERROR]Opening dev=%s\n", argv[1]);



	while(r_order != 0){
		r_order = read_remote_order(); //esto hace todo , de momento recibir de bluettoth y cambiar el estado
	}
}

