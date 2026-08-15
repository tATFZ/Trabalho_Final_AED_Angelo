/*
 * Util.h
 */

#ifndef UTIL_H
#define UTIL_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdarg.h>

/*******************************************************
	Modulo Util - Algumas definicoes uteis, de uso geral
*******************************************************/

/*------------------------------------------*/
/* Constantes publicas */

#define NAO_EXISTE	(-1)

/*------------------------------------------*/
/* Tipos publicos */

/***********************************************
Para representar o tipo das strings, voce pode
usar char * ou string; depende da sua preferencia.
***********************************************/
typedef char *string;

/*------------------------------------------*/
/* Prototipos das funcoes publicas */

/***********************************************
aviso - Escreve um mensagem formatado no canal de erros.
Parametros:
	txt - a mensagem a escrever
	... - argumentos extra
Retorno: nada
Precondicao: txt != NULL
***********************************************/
void aviso(string txt, ...);

/***********************************************
erroFatal - Escreve uma mensagem de erro formatada
	e aborta a execucao do programa.
Parametros:
	txt - a mensagem a escrever
	... - argumentos extra
Retorno: nada
Precondicao: txt != NULL
***********************************************/
void erroFatal(string txt, ...);

/***********************************************
semMemoria - Escreve mensagem de falta de memoria e
	aborta a execucao do programa.
Parametros: nada
Retorno: nada
Precondicao: nada
***********************************************/
void semMemoria(void);

/***********************************************
comparaInteiros - Compara dois valores inteiros.
Parametros: i1, i2 - dois inteiros
Retorno: 0 se i1 = i2; -1 se i1 < i2; 1 se i1 > i2
Precondicao: nada
***********************************************/
int comparaInteiros(int i1, int i2);

/***********************************************
criaString - Aloca dinamicamente uma string.
Parametros: s - uma string
Retorno: apontador para uma copia da string s
Precondicao: s != NULL
***********************************************/
string criaString(string s);

/***********************************************
criaStringN - Reserva um bloco de memoria dinamico com
capacidade para uma string de comprimento maximo n.
Geralmente esta funcao e' usada conjuntamente com 'recriaString'.
Parametros: n - capacidade do bloco de memoria
Retorno: apontador para o bloco de memoria
Precondicao: n >= 0
***********************************************/
string criaStringN(int n);

/***********************************************
recriaString - Dada uma string que ocupa a parte inicial
dum bloco de memoria dinamico, liberta a parte do bloco que
esta' a mais. Sendo pouco provavel, tambem podera acontecer
o sistema transferir a string para outra zona de memoria.
Parametros: s - uma string que ocorre na parte inicial dum bloco
	previamente alocado
Retorno: apontador para o mesmo texto, mas com o espaco otimizado
Precondicao: s != NULL
***********************************************/
string recriaString(string s);

/***********************************************
destroiString - Elimina uma string que foi previamente criada usando
alguma das funcoes de criacao anteriores.
Parametros: s - uma string dinamica
Retorno: nada
Precondicao: s != NULL
***********************************************/
void destroiString(string s);

#endif /* UTIL_H */
