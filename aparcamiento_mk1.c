//desarrollador Javier Redondo
//programa para asignar, desasignar o evaluar dos plazas de garaje y calcular el coste del estacionamiento pero no tiene un display de la hora.
#include <stdio.h>
#include <time.h>
void main() {

	int plaza1 = 0, plaza2 = 0, i, j, k;
	char opcion1, matricula1[8], matricula2[8], matricula_temp[8], opcion2;
	int inicio1, inicio2, final1, final2;
	while (1) {
		printf("Pulse:\n"
			"R - Reservar plaza\n"
			"A - Abandonar plaza\n"
			"E - Estado del aparcamiento\n");
		scanf_s("%c", &opcion1);
		getchar();
		system("cls");
		switch (opcion1) {
		case'r':
		case 'R': 
			if (plaza1 == 0 || plaza2 == 0) {
				if (plaza1 == 0) {
					printf("Se le ha asignado la plaza 1\n");
					plaza1 = 1;
					inicio1 = time(NULL);
					printf("Introduzca su matricula.\n");
					scanf_s("%s", matricula1, 8);
					getchar();
					system("PAUSE");
					system("cls");
				}
				else {
					printf("Se le ha asignado la plaza 2\n");
					plaza2 = 1;
					inicio2 = time(NULL);
					printf("Introduzca su matricula.\n");
					scanf_s("%s", matricula2, 8);
					getchar();
					system("PAUSE");
					system("cls");
				}
			}
			else {
				printf("Ambas plazas estan ocupadas, no puede estacionar.\n");
				system("PAUSE");
				system("cls");
			}
			break;
		case 'a':
		case 'A':
			if (plaza1 == 1 || plaza2 == 1) {
				printf("Introduzca su matricula");
				scanf_s("%s", matricula_temp, 8);
				j = 0; k = 0;
				for (i = 0; i < 8; i++) {
					if (matricula_temp[i] != matricula1[i]) {
						k = 1;
						break;
					}
					else if (i == 7 && plaza1==1) {
						printf("Ha abandonado la plaza 1\n");
						plaza1 = 0;
						final1 = time(NULL);
						printf("Ha de pagar %.2f euros ", (final1 - inicio1)*0.00033);
					}
				}
				for (i = 0; i < 8; i++) {
					if (matricula_temp[i] != matricula2[i]) {
						j = 1;
						break;
					}
					else if (i == 7 && plaza1 == 1) {
						printf("Ha abandonado la plaza 2\n");
						plaza2 = 0;
						final2 = time(NULL);
						printf("Ha de pagar %.2f euros ", (final2 - inicio2)*0.00033);
					}
				}
				if (j + k == 2) {
					printf("no se ha encontrado ningun coche con esa matricula");
				}
				system("pause");
				system("cls");
			}
			else {
				printf("No hay plazas ocupadas.\n");
				system("pause");
				system("cls");
			}
			break;
		case 'E':
		case 'e':
			if (plaza1 == 0) {
				printf("Plaza 1 - Libre \n");
			}
			else {
				printf("Plaza 1 - Ocupada - Matricula %s \n", matricula1);
				final1 = time(NULL);
				printf("Ya ha de pagar %.2f euros y subiendo ", (final1 - inicio1)*0.00033);
			}
			if (plaza2 == 0) {
				printf("Plaza 2 - Libre \n");
			}
			else {
				printf("Plaza 2 - Ocupada - Matricula %s \n", matricula2);
				final2 = time(NULL);
				printf("Ya ha de pagar %.2f euros y subiendo ", (final2 - inicio2)*0.00033);
			}
				system("PAUSE");
				system("cls");
			
			break;
		default:
			printf("La opcion seleccionada no es correcta\n");
			system("pause");
			system("cls");
		}
	}
}