/*
 * Historia.c
 */

#include "Historia.h"
#include "Fila.h"

/*------------------------------------------*/
/* Tipo privado */

struct Historia{
	Info info;
	Fila registos;
};

/*------------------------------------------*/
/* Funcoes privadas */

/*------------------------------------------*/
/* Funcoes publicas */

Historia criaHistoria(void){
	Historia h = malloc(sizeof(struct Historia));
	if (h == NULL) semMemoria();
	h->info = criaInfo("Historia", destroiHistoria, destroiTudoHistoria,
			NULL, NULL, NULL);
	h->registos = criaFila();
	return h;
}

void destroiHistoria(Historia h){
	destroiFila(h->registos);
	free(h);
}

void destroiTudoHistoria(Historia h){
	destroiTudoFila(h->registos);
	free(h);
}

void acrescentaHistoria(Historia h, Registo r){
	acrescentaFila(h->registos, r);
}

Iterador iteradorHistoria(Historia h){
	return iteradorFila(h->registos);
}