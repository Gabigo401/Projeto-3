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

int carregamento_do_jogo(Estado_Do_Jogo *jogo){  //int que ira retornar como 1 como sucesso ou 0 como erro
	FILE *f = fopen("Salvamento.bin", "rb");   //abre o arquivo de salvamento que esta salvo em binario
	if(f != NULL){   //verifica se o arquivo foi aberto 
		fread(jogo, sizeof(Estado_Do_Jogo), 1, f); //le a struct Estado_Do_Jogo a partir do arquivo f e os salva no endereço jogo e restaura oque ja foi salvo
		fclose(f); //fecha o arquivo
		return 1;  //se for sucesso e 1
	}
	return 0;  //se for erro e 0
}

void registrar_log(const char *mensagem) {  //função para salvar todas as ações do usuario e recebe um char constante mensagem
    FILE *log = fopen("log.txt", "a");   //abre ou cria um txt chamado log  e o ponteiro e usado para manipular o arquivo
    if (log != NULL) {   //if para verificar se o arquivo foi aberto
        fprintf(log, "%s\n", mensagem);  //escreve no arquivo a mensagem
        fclose(log);  //fecha o arquivo
    }

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
        if(strlen(tentativa) > 1){   //if para ler se a palavra digitada tiver mais de 1 caractere e se tiver ela e reconhecida como tentativa de acertar a palavra inteira
            if(strcmp(tentativa, jogo.palavra_secreta) == 0){   //se a tentativa for igual a palavra escolhida aparece a mensagem de vitoria
                printf("\nParabens Voce acertou a palavra: %s\n", jogo.palavra_secreta);   //mostra a palavra para comprovar que voce acertou
                registrar_log("Acertou a palavra completa");    //armazenar no log que ffoi acertada uma palavra
                return;
            } else {
                printf("Palavra incorreta!\n");   //se  a palavra que foi chutada esta incorreta aparece essa parte e mostra que voce errou
                registrar_log("Errou a palavra completa");  //registra no log que a palavra que o usuario digitou esta incorreta
                jogo.tentativas_restantes--;  //diminui uma tentativa do contador e volta  pro while
                continue;
            }
        }else {  //else usado  para mostrar que se  o caractere for so uma letra essa parte e iniciada
            letra = tentativa[0]; //salva o caractere em letra
            int acertou = 0;  //cria o int acertou para verificar  se a letra aparece na palavra
            for (i = 0; i < tamanho; i++) {  //usa o i para percorrer a palavra secreta
                if (jogo.palavra_secreta[i] == letra && jogo.palavra_usuario[i] == '_') {  //if para verificar se o caractere  esta presente na palavra secreta e se for descoberta substitui o '-' pelo caractere
                    jogo.palavra_usuario[i] = letra;
                    jogo.acertos++;  //incremento de acertos
                    acertou = 1;
                }
            }
            if (!acertou) {  //se a variavel acertou ainda estiver 0 significa que o caractere estava incorreto
                printf("Letra incorreta!\n");   //fala pro usuario que esta errada
                jogo.tentativas_restantes--;   //diminui o numero de tentativas restantes
            }
        }
    }
    if (jogo.tentativas_restantes == 0) {   //se o numero de tentativas chegar a zero o jogo e encerrado com uma mensagem de derrota e  mostra a palavra secreta
        printf("\nVocê perdeu! A palavra era: %s\n", jogo.palavra_secreta);  
    } else if (jogo.acertos == tamanho) {  //se aa variavel acertor for igual ao tamanho da palavra mostra que o usuario acertou a palavra secrete e da os parabens ao jogador
        printf("\nParabéns! Você acertou a palavra: %s\n", jogo.palavra_secreta);
    }
}
 
  void Tentativas_E_TamanhoMaximo(int *tentativas_maximas, int *tamanho_maximo_palavra){ //função para determinar o tamanho maximo da palavras e as tentativas
    *tentativas_maximas = 10;  //valor de 10 para as tentativas
    *tamanho_maximo_palavra = 100;   //valor de 100 para o tamanho da palavra
 }

int main(){
    system("pause");
    return 0;
}