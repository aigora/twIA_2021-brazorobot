#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <windows.h>
#include "SerialClass.h"

#define F 9
#define MAX_BUFFER 200

void Inicializacion(Serial* Arduino);
void Configuracion_Fichero(void);
void Receive_Data(Serial* Arduino);

int main() {

	Serial* Arduino;
	char puerto[] = "COM3"; //Puerto serie al que está conectado Arduino
	char BufferEntrada[MAX_BUFFER];
	
	Arduino = new Serial((char*)puerto);  // Establece la conexión con Arduino

	Inicializacion(Arduino);
	Configuracion_Fichero();

	while (Arduino->IsConnected()) {
		Receive_Data(Arduino);
	}
	
    /*if (fclose(pf) == NULL)
        printf("\n Archivo cerrado correctamente");
    else
        printf("\n Error en el cierre del archivo");
		*/

}

void Inicializacion(Serial* Arduino) {
	char espacio;

	do {

		printf("\nPor favor, coloquese el guante");
		printf("\nAsegurese de que el resto de sistemas estan encendidos y operativos");
		printf("\nSi es asi, aparecera un cartel informativo");
		if (Arduino->IsConnected()) {
			printf("Arduino esta conectado\n");
		}
		printf("\nHabiendo hecho lo anterior, presione la tecla espaciadora e intro ");
		scanf_s("%c", &espacio, 1);
		if (espacio != ' ') {
			printf("\nLa tecla pulsada no es el espacio, pruebe de nuevo");
		}

	} while (espacio != ' ');

	return;
}

void Configuracion_Fichero(void) {
	int opc;
	char fecha[F];
	FILE* pf;

	printf("\n\n\nLos movimientos realizados por el brazo robot quedaran guardados en un fichero.txt.");
	printf("\nSeleccione el nombre del fichero de entre los propuestos.");
	printf("\n1:Mov_Brazo\n2:BrazoRobot\n3:Historial_movimientos");
	printf("\n\n");
	scanf_s("%d", &opc);
	getchar();

	errno_t err;

	switch (opc) {
	case 1:
		err = fopen_s(&pf, "Mov_Brazo", "a+");
		if (err == 0) {
			printf("\n\nEl archivo esta abierto\n");
			printf("\nTeclee la fecha para que conste en el fichero (dd/mm/aa): ");
			gets_s(fecha);
			fprintf(pf, "%s \n", fecha);
			return;
		}
		else {
			printf("\n\nEl archivo NO esta abierto\n");
		}

		break;
	case 2:
		err = fopen_s(&pf, "BrazoRobot", "a+");
		if (err == 0) {
			printf("\n\nEl archivo esta abierto\n");
			printf("\nTeclee la fecha para que conste en el fichero (dd/mm/aa): ");
			gets_s(fecha);
			fprintf(pf, "%s \n", fecha);
			return;
		}
		else {
			printf("\n\nEl archivo NO esta abierto\n");
		}

		break;
	case 3:
		err = fopen_s(&pf, "Historial_movimientos", "a+");
		if (err == 0) {
			printf("\n\nEl archivo esta abierto\n");
			printf("\nTeclee la fecha para que conste en el fichero (dd/mm/aa): ");
			gets_s(fecha);
			fprintf(pf, "%s \n", fecha);
			return;
		}
		else {
			printf("\n\nEl archivo NO esta abierto\n");
		}

		break;
	default:
		printf("\nLa opcion seleccionada no es correcta.");
		break;
	}

}

void Receive_Data(Serial* Arduino) {

}
