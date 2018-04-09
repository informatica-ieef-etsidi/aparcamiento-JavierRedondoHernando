#include <stdio.h>
#include <time.h>
#define TAM 4
struct user {
	char usuario[20];
	char contrasegna[20];
};
struct user_temp {
	char usuario[20];
	char contrasegna[20];
};


struct aparcamiento {
	int estado;
	char tipo;
	char matricula[8];
	int inicio;
	int final;
};

void main() {
	char opcion, matricula_temp[8], moto_o_coche;
	int s = 1, i = 1, j, a;
	struct user boss = { "Jefe","1234" };
	struct user_temp temp;
	struct aparcamiento plaza[TAM];
	do {
		printf("Usuario: ");
		scanf_s("%s", temp.usuario,20);
		printf("Contrasegna: ");
		scanf_s("%s", temp.contrasegna,20);
		++i;
		a = 0;
		j = 0;
		while (temp.usuario[j] != '\0') {
			if (temp.usuario[j] != boss.usuario[j]) {
				a++;
			}
			j++;
		}
		j = 0;
		while (temp.contrasegna[j] != '\0') {
			if (temp.contrasegna[j] != boss.contrasegna[j]) {
				a++;
			}
			j++;
		}
		if (a != 0) {
			printf("Usuario o contrasegna erroneos. Quedan %d intentos\n", 6 - i);
		}
		if (i == 6) {
			a = 0;
			s = 0;
		}
	} while (a!=0);
	for (i = 0; i < TAM; i++) {
		if (i < (TAM / 2)) {
			plaza[i].tipo = 'm';
		}
		else {
			plaza[i].tipo = 'c';
		}
		plaza[i].estado = 0;
	}
	while (s == 1) {
		system("cls");

		//añadida funcion para dar la hora
		struct tm newtime;
		__int64 ltime;
		char buf[26];
		errno_t err;

		_time64(&ltime);

		// Obtain coordinated universal time:   
		err = _gmtime64_s(&newtime, &ltime);
		if (err)
		{
			printf("Invalid Argument to _gmtime64_s.");
		}

		// Convert to an ASCII representation   
		err = asctime_s(buf, 26, &newtime);
		if (err)
		{
			printf("Invalid Argument to asctime_s.");
		}

		printf("La fecha y hora son: %s\n",
			buf);
		//hasta aqui la funcion para dar la hora


		printf("Seleccione una de estas opciones:\nR - Reservar plaza\nA - Abandonar plaza\nE - Estado del aparcamiento\nB - Buscar veiculo por matricula\nS - Salir del programa\n");
		getchar();
		scanf_s("%c", &opcion);
		system("cls");
		switch (opcion) {
		case 'R':
		case 'r':
			printf("Quiere una plaza de moto o de coche?\nM - Moto\nC - Coche\n");
			getchar();
			scanf_s("%c", &moto_o_coche);
			system("cls");
			if (moto_o_coche == 'M' || moto_o_coche == 'm') {
				for (i = 0; i < TAM; i++) {
					if (plaza[i].estado == 0 && plaza[i].tipo == 'm') {
						do {
							printf("Se le ha asignado la plaza %d\n", i + 1);
							plaza[i].estado = 1;
							plaza[i].inicio = time(NULL);
							printf("Introduzca su matricula.\n");
							scanf_s("%s", plaza[i].matricula, 8);
							a = 0;
							for (j = 0; j < 7; j++) {
								if (((plaza[i].matricula[j]<'0' || plaza[i].matricula[j]>'9') && j <= 3) || ((plaza[i].matricula[j]<'A' || plaza[i].matricula[j]>'Z') && j > 3)) {
									a++;
								}
							}
							if (a != 0) {
								printf("Matricula erronea, la operacion se reiniciara.\n");
								getchar();
								system("pause");
								system("cls");
							}
						} while (a != 0);
						system("PAUSE");
						system("cls");
						break;
					}
					else if (i==TAM-1) {
						printf("Todas las plazas estan ocupadas, no puede estacionar.\n");
						system("PAUSE");
						system("cls");
					}
				}
			}
			else if (moto_o_coche == 'C' || moto_o_coche == 'c') {
				for (i = 0; i < TAM; i++) {
					if (plaza[i].estado == 0 && plaza[i].tipo == 'c') {
						do {
							printf("Se le ha asignado la plaza %d\n", i + 1);
							plaza[i].estado = 1;
							plaza[i].inicio = time(NULL);
							printf("Introduzca su matricula.\n");
							scanf_s("%s", plaza[i].matricula, 8);
							a = 0;
							for (j = 0; j < 7; j++) {
								if (((plaza[i].matricula[j]<'0' || plaza[i].matricula[j]>'9') && j <= 3) || ((plaza[i].matricula[j]<'A' || plaza[i].matricula[j]>'Z') && j > 3)) {
									a++;
									getchar();
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
						break;
					}
					else if (i==TAM-1) {
						printf("Todas las plazas estan ocupadas, no puede estacionar.\n");
						system("PAUSE");
						system("cls");
					}
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
			for (i = 0; i < TAM; i++) {
				for (j = 0; j < 8; j++) {
					if (matricula_temp[j] != plaza[i].matricula[j]) {
						break;
					}
					else if (j == 7 && plaza[i].estado == 1) {
						printf("Ha abandonado la plaza %d\n", i + 1);
						plaza[i].estado = 0;
						plaza[i].final = time(NULL);
						printf("Ha de pagar %.2f euros\n ", (plaza[i].final - plaza[i].inicio)*0.0033);
						a = 1;
					}
				}
				if (a == 1) {
					break;
				}
			}
			if (a != 1) {
				printf("No se ha encontrado ningun coche con esa matricula.");
			}
			system("pause");
			system("cls");
			break;
		case 'E':
		case 'e':
			for (i = 0; i < TAM; i++) {
				if (plaza[i].estado == 1) {
					plaza[i].final = time(NULL);
					printf("La plaza %d esta ocupada por el veiculo de matricula %s. Ya ha de pagar %.2f euros y subiendo\n", i + 1, plaza[i].matricula, (plaza[i].final - plaza[i].inicio)*0.0033);
				}
				else {
					printf("La plaza %d no esta ocupada\n", i + 1);
				}
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
			for (i = 0; i < TAM; i++) {
				for (j = 0; j < 8; j++) {
					if (matricula_temp[j] != plaza[i].matricula[j]) {
						break;
					}
					else if (j == 7 && plaza[i].estado == 1) {
						printf("Esta en la plaza %d\n", i + 1);
						plaza[i].final = time(NULL);
						printf("Ya ha de pagar %.2f euros y subiendo\n ", (plaza[i].final - plaza[i].inicio)*0.0033);
						a = 1;
					}
				}
				if (a == 1) {
					break;
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
			s = 0;
			break;
		default:
			printf("Opcion no valida\n");
			system("pause");
			system("cls");
			
		}
	}
}
