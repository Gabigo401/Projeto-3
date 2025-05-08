#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void Salvamento_Estado_Do_Jogo(Estado_Do_Jogo jogo){ //recebe a struct estado de jogo
	FILE *f = fopen("Salvamento.bin", "wb");   //cria um arquivo em binario para escrever nele
	if (f != NULL){   //verifica se o arquivo foi aberto ou não
		fwrite(&jogo, sizeof(Estado_Do_Jogo), 1, f);  //escreve no arquivo e o fwrite escreve no arquivo usando o endereço de 'jogo' e o 1 mostra que so 1 bloco e salvado
		fclose(f);  //fecha o arquivo e mostra se foi um sucesso
		printf("O Jogo foi salvo com sucesso\n");
	}else {
		printf("Erro ao salva o jogo\n");   //mostra se o arquivo não abriu
	}
}


int main(){
    system("pause");
    return 0;
}