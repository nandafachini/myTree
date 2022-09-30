
#include <stdio.h>
#include <stdbool.h>
#define MAX 50 

// typedef int bool;
typedef int TIPOCHAVE;

typedef struct {
    TIPOCHAVE chave;
} REGISTRO;

typedef struct {
    REGISTRO A[MAX];
    int inicio;             //inicio da fila
    int nroElem;            // numero de elementos da fila
} FILA;


void inicializarFila(FILA* f) {
    f->inicio = 0;                      // meu inicio é zero
    f->nroElem = 0;                     // numero de elementos também é zero, ou seja, fila vazia
}

int tamanhoFila(FILA* f) {
    return f->nroElem;
}

void exibirFila(FILA* f) { 
    printf("Fila \" ");
    int i = f->inicio;                   // i será o meu índice
    int temp;                            // variável auxiliar

    for(temp =0; temp < f-> nroElem; temp++) {  //vou passando pela quantidade de numero de elementos
        printf("%i ", f->A[i].chave);           // imprime a chave do elemento atual
        i = (i + 1) % MAX;                      // atualiza o i para o próximo elemento, se o i passar da quantidade de elementos não vai dar certo, então usa % MAX
    }

    printf("\"\n");
}

bool inserirElementoFila(FILA* f, REGISTRO reg) {
    
    if(f->nroElem >= MAX) return false;                 // ver se a fila está cheia
    
    int posicao = (f->inicio + f->nroElem) % MAX;       // sempre inserimos na primeira posição disponível
    
    f->A[posicao] = reg;                                // registro do usuário vai para a posição disponível
    f->nroElem++;                                        // numero de elementos aumentado
    
    return true;

}

// elemento do início da fila é excluído
bool excluirElementoFila(FILA* f, REGISTRO* reg) {
    
    if (f->nroElem == 0) return false;                    //ver se a minha lista está vazia
    
    *reg = f->A[f->inicio];                               // pegar o elemento que está no início, copiar o registro dele para endereço de memória passado pelo usuário
    f->inicio = (f->inicio+1) % MAX;                      // atualizar o valor do campo inicio
    f->nroElem--;
    
    return true;
}

void reinicializarFila(FILA* f){
    f->inicio = 0;
    f->nroElem = 0;
}
