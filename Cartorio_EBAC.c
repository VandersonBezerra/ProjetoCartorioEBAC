#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��ode espa�o de mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro()
{
	
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    
    printf("CPF para cadastro: ");
    scanf("%s", cpf);
    
    strcpy(arquivo, cpf); //respons�vel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo
	fprintf(file,cpf); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //"a" de atualiza��o
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
		printf("Consulta n�o localizada! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nInforma��es do usu�rio! ");
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
		printf("Usu�rio n�o encontrado!\n");
		system("pause");
    }
	

}



int main()
{
    int opcao=0; //Definindo vari�veis
    int x=1; //vari�vel la�o
   
    for(x=1;x=1;)
    {
	  
	  system("cls"); //Respons�vel por limpar a tela
	  
      setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
      
	  printf("Registro da EBAC\n\n"); //In�cio do menu
	  printf("Escolha a op��o desejada no menu:\n\n");
	  printf("\t1 - Registrar nomes\n");
	  printf("\t2 - Consultar nomes\n");
	  printf("\t3 - Deletar nomes\n\n"); 
	  printf("Op��o:"); //Fim do menu

      scanf("%d", &opcao); //Armazenando a escolha do usu�rio
    
      system("cls");
      
      
      switch(opcao) //in�icio da sele��o
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
		printf("Essa op��o n�o est� dispon�vel\n");
		system("pause");
		break;
		  
    	    
	  }
    

    }

} 

	
	
		
	


