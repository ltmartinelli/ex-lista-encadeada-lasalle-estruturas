#include<stdlib.h>
#include<stdio.h>

//Define a estrutura da Lista Encadeada (Define como sera cada elemento/Nodo da lista)
typedef struct No{
   char *nome;
   int idade; 
   int matricula;
   struct No *prox; //Ponteiro para o proximo elemento da lista
} No;

////////////////////////
//FUNCAO DO EXERCÍCIO //
////////////////////////

//Funcao que imprime a media dos alunos

void apresenta_media(No * lista){
  //Percorrendo os elementos da lista
  int cont=0;
   float soma=0, resultado = 0;

   if (lista != NULL){
      while (lista != NULL){
       soma+= lista->idade;
       cont++;
       lista = lista->prox;
     }
     resultado = soma/cont;
     printf("Media de Idade: %.2f\n", resultado);
   }
}

//Funcao que cria um elemento
//Retorna um ponteiro para o elemento criado
No * cria_elemento(int idade, int matricula, char *nome){
  No *novo;
  novo = (No *) malloc(sizeof(No));
  novo->nome = nome;
  novo->matricula = matricula; 
  novo->idade = idade;
  novo->prox  = NULL;
  return novo;
}


//Funcao para inserir um elemento na primeira posicao da lista
No * insere_primeiro(No * lista, No * novo){
   novo->prox = lista;
   return novo;
}



void apresenta_lista(No * lista){
  //Percorrendo os elementos da lista
   if (lista != NULL){
     printf("Aluno|Matricula|Idade\n\n");
     while (lista != NULL){
       printf("%s|%d|%d\n", lista->nome, lista->matricula, lista->idade);
       lista = lista->prox;
     }
     printf("\n");
   }
}



 int main() {

   //No de referencia - Inicio da Lista
   No * lista = NULL;

   //Cria elementos para inserir na lista
   No *n1 = cria_elemento(26, 210139, "Lucas");
   No *n2 = cria_elemento(32, 109892, "Sarah");
   No *n3 = cria_elemento(28, 210132, "Jose");
   No *n4 = cria_elemento(21, 112032, "Carlos");
   No *n5 = cria_elemento(19,21399, "Matheus");

   lista = insere_primeiro(lista, n1);
   lista = insere_primeiro(lista, n2);
   lista = insere_primeiro(lista, n3);
   lista = insere_primeiro(lista, n4);
   lista = insere_primeiro(lista, n5);

   ////////////////////////////////////////////////
   ////////////DEMONSTRACAO DO EXERCICIO///////////
   ////////////////////////////////////////////////

   //Apresenta a lista de alunos e depois a média//
   apresenta_lista(lista);
   apresenta_media(lista);


}