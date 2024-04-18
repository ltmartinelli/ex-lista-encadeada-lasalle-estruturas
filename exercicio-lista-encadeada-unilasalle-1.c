#include<stdlib.h>
#include<stdio.h>

//Define a estrutura da Lista Encadeada (Define como sera cada elemento/Nodo da lista)
typedef struct No{
   int idade; //Dados da lista
   struct No *prox; //Ponteiro para o proximo elemento da lista
} No;

////////////////////////
//FUNCAO DO EXERCÍCIO //
////////////////////////

//Funcao que remove elemento em uma posicao da lista

No * remove_elemento(No * lista, int posicao){

  No * aux = lista;
  int cont = 1;

  if (lista == NULL){
     return lista;
  } else if (posicao == 1){
    lista = aux-> prox;
    free(aux);
  }

  while(aux->prox!= NULL && cont < (posicao-1)){
    aux = aux->prox;
    cont++;
  }

  No * no_a_deletar = aux->prox;  
  aux->prox = no_a_deletar->prox;
  free(no_a_deletar);

  return lista;
}


//Funcao que cria um elemento
//Retorna um ponteiro para o elemento criado
No * cria_elemento(int idade){
  No *novo;
  novo = (No *) malloc(sizeof(No));
  novo->idade = idade;
  novo->prox  = NULL;
  return novo;
}


//Funcao para inserir um elemento na primeira posicao da lista
No * insere_primeiro(No * lista, No * novo){
   novo->prox = lista;
   return novo;
}



//Insere o novo elemento na ultima posicao da lista
No * insere_ultimo(No * lista, No * novo){
  if (lista != NULL) {
      No * aux = lista;
      while (aux->prox != NULL){
        aux = aux->prox;
      }
      aux->prox = novo;
      return lista;
  }else{   
     return novo;
  }
}


void apresenta_lista(No * lista){
  //Percorrendo os elementos da lista
   int cont = 0;
   if (lista != NULL){
     printf("|");
     while (lista != NULL){
       printf("%d|", lista->idade);
       lista = lista->prox;
     }
     printf("\n");
   }
}


No * inserir_elemento_na_posicao(No * lista, No * novo, int posicao){

  No * aux = lista;
  int cont = 1;

  if (lista == NULL){
     return novo;
  }

  while(aux->prox!= NULL && cont < (posicao-1)){
    aux = aux->prox;
    cont++;
  }

  novo->prox = aux->prox;
  aux->prox = novo;

  if (posicao == 1){
      return novo;
  }else{
     return lista;
  }
}



 int main() {

   //No de referencia - Inicio da Lista
   No * lista = NULL;

   //Cria elementos para inserir na lista
   No *n = cria_elemento(35);
   No *n2 = cria_elemento(50);
   No *n3 = cria_elemento(30);
   No *n4 = cria_elemento(55);
   No *n5 = cria_elemento(3);

   lista = insere_ultimo(lista, n);
   lista = insere_ultimo(lista, n2);
   lista = insere_primeiro(lista, n3);
   lista = insere_ultimo(lista, n4);
   lista = inserir_elemento_na_posicao(lista, n5, 3);
   // Apresenta a lista pronta
   apresenta_lista(lista);
   system("PAUSE");

   ///////////////////////////////////////////
   //-------DEMONSTRAÇÃO DO EXERCÍCIO-------//
   ///////////////////////////////////////////


    //Removendo o elemento na posição 3
   printf("Removendo o elemento na posicao 3 \n");
   lista = remove_elemento(lista,3);
   //Apresenta a lista com o elemento na posicao 3 removido
   apresenta_lista(lista);

  system("PAUSE");

   //Removendo o elemento na posição 1
   printf("Removendo o elemento na posicao 1 \n");
   lista = remove_elemento(lista,1);
   //Apresenta a lista com o elemento na posicao 1 removido
   apresenta_lista(lista);
  
}