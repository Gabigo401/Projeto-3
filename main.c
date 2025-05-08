#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void Jogando_Forca(Estado_Do_Jogo jogo){ //função para iniciar o jogo e ela recebe a estrutura  do tipo Estado_Do_Jogo que e todas as informações  do estado atual do jogo
    int tamanho = strlen(jogo.palavra_secreta);  //calcula o tamanho da palavra secreta e ela fica armazenada no int tamanho 
    char tentativa[100];  //char que vai armazenar oque o usuario digitar, que pode ser uma letra ou palavra 
    int i;   //int que vai ser usado nos loops
    char letra;  // char para guardar a letra que o usuario digitou

    while(jogo.tentativas_restantes > 0 && jogo.acertos < tamanho){  //while que faz o jogo continuar enquanto o jogador tem tentativas restantes e não acertou a palavra
        printf("\nPalavra: %s\n", jogo.palavra_usuario);   //mostra ao jogador a quantidade de espaços que tem a palavra usando o '-' e mostra a quantidade de tentativas restantes
        printf("Tentativas restantes: %d\n", jogo.tentativas_restantes);
        printf("Digite uma letra (ou digite 1 para salvar o jogo e sair): ");  //pede ao usuario uma letra ou se ele quer salvar o jogo e sair
        scanf("%s", tentativa);  //salva a escolha do jogador na variavel tentativa
        while(getchar() != '\n'); //usei para limpar o buffer  de entrada

        registrar_log(tentativa);   //chama a função 'registrar_log' e salva no log.txt

        if(strcmp(tentativa, '1') == 0){   //se o jogador escolher a opção de salvar o jogo ele e salvo chamando a função criada para salvar o jogo 
            Salvamento_Estado_Do_Jogo(jogo);
            return;   //apos o salvamento o jogo e terminado 
        }
    }
}

int main(){
    system("pause");
    return 0;
}