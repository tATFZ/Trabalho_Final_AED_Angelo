/*
 * GerirCaixas.c
 */

 #include "GerirCaixas.h"
 #define MAX_CAIXAS 10

 typedef struct gerirCaixas {
    Info info;
    Sequencia Caixa; 
    int num_caixa;

 }*GerirCaixas;

GerirCaixas criaGerirCaixas(void){
   GerirCaixas g = malloc(sizeof(struct gerirCaixas));
   g->Caixa= criaSequencia();
   g->num_caixa = 0;

   for(int i = 0 ; i < MAX_CAIXAS; i++ ){
      Caixa c = criaCaixa();
      adicionaIdCaixa(c, g->num_caixa);
      acrescentaSequencia(g->Caixa, c);
      g->num_caixa++;
   }
   g->info = criaInfo("GerirCaixas", destroi_GerirCaixas, destroiTudo_GerirCaixas, NULL, NULL, NULL);

   return g;
}

void destroi_GerirCaixas(GerirCaixas g){
   destroiSequencia(g->Caixa);
   g->num_caixa = 0;
   free(g);
}

void destroiTudo_GerirCaixas(GerirCaixas g){
   destroiTudoSequencia(g->Caixa);
   g->num_caixa = 0;
   free(g);
}

bool existeClienteGerirCaixas(GerirCaixas g, Cliente d){
   if(g == NULL || d == NULL ){
      return false;
   }
   Iterador it = iteradorSequencia(g->Caixa); //iterador de caixas
   while(temSeguinteIterador(it)){

      Caixa c = seguinteIterador(it); //obtem uma caixa
      if(existeClienteCaixa(c, d)){ //verifica se na caixa obtida temos um cliente igual
         destroiIterador(it);
         return true;
      }

   }
   destroiIterador(it);
   return false; // se nao encontrarmos retorna false
}

int devolveNumeroGerirCaixas(GerirCaixas g){
   if(g == NULL){
      return -1;
   }
   int numCaixas = g->num_caixa;
   
   return numCaixas;
}

void adicionaClienteGerirCaixas(GerirCaixas g, Cliente d, int caixa){
   if(g == NULL || d == NULL ){
      return;
   }
   Caixa c = elementoSequencia(g->Caixa, caixa);  // escolhe a caixa a colocar o cliente

   if(caixa != 0){ //se a caixa for diferente de 0 

   adicionaTempoCliente(d, 50);//adiciona 50 segundos de burocracia

   }

   adicionaClienteCaixa(c, d); // coloca o cliente d na caixa c
}

int melhorTempoGerirCaixas(GerirCaixas g, int cestovazio){
   int melhorTempo = -1;
   int numMelhorCaixa = -1;
   if(g == NULL){
      return -1;
   }

   Iterador it = iteradorSequencia(g->Caixa); //vai buscar o iterador de cada caixa
   
   while(temSeguinteIterador(it)){
      Caixa c = seguinteIterador(it); // temos uma caixa
      int tempo = devolveTempoCaixa(c); //tempo atual dessa caixa
      int id = devolveIdCaixa(c);

      if (id == 0 && cestovazio == 0) {  //se o cesto nao estiver vazio skip da caixa 0 
            continue;
        }

      if(melhorTempo == -1 || tempo < melhorTempo){  //comparamos os tempos
         melhorTempo = tempo;
         numMelhorCaixa = id; // vamos buscar o id da caixa com menor tempo
      }
   
   }
   destroiIterador(it);
   
   return numMelhorCaixa;
}

Caixa devolveCaixaGerirCaixas(GerirCaixas g, int idCaixa){
   if(g == NULL || idCaixa < 0 || idCaixa >= g->num_caixa){
      return NULL;
   }
   Caixa c = elementoSequencia(g->Caixa, idCaixa);
   return c;
}

void removeClienteGerirCaixas(GerirCaixas g, int idCaixa){
   if(g == NULL){
      return;
   }

   Caixa c = elementoSequencia(g->Caixa, idCaixa);
   removeClienteFila(c);
}

/*Autoria: Angelo Zhang     nº 71099 
           Diogo Fornelos   nº 71105
*/