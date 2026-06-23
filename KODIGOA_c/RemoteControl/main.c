#include <stdio.h>
#include "remote_control.h"

int main(int argc, char* argv[]) {

	if (gpioInitialise() < 0)
	{
		printf("Error al inicializar PiGPIO.\n"); //ERROREA NOTIFIKATU GPIO HASIERATZERAKOAN

		return 1;

	}

	int status = 0;
	REMOTE_ORDER r_order = 0;
	printf("%d", argc);
	if (argc == 1) {
		printf("Usage: %s [device]\n\n", argv[0]);
		return -1;
	}

	printf("Opening %s\n", argv[1]);
	status = init_ble();
	if (status <= 0) printf("[ERROR]Opening dev=%s\n", argv[1]);



	while (1) {
		r_order = read_remote_order(); //HONEEK GUZTIOA BETETZEN DITU, ESTADOA EGUNERATU
	}
}

