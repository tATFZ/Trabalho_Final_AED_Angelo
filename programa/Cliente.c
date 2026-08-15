/*
 * Cliente.c
 */

#include "Cliente.h"

typedef struct cliente {

    Info info;
    Dicionario cesto;
    int idCliente;
    int tempoCliente;
    int caixaCliente;
    int dinheiroCliente;
}*Cliente;

Cliente criaCliente(void){
    Cliente c = malloc(sizeof(struct cliente));
    if (c == NULL) {
        semMemoria();
    }

    c->info = criaInfo("Cliente", destroiCliente, destroiCliente, comparaCliente, NULL, NULL);
    c->cesto = criaDicionario(); 
    c->idCliente = 0;
    c->tempoCliente = 0;
    c->caixaCliente = 0;
    c->dinheiroCliente = 0;
    return c;
}

void alteraIdCliente(Cliente c, int novoId){
    c->idCliente = novoId;
}

void destroiCliente(Cliente c){
    if(c == NULL){
        return;
    }
    destroiDicionario(c->cesto);
    free(c); 
}

void adicionaProdutoCestoCliente(Cliente c, string nome, Produto p){
    if(c == NULL || nome == NULL || p == NULL){
        return; 
    }   
        Str chave = criaStr(nome); // Cria a chave do produto
        acrescentaDicionario(c->cesto, chave, p); // Adiciona o produto ao cesto do cliente
}

Produto devolveProdutoCestoCliente(Cliente c, string chave){
    if (c == NULL || chave == NULL) {
        return NULL; 
    }

    Produto p = elementoDicionario(c->cesto, criaStr(chave)); // Devolve o produto do cesto
    return p;
}

bool existeProdutoCestoCliente(Cliente c, string chave){
    if(c == NULL){
        return false;
    }

    if(existeDicionario(c->cesto, criaStr(chave))){
        return true;
    }
    else {
        return false;
    }
}

Iterador iteradorOrdenadoChaveCestoCliente(Cliente c) {
    if (c == NULL) {
        return NULL;
    }
    return iteradorOrdenadoChavesDicionario(c->cesto);
}

bool cestoVazioCliente(Cliente c){
    if(c == NULL){
        return false;
    }
    if(vazioDicionario(c->cesto)){
        return true;
    }
    else {
        return false;
    }
}

int devolveIdCliente(Cliente c){
    if(c == NULL){
    return -1;
    }
    
    int id = c->idCliente;
    return id;

}

int comparaCliente(Cliente a, Cliente b){

    int idA = a->idCliente;
    int idB = b->idCliente;
    int j = 0;

    j = comparaInteiros(idA, idB);

    return j;
}

int devolveTempoCliente(Cliente c){
    if(c == NULL){
        return -1;
    }

    return c->tempoCliente;

}

void adicionaTempoCliente(Cliente c, int novoTempo){
    if(c == NULL){
        return;
    }
    int tempo = c->tempoCliente;
    c->tempoCliente = tempo + novoTempo;
}

void alteraCaixaCliente(Cliente c, int caixaCliente){
    if(c == NULL){
        return;
    }
    int novaCaixa = caixaCliente;
    c->caixaCliente = novaCaixa; 

}

int devolveIdCaixaCliente(Cliente c){
    if(c == NULL){
        return -1;
    }

    return c->caixaCliente;
}

int devolveDinheiroCliente(Cliente c){
    if(c == NULL){
        return -1;
    }
    return c->dinheiroCliente;
}

void adicionaDinheiroCliente(Cliente c, int valor){
    if(c == NULL){
        return;
    } 
    
    c->dinheiroCliente += valor;
}

int devolvePesoCliente(Cliente c){
    if(c == NULL){
        return -1;
    }
    int peso = 0;

    Iterador it = iteradorDicionario(c->cesto);
    while(temSeguinteIterador(it)){
        Produto p = seguinteIterador(it);
        peso = peso + devolvePesoProduto(p);
        peso = peso * devolveQuantidadeProduto(p);
    }
    destroiIterador(it);
    return peso;
}

void alteraTempoCliente(Cliente c, int novoTempo){
    if(c == NULL){
        return;
    } 
    c->tempoCliente = novoTempo;
}

/*Autoria: Angelo Zhang     nº 71099 
           Diogo Fornelos   nº 71105
*/