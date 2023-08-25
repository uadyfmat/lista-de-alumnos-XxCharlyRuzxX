#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

struct alumno {
	char* nombre;
	int creditos_ap;
	int semestre; 
	struct alumno* enlace;
};

struct alumno* crearAlumno(char* nombre, int creditos, int semestre) {
	struct alumno* nuevo = (struct alumno*)malloc(sizeof(struct alumno));
	nuevo->nombre = (char*)malloc((strlen(nombre) + 1) * sizeof(char));
	strcpy(nuevo->nombre, nombre);
	nuevo->creditos_ap = creditos;
	nuevo->semestre = semestre;
	nuevo->enlace = NULL;
	return nuevo;
}

void imprimirLista(struct alumno* cabecera) {
	struct alumno* actual;
	actual = cabecera;
	
	if (cabecera == NULL) {
		printf("La lista está vacía\n");
	} else {
		while (actual != NULL) {
			printf("Nombre: %s  ", actual->nombre);
			printf("Créditos aprobados: %d   ", actual->creditos_ap);
			printf("Semestre: %d\n", actual->semestre);
			actual = actual->enlace; 
		}
	}
}

void imprimirAlumno(struct alumno* cabecera, char* alumno) {
	struct alumno* actual;
	actual = cabecera;
	int encontrado = 0;
	
	if (cabecera == NULL) {
		printf("La lista está vacía\n");
	} else {
		while (actual != NULL) {
			if (strcmp(alumno, actual->nombre) == 0) {
				printf("Nombre: %s  ", actual->nombre);
				printf("Créditos aprobados: %d   ", actual->creditos_ap);
				printf("Semestre: %d\n", actual->semestre);
				encontrado = 1;
				break;
			}
			actual = actual->enlace; 
		}
		
		if (!encontrado) {
			printf("No se encontró el alumno\n");
		}
	}
}



void insertarNodoOrdenadoCreditos(struct alumno** cabecera, struct alumno* nuevo) {
	struct alumno* actual;
	struct alumno* anterior = NULL;
	
	actual = *cabecera;
	
	if (*cabecera == NULL ) {
		nuevo->enlace = actual;
		*cabecera = nuevo;
	} else {
		while (actual != NULL && nuevo->creditos_ap > actual->creditos_ap) {
			anterior = actual;
			actual = actual->enlace;
		}
		anterior->enlace = nuevo;
		nuevo->enlace = actual;
	}
	return;
}
int main(int argc, char *argv[]) {
	struct alumno* cabecera = NULL;
	
	insertarNodoOrdenadoCreditos(&cabecera, crearAlumno("Carlos", 30, 3));
	insertarNodoOrdenadoCreditos(&cabecera, crearAlumno("Papo", 69, 7));
	insertarNodoOrdenadoCreditos(&cabecera, crearAlumno("Tito", 39, 5));
	imprimirLista(cabecera);
	imprimirAlumno(cabecera, "Carlos");
	
	return 0;
}
