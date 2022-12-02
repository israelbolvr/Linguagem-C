#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


typedef struct node{
  char nome[50];
  struct node*next;
}node;

typedef struct{
  node*head;
  node*last;
}Lista;

void add(Lista*lista, char*c){
  node*elemento = malloc(sizeof(node));
  strcpy(elemento->nome, c);
  elemento->next = lista->head;
  lista->head = elemento;
}

void add_final(Lista*lista, char*c){
  node*aux,*elemento = malloc(sizeof(node));
  strcpy(elemento->nome, c);
  elemento->next = NULL;
  if(lista->head == NULL){
    lista->head = elemento;
  }else{
    aux = lista->head;
    while(aux->next)
      aux = aux->next;
    aux->next = elemento;
  }
}

void add_meio(Lista*lista, int valor, int previous){
  No*aux ,*elemento = malloc(sizeof(No));
  elemento->num = valor;
  if(lista->head == NULL){
    elemento->next = NULL;
    lista->head = elemento;
  }else{
    aux = lista->head;
    while(aux->num != previous && aux->next)
      aux = aux->next;
    elemento->next = aux->next;
    aux->next = elemento;
  }
}


void inserir_ordenado(Lista*lista, char*c){
  node*aux, *elemento = malloc(sizeof(node));
  strcpy(elemento->nome,c);
  if(lista->head == NULL){
    elemento->next = NULL;
    lista->head = elemento;
  }else if(strcmp(elemento->nome, (lista->head)->nome) < 0){
    elemento->next = lista->head;
    lista->head = elemento;
  }else{
    aux = lista->head;
    while(aux->next && strcmp(elemento->nome, (aux->next)->nome) > 0)
      aux = aux->next;
    elemento->next = aux->next;
    aux->next = elemento;
  }
} 

 void remover(Lista*lista, char*c){
  node*elemento = lista->head;
  node*aux = NULL;
  bool verify = false;
  while(!verify && elemento!=NULL){
    if(strcmp(c, elemento->nome) == 0){
      verify = true;
    }else{
      aux = elemento;
      elemento = elemento->next;
    }
  }
  if(verify){
    if(elemento == lista->head){
      lista->head = elemento->next;
    }else if(elemento->next == NULL){
      aux->next = NULL;
      lista->last = aux;
    }else{
      aux->next = elemento->next;
    }
    free(elemento);
  }else{
    printf("Elemento nao foi encontrado.");
  }
}

void print(Lista*lista){
  node*elemento = lista->head;
  while(elemento){
    printf("%s\n", elemento->nome);
    elemento = elemento->next;
  }
}

int main(void) {
  Lista lista;
  lista.head = NULL;
  /* add(&lista, "humnertop");
  add_final(&lista, "joao");
  add(&lista, "julia");
  add_final(&lista, "ribeiro");
  add(&lista, "rael");
  add_final(&lista, "santos");
  add(&lista, "elmer");
  add_final(&lista, "sena");
  add(&lista, "ze");
  remover(&lista, "rael");   */
  inserir_ordenado(&lista, "humnertop");
  inserir_ordenado(&lista, "joao");
  inserir_ordenado(&lista, "julia");
  inserir_ordenado(&lista, "ribeiro");
  inserir_ordenado(&lista, "rael");
  inserir_ordenado(&lista, "santos");
  inserir_ordenado(&lista, "elmer");
  remover(&lista, "ribeiro");
  
  print(&lista);
  return 0;
}








