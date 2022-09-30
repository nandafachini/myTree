#define MAX 50
#define INVALIDO -1

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int TIPOCHAVE;

typedef struct {
    TIPOCHAVE chave;
} REGISTRO;


typedef struct {
    REGISTRO reg;
    int prox;
} ELEMENTO;

typedef struct {
    ELEMENTO A[MAX];
    int inicio;
    int dispo;
} LISTA;




void inicializarLista(LISTA* l) {      //meu arranjo pre definido

    int i;
    for(i = 0; i < MAX - 1; i++){
        l-> A[i].prox = i + 1;         // pegar cada elemento da minha lista e dizer que o próximo está disponível
    l-> A[MAX-1].prox = INVALIDO;      // meu útimo elemento não aponta para nenhum próximo elemento
    l-> inicio = INVALIDO;             // meu primeiro elemento não aponta para nenum próximo elemento pois estamos apenas inicializando
    l-> dispo=0;                       // apontar para zero pois todos os elementos estão disponíveis, começando do indice 0
    }
}

int tamanho(LISTA* l) {                // precisamos saber quantos elementos válidos temos na lista
    int i = l->inicio;
    int tam = 0;

    while(i != INVALIDO) {             // quanto meu i for diferente de 0, ou seja, enquando for diferente de inválido. 
        tam++;                         // aumentamos o tamanho
        i = l->A[i].prox;              // seguimos apontando para o próximo
    }

    return tam;
}

void exibirLista(LISTA* l) {           // agora vamos imprimir os elementos disponíveis
    int i = l-> inicio;

    printf("Lista \" ");

    while(i != INVALIDO) {              // enquanto meu elemento for válido
    printf("%i ", l->A[i].reg.chave);  // imprime a chave do elemento da posição i
    i = l->A[i].prox;                  // seguimos apontando para o próximo

    }
    printf("\"\n");
}

int buscaSequencialOrd(LISTA* l, TIPOCHAVE ch) {    // minha lista está ordenada por índices, busco a chave de valor ch
    int i = l->inicio;
    
    while(i != INVALIDO && l-> A[i].reg.chave < ch) // enquanto o meu ir for válido, e a minha chave for menor do que o elemento que estou buscando 
        i = l->A[i].prox;                           // seguimos apontando para o próximo, ou seja continuo buscando
    if( i != INVALIDO && l->A[i].reg.chave == ch)   // se o elemento tiver o indice igual à chave que procuramos
    return i;
}

// vamos inserir no lugar do primeiro que estiver disponível na lista de disponíveis e tirar ele da lista de disponíveis
// então primeiro vamos retirar o primeiro elemento disponível da lista de disponíveis e retornar a sua posição 

int obterNo(LISTA* l) {                             // obter um elemento que estava na lista de disponíveis
    int resultado = l->dispo;                       // guardar a posição do primeiro elemento disponível
    
    if(l->dispo != INVALIDO)                        // se realmente existir um elemento disponível
        l->dispo = l->A[l->dispo].prox;                  // o primeiro disponível passa a ser o próximo disponível    
    return resultado;                               // guardamos o primeiro disponível em resultado
}


bool inserirEmListaOrd(LISTA* l, REGISTRO reg){
    if (l->dispo == INVALIDO) return false;         // se não tiver espaço disponível retornamos nossa função como false

    int ant = INVALIDO;                             // guardando a minha posição anterior
    int i = l->inicio;                              // guardando a minha posição incial
    TIPOCHAVE ch = reg.chave;                       // procurando a posição

    while ((i != INVALIDO) && (l->A[i].reg.chave < ch)){ // enquanto ainda não achei minha posição
        ant = i;                                        // anterior recebe o atual
        i = l->A[i].prox;                                // atual recebe o próximo
    }

    if (i != INVALIDO && l->A[i].reg.chave == ch) return false; //se a posição do elemento for válida e a chave for igual a chave buscada, significa que o item que quero inserir já está na minha lista
    
    i = obterNo(l);                                     // caso contrário vamos inserir
    l->A[i].reg = reg;                                  // inserimos nosso registro

    if(ant == INVALIDO) {                               // ver se o elemento que está sendo inserido tem um anterior
        l->A[i].prox = l->inicio;                       // o próximo do item que vamos inserir vai ser o primeiro, ou seja, colocamos o nosso elemento no primeiro indice
        l->inicio = i;                                  //e agora o meu inicio vai ser o i
    } else {                                            // se não tiver um anterior
        l->A[i].prox = l->A[ant].prox;                  // vai apontar para o próximo do anterior dele
        l->A[ant].prox = i;                             // e o anterior dele tem que apontar para ele
    }
    return true;
}

// para excluir um elemento seguimos a mesma lógica de inserir um elemento
// vemos se o elemento realmente existe, se existir nós excluímos e agora inserimos na lista de disponíveis
// acertar o ponteiro, então quem apontava para o item que foi exclído, agora tem que apontar para o próximo dele


// é mais fácil inserir no primeiro indice
void devolverNo(LISTA* l, int j) {                      // devolver um espaço para a lista de disponíveis
    l->A[j].prox = l->dispo;                            // o elemento que tá sendo inserido vai ter como próximo quem era o primeiro elemento
    l->dispo = j;                                       // e o meu primeiro elemento agora vai ser o elemento que está sendo inserido
}


bool excluirElemLista(LISTA* l, TIPOCHAVE ch) {
    int ant = INVALIDO;                                 // guardando a minha posição anterior
    int i = l->inicio;                                  // guardando a minha posição incial

    while ((i != INVALIDO) && (l->A[i].reg.chave < ch)){ // enquanto ainda não achei minha posição
        ant = i;                                         // anterior recebe o atual
        i = l->A[i].prox;                                // atual recebe o próximo
    }

    if (i==INVALIDO || l->A[i].reg.chave != ch) return false;   // se o item já for inválido, ou seja, não existir ou se a chave não for igual a chave que estamos procurando, não dá para excluir
    if(ant == INVALIDO) {                                   // ver se o elemento que está sendo inserido tem um anterior
    l->inicio = l->A[i].prox;                               // o início vai apontar para o próximo agora
    } else {

     l->A[i].prox = l->A[i].prox;                       // se ele tiver anterior, o anterior vai apontar para o próximo dele
    devolverNo(l,i);                                        // devolvemos para a nossa lista de disponíveis
    return true;
    
}

void reinicializarLista(LISTA* l); {
    inicializarLista(l);
}


