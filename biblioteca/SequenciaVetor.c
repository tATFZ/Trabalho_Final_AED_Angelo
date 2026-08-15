/*
 * SequenciaVetor.c
 */

#include "Sequencia.h"
#include "Vetor.h"

/*------------------------------------------*/
/* Constantes privadas */

#define CAPACIDADE_INICIAL	4

/*------------------------------------------*/
/* Tipo privado */

struct Sequencia{
	Info info;
	vetor elems;	  // vetor dinamico
	int numElems;
	int capacidade;
};

/*------------------------------------------*/
/* Funcoes privadas */

static void asseguraCapacidade(Sequencia s){
	if (tamanhoSequencia(s) == s->capacidade){ // se sequencia cheia...
		int novaCapacidade = s->capacidade * 2; // ... entao duplica capacidade
		s->elems = realloc(s->elems, sizeof(obj) * novaCapacidade);
		s->capacidade = novaCapacidade;
	}
}

/* converte indices negativos */
static int ajustaPos(Sequencia s, int i){
	if (i < 0)
		i = tamanhoSequencia(s) + i;
	return i;
}

/*------------------------------------------*/
/* Funcoes publicas */

Sequencia criaSequencia(void){
	int cap = CAPACIDADE_INICIAL;
	Sequencia s = malloc(sizeof(struct Sequencia));
	if (s == NULL) semMemoria();
	s->elems = malloc(sizeof(obj) * cap);
	if (s->elems == NULL) semMemoria();
	s->info = criaInfo("Sequencia", destroiSequencia, destroiTudoSequencia,
						NULL, NULL, textoSequencia);
	s->numElems = 0;
	s->capacidade = cap;
	return s;
}

void destroiSequencia(Sequencia s){
	free(s->elems);
	free(s);
}

void destroiTudoSequencia(Sequencia s){
	for (int i=0 ; i < s->numElems; i++)
		destroi(s->elems[i]);
	destroiSequencia(s);
}

string textoSequencia(Sequencia s){
	return textoVetor(s->elems, s->numElems);
}

bool vaziaSequencia(Sequencia s){
	return s->numElems == 0;
}

int tamanhoSequencia(Sequencia s){
	return s->numElems;
}

obj elementoSequencia(Sequencia s, int i){
	i = ajustaPos(s, i);
	return s->elems[i];
}

obj atribuiSequencia(Sequencia s, obj elem, int i){
	i = ajustaPos(s, i);
	obj antigo = elementoSequencia(s, i);
	s->elems[i] = elem;
	return antigo;
}

void insereSequencia(Sequencia s, obj elem, int i){
	asseguraCapacidade(s);
	i = ajustaPos(s, i);
	// empurra para a frente
	for (int k = s->numElems-1; k >= i ; k--)
		s->elems[k+1] = s->elems[k];
	s->elems[i] = elem;
	s->numElems++;
}

void acrescentaSequencia(Sequencia s, obj elem){
	insereSequencia(s, elem, tamanhoSequencia(s));
}

obj removeSequencia(Sequencia s, int i){
	i = ajustaPos(s, i);
	obj antigo = elementoSequencia(s, i);
	// puxa para tras
	for (int k=i+1; k < s->numElems; k++)
		s->elems[k-1] = s->elems[k];
	s->numElems--;
	return antigo;
}

Iterador iteradorSequencia(Sequencia s){
	return criaIterador(copiaVetor(s->elems, s->numElems), s->numElems);
}

Iterador iteradorOrdenadoSequencia(Sequencia s){
	return criaIteradorOrdenado(copiaVetor(s->elems, s->numElems), s->numElems);
}

#include "Int.h"

void testeSequencia(void){
	printf("Testando Sequencia:\n\t");
	Sequencia s = criaSequencia();
	for (int valor = 0; valor < 10; valor++)
		acrescentaSequencia(s, criaInt(valor));
	printf("%s\n", textoSequencia(s));

	for (int i = 0; i < 10; i++)
		insereSequencia(s, criaInt(i*10), tamanhoSequencia(s));
	printf("%s\n", textoSequencia(s));
}
