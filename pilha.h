#ifndef LISTA_H
#define LISTA_H

#define SUCESSO 1
#define NAO_EXISTE -1
#define JA_EXISTE -2
#define INVALIDO -3
#define CHEIA -4
#define VAZIA -5

typedef struct t_no *t_apontador;

typedef struct t_no {
	int elem_p;
	t_apontador prox_p;
} t_no;


typedef struct {
	t_apontador topo;
	int count;
} t_pilha;


int inicializar_pil(t_pilha *P);
int push(int e, t_pilha *P);
int pop(t_pilha *P);
int vazia_pil(t_pilha *P);
int cheia_pil(t_pilha *P);
int topo_pil(t_pilha *P);
int contar_pil(t_pilha *P);
void destruir_pil(t_pilha *P);

#endif