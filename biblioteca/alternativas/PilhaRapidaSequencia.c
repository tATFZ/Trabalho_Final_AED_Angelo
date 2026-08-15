/*
 * PilhaRapidaLista.c
 */

#include "Pilha.h"
#include "Sequencia.h"

/*------------------------------------------*/
/* Tipo privado */

struct Pilha{
	Info info;
	Sequencia seq;
};

/*	Os elementos entram pela ultima posicao e saem pela
	ultima posicao. Assim fica eficiente, assumindo que
	estamos a usar uma sequencia implementada com vetor.
*/

/*------------------------------------------*/
/* Funcoes publicas */

Pilha criaPilha(void){
	Pilha p = malloc(sizeof(struct Pilha));
	if (p == NULL) semMemoria();
	p->info = criaInfo("Pilha", destroiPilha, destroiTudoPilha,
				NULL, NULL, textoPilha);
	p->seq = criaSequencia();	// sequencia vazia
	return p;
}

void destroiPilha(Pilha p){
	destroi(p->seq);
	free(p);
}

void destroiTudoPilha(Pilha p){
	destroiTudo(p->seq);
	free(p);
}

string textoPilha(Pilha p){
	return texto(p->seq);
}

bool vaziaPilha(Pilha p){
	return vaziaSequencia(p->seq);
}

int tamanhoPilha(Pilha p){
	return tamanhoSequencia(p->seq);
}

/* Precondicao: p != NULL && !vaziaPilha(p) */
obj topoPilha(Pilha p){
	return elementoSequencia(p->seq, -1);
}

void emPilha(Pilha p, obj elem){
	acrescentaSequencia(p->seq, elem);
}

/* Precondicao: p != NULL && !vaziaPilha(p) */
obj desemPilha(Pilha p){
	return removeSequencia(p->seq, -1);
}

Iterador iteradorPilha(Pilha p){
	return iteradorSequencia(p->seq);
}

Iterador iteradorOrdenadoPilha(Pilha p){
	return iteradorOrdenadoSequencia(p->seq);
}

#include "Int.h"

void testePilha(void){
	printf("Testando Pilha:\n");
	Pilha p = criaPilha();
	emPilha(p, criaInt(0));
	emPilha(p, criaInt(1));
	emPilha(p, criaInt(2));
	emPilha(p, criaInt(3));
	printf("%s\n", textoPilha(p));

	Iterador it = iteradorPilha(p);
	while (temSeguinteIterador(it))
		printf("%s\n", texto(seguinteIterador(it)));
	destroiIterador(it);

	printf("topo = %s\n", texto(topoPilha(p)));
	printf("desempilha = %s\n", texto(desemPilha(p)));
	printf("desempilha = %s\n", texto(desemPilha(p)));
	printf("%s\n", textoPilha(p));
}











