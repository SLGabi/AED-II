#include <stdio.h>
#include <stdlib.h>

void menu(int grafo[20][20]);

int main(){
    int grafo[20][20];

    for(int i=0; i<20; i++){ 
        for(int j=0; j<20; j++){
            grafo[i][j] = 0; //zerando inicialmente
        }
    }

    menu(grafo);
}

void menu(int grafo[20][20]){
    int escolha, escolha1, escolha2, opcao, x, y, peso;
    do{
        printf("O que deseja fazer?\n");
        printf("<1>Adicionar uma aresta entre dois vertices\n");
        printf("<2>Listar grafo\n");
        printf("<3>Sair\n");
        scanf("%d", &escolha);

        //switch case pra escolher os casos
        switch(escolha){
            case 1:
            printf("Qual o numero do primeiro vertice? Lembre-se, os vertices vao de 0 até 19\n"); //escolhendo o primeiro vertice
            scanf("%d", &x);
            while(x<0 || x>19) {
                printf("Digite um numero entre 0 e 19\n");
                scanf("%d",&x);
            }

            printf("Deseja inserir entre o próximo ou o anterior? <1>Anterior; <2>Próximo\n"); //há duas opções, inserir na aresta com o proximo ou com o anterior
            scanf("%d", &opcao);
            while(opcao<1 || opcao>2) {
                printf("Deseja inserir entre o próximo ou o anterior? <1>Proximo; <2>Anterior\n");
                scanf("%d",&opcao);
            }

            if(opcao==1){
                if(x != 0)
                    y = x - 1; //se x for diferente de 0, é possível existir a aresta entre o vértice x e o vertice anterior, senao, não é possível, pois o vertice x será o primeiro
                else{
                    printf("a primeira aresta já é o primeiro vertice. Tente novamente\n");
                    break;
                }
            }

            else{
                if(x != 19)
                    y = x + 1; //se x for diferente de 19, é possível existir a aresta entre o vértice x e o vertice posterior, senao, não é possível, pois o vertice x será o ultimo
                else{
                    printf("a primeira aresta já é o ultimo vertice. Tente novamente\n");
                    break;
                }
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
            grafo[y][x] = peso;
            break;

            
            //--CASO 2--
            case 2:
            printf("<1>Listar em matriz; <2>Listar em lista; <3>Peso de uma aresta especifica\n");
            scanf("%d", &escolha2);

            if(escolha2 == 1){ //listando em matriz
                for(int i = 0; i<20; i++){
                    for(int j = 0; j < 20; j++) {
                        printf("|%d|",grafo[i][j]);
                    }
                    printf("\n");
                }
            }

            else if(escolha2 == 2){ //listando em lista
                for(int i = 0; i<20; i++){
                    for(int j = 0; j < 20; j++) {
                        printf("vertice %d e vertice %d: %d\n",i, j, grafo[i][j]);
                    }
                }
            }

            else{ //listando específico
                printf("Qual o numero do primeiro vertice? Lembre-se, os vertices vao de 0 até 19\n"); //escolhendo o primeiro vertice
                scanf("%d", &x);
                while(x<0 || x>19) {
                    printf("Digite um numero entre 0 e 19\n");
                    scanf("%d",&x);
                }

                printf("Deseja inserir entre o próximo ou o anterior? <1>Anterior; <2>Próximo\n"); //há duas opções, inserir na aresta com o proximo ou com o anterior
                scanf("%d", &opcao);
                while(opcao<1 || opcao>2) {
                    printf("Deseja inserir entre o próximo ou o anterior? <1>Proximo; <2>Anterior\n");
                    scanf("%d",&opcao);
                }

                if(opcao==1){
                    if(x != 0)
                        y = x - 1; //se x for diferente de 0, é possível existir a aresta entre o vértice x e o vertice anterior, senao, não é possível, pois o vertice x será o primeiro
                    else{
                        printf("a primeira aresta já é o primeiro vertice. Tente novamente\n");
                        break;
                    }
                }

                else{
                    if(x != 19)
                        y = x + 1; //se x for diferente de 19, é possível existir a aresta entre o vértice x e o vertice posterior, senao, não é possível, pois o vertice x será o ultimo
                    else{
                        printf("a primeira aresta já é o ultimo vertice. Tente novamente\n");
                        break;
                        
                    }
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
