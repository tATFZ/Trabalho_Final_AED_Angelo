/*
 * Util.c
 */

#include "Util.h"

/*------------------------------------------*/
/* Funcoes publicas */

void aviso(string txt, ...){
	va_list args;
	va_start(args, txt);
	fprintf(stderr, "AVISO: ");
	vfprintf(stderr, txt, args);
	fprintf(stderr, "!\n");
	va_end(args);
}

void erroFatal(string txt, ...){
	va_list args;
	va_start(args, txt);
	fprintf(stderr, "ERRO FATAL: ");
	vfprintf(stderr, txt, args);
	fprintf(stderr, "!\n");
	va_end(args);
	exit(1);
}

void semMemoria(void){
	erroFatal("Memoria esgotada");
}

int comparaInteiros(int i1, int i2){
	if (i1 == i2) return 0;
	else if (i1 < i2) return -1;
	else return 1;
}

string criaString(string s){
	string str = strdup(s);
	if (str == NULL) semMemoria();
	return str;
}

string criaStringN(int n){
	string str = malloc(n+1);
	if (str == NULL) semMemoria();
	str[0] = '\0';
	return str;
}

string recriaString(string s){
	return realloc(s, strlen(s)+1);
}

void destroiString(string s){
	free(s);
}
