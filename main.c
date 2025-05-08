#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void registrar_log(const char *mensagem) {  //função para salvar todas as ações do usuario e recebe um char constante mensagem
    FILE *log = fopen("log.txt", "a");   //abre ou cria um txt chamado log  e o ponteiro e usado para manipular o arquivo
    if (log != NULL) {   //if para verificar se o arquivo foi aberto
        fprintf(log, "%s\n", mensagem);  //escreve no arquivo a mensagem
        fclose(log);  //fecha o arquivo
    }
}

int main(){
    system("pause");
    return 0;
}