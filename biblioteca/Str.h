/*
 * Int.h
 */

#ifndef STR_H
#define STR_H

#include "Util.h"
#include "Info.h"

/***********************************************
	TAD String - Strings representadas por objetos
***********************************************/

/*------------------------------------------*/
/* Tipo publico */

typedef struct Str *Str;

/*------------------------------------------*/
/* Prototipos das funcoes publicas */

/***********************************************
criaStr - Cria um objeto que representa uma string.
Parametros: valor - a string a representar
Retorno: o objeto criado
Precondicao: valor != NULL
***********************************************/
Str criaStr(string valor);

/***********************************************
destroiStr - Elimina um objeto str.
Parametros: str - objeto str
Retorno: nada
Precondicao: str != NULL
***********************************************/
void destroiStr(Str str);

/***********************************************
comparaStr - Compara duas strs.
Parametros: str1, str2 - objetos str
Retorno: negativo, zero ou positivo
Precondicao: str1 != NULL && str2 != NULL
***********************************************/
int comparaStr(Str str1, Str str2);

/***********************************************
dispersaoStr - Funcao de dispersao das strs.
Parametros: str - objeto str; dim - dimensao da tabela
Retorno: valor de dispersao
Precondicao: str != NULL && dim > 0
***********************************************/
int dispersaoStr(Str str, int dim);

/***********************************************
textoStr - Converte em texto, para mostrar em situacoes de debug.
Parametros: str - objeto str
Retorno: o texto criado
Precondicao: str != NULL
***********************************************/
string textoStr(Str str);

/***********************************************
valorStr - Extrai a string guardada num objeto str.
Parametros: s - objeto str
Retorno: a string guardada no objeto
Precondicao: s != NULL
**********************************************/
string valorStr(Str str);

/***********************************************
testeStr - Alguns testes simples.
***********************************************/
void testeStr(void);

#endif /* STR_H */
