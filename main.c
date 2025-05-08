#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int carregamento_do_jogo(Estado_Do_Jogo *jogo){  //int que ira retornar como 1 como sucesso ou 0 como erro
	FILE *f = fopen("Salvamento.bin", "rb");   //abre o arquivo de salvamento que esta salvo em binario
	if(f != NULL){   //verifica se o arquivo foi aberto 
		fread(jogo, sizeof(Estado_Do_Jogo), 1, f); //le a struct Estado_Do_Jogo a partir do arquivo f e os salva no endereço jogo e restaura oque ja foi salvo
		fclose(f); //fecha o arquivo
		return 1;  //se for sucesso e 1
	}
	return 0;  //se for erro e 0
}

int main(){
    system("pause");
    return 0;
}