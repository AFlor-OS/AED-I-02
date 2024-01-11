#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int inicializar_pil(t_pilha *P) {
	P->topo = NULL;
	P->count = 0;
	return SUCESSO;
}

int topo_pil(t_pilha *P) {
	if (vazia_pil(P)) {
		printf("Nao tem topo!!!!\n");
		return VAZIA;
	} else {
		return P->topo->elem_p;
	}
}

int contar_pil(t_pilha *P) {
	return P->count;
}

int push(int e, t_pilha *P) { // primeira pos

	t_apontador a = (t_apontador) malloc(sizeof(t_no));

	if (a == NULL) {
		printf("Pilha (memoria) cheia!\n");
		return CHEIA;
	}

	a->elem_p = e;
	a->prox_p = P->topo;
	P->topo = a;
	P->count++;

	return SUCESSO;

}

int pop(t_pilha *P) {

	if (vazia_pil(P)) {
		return NAO_EXISTE;
	}

	t_apontador a = P->topo;
	int e = a->elem_p;


	P->topo = P->topo->prox_p;
	free(a);

	P->count--;

	return e;

}



int cheia_pil(t_pilha *P) {
	
	t_apontador a = (t_apontador) malloc(sizeof(t_no));

	if (a == NULL){
		return 1;
    }
	return 0;
}
int vazia_pil(t_pilha *P) {

	if (P->topo == NULL){
		return 1;
    }
	return 0;

}

void destruir_pil(t_pilha *P) {
    while (!vazia_pil(P)) {
        t_apontador a = P->topo;
        P->topo = P->topo->prox_p;
        free(a);
    }
    P->count = 0;
}