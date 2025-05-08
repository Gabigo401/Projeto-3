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