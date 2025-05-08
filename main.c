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
    srand(time(NULL));   //inicio o gerador de numeros aleatorios
    int indice_aleatorio = rand() % contador;  //escolhe um indice aleatorio entre 0 e o contador -1
    Estado_Do_Jogo novo_jogo;   //cria uma variavel novo_jogo a partir da do Estado_Do_Jogo
    strcpy(novo_jogo.palavra_secreta, lista[indice_aleatorio]);  //copia a palavra aleatorio escolhida da lista do arquivo e armazena na variavel palavra_secreta
    int tamanho = strlen(novo_jogo.palavra_secreta);  //usado para calcular o numero de letras que esta armazenado no palavra_secreta
    novo_jogo.tentativas_restantes = tentativas_maximas;    //inicia o numero de tentativas permitidas e ela so diminui se a pessoa errar uma letra
    novo_jogo.acertos = 0;  //inicio o contador de acertos
    int i;

    if(i = 0; i < tamanho; i++){   //usa a variavel i para percorrer a string palavra_usuario
        novo_jogo.palavra_usuario[i] = '-';  //preence a string palavra_usuario com '-' em todas as posições para mostrar que nenhuma letra foi descoberta ainda
    }
    novo_jogo.palavra_usuario[tamanho] = '\0';  //adiciona o \0 para finalizar a string
    Jogando_Forca(novo_jogo);  //chama a função Jogando_Forca passando o novo_jogo preenchido e executando o jogo apos isso
}

int main(){
    system("pause");
    return 0;
}