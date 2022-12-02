#include <stdio.h>
#include <stdlib.h>

typedef struct No{
  int num;
  struct No*next;
}No;

typedef struct{
  No*head;
  No*last;
}Lista;

void add(Lista*lista, int valor){
  No* elemento = malloc(sizeof(No));
  elemento->num = valor;
  elemento->next = lista->head;
  lista->head = elemento;
}

void add_final(Lista*lista, int valor){
  No*aux, *elemento = malloc(sizeof(No));
  elemento->num = valor;
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

remover(Lista*lista, int valor){
  No*aux,*remover = NULL;
  if(lista->head){
    if((lista->head)->num == valor){
      remover = lista->head;
      lista->head = remover->next;
    }else{
      aux = lista->head;
      while(aux->next && (aux->next)->num != valor)
        aux = aux->next;
      if(aux->next){
        remover = aux->next;
        aux->next = remover->next;
      }
    }
  }

  return remover;
}

void show(Lista*lista){
  No*elemento = lista->head;
  while(elemento){
    printf("%d\n", elemento->num);
    elemento = elemento->next;
  }
}

int main(void){
  Lista lista;
  lista.head = NULL;
  add(&lista, 60);
  add_final(&lista, 25);
  add(&lista, 30);
  add_final(&lista, 35);
  //add_meio(&lista,41,60);
  add(&lista, 20);
  add_final(&lista, 95);
  add(&lista, 90);
  add_final(&lista, 45);
  add(&lista, 70);
  add_final(&lista, 35);
  add(&lista, 420);
  add(&lista, 10);
  remover(&lista, 70);
  
  show(&lista);
  return 0;
}