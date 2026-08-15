/*
 * Registo.c
 */

#include "Registo.h"

/*------------------------------------------*/
/* Tipo privado */

struct Registo{
	Info info;
	int cliente;
	int caixa;
	int momento;
	int pagou;
	int peso;
};

/*------------------------------------------*/
/* Funcoes privadas */

/*------------------------------------------*/
/* Funcoes publicas */

Registo criaRegisto(int cliente, int caixa, int momento, int pagou, int peso){
	Registo r = malloc(sizeof(struct Registo));
	if (r == NULL) semMemoria();
	r->info = criaInfo("Registo", destroiRegisto, destroiRegisto,
			NULL, NULL, NULL);
	r->cliente = cliente;
	r->caixa = caixa;
	r->momento = momento;
	r->pagou = pagou;
	r->peso = peso;
	return r;
}

void destroiRegisto(Registo r){
	free(r);
}

int clienteRegisto(Registo r){
	return r->cliente;
}

int caixaRegisto(Registo r){
	return r->caixa;
}

int momentoRegisto(Registo r){
	return r->momento;
}

int pagouRegisto(Registo r){
	return r->pagou;
}

int pesoRegisto(Registo r){
	return r->peso;
}