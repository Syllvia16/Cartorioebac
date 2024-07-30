#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//inicio cria��o de vari�veis/string
     char arquivo[40];
     char cpf[40];
     char nome[40];
     char sobrenome[40];
     char cargo [40];
	 //final cria��o das vari�veis/string
	 
	 printf("Digite o CPF a ser cadastrado:"); //coletando informa��o do usu�rio
     scanf("%s", cpf);//%s refere-se a string
     
     strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
     
     FILE *file; //criar o arquivo 
     file = fopen(arquivo, "w"); // cria o arquivo e o "W" significa escrever
     fprintf(file,cpf); //salva o valor da variavel
     fclose(file); // fecha o arquivo
     
     
     file = fopen(arquivo, "a"); // cria o arquivo
     fprintf(file,","); // cria a ","
     fclose(file); // fecha o arquivo
     
     
     printf("Digite o nome a ser cadastrado:"); //coletando informa��o do usu�rio
     scanf("%s", nome);//%s refere-se a string
     
     file = fopen(arquivo, "a");// cria o arquivo
     fprintf(file, nome); //salva o valor da variavel
     fclose(file); // fecha o arquivo
     
     file = fopen(arquivo, "a");// cria o arquivo
     fprintf(file,","); //cria a ","
     fclose(file);// fecha o arquivo
     
     printf("Digite o sobrenome a ser cadastrado:");//coletando informa��o do usu�rio
     scanf("%s", sobrenome);//%s refere-se a string
     
     file = fopen(arquivo, "a"); // cria o arquivo
     fprintf(file,sobrenome); //salva o valor da variavel
     fclose(file);// fecha o arquivo
     
     file = fopen(arquivo, "a");// cria o arquivo
     fprintf(file,",");// cria a ","
     fclose(file);// fecha o arquivo
     
     printf("Digite o cargo a ser dacastrado:");//coletando informa��o do usu�rio
     scanf("%s", cargo);//%s refere-se a string
     
     file = fopen(arquivo, "a");// cria o arquivo
     fprintf(file,cargo); //salva o valor da variavel
     fclose(file);// fecha o arquivo
     
     system("pause"); //respons�vel por pausar a janela, para que o usu�rio posso ler
     
     
     
}

int consulta()//fun��o respons�vel por consultar os usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese");//Definindo a linguagem
	
	//inicio cria��o de vari�veis/string
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado:");//coletando informa��o do usu�rio
	scanf("%s",cpf);//%s refere-se a string
	
	FILE *file;//criar o arquivo
	file = fopen(cpf,"r");// respons�vel por l� o arquivo
	
	if(file== NULL)// respons�vel por abrir o arquivo ou se n�o foi poss�vel
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!.\n");
	}

    while(fgets(conteudo, 200, file) != NULL)
    {
    	printf("\nEssas s�o as informa��es do usu�rio:");
    	printf("%s", conteudo);
    	printf("\n\n");
    	
	}
    
      system("pause");  //respons�vel por pausar a janela, para que o usu�rio posso ler  
}

int deletar()// respons�vel por deletar os usu�rios do sistema
{
	//inicio cria��o de vari�veis/string
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");//coletando informa��o do usu�rio 
	scanf("%s",cpf);//%s refere-se a string
	
	remove(cpf); //deleta o arquivo
	
	FILE *file; //criar o arquivo
	file = fopen(cpf,"r");// respons�vel por l� o arquivo
	
	if(file== NULL) // respons�vel por abrir o arquivo ou se n�o foi poss�vel
	{
		printf("O usu�rio foi deletado com sucesso!\n");
		system("pause"); //respons�vel por pausar a janela, para que o usu�rio posso ler
	}
}
int main()
{
       int opcao=0;//Definindo variaveis
       int laco=1;
       
       for(laco=1;laco=1;)
	{
	
	   system("cls"); //respons�vel por limpar a tela
	   
	   setlocale(LC_ALL, "Portuguese");//Definindo a linguagem
	
	   printf("### Cart�rio da EBAC ###\n\n"); //inicio do menu
	   printf("Escolha a op��o desejada do  Menu:\n\n ");
	   printf("\t1 - Registrar Nomes\n ");
	   printf("\t2 - Consultar  Nomes\n");
	   printf("\t3-  Deletar Nomes\n");
	   printf("\t4-  Sair do sistema\n");
       printf("Op��o:");//fim do menu
       
    
    scanf("%d", &opcao); //armazenando a escolha do usu�rio
    
    system("cls"); //respons�vel por limpar a tela
    
    
	switch(opcao) //inicio da sele��o
{
	    case 1:
		registro(); //chamada de fun��es
		break;
		
	     case 2:
	     consulta(); //chamada de fun��es
		 break;
			
	    case 3:
		deletar(); //chamada de fun��es
		break;
		
		case 4:
		printf("Obrigado por utilizar o sistema!\n");
		return 0;
		break;	
		
		
		default:
			printf("Essa op��o n�o esta dispon�vel!\n");
			system("pause");
			break;
	} // fim da sele��o
}

}

