#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <windows.h>
#include "SerialClass.h"

#define F 9
#define MAX_BUFFER 200

void Inicializacion(Serial* Arduino);
FILE* Configuracion_Fichero(void);
void Receive_Data(Serial* Arduino, FILE*);
int Receive_from_hw(Serial* Arduino, char* BufferEntrada);
void Process_Data(int, FILE*);
void Cierre_Fichero(FILE*);

int main() {
	FILE* pf;

	Serial* Arduino;
	char puerto[] = "COM3"; //Puerto serie al que está conectado Arduino

	Arduino = new Serial((char*)puerto);  // Establece la conexión con Arduino

	Inicializacion(Arduino);
	pf = Configuracion_Fichero();

	while (Arduino->IsConnected()) {
		Receive_Data(Arduino, pf);
	}

	Cierre_Fichero(pf);

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

FILE* Configuracion_Fichero() {
	FILE* pf;
	int opc;
	char fecha[F];

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
			return pf;
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
			return pf;
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
			return pf;
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

void Receive_Data(Serial* Arduino, FILE* pf) {
	char BufferEntrada[MAX_BUFFER];
	int numero_recibido;

	if (Arduino->IsConnected()) {
		numero_recibido = Receive_from_hw(Arduino, BufferEntrada);;
		Process_Data(numero_recibido, pf);
	}
	return;
}

int Receive_from_hw(Serial* Arduino, char* BufferEntrada) {
	int bytesRecibidos, bytesTotales = 0;
	int intentos_lectura = 0;
	char cadena[MAX_BUFFER];

	BufferEntrada[0] = '\0';
	cadena[0] = '\0';
	bytesRecibidos = Arduino->ReadData(cadena, sizeof(char) * (MAX_BUFFER - 1));
	if (bytesRecibidos != -1) {
		cadena[bytesRecibidos] = '\0';
		strcat_s(BufferEntrada, MAX_BUFFER, cadena);
		bytesTotales += bytesRecibidos;
	}

	return bytesTotales;
}

void Process_Data(int numero_recibido, FILE* pf) {

	if ((numero_recibido > 210) && (numero_recibido < 230)) {
		printf("\n Se ha movido hacia arriba la muñeca");
		fprintf(pf, "\n Se ha movido hacia arriba la muñeca");
	}
	else if ((numero_recibido > 160) && (numero_recibido < 190)) {
		printf("\n Se ha movido hacia abajo la muñeca");
		fprintf(pf, "\n Se ha movido hacia abajo la muñeca");
	}
	else if ((numero_recibido > 180) && (numero_recibido < 200)) {
		printf("\n Se han abierto las pinzas");
		fprintf(pf, "\n Se han abierto las pinzas");
	}
	else if ((numero_recibido > 150) && (numero_recibido < 175)) {
		printf("\n Se han cerrado las pinzas");
		fprintf(pf, "\n Se han cerrado las pinzas");
	}
	else if ((numero_recibido > 240) && (numero_recibido < 255)) {
		printf("\n Se ha movido hacia la derecha la base");
		fprintf(pf, "\n Se ha movido hacia la derecha la base");
	}
	else if ((numero_recibido > 205) && (numero_recibido < 235)) {
		printf("\n Se ha movido hacia la izquierda la base");
		fprintf(pf, "\n Se ha movido hacia la izquierda la base");
	}
	else if (numero_recibido > 35) {
		printf("\n Se ha movido hacia arriba el codo");
		printf("\n Se ha movido hacia arriba el hombro");
		fprintf(pf, "\n Se ha movido hacia arriba el codo");
		fprintf(pf, "\n Se ha movido hacia arriba el hombro");
	}
	else if (numero_recibido < -35) {
		printf("\n Se ha movido hacia abajo el codo");
		printf("\n Se ha movido hacia abajo el hombro");
		fprintf(pf, "\n Se ha movido hacia abajo el codo");
		fprintf(pf, "\n Se ha movido hacia abajo el hombro");
	}


	return;
}

void Cierre_Fichero(FILE* pf) {
	if (fclose(pf) == NULL)
		printf("\n Archivo cerrado correctamente");
	else
		printf("\n Error en el cierre del archivo");

	return;
}