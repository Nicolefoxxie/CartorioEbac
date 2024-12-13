#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//inicio cria��o de variaveis/string
	char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    char data[8];
    char telefone[13];
    //final da cria��o de variaveis/string
    
    printf("Digite o seu CPF: "); //coletando informa��o do usu�rio
    scanf("%s", cpf); //%s refere-se a string
    
    strcpy(arquivo, cpf); // Responsavel por copiar os valores das string
    
    FILE *file; //Chamando um arquivo
    file = fopen(arquivo, "w"); // cria arquivos e o "w" significa escrever
    fprintf(file,cpf); //salvo valor da variavel
    fclose(file); // fecho arquivo
    
    file = fopen(arquivo, "a"); //Chamando um arquivo
    fprintf(file, ",");// adicionando pontos
    fclose(file); //fecho arquivo
    
    printf ("digite seu nome : "); //Conversa com usu�rio
    scanf("%s",nome);//%s refere-se a string
    
    file = fopen(arquivo, "a");//Chamando um arquivo
    fprintf(file,nome); //salvo valor da variavel
    fclose(file);// fecho arquivo
     
    file = fopen(arquivo, "a");//Chamando um arquivo
    fprintf(file,",");// adicionando pontos
    fclose(file);// fecho arquivo

    
    printf("digite o seu sobrenome: ");//Conversa com usu�rio
    scanf("%s",sobrenome);//%s refere-se a string
    
    file = fopen(arquivo, "a");//Chamando um arquivo
    fprintf(file,sobrenome);//salvo valor da variavel
    fclose(file);// fecho arquivo
    
     file = fopen(arquivo, "a");//Chamando um arquivo
    fprintf(file,",");// adicionando pontos
    fclose(file);// fecho arquivo
    
     printf ("digite sua Data de Nascimento : "); //Conversa com usu�rio
     scanf("%s",data);//%s refere-se a string
    
     file = fopen(arquivo, "a");//Chamando um arquivo
     fprintf(file,data); //salvo valor da variavel
       fclose(file);// fecho arquivo
     
    file = fopen(arquivo, "a");//Chamando um arquivo
    fprintf(file,",");// adicionando pontos
    fclose(file);// fecho arquivo
     
      printf ("digite seu Telefone: "); //Conversa com usu�rio
    scanf("%s",telefone);//%s refere-se a string
    
    file = fopen(arquivo, "a");//Chamando um arquivo
    fprintf(file,telefone); //salvo valor da variavel
    fclose(file);// fecho arquivo
     
    file = fopen(arquivo, "a");//Chamando um arquivo
    fprintf(file,",");// adicionando pontos
    fclose(file);// fecho arquivo
    
    printf("digite seu cargo na Ebac:" );//Conversa com usu�rio
    scanf("%s",cargo);//%s refere-se a string
    
    file = fopen(arquivo, "a");//Chamando um arquivo
    fprintf(file,cargo);//salvo valor da variavel
    fclose(file);// fecho arquivo
    
    
    system("cls");	//responsavel por limpar
    printf("\tUsuario cadastrado com sucesso!\n\n" );//Conversa com usu�rio
    system("pause");//pausar nessa tela
    system("cls");	//responsavel por limpar
    
}


int consulta() //Fun��o respons�vel por consultar os usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	//inicio cria��o de variaveis/string
	char cpf[40];
	char conteudo[200];
	//final da cria��o de variaveis/string
	
	printf("digite o cpf a ser consultado: "); //Conversa com usu�rio
	scanf("%s",cpf); //%s refere-se a string
	
	FILE *file; //Chamando um arquivo
	file = fopen(cpf,"r"); // procurando a variavel nos arquivos

    
	
	if(file == NULL) //Caso n�o ache:
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!. \n"); //envie essa mensagem ao usu�rio
        system("pause");//pausar nessa tela
	}
	
	while(fgets(conteudo, 200, file) != NULL) //caso encontre:
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");//conversa com usu�rio
		printf("%s", conteudo); //mostrar variavel encontrada
		printf("\n\n");//pular 
		system("pause");//pausar nessa tela
		
		system("cls");//responsavel por limpar
		printf("\nFim da consulta\n\n");//conversa com usu�rio
		system("pause");//pausar nessa tela	
	}
		
}

int deletar()//Fun��o respons�vel por deletar os usu�rios no sistema
{
     char cpf[40];
     
     printf("Digite o CPF do Usu�rio a ser deletado: ");
     scanf("%s",cpf);
     
     remove(cpf);
     
     FILE *file;
     file = fopen(cpf,"r");
     
     if(file == NULL)
     {
     	printf("Usu�rio n�o encontrado\n\n");
     	system("pause");
	 }
     system("cls");	//responsavel por limpar
}

int main()
{
	
	
		
	int opcao=0; //Definindo vari�veis
	int laco=1;
	char senhadigitada[]="a";
	int comparacao;
	
    
    printf("### Cart�rio da EBAC ###\n\n");
    printf("Login de adminstrador!\n\nDigite sua senha: ");
    scanf("%s",senhadigitada);
  
    comparacao = strcmp(senhadigitada, "amor");
 
     if ( comparacao == 0)
     {
   	
   	      system("cls");	//responsavel por limpar
    	  for(laco=1;laco=1;)
        {
    	     setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem

    	     printf("### Cart�rio da EBAC ###\n\n"); //inicio do menu
    	     printf("escolha a op��o desejada do menu:\n\n");
    	     printf("\t1 - Registrar nomes\n");
    	     printf("\t2 - Consultar nomes\n");	
    	     printf("\t3 - Deletar nomes\n"); 
    	     printf("\t4 - Sair do sistema\n\n");
    	     printf("Op��o: "); //fim do menu
   
             scanf("%d", &opcao); //armazenando a escolha de usu�rio
       
   
             system("cls");//responsavel por limpar
   
                switch(opcao) //inicio do sele��o do menu
               {
        	    case 1:
                registro(); //chamada de fun��es
                break;//finalizar Comando/fechar
        
                 case 2:
                 consulta(); //chamada de fun��es
                 break;//finalizar Comando/fechar
        
                 case 3:
         	     deletar(); //chamada de fun��es
                 break;//finalizar Comando/fechar
       
	             case 4:
	             printf("Obrigado por utilizar o sistema!\n" );//conversa com usu�rio
	             return 0;
     	         break;//finalizar Comando/fechar
      
     	        
			     default:  //Caso n�o ache:
                 printf("Essa op��o n�o est� disponivel\n" );//conversa com usu�rio
                 system("pause");//pausar nessa tela
	             break; //finalizar Comando/fechar
      	        } 
		  }
   	
   }
    else
        printf("\tSenha incorreta!\n\n");
}  
    
    
