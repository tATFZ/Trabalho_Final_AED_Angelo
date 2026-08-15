/*
 * Cliente.h
 */

#ifndef Cliente_h
#define Cliente_h

#include "Util.h"
#include "Dicionario.h"
#include "Str.h"
#include "Int.h"
#include "Info.h"

#include "Produto.h"

/*------------------------------------------*/
/* Tipo publico */

typedef struct cliente *Cliente;

/*------------------------------------------*/
/* Prototipos das funcoes publicas */

/***********************************************
criaCliente - Cria o cliente
Parametros: Nao tem parametros de entrada
Retorno: o cliente criado
Precondicao: o cliente nao existe
***********************************************/
Cliente criaCliente(void);

/***********************************************
destoiCliente - Destroi o cliente
Parametros: c - cliente
Retorno: nada
Precondicao: o cliente existe
***********************************************/
void destroiCliente(Cliente c);

/***********************************************
alteraIdCliente - Altera o id do cliente
Parametros: c - cliente, novoId - novo Id
Retorno: nada
Precondicao: o cliente existe
***********************************************/
void alteraIdCliente(Cliente c, int novoId);

/***********************************************
adicionaProdutoCestoCliente - Adiciona um produto ao cesto do cliente
Parametros: c - cliente, nome - nome que da origem `a chave do dicionario, p - produto
Retorno: nada
Precondicao: o cliente o nome e o produto existem
***********************************************/
void adicionaProdutoCestoCliente(Cliente c, string nome, Produto p);

/***********************************************
devolveProdutoCestoCliente - Devolve o produto do cesto do cliente
Parametros: c - cliente, chave - chave do dicionario
Retorno: Produto procurado
Precondicao: o cliente e o produto existem
***********************************************/
Produto devolveProdutoCestoCliente(Cliente c, string chave);

/***********************************************
existeProdutoCestoCliente - Verifica se existe o produto no cesto
Parametros: c - cliente, chave - chave do dicionario
Retorno: True se existe, False caso contrario
Precondicao: o cliente existe
***********************************************/
bool existeProdutoCestoCliente(Cliente c, string chave);

/***********************************************
iteradorOrdenadoChaveCestoCliente - Devolve iterador ordenado das chaves do cesto do cliente
Parametros: c - cliente
Retorno: iterador ordenado das chaves do cesto
Precondicao: o cliente existe
***********************************************/
Iterador iteradorOrdenadoChaveCestoCliente(Cliente c);

/***********************************************
cestoVazioCliente - Verifica se o cesto esta vazio
Parametros: c - cliente
Retorno: True se esta vazio, False caso contrario
Precondicao: o cliente existe
***********************************************/
bool cestoVazioCliente(Cliente c);

/***********************************************
devolveIdCliente - Devolve o id do cliente
Parametros: c - cliente
Retorno: id do cliente, "-1" - se o cliente nao existir 
Precondicao: o cliente existe
***********************************************/
int devolveIdCliente(Cliente c);

/***********************************************
comparaCliente - Compara o id de dois clientes
Parametros: a - cliente, b - cliente
Retorno:  0 se a = b; -1 se a < b; 1 se a > b
Precondicao: o cliente a e b existem
***********************************************/
int comparaCliente(Cliente a, Cliente b);

/***********************************************
devolveTempoCliente - Devolve o tempo total do cliente
Parametros: c - cliente
Retorno: tempo do cliente, "-1" - se o cliente nao existir
Precondicao: o cliente existe
***********************************************/
int devolveTempoCliente(Cliente c);

/***********************************************
adicionaTempoCliente - Adiciona tempo ao cliente
Parametros: c - cliente, tempoAdiciona -  tempo adicionado
Retorno: nada
Precondicao: o cliente existe
***********************************************/
void adicionaTempoCliente(Cliente c, int tempoAdiciona);

/***********************************************
alteraCaixaCliente - Altera o id da caixa do cliente
Parametros: c - cliente, caixaCliente - id da caixa onde o cliente esta
Retorno: nada
Precondicao: o cliente existe
***********************************************/
void alteraCaixaCliente(Cliente c, int caixaCliente);

/***********************************************
devolveIdCaixaCliente - Devolve o id da caixa onde o cliente esta
Parametros: c - cliente
Retorno: id da caixa onde o cliente esta, "-1" - se o cliente nao existir
Precondicao: o cliente existe
***********************************************/
int devolveIdCaixaCliente(Cliente c);

/***********************************************
devolveDinheiroCliente - Devolve o custo do cesto do cliente
Parametros: c - cliente
Retorno: dinheiro que custa o cesto, "-1" - se o cliente nao existir
Precondicao: o cliente existe
***********************************************/
int devolveDinheiroCliente(Cliente c);

/***********************************************
adicionaDinheiroCliente - Atualiza o valor do dinheiro do cliente
Parametros: c - cliente
Retorno: nada
Precondicao: o cliente existe
***********************************************/
void adicionaDinheiroCliente(Cliente c, int valor);

/***********************************************
devolvePesoCliente - Devolve o peso do cesto do cliente
Parametros: c - cliente
Retorno: peso que custa o cesto, "-1" - se o cliente nao existir
Precondicao: o cliente existe
***********************************************/
int devolvePesoCliente(Cliente c);

/***********************************************
alteraTempoCliente - Atualiza o valor do tempo do cliente
Parametros: c - cliente
Retorno: nada
Precondicao: o cliente existe
***********************************************/
void alteraTempoCliente(Cliente c, int novoTempo);

#endif /*Cliente_H*/

/*Autoria: Angelo Zhang     nº 71099 
           Diogo Fornelos   nº 71105
*/