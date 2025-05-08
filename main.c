#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct{   //struct criada para salvar o estado que o jogo se encontrar
	char palavra_secreta[100];   //char para o numero maximo de letrar para a palavra secreta
	char palavra_usuario[100];   //char para o numero max para a palavra usuario
	int tentativas_restantes;   //int para as tentativas do usuario
	int acertos;   //int para os acertor
}Estado_Do_Jogo;   //salva tudo com o nome 'Estado_Do_Jogo"

int main(){
    system("pause");
    return 0;
}