/*
 * Vetor.h
 */

#ifndef VETOR_H
#define VETOR_H

#include "Util.h"
#include "Info.h"

/***********************************************
	Modulo Vector - Vetores genericos (nao e' TAD)

Este modulo oferece algumas funcoes uteis
para vetores de objetos. Podia incluir mais
funcoes uteis como,'criaVetor', 'destroiVetor',
'cresceVetor', etc. Contudo essas funcoes nao foram
criadas para os alunos serem obrigados a treinar a
manipulacao direta de vetores, nomeadamente usando
diretamente 'malloc' e 'realloc'.
***********************************************/

/*------------------------------------------*/
/* Tipo publico */

typedef obj *vetor;

/*------------------------------------------*/
/* Prototipos das funcoes publicas */

/***********************************************
copiaVetor - Copia um vetor de objetos.
Parametros:
	v - vetor a copiar
	n - numero de objetos no vetor
Retorno: copia do vetor
Precondicao: v != NULL && n >= 0
***********************************************/
vetor copiaVetor(vetor v, int n);

/***********************************************
ordenaVetor - Ordena um vetor de objetos.
Parametros:
	v - vetor a ordenar
	n - numero de objetos no vetor
Retorno: nada
Precondicao: v != NULL && n >= 0
***********************************************/
void ordenaVetor(vetor v, int n);

/***********************************************
homogeneoVetor - Testa se todos os objetos no vetor sao do mesmo tipo.
Parametros:
	v - vetor a testar
	n - numero de objetos no vetor
Retorno: true - se homogeneo; false - caso contrario
Precondicao: v != NULL && n >= 0
***********************************************/
bool homogeneoVetor(vetor v, int n);

/***********************************************
textoVetor - Converte em texto, para mostrar em situacoes de debug.
Parametros:
	v - vetor a mostrar
	n - numero de objetos no vetor
Retorno: o texto criado
Precondicao: v != NULL && n >= 0
***********************************************/
string textoVetor(vetor v, int n);

#endif /* VETOR */
