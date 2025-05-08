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

    int tentativas_maximas, tamanho_maximo_palavra;  //int para duas variaveis que e as tentativas maximas e o tamanho maximo
    Tentativas_E_TamanhoMaximo(&tentativas_maximas, &tamanho_maximo_palavra);  //chama a função que declara o tamanho delas ja na função e usa ponteiro nelas
	
	if (escolha == 1) {  //verifica se  o usuario escolheu jogo novo
        escolha_De_Palavra(tentativas_maximas, tamanho_maximo_palavra);  //se for jogo novo chamar a função para escolher uma palavra do arquivo txt e inicia o jogo
    } else if (escolha == 2) {  //se a escolha for 2
        Estado_Do_Jogo jogo;   //declara uma variavel estaddo de jogo chamado jogo para armazenar  o estado carregado do arquivo
        if (carregamento_do_jogo(&jogo)) {  //carrega o arquivo bin aonde foi salvo alguma partida anterior
            printf("Jogo carregado com sucesso!\n");
            Jogando_Forca(jogo);  //começa o jogo da onde o ultimo parou
        } else {
            printf("Nenhum jogo salvo encontrado.\n");  //aparece isso se nada foi salvo no arquivo
        }
    } else {
        printf("Saindo do programa.\n"); //se for 0 o jogo e fechado 
    }
    system("pause");
    return 0;
}