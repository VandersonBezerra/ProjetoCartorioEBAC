#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocaçãode espaço de memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro()
{
	
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    
    printf("CPF para cadastro: ");
    scanf("%s", cpf);
    
    strcpy(arquivo, cpf); //responsável por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo
	fprintf(file,cpf); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //"a" de atualização
	fprintf(file,",");
	fclose(file);
	
	printf("Nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("CPF a ser consultado:");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //"r" de read/ler
	
	if(file == NULL)
	{
		printf("Consulta não localizada! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nInformações do usuário! ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar()
{
	char cpf[40];
	
	printf("CPF a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Usuário não encontrado!\n");
		system("pause");
    }
	

}



int main()
{
    int opcao=0; //Definindo variáveis
    int x=1; //variável laço
   
    for(x=1;x=1;)
    {
	  
	  system("cls"); //Responsável por limpar a tela
	  
      setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
      
	  printf("Registro da EBAC\n\n"); //Início do menu
	  printf("Escolha a opção desejada no menu:\n\n");
	  printf("\t1 - Registrar nomes\n");
	  printf("\t2 - Consultar nomes\n");
	  printf("\t3 - Deletar nomes\n\n"); 
	  printf("Opção:"); //Fim do menu

      scanf("%d", &opcao); //Armazenando a escolha do usuário
    
      system("cls");
      
      
      switch(opcao) //iníicio da seleção
      {
      	case 1:
      	registro();
   	    break;
    	
		case 2:
    	consulta();
        break;
			
		case 3:
      	deletar();
   	    break;   
   	    
		default:
		printf("Essa opção não está disponível\n");
		system("pause");
		break;
		  
    	    
	  }
    

    }

} 

	
	
		
	


