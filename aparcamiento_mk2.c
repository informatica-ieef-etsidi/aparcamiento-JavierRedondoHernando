#include <stdio.h>

void main() {
	char opcion, moto_o_coche, matricula1c[8], matricula2c[8], matricula1m[8], matricula2m[8], matricula_temp[8];
	int i = 1, j, a;
	int plaza1c = 0, plaza2c = 0, plaza1m = 0, plaza2m = 0;
	int inicio1c, inicio2c, final1c, final2c, inicio1m, inicio2m, final1m, final2m;
	while (i == 1) {
		printf("Seleccione una de estas opciones:\nR - Reservar plaza\nA - Abandonar plaza\nE - Estado del aparcamiento\nB - Buscar veiculo por matricula\nS - Salir del programa\n");
		scanf_s("%c", &opcion);
		if (opcion == '\n') {
			scanf_s("%c", &opcion);
		}
		system("cls");
		switch (opcion) {
		case 'R':
		case 'r':
			printf("Quiere una plaza de moto o de coche?\nM - Moto\nC - Coche\n");
			getchar();
			scanf_s("%c", &moto_o_coche);
			system("cls");
			if (moto_o_coche == 'M' || moto_o_coche == 'm') {
				if (plaza1m == 0 || plaza2m == 0) {
					if (plaza1m == 0) {
						do {
							printf("Se le ha asignado la plaza 1\n");
							plaza1m = 1;
							inicio1m = time(NULL);
							printf("Introduzca su matricula.\n");
							scanf_s("%s", matricula1m, 8);
							getchar();
							a = 0;
							for (j = 0; j < 7; j++) {
								if (((matricula1m[j]<'0' || matricula1m[j]>'9') && j <= 3) || ((matricula1m[j]<'A' || matricula1m[j]>'Z') && j > 3)) {
									a++;
								}
							}
							if (a != 0) {
								printf("Matricula erronea, la operacion se reiniciara.\n");
								system("pause");
								system("cls");
							}
						} while (a != 0);
						system("PAUSE");
						system("cls");
					}
					else {
						do {
							printf("Se le ha asignado la plaza 2\n");
							plaza2m = 1;
							inicio2m = time(NULL);
							printf("Introduzca su matricula.\n");
							scanf_s("%s", matricula2m, 8);
							getchar();
							a = 0;
							for (j = 0; j < 7; j++) {
								if (((matricula2m[j]<'0' || matricula2m[j]>'9') && j <= 3) || ((matricula2m[j]<'A' || matricula2m[j]>'Z') && j > 3)) {
									a++;
								}
							}
							if (a != 0) {
								printf("Matricula erronea, la operacion se reiniciara.\n");
							}
						} while (a != 0);
						system("PAUSE");
						system("cls");
					}
				}
				else {
					printf("Ambas plazas estan ocupadas, no puede estacionar.\n");
					system("PAUSE");
					system("cls");
				}
			}
			else if (moto_o_coche == 'C' || moto_o_coche == 'c') {
				if (plaza1c == 0 || plaza2c == 0) {
					if (plaza1c == 0) {
						do {
							printf("Se le ha asignado la plaza 1\n");
							plaza1c = 1;
							inicio1c = time(NULL);
							printf("Introduzca su matricula.\n");
							scanf_s("%s", matricula1c, 8);
							getchar();
							a = 0;
							for (j = 0; j < 7; j++) {
								if (((matricula1c[j]<'0' || matricula1c[j]>'9') && j <= 3) || ((matricula1c[j]<'A' || matricula1c[j]>'Z') && j > 3)) {
									a++;
								}
							}
							if (a != 0) {
								printf("Matricula erronea, la operacion se reiniciara.\n");
							}
						} while (a != 0);
						system("PAUSE");
						system("cls");
					}
					else {
						do {
							printf("Se le ha asignado la plaza 2\n");
							plaza2c = 1;
							inicio2c = time(NULL);
							printf("Introduzca su matricula.\n");
							scanf_s("%s", matricula2c, 8);
							getchar();
							a = 0;
							for (j = 0; j < 7; j++) {
								if (((matricula1c[j]<'0' || matricula1c[j]>'9') && j <= 3) || ((matricula1c[j]<'A' || matricula1c[j]>'Z') && j > 3)) {
									a++;
								}
							}
							if (a != 0) {
								printf("Matricula erronea, la operacion se reiniciara.\n");
							}
						} while (a != 0);
						system("PAUSE");
						system("cls");
					}
				}
				else {
					printf("Ambas plazas estan ocupadas, no puede estacionar.\n");
					system("PAUSE");
					system("cls");
				}
			}
			else {
				printf("Opcion no valida\n");
				system("pause");
				system("cls");
			}
			break;
		case 'A':
		case 'a':
			if (plaza1m == 1 || plaza2m == 1 || plaza1c == 1 || plaza2c == 1) {
				do {
					printf("Introduzca su matricula:  ");
					scanf_s("%s", matricula_temp, 8);
					a = 0;
					for (j = 0; j < 7; j++) {
						if (((matricula_temp[j]<'0' || matricula_temp[j]>'9') && j <= 3) || ((matricula_temp[j]<'A' || matricula_temp[j]>'Z') && j > 3)) {
							a++;
						}
					}
					if (a != 0) {
						printf("Matricula erronea, la operacion se reiniciara.\n");
						system("pause");
						system("cls");
					}
				} while (a != 0);
				a = 0;
				for (j = 0; j < 8; j++) {
					if (matricula_temp[j] != matricula1m[j]) {
						break;
					}
					else if (j == 7 && plaza1m == 1) {
						printf("Ha abandonado la plaza 1 de moto\n");
						plaza1m = 0;
						final1m = time(NULL);
						printf("Ha de pagar %.2f euros\n ", (final1m - inicio1m)*0.0033);
						a = 1;
					}
				}
				for (j = 0; j < 8; j++) {
					if (matricula_temp[j] != matricula2m[j]) {
						break;
					}
					else if (j == 7 && plaza2m == 1) {
						printf("Ha abandonado la plaza 2 de moto\n");
						plaza2m = 0;
						final2m = time(NULL);
						printf("Ha de pagar %.2f euros\n ", (final2m - inicio2m)*0.00033);
						a = 1;
					}
				}
				for (j = 0; j < 8; j++) {
					if (matricula_temp[j] != matricula1c[j]) {
						break;
					}
					else if (j == 7 && plaza1c == 1) {
						printf("Ha abandonado la plaza 1 de coche\n");
						plaza1c = 0;
						final1c = time(NULL);
						printf("Ha de pagar %.2f euros\n ", (final1c - inicio1c)*0.0033);
						a = 1;
					}
				}
				for (j = 0; j < 8; j++) {
					if (matricula_temp[j] != matricula2c[j]) {
						break;
					}
					else if (j == 7 && plaza2c == 1) {
						printf("Ha abandonado la plaza 2 de coche\n");
						plaza2c = 0;
						final2c = time(NULL);
						printf("Ha de pagar %.2f euros\n ", (final2c - inicio2c)*0.00033);
						a = 1;
					}
				}
				if (a != 1) {
					printf("No se ha encontrado ningun coche con esa matricula.");
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
			if (plaza1m == 0) {
				printf(">>Plaza 1 de moto- Libre \n");
			}
			else {
				printf(">>Plaza 1 de moto - Ocupada - Matricula %s \n", matricula1m);
				final1m = time(NULL);
				printf("Ya ha de pagar %.2f euros y subiendo\n ", (final1m - inicio1m)*0.00033);
			}
			if (plaza2m == 0) {
				printf(">>Plaza 2 de moto - Libre \n");
			}
			else {
				printf(">>Plaza 2 de moto - Ocupada - Matricula %s \n", matricula2m);
				final2m = time(NULL);
				printf("Ya ha de pagar %.2f euros y subiendo\n", (final2m - inicio2m)*0.00033);
			}
			if (plaza1c == 0) {
				printf(">>Plaza 1 de coche - Libre \n");
			}
			else {
				printf(">>Plaza 1 de coche - Ocupada - Matricula %s \n", matricula1c);
				final1c = time(NULL);
				printf("Ya ha de pagar %.2f euros y subiendo\n ", (final1c - inicio1c)*0.00033);
			}
			if (plaza2c == 0) {
				printf(">>Plaza 2 de coche - Libre \n");
			}
			else {
				printf(">>Plaza 2 de coche - Ocupada - Matricula %s \n", matricula2c);
				final2c = time(NULL);
				printf("Ya ha de pagar %.2f euros y subiendo\n", (final2c - inicio2c)*0.00033);
			}
			system("PAUSE");
			system("cls");

			break;
		case 'b':
		case 'B':
			do {
				printf("Introduzca su matricula:  ");
				scanf_s("%s", matricula_temp, 8);
				a = 0;
				for (j = 0; j < 7; j++) {
					if (((matricula_temp[j]<'0' || matricula_temp[j]>'9') && j <= 3) || ((matricula_temp[j]<'A' || matricula_temp[j]>'Z') && j > 3)) {
						a++;
					}
				}
				if (a != 0) {
					printf("Matricula erronea, la operacion se reiniciara.\n");
					system("pause");
					system("cls");
				}
			} while (a != 0);
			a = 0;
			for (j = 0; j < 8; j++) {
				if (matricula_temp[j] != matricula1m[j]) {
					break;
				}
				else if (j == 7 && plaza1m == 1) {
					printf("Esta en la plaza 1 de moto\n");
					final1m = time(NULL);
					printf("Ya ha de pagar %.2f euros y subiendo\n", (final1m - inicio1m)*0.0033);
					a = 1;
				}
			}
			for (j = 0; j < 8; j++) {
				if (matricula_temp[j] != matricula2m[j]) {
					break;
				}
				else if (j == 7 && plaza2m == 1) {
					printf("Esta en la plaza 2 de moto\n");
					final2m = time(NULL);
					printf("Ha de pagar %.2f euros\n", (final2m - inicio2m)*0.00033);
					a = 1;
				}
			}
			for (j = 0; j < 8; j++) {
				if (matricula_temp[j] != matricula1c[j]) {
					break;
				}
				else if (j == 7 && plaza1c == 1) {
					printf("Esta en la plaza 1 de coche\n");
					final1c = time(NULL);
					printf("Ya ha de pagar %.2f euros y subiendo\n", (final1c - inicio1c)*0.0033);
					a = 1;
				}
			}
			for (j = 0; j < 8; j++) {
				if (matricula_temp[j] != matricula2c[j]) {
					break;
				}
				else if (j == 7 && plaza2c == 1) {
					printf("Esta en la plaza 2 de coche\n");
					final2c = time(NULL);
					printf("Ya ha de pagar %.2f euros y subiendo\n", (final2c - inicio2c)*0.00033);
					a = 1;
				}
			}
			if (a != 1) {
				printf("No se ha encontrado ningun coche con esa matricula.");
			}
			system("pause");
			system("cls");
			break;
		case 'S':
		case 's':
			i = 0;
			break;
		default:
			printf("Opcion no valida\n");
			system("pause");
			system("cls");
		}
	}
}
