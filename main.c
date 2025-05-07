#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void escolha_De_Palavra(int tentativas_maximas, int tamanho_maximo_palavra){
    FILE *arquivo = fopen("palavras.txt", "r");  //abrindo um arquivo txt com as palavras que vão ser escolhidas aleatoriamente para serem adivinhadas
    
    if(arquivo == NULL){   //if se o arquivo não for aberto
        printf("Falha ao abrir o arquivo");  //se o arquivo não for aberto aparece a mensagem falando que deu erro e voltando ao inicio do programa
        return;
    }
}

int main(){
    system("pause");
    return 0;
}