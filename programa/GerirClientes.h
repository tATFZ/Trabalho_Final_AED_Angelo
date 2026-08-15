/*
 * GerirClientes.h
 */

#ifndef GerirClientes_h
#define GerirClientes_h

#include "Dicionario.h"
#include "Int.h"
#include "Str.h"
#include "Info.h"

#include "Cliente.h"

/*------------------------------------------*/
/* Tipo publico */

 typedef struct gerirClientes *GerirClientes;

/*------------------------------------------*/

/* Prototipos das funcoes publicas */
/***********************************************
 cria_GC - Cria o GerirClientes.
 Parametros: nada
 Retorno: Retorna GerirClientes
 Precondicao: O GerirClientes ainda nao existe
***********************************************/
GerirClientes cria_GC();

/***********************************************
 destroiTudo_GC - Destroi o GerirClientes e os seus elementos.
 Parametros: nada
 Retorno: nada
 Precondicao: O GerirClientes ja' existe
***********************************************/
void destroiTudo_GC(GerirClientes g);

/***********************************************
 destroi_GC - Destroi o GerirClientes.
 Parametros: nada
 Retorno: nada
 Precondicao: O GerirClientes ja' existe
***********************************************/
void destroi_GC(GerirClientes g);

/***********************************************
 adicionaCliente_GC - Adiciona um cliente.
 Parametros: g - GerirClientes
 Retorno: nada
 Precondicao: O GerirClientes ja' existe
***********************************************/
void adicionaCliente_GC(GerirClientes g);

/***********************************************
 numeroAtualClienteGC - Numero atual de clientes.
 Parametros: g - GerirClientes
 Retorno: Numero atual de clientes
 Precondicao: O GerirClientes ja' existe
***********************************************/
int numeroAtualClienteGC(GerirClientes g);

/***********************************************
 existeProdutoCestoGC - Verifica se existe produto no cesto do cliente.
 Parametros: g - GerirClientes, numCliente - numero do cliente, nome - nome do produto
 Retorno: True se existe no cesto, False caso contrario
 Precondicao: O GerirClientes ja' existe
***********************************************/
bool existeProdutoCestoGC(GerirClientes g, int numCliente, string nome);

/***********************************************
 alteraQuantidadeProdutoGC - Altera a quantidade do produto do cliente.
 Parametros: g - GerirClientes, numCliente - numero do cliente, nome - nome do produto, quantidade - quantidade do produto
 Retorno: True se existe no cesto, False caso contrario
 Precondicao: O GerirClientes ja' existe
***********************************************/
void alteraQuantidadeProdutoGC(GerirClientes g, int quantidade, int numCliente, string nome);

/***********************************************
 devolveClienteGC - Devolve o cliente do dicionario de clientes
 Parametros: g - GerirClientes, int numCliente - numero do cliente
 Retorno: c - cliente com numCliente
 Precondicao: O GerirClientes ja' existe
***********************************************/
Cliente devolveClienteGC(GerirClientes g, int numCliente);

/***********************************************
 devolveIteradorOrdenadoChaveGC - Devolve as chaves ordenadas do dicionario de clientes
 Parametros: g - GerirClientes
 Retorno: it - iterador ordenado das chaves
 Precondicao: O GerirClientes ja' existe
***********************************************/
Iterador devolveIteradorOrdenadoChaveGC(GerirClientes g);

/***********************************************
 adicionaProdutoCestoGC - Adiciona o produto no cesto do cliente
 Parametros: g - GerirClientes,  numCliente - numero do cliente, nome - nome do produto, quantidade - quantidade do produto
 Retorno: nada
 Precondicao: O GerirClientes ja' existe
***********************************************/
void adicionaProdutoCestoGC(GerirClientes g, int numCliente, Produto p, string nome);

/***********************************************
cestoVazioClienteGC - Verifica se o cesto esta vazio
Parametros: g - GerirClientes,  numCliente - numero do cliente
Retorno: True se esta vazio, false caso contrario
Precondicao: o GerirClientes existe
***********************************************/
bool cestoVazioClienteGC(GerirClientes g, int numCliente);

/***********************************************
adicionaTempoClienteGC - Adiciona tempo ao cliente
Parametros: g - GerirClientes, adicionaTempo -  tempo adicionado, numCliente - numero do cliente
Retorno: nada
Precondicao: o GerirClientes existe
***********************************************/
void adicionaTempoClienteGC(GerirClientes g, int adicionaTempo, int numCliente);

/*********************************************
devolveProdutoCestoGC - Devolve o produto do cesto do cliente
Parametros: g - GerirClientes, numCliente - numero do cliente, chave - chave do dicionario
Retorno: Produto procurado
Precondicao: o GerirClientes existe
*********************************************/
Produto devolveProdutoCestoGC(GerirClientes g, int numCliente, string chave);

/*********************************************
alteraCaixaGC - Altera o id da caixa do cliente
Parametros: g - GerirClientes, numCliente - numero do cliente, caixaCliente - numero da caixa do cliente
Retorno: nada
Precondicao: o GerirClientes existe
*********************************************/
void alteraCaixaGC(GerirClientes g, int numCliente, int caixaCliente);

/***********************************************
devolveIdCaixaGC - Devolve o id da caixa onde o cliente esta
Parametros: g - GerirClientes, numCliente - numero do cliente
Retorno: id da caixa onde o cliente esta, "-1" - se o GerirClientes nao existir
Precondicao: o GerirClientes existe
***********************************************/
int devolveIdCaixaGC(GerirClientes g, int numCliente);

/***********************************************
adicionaDinheiroClienteGC - Adiciona dinheiro ao total do cliente
Parametros: g - GerirClientes, novoDinheiro - novo valor a somar ao total, numCliente - numero do cliente
Retorno: nada
Precondicao: o GerirClientes existe e o numCliente tambem
***********************************************/
void adicionaDinheiroClienteGC(GerirClientes g, int novoDinheiro, int numCliente);

/***********************************************
removeClienteGC - Remove o cliente escolhido de GerirClientes 
Parametros: g - GerirClientes, numCliente - numero do cliente
Retorno: nada
Precondicao: o GerirClientes existe e o numCliente tambem
***********************************************/
void removeClienteGC(GerirClientes g, int numCliente);

/***********************************************
existeClienteGC - Verifica se existem clientes no GerirClientes
Parametros: g - GerirClientes
Retorno: True se esta vazio, false caso contrario
Precondicao: o GerirClientes existe
***********************************************/
bool existeClienteGC(GerirClientes g);

#endif /*GerirClientes_h*/


/*Autoria: Angelo Zhang     nº 71099 
           Diogo Fornelos   nº 71105
*/