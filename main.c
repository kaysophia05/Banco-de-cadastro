#include <stdio.h>
//Declaração da estruturas de dados contendo os 5 atributos
typedef struct {
  int code;
  char nome[50];
  char turno;
  float salario;
  float hora_diaria;
} identificacao;

int main(void) {
  //Declaração de variáveis
  identificacao fucionario[5]; //variável vetor do tipo struct para armazenar cinco funcionários do supermercado
  int code_busca;

  //Declaração das funções a serem utilizadas
  //As funções foram criadas abaixo da função principal "main", por isso o motivo da declaração das mesmas;
  void cadastro(identificacao vet[], int t); 
  void busca_fucionario(identificacao vet[],int t, int code);

  printf("\t\t\t\t\tCADASTRO DE FUCIONÁRIOS\n");
  //Chamada da Função Cadastro, para cadastrar os 5 fucionários do supermecado
  cadastro(fucionario,5);

  printf("\n\n\t\tPESQUISA DE REGISTRO");
  //Entrada de dados pelo usuario para pesquisa dos atributos
  printf("\nDigite o Codigo do Fucionário que Deseja Pesquisar: ");
  scanf("%d",&code_busca);

  //Chamada da função busca fucionário, para retornar o resultado da pesquisa dos atributos
  busca_fucionario(fucionario,5,code_busca); 
  return 0;
}

//Função para buscar os dados do/dos fucionários, recebendo como parametro um vetor do tipo struct, o tamanho do vetor e o codigo de busca 
void busca_fucionario(identificacao vet[],int t, int code){
	int i;
	for(i=0;i<t;i++){
		if(code==vet[i].code){
      printf("\n\tFucionario Encontrado!! ");
      printf("\nCodigo De Registro: %d",vet[i].code);
			printf("\nNome: %s",vet[i].nome);
			printf("Salario: %2.f",vet[i].salario);
      printf("\nTurno de Atuação: %c",vet[i].turno);
      printf("\nHoras Diarias de Atuação: %2.f",vet[i].hora_diaria);
		} 
	}
    //if para comparar todos valores do vetor, usando a logica do E
    //se todos forem diferentes imprimi a mensagem de nao encontrado. 
    //Caso ache mais de um fucionario com mesmo codigo, irá imprimir também.
    if(code != vet[0].code && code != vet[1].code && code != vet[2].code && code != vet[3].code && code != vet[4].code && code != vet[5].code){
      printf("\n\nRegistro Não Encontrado!!");
    }
}

  //Função de cadastro para armazenar os dados de cadastro dos fucionários, recebendo como parametro um vetor do tipo struct, o tamanho do vetor 
void cadastro(identificacao vet[], int t){
	int i,id;
  //variável alxiliar (id) para identificar o codigo do usuário que está sendo cadastrado

  //Laçao de percorre o vetor struct   para leitura
	for(i=0;i<t;i++){
  printf("\n(%d) Digite o codigo de verificacao: ",i+1);
  scanf("%d",&vet[i].code);
    id = i; // (id) recebe o valor do índice do último elemento do vetor de funcionários,
  getchar(); //Função para limpar o buffer do teclado, evitando  problemas em leituras seguintes
  
  printf("\n\tCadastro Fucionário: %d \n\n",vet[id].code);
  printf("Digite primeiro e ultimo nome: ");
  fgets(vet[i].nome,50,stdin);
    //leitura de uma string
  
  
  printf("Identifique o turno de trabalho  \n(m)Manhã\t(t)Tarde\t(n)Noite:   ");
  scanf("%c",&vet[i].turno);

    
  printf("Digite o Salario: ");
  scanf("%f",&vet[i].salario);
  
  printf("Digite as Horas De Trabalho Diárias: ");
  scanf("%f",&vet[i].hora_diaria);

  printf("\n\nFucionário (%d) Cadastrado !!\n",vet[id].code);
	}
}
