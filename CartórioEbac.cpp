#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //Função responsável por cadastrar os usuários no sistema
{
	//inicio criação de variaveis/string
	char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    char data[8];
    char telefone[13];
    //final da criação de variaveis/string
    
    printf("Digite o seu CPF: "); //coletando informação do usuário
    scanf("%s", cpf); //%s refere-se a string
    
    strcpy(arquivo, cpf); // Responsavel por copiar os valores das string
    
    FILE *file; //Chamando um arquivo
    file = fopen(arquivo, "w"); // cria arquivos e o "w" significa escrever
    fprintf(file,cpf); //salvo valor da variavel
    fclose(file); // fecho arquivo
    
    file = fopen(arquivo, "a"); //Chamando um arquivo
    fprintf(file, ",");// adicionando pontos
    fclose(file); //fecho arquivo
    
    printf ("digite seu nome : "); //Conversa com usuário
    scanf("%s",nome);//%s refere-se a string
    
    file = fopen(arquivo, "a");//Chamando um arquivo
    fprintf(file,nome); //salvo valor da variavel
    fclose(file);// fecho arquivo
     
    file = fopen(arquivo, "a");//Chamando um arquivo
    fprintf(file,",");// adicionando pontos
    fclose(file);// fecho arquivo

    
    printf("digite o seu sobrenome: ");//Conversa com usuário
    scanf("%s",sobrenome);//%s refere-se a string
    
    file = fopen(arquivo, "a");//Chamando um arquivo
    fprintf(file,sobrenome);//salvo valor da variavel
    fclose(file);// fecho arquivo
    
     file = fopen(arquivo, "a");//Chamando um arquivo
    fprintf(file,",");// adicionando pontos
    fclose(file);// fecho arquivo
    
     printf ("digite sua Data de Nascimento : "); //Conversa com usuário
     scanf("%s",data);//%s refere-se a string
    
     file = fopen(arquivo, "a");//Chamando um arquivo
     fprintf(file,data); //salvo valor da variavel
       fclose(file);// fecho arquivo
     
    file = fopen(arquivo, "a");//Chamando um arquivo
    fprintf(file,",");// adicionando pontos
    fclose(file);// fecho arquivo
     
      printf ("digite seu Telefone: "); //Conversa com usuário
    scanf("%s",telefone);//%s refere-se a string
    
    file = fopen(arquivo, "a");//Chamando um arquivo
    fprintf(file,telefone); //salvo valor da variavel
    fclose(file);// fecho arquivo
     
    file = fopen(arquivo, "a");//Chamando um arquivo
    fprintf(file,",");// adicionando pontos
    fclose(file);// fecho arquivo
    
    printf("digite seu cargo na Ebac:" );//Conversa com usuário
    scanf("%s",cargo);//%s refere-se a string
    
    file = fopen(arquivo, "a");//Chamando um arquivo
    fprintf(file,cargo);//salvo valor da variavel
    fclose(file);// fecho arquivo
    
    
    system("cls");	//responsavel por limpar
    printf("\tUsuario cadastrado com sucesso!\n\n" );//Conversa com usuário
    system("pause");//pausar nessa tela
    system("cls");	//responsavel por limpar
    
}


int consulta() //Função responsável por consultar os usuários no sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	//inicio criação de variaveis/string
	char cpf[40];
	char conteudo[200];
	//final da criação de variaveis/string
	
	printf("digite o cpf a ser consultado: "); //Conversa com usuário
	scanf("%s",cpf); //%s refere-se a string
	
	FILE *file; //Chamando um arquivo
	file = fopen(cpf,"r"); // procurando a variavel nos arquivos

    
	
	if(file == NULL) //Caso não ache:
	{
		printf("Não foi possivel abrir o arquivo, não localizado!. \n"); //envie essa mensagem ao usuário
        system("pause");//pausar nessa tela
	}
	
	while(fgets(conteudo, 200, file) != NULL) //caso encontre:
	{
		printf("\nEssas são as informações do usuário: ");//conversa com usuário
		printf("%s", conteudo); //mostrar variavel encontrada
		printf("\n\n");//pular 
		system("pause");//pausar nessa tela
		
		system("cls");//responsavel por limpar
		printf("\nFim da consulta\n\n");//conversa com usuário
		system("pause");//pausar nessa tela	
	}
		
}

int deletar()//Função responsável por deletar os usuários no sistema
{
     char cpf[40];
     
     printf("Digite o CPF do Usuário a ser deletado: ");
     scanf("%s",cpf);
     
     remove(cpf);
     
     FILE *file;
     file = fopen(cpf,"r");
     
     if(file == NULL)
     {
     	printf("Usuário não encontrado\n\n");
     	system("pause");
	 }
     system("cls");	//responsavel por limpar
}

int main()
{
	
	
		
	int opcao=0; //Definindo variáveis
	int laco=1;
	char senhadigitada[]="a";
	int comparacao;
	
    
    printf("### Cartório da EBAC ###\n\n");
    printf("Login de adminstrador!\n\nDigite sua senha: ");
    scanf("%s",senhadigitada);
  
    comparacao = strcmp(senhadigitada, "amor");
 
     if ( comparacao == 0)
     {
   	
   	      system("cls");	//responsavel por limpar
    	  for(laco=1;laco=1;)
        {
    	     setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem

    	     printf("### Cartório da EBAC ###\n\n"); //inicio do menu
    	     printf("escolha a opção desejada do menu:\n\n");
    	     printf("\t1 - Registrar nomes\n");
    	     printf("\t2 - Consultar nomes\n");	
    	     printf("\t3 - Deletar nomes\n"); 
    	     printf("\t4 - Sair do sistema\n\n");
    	     printf("Opção: "); //fim do menu
   
             scanf("%d", &opcao); //armazenando a escolha de usuário
       
   
             system("cls");//responsavel por limpar
   
                switch(opcao) //inicio do seleção do menu
               {
        	    case 1:
                registro(); //chamada de funções
                break;//finalizar Comando/fechar
        
                 case 2:
                 consulta(); //chamada de funções
                 break;//finalizar Comando/fechar
        
                 case 3:
         	     deletar(); //chamada de funções
                 break;//finalizar Comando/fechar
       
	             case 4:
	             printf("Obrigado por utilizar o sistema!\n" );//conversa com usuário
	             return 0;
     	         break;//finalizar Comando/fechar
      
     	        
			     default:  //Caso não ache:
                 printf("Essa opção não está disponivel\n" );//conversa com usuário
                 system("pause");//pausar nessa tela
	             break; //finalizar Comando/fechar
      	        } 
		  }
   	
   }
    else
        printf("\tSenha incorreta!\n\n");
}  
    
    
