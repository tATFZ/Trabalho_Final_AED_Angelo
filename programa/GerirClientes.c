/*
 * GerirClientes.c
 */

#include "GerirClientes.h"

typedef struct gerirClientes {

    Info info;
    Dicionario GerirClientes;
    int numClientes;

}*GerirClientes;

GerirClientes cria_GC(void) {
    GerirClientes g = malloc(sizeof(struct gerirClientes));
    if (g == NULL) {
        semMemoria(); // Verifica se a memoria foi alocada
    }

    g->info = criaInfo("GerirClientes", destroi_GC, destroiTudo_GC, NULL, NULL, NULL);
    g->GerirClientes = criaDicionario(); // Cria o dicionário para armazenar os clientes
    g->numClientes = -1;              

    return g;
}

void destroiTudo_GC(GerirClientes g){
    if (g == NULL || g->GerirClientes == NULL) {

        destroiTudoDicionario(g->GerirClientes);
        free(g);
        return;
    }
}

void destroi_GC(GerirClientes g){
    if (g == NULL || g->GerirClientes == NULL) {
        return;
    }

    destroiDicionario(g->GerirClientes);
    free(g);
}

void adicionaCliente_GC(GerirClientes g) { 
    if (g == NULL) return;

    int j = g->numClientes;
    int numAtual = j+1;

    Cliente c = criaCliente();
    alteraIdCliente(c, numAtual);
    acrescentaDicionario(g->GerirClientes, criaInt(numAtual), c);
    g->numClientes = j+1;
}

int numeroAtualClienteGC(GerirClientes g){
    if(g == NULL){
        return -1;
    }

    return g->numClientes; //retorna o numero de clientes atual
}


bool existeProdutoCestoGC(GerirClientes g, int numCliente, string nome){
    if(g == NULL){
        return false;
    }

    Cliente c = elementoDicionario(g->GerirClientes, criaInt(numCliente));
    
    if(existeProdutoCestoCliente(c, nome)){
        return true;
    }
    return false;
}

void alteraQuantidadeProdutoGC(GerirClientes g, int quantidade, int numCliente, string nome){

    Cliente c = elementoDicionario(g->GerirClientes, criaInt(numCliente));

    Produto p = devolveProdutoCestoCliente(c, nome);
    int j = (devolveQuantidadeProduto(p) + quantidade);
    alteraQuantidadeProduto(p, j);

}

Cliente devolveClienteGC(GerirClientes g, int numCliente){
    if(g == NULL){
        return NULL;
    }

    Cliente c = elementoDicionario(g->GerirClientes, criaInt(numCliente));
    return c;
}
        
Iterador devolveIteradorOrdenadoChaveGC(GerirClientes g){
    if(g == NULL){
        return NULL;
    }
    
    Iterador it = iteradorOrdenadoChavesDicionario(g->GerirClientes);
    return it;
}

void adicionaProdutoCestoGC(GerirClientes g, int numCliente, Produto p, string nome){

    Cliente c = elementoDicionario(g->GerirClientes, criaInt(numCliente));
    adicionaProdutoCestoCliente(c, nome, p);
    
}

bool cestoVazioClienteGC(GerirClientes g, int numCliente){
    if(g == NULL){
        return true;
    }

    Cliente c = elementoDicionario(g->GerirClientes, criaInt(numCliente));
    
    if(cestoVazioCliente(c)){
        return true;
    }
    return false;
} 

void adicionaTempoClienteGC(GerirClientes g, int adicionaTempo, int numCliente){
    if(g == NULL){
        return;
    }

    Cliente c = elementoDicionario(g->GerirClientes, criaInt(numCliente));

    adicionaTempoCliente(c, adicionaTempo);

}

Produto devolveProdutoCestoGC(GerirClientes g, int numCliente, string chave){
    if(g == NULL){
        return NULL;
    }

    Cliente c = elementoDicionario(g->GerirClientes, criaInt(numCliente));
    Produto p = devolveProdutoCestoCliente(c, chave);

    return p;
}

void alteraCaixaGC(GerirClientes g, int numCliente, int caixaCliente){
    if(g == NULL){
        return;
    }

    Cliente c = elementoDicionario(g->GerirClientes, criaInt(numCliente));
    alteraCaixaCliente(c, caixaCliente);
    
}

int devolveIdCaixaGC(GerirClientes g, int numCliente){
    if(g == NULL){
        return -1;
    }

    Cliente c = elementoDicionario(g->GerirClientes, criaInt(numCliente));
    int idcaixa = 0;
    idcaixa = devolveIdCaixaCliente(c);
    return idcaixa;

}

void adicionaDinheiroClienteGC(GerirClientes g, int novoDinheiro, int numCliente){
    if (g == NULL){
        return;
    }

    Cliente c = elementoDicionario(g->GerirClientes, criaInt(numCliente));  
    
    if (c == NULL){
        return;
    }
    
    adicionaDinheiroCliente(c, novoDinheiro);
}

void removeClienteGC(GerirClientes g, int numCliente){
    if (g == NULL){
        return;
    }
    removeDicionario(g->GerirClientes, criaInt(numCliente));
}

bool existeClienteGC(GerirClientes g){
    if(vazioDicionario(g->GerirClientes)){
        return true;
    }
    return false;
}
/*Autoria: Angelo Zhang     nº 71099 
           Diogo Fornelos   nº 71105
*/