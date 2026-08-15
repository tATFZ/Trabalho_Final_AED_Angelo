/*
 * Par.h
 */

#ifndef PAR_H
#define PAR_H

#include "Util.h"
#include "Info.h"

/***********************************************
	TAD Par - Pares ordenados genericos
***********************************************/

/*------------------------------------------*/
/* Tipo publico */
typedef struct Par *Par;

/*------------------------------------------*/
/* Prototipos das funcoes publicas */

/***********************************************
criaPar - Cria um objeto par ordenado.
Parametros: a, b - as componentes a guardar no par
Retorno: o par criado
Precondicao: a != NULL && a != NULL
***********************************************/
Par criaPar(obj a, obj b);

/***********************************************
destroiPar - Elimina um par, mas nao os seus elementos.
Parametros: p - par
Retorno: nada
Precondicao: p != NULL
***********************************************/
void destroiPar(Par p);

/***********************************************
destroiTudoPar - Elimina um par, mais os seus elementos.
Parametros: p - par
Retorno: nada
Precondicao: p != NULL
***********************************************/
void destroiTudoPar(Par p);

/***********************************************
comparaPar - Compara dois pares.
Parametros: p1, p2 - pares a comparar
Retorno: negativo, zero ou positivo
Precondicao: p1 != NULL && p2 != NULL
***********************************************/
int comparaPar(Par p1, Par p2);

/***********************************************
textoPar - Converte em texto, para mostrar em situacoes de debug.
Parametros: p - par
Retorno: o texto criado
Precondicao: p != NULL
***********************************************/
string textoPar(Par p);

/***********************************************
valorAPar - Obtem a primeira componente dum par ordenado.
Parametros: p - par
Retorno: a primeira componente
Precondicao: p != NULL
**********************************************/
obj valorAPar(Par p);

/***********************************************
valorBPar - Obtem a segunda componente dum par ordenado.
Parametros: p - par
Retorno: a segunda componente
Precondicao: p != NULL
**********************************************/
obj valorBPar(Par p);

/***********************************************
testePar - Alguns testes simples.
***********************************************/
void testePar(void);

#endif /* PAR_H */
