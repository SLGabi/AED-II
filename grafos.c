#include <stdio.h>
#include <stdlib.h>

//void menu(int *grafo);

int main(){
    int tamanho; //o usuario escolhe o tamanho do grafo, até 20
    printf("Quantas vertices deseja ter?\n");
    scanf("%d", &tamanho);
    while(tamanho<=0 || tamanho>20){
        printf("Quantas vertices deseja ter?\n");
        scanf("%d", &tamanho);
    }

    int grafo[tamanho][tamanho], escolha, escolha1, escolha2, x, y, peso;

    for(int i=0; i<tamanho; i++){
        for(int j=0; j<tamanho; j++){
            grafo[i][j] = 0; //zerando as arestas inicialmente
        }
    }

    //--MENU--
    do{
        printf("O que deseja fazer?\n");
        printf("<1>Adicionar uma aresta\n");
        printf("<2>Listar grafo\n");
        printf("<3>Sair\n");
        scanf("%d", &escolha);

        //switch case pra escolher os casos
        switch(escolha){
            case 1:
            printf("Qual o numero do primeiro vertice? Lembre-se, os vertices vao de 0 ate o tamanho escolhido - 1\n"); //escolhendo o primeiro vertice
            scanf("%d", &x);
            while(x<0 || x>=tamanho) {
                printf("Qual o numero do primeiro vertice? Lembre-se, os vertices vao de 0 ate o tamanho escolhido - 1\n");
                scanf("%d",&x);
            }
            printf("Qual o numero do segundo vertice? Lembre-se, os vertices vao de 0 ate o tamanho escolhido - 1\n"); //escolhendo o segundo vertice
            scanf("%d", &y);
            while(y<0 || y>=tamanho) {
                printf("Qual o numero do segundo vertice? Lembre-se, os vertices vao de 0 ate o tamanho escolhido - 1\n");
                scanf("%d",&y);
            }

            if(grafo[x][y] != 0){
                printf("Ja existe um valor de aresta existente nessa posicao. Deseja sobrescrever? <1>Sim <2>Nao\n");
                scanf("%d", &escolha1);
                if(escolha1 == 2){
                    break;
                }
                
                
            }
            printf("Qual o peso da aresta?\n");
            scanf("%d",&peso); //sempre considerando valores positivos pro peso
            while(peso < 0){
                printf("Qual o peso da aresta?\n");
                scanf("%d",&peso);
            }
            grafo[x][y] = peso;
            break;

            
            //--CASO 2--
            case 2:
            printf("<1>Listar em matriz; <2>Listar em lista; <3>Peso de uma aresta especifica\n");
            scanf("%d", &escolha2);

            if(escolha2 == 1){ //listando em matriz
                for(int i = 0; i<tamanho; i++){
                    for(int j = 0; j < tamanho; j++) {
                        printf("|%d|",grafo[i][j]);
                    }
                    printf("\n");
                }
            }

            else if(escolha2 == 2){ //listando em lista
                for(int i = 0; i<tamanho; i++){
                    for(int j = 0; j < tamanho; j++) {
                        printf("vertice %d e vertice %d: %d\n",i, j, grafo[i][j]);
                    }
                }
            }

            else{ //listando específico
                printf("Qual o numero do primeiro vertice? Lembre-se, os vertices vao de 0 ate o tamanho escolhido - 1\n"); //escolhendo o primeiro vertice
                scanf("%d", &x);
                while(x<0 || x>=tamanho) {
                    printf("Qual o numero do primeiro vertice? Lembre-se, os vertices vao de 0 ate o tamanho escolhido - 1\n");
                    scanf("%d",&x);
                }

                printf("Qual o numero do segundo vertice? Lembre-se, os vertices vao de 0 ate o tamanho escolhido - 1\n"); //escolhendo o segundo vertice
                scanf("%d", &y);
                while(y<0 || y>=tamanho) {
                    printf("Qual o numero do segundo vertice? Lembre-se, os vertices vao de 0 ate o tamanho escolhido - 1\n");
                    scanf("%d",&y);
                }


                if(grafo[x][y]== 0) {
                    printf("Nao existe peso de arestas entre os vertices %d e %d\n", x, y);
                }
                else {
                    printf("o valor do peso da aresta entre os vertices %d e %d eh: %d\n",x, y, grafo[x][y]);
                }
            }
            break;  

            case 3:
            break;

            default:
            printf("Opcao invalida.\n");
            break;

        }
    }while(escolha!=3);
}

