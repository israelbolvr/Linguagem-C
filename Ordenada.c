#include <stdio.h>
#include <string.h>
typedef struct node{
    char name[100];
    struct node*next;
}node;

void add(node**list, char*key){
    node*element = malloc(sizeof(node));
    node*previous = NULL; 
    strcpy(element->name, key);
    node*aux = *list;
    if(*list == NULL){
        element->next = NULL;
        *list = element;

    }else if(strcmp((*list)->name, key) > 0){
        element->next = *list;
        *list = element;
    }
    else{
        while(aux != NULL && strcmp(aux->name, key) < 0){
            previous = aux;
            aux = aux->next;
        }   
        previous->next = element;
        element->next = aux;
    }
}

void print(node**list){
    node*element = *list;
    while(element){
        printf("%s\n", element->name);
        element = element->next;
    }
}

int main(){
    node*list = NULL; //inicio da lista
    //char key[100]; //chave a ser procurada
    //printf("Digite o nome:\n");
    //scanf("%s", &key); //nome digitado
    add(&list, "Julia");
    add(&list, "humberto");
    add(&list, "israel");
    add(&list, "ze");
    add(&list, "Jullia");
    print(&list);
    return 0; 
}