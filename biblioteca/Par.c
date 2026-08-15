/*
 * Par.c
 */

#include "Par.h"

/*------------------------------------------*/
/* Tipo privado */

struct Par {
	Info info;
	obj a;
	obj b;
};

/*------------------------------------------*/
/* Funcoes publicas */

Par criaPar(obj a, obj b){
	Par p = malloc(sizeof(struct Par));
	if (p == NULL) semMemoria();
	p->info = criaInfo("Par", destroiPar, destroiTudoPar,
				comparaPar, NULL, textoPar);
	p->a = a;
	p->b = b;
	return p;
}

void destroiPar(Par p){
	free(p);
}

void destroiTudoPar(Par p){
	destroi(p->a);
	destroi(p->b);
	destroiPar(p);
}

int comparaPar(Par p1, Par p2){
	bool r1 = compara(p1->a, p2->a);
	return r1 == 0 ? compara(p1->b, p2->b): r1;
}

string textoPar(Par p){
	string txt = criaStringN(200);
	sprintf(txt, "(%s, %s)", texto(p->a), texto(p->b));
	return recriaString(txt);
}

obj valorAPar(Par p){
	return p->a;
}

obj valorBPar(Par p){
	return p->b;
}

#include "Int.h"

void testePar(void){
	printf("Testando Par:\n");
	Par p = criaPar(criaInt(23), criaInt(-999));
	printf("%s\n", textoPar(p));
	printf("(%d, %d)", valorInt(valorAPar(p)), valorInt(valorBPar(p)));
	destroiTudoPar(p);
}

