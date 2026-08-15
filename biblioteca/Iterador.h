/*
 * Iterador.h
 */

#ifndef ITERADOR_H
#define ITERADOR_H

#include "Util.h"
#include "Info.h"
#include "Vetor.h"

/***********************************************
	TAD Iterador - Iteradores genericos
***********************************************/

/*------------------------------------------*/
/* Tipo publico */

typedef struct Iterador *Iterador;

/*------------------------------------------*/
/* Prototipos das funcoes publicas */

/***********************************************
criaIterador - Cria um iterador
Parametros:
	vetorCopia - uma copia do vetor a iterar;
		esta copia sera automaticamente eliminada quando
		o iterador for destruido
	n - numero de elementos no vetor
Retorno: o iterador criado
Precondicao: vetorCopia != NULL && n >= 0
***********************************************/
Iterador criaIterador(vetor vetorCopia, int n);

/***********************************************
criaIteradorOrdenado - Cria um iterador ordenado.
Parametros:
	vetorCopia - recebe uma copia do vetor a iterar;
		esta copia sera automaticamente eliminada quando
		o iterador for destruido
	n - tamanho de vetorCopia
Retorno: o iterador criado
Precondicao: vetorCopia != NULL && n >= 0
***********************************************/
Iterador criaIteradorOrdenado(vetor vetorCopia, int n);

/***********************************************
destroiIterador - Elimina um iterador, mas nao os seus elementos.
Parametros: it - iterador
Retorno: nada
Precondicao: it != NULL
***********************************************/
void destroiIterador(Iterador it);

/***********************************************
textoIterador - Converte em texto, para mostrar em situacoes de debug.
Parametros: it - iterador
Retorno: o texto criado
Precondicao: it != NULL
***********************************************/
string textoIterador(Iterador it);

/***********************************************
temSeguinteIterador - Testa se existe pelo menos mais um elemento para iterar.
Parametros: it - iterador
Retorno: true - caso existam mais elementos; false - caso contrario
Precondicao: it != NULL
***********************************************/
bool temSeguinteIterador(Iterador it);

/***********************************************
seguinteIterador - Obtem o elemento seguinte no iterador.
Parametros: it - iterador
Retorno: elemento
Precondicao: it != NULL && temSeguinteIterador(it)
***********************************************/
obj seguinteIterador(Iterador it);

/***********************************************
testeIterador - Alguns testes simples.
***********************************************/
void testeIterador(void);

#endif /* ITERATOR_H */
