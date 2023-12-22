#include <stdio.h> //biblioteca de funções compiladas do usuario
#include <stdlib.h> //biblioteca de alocação de espaço em memoria
#include <locale.h> //biblioteca de alocação de texto por regiao acentos e outras coisas
#include  <string.h> //biblioteca responsavel pelas strings


int registro()
{
	setlocale(LC_ALL, "portuguese");
	
	char arquivo[400];
	char cpf[40];
	char nome[40];
	char sobrenome[100];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: \n");
	scanf("%s",cpf);
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores da strings
	
	FILE *file; //cria um arquivo
	file = fopen(arquivo, "w"); // cria um arquivo  o W serve pra escrever o arquivo
	fprintf(file,cpf); //vai escrever o cpf no arquivo
	fclose(file); //encerra a variavel fecha o arquivo
	
	file = fopen(arquivo, "a"); //o A atualiza o arquivo
	fprintf(file,","); //aqui eu atualizei colocando uma virgula depois do cpf
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: \n");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: \n");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: \n");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ".");
	fclose(file);
	
	system("pause");
	
	
}

int consulta()


{
	setlocale(LC_ALL, "portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); // o R é de read de ler
	
	if(file == NULL)
	{
		printf("Arquivo nao localizado.\n");
	}
	 while(fgets(conteudo, 200, file) != NULL) //enquanto a busca na variavel "conteudo" ate 200 valores que esta dentro do arquivo enquanto tiver informação la
	 {
	 	printf("\nEssas são as informações do usuário: ");
	 	printf("%s", conteudo);
	 	printf("\n\n");
	 	
	 }
	 
	 system("pause");


}

int deletar()
{
	setlocale(LC_ALL, "portuguese");
	
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf); //%s é salvar de string
	
		remove(cpf);
	
		FILE *file;
		file = fopen(cpf,"r");
		

		
		if(file == NULL)
	{
		printf("\nO usuário não se encontra no sisitem!.\n");
		system("pause");
		
	}	
	
		if(file != NULL) //!= significa diferente de 
	{
		
		printf("\n Usuário deletado!.\n");
		system("pause");
	
	}

	
		
	
}

int main()
	{
	int opcao=0;
	int laco=1;
	char senhadigitada[]="a";
	int comparacao;
	
		printf("### Cartório da EBAC ###\n\n");
		printf("Login de Adiministrador! \n\nDigite a sua senha: ");
		scanf("%s",senhadigitada);
		
		comparacao = strcmp(senhadigitada, "admin");
		
		if (comparacao == 0)
		{
			system("cls");//limpa a tela
			
		
	
			for(laco=1;laco=1;) //usado para fazer repetiçoes
			{
	
			system("cls");
			
			setlocale(LC_ALL, "portuguese"); //isso mostra que pode ter acento pq a locale.h permite o uso regional o LC_ALL mostra de qual região pegar os acentos de texto
		
			printf("### Cartório da EBAC ###\n\n");
			printf("Escolha a opção desejada do menu: \n\n");
			printf("\t1 - Registrar nomes \n");
			printf("\t2 - Consultar nomes \n");
			printf("\t3 - Deletar nomes \n");// \t da o espaço de um TAB
			printf("\t4 - Sair do Sistema \n\n");
			printf("Opção: ");
	
			scanf("%d", &opcao); //usa o %d para verificar com o usuario qual opção selecionou
	
			system("cls"); //limpa a tela depois do uso
		
			switch(opcao) // switch case é parecido com o if e mais limpo
			{
				case 1:
				registro();		//chama as funções
				break;
				
				case 2:
				consulta();	
				break;
						
				case 3:
				deletar();
				break;
				
				case 4:
				printf("Obrigado por utilizar o sistem! \n");
				return 0;
				break;
						
				default:
				printf("Operação inexistente\n");
				system("pause");
				break;
			}
		}
		
		
	}
	else
			printf("Senha incorreta!!!");
}	
