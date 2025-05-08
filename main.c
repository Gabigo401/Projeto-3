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

    char lista[100][100];  //char para armazenar ate 100 palavras
    int contador = 0;  //contador usado  para contar quantas palavras foram lidas do arquivo

    while(fgets(lista[contador], tamanho_maximo_palavra, arquivo)){    //laço de repetição usando o fgets para ler linha por linha  do arquivo e armazenar em lista[contador] e o 'tamanho_maximo_palavra e usado para colocar um limite do tamanho da linha
        lista[contador][strcspn(lista[contador], "\n")] = '\0';   //usei para remover o \n do final da palavra que foi lida que foi gerado por fgets, o strcspn e usado para encontrar a posição de \n e o substitui por \0 que seria o fim da string
        contador++;  //incrementa o contador apor cada palavra lida
    }
    fclose(arquivo);   //fecha o arquivo apos a leitura

    if(contador == 0){   //se o contador estiver 0 esse if e usado
        printf("O arquivo esta vazio");   //fala que o arquivo ta vazio
        return;
    }
}

int main(){
    system("pause");
    return 0;
}