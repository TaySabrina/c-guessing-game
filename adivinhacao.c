#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

    //imprime o cabeçalho do jogo.
    
    printf(" _   |~  _                                \n");                     
    printf("[_]--'--[_]         Bem Vindo ao          \n");                    
    printf("|'|""`""|'|         Jogo da Adivinhacao!  \n");                    
    printf("| | /^\\ | |                              \n");                    
    printf("|_|_|I|_|_|                               \n");                    
    printf("\n\n");

    int segundos = time(0);
    srand(segundos);
    int numerogrande = rand();

    int numerosecreto = numerogrande % 100; 
    int chute;
    int tentativas = 1;
    double pontos = 1000;

    int acertou = 0;

    int nivel;
    printf("Qual o nivel de dificuldade? \n");
    printf("(1) Facil (2) Medio (3) Dificil\n\n");
    printf("Escolha: ");
    scanf("%d", &nivel);

    int numerotentativas;

    switch (nivel)
    {
        case 1:
            numerotentativas = 20;
            break;

        case 2:
            numerotentativas = 15;
            break;

        default:
            numerotentativas = 6;
            break;
    }

    for(int i = 1; i <= numerotentativas; i++)
    {
        printf("Tentativa %d\n", tentativas);
        printf("Qual e o seu chute? \n");
        scanf("%d", &chute);
        printf("Seu chute foi %d.\n", chute);

        if(chute <0){
            printf("Voce nao pode chutar numeros negativos.\n");
            continue;
        }

        int acertou = (chute == numerosecreto);
        int menor = (chute < numerosecreto);

        if(acertou)
        {
            break;
        }
        
        else if(menor)
        {
            printf("Seu chute foi menor que o Numero Secreto.\n");
            printf("Mas nao desanime, tente de novo!\n");
        }
        else
        {
            printf("Seu chute foi maior que o Numero Secreto.\n");
        }
        tentativas = tentativas + 1;
        double pontosperdidos = abs(chute - numerosecreto) / (double)2;
        pontos = pontos - pontosperdidos;
  
    }
    printf("Fim de jogo!\n"); 
    if(acertou){
        printf("Você ganhou!!\n");
        printf("Voce acertou em %d tentativas.\n", tentativas);
        printf("Total de pontos: %.1f\n", pontos);
    }
    else{
        printf("Voce perdeu! Tente de novo!\n");
    }
    
    
}