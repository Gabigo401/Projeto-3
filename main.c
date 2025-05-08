#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(){
    int escolha;    //int para armazenar uma escolha do usuario
	printf("Seja bem-vindo ao Jogo forca\n");   //mensagem de boas vindas
	printf("\nINSTRUÇÕES DO JOGO:\n");   //mensagem das instruções de como jogar
    printf("--------------------------------------------------\n");
    printf("Objetivo: Descubra a palavra secreta letra por letra.\n");   //o objetivo do jogo
    printf("Você tem um número limitado de tentativas.\n");
    printf("\nCOMANDOS:\n");
    printf("- Digite uma letra para tentar revelá-la na palavra.\n");   //os comando que o usuario pode usar
    printf("- Digite a palavra inteira se quiser tentar adivinhar de uma vez.\n");
    printf("- Digite '1' a qualquer momento para SALVAR o jogo e sair.\n");
    printf("\nDICAS:\n");
    printf("- Letras corretas são reveladas na posição certa.\n");   //dicas ddo jogo
    printf("- Letras erradas reduzem o número de tentativas restantes.\n");
    printf("- Se todas as letras forem descobertas ou você acertar a palavra, você vence!\n");
    printf("- Se acabar as tentativas, você perde.\n");
    printf("--------------------------------------------------\n\n");
    printf("1 - Novo jogo\n2 - Continuar jogo salvo\n0 - Sair\n");   //mostra as opções para o jogador entre um novo jogo, carregar um jogo salvo ou sair do programa
	scanf("%d", &escolha);   //le e salva a escolha do jogador no endereço de escolha

    system("pause");
    return 0;
}