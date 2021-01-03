/*
  Project 46 - Daniel's Resto - Classe e Sabor ao seu dispor!
  
  Descricao
  
  O restaurante "Daniel's Resto", tem sua sede em 
     
	 Belo Horizonte MG
     Rua Nobre, Pampulha, numero 100.
  
  Seu proprietario e conhecedor da mais legitima culinaria Mineira e e formado na Franca:
    
	Ecole DelMetre Paris Certificacao Internacional
  
  Para prova de conceito fora desenvolvido esse codigo executavel em Windows.
  
  O Usuario solicita seu pedido no console apos ser apresentado o Menu:
  
  Pratos da Casa:
   
   Tropeiro (Linguica Suina, Arroz, Feijao, Ovo, Cebola, Bacon, Farofa e Couve)
   Camarao (Camarao, Arroz, Molho de Tomate, Creme de Leite, Champignon, acompanha Batata Palha)
   Picanha (Picanha, Arroz, Caldo de Feijao, Palmito, Tomate, Alho, Cebola e Catupiry, acompanha Alho Frito)
   Peixe Top (File de Peixw, Arroz, Batata, Cenoura, Cheiro Verde, Azeite)
   Bolonhesa (Carne Bovina Moida, Espaguete, Molho de Yomate, e Cheiro Verde)
   Feijoada (Feijoada, Arroz e Couve Mineira, acompanha laranra em fatias deliciosa)
   Caipirinha (Bebida especialidade do Chef, servido estupidamente gelada e regada a Limao Capeta)
  
  Para escolher a combinacao, o usuario primeiro digita o codigo do produto
  depois tecla espaco
  e em seguida digita a quantidade do produto (veja exemplo na saida).
  
  Escolhido o combo, o usuario digita 'c' para pedir a conta.
  Em seguida a despesa e apresentada na tela.
  
  Este aplicativo roda no console.
  
  Caso queira testar, o codigo esta funcional e basta roda-lo em Dev-C++
  Link para baixar o programa:
  https://sourceforge.net/projects/orwelldevcpp/
  
  Segue Modelagem dos Objetos e Metodos:
  
  ItemPedido {
     cha[] descricao;
     double valor_unitario;
     int quantidade;
  }
  
  Pedido {
     List<ItemPedido> produto;
     
	 ItemPedido incluirItem(ItemPedido){};
     
	 double totalPedido(){};
  }
  
  p[1][7] - Preco de cada Produto
  q[7][1] - Quantidade pedida
  t[1][7] - Total a Pagar
  
  Entao, faca a matrix de multiplicacao:
  
  p[1][7]    *   q[7][1]       =  t[1][7]
   _      _                       _      _
  |  50.0 |                      |  50.0 |
  |  87.9 |                      |  87.9 |
  |  99.9 |  * [1,1,1,1,1,1,1] = |  99.9 |
  |  68.9 |                      |  68.9 |
  |  48.0 |                      |  48.0 |
  |  34.9 |                      |  34.9 |
  |_ 49.9_|                      |_ 49.9_|
  
                        Total =  $ 439.50         
 
********************************************
Saida: (Teste)


-------------------------------------
::::::::::::Daniel's Resto:::::::::::
--------------Bem Vindo--------------
-----------------MENU----------------
Cod     Produto         Preco
-------------------------------------
1       Tropeiro                50.00
2       Camarao                 87.90
3       Picanha                 99.90
4       Peixe Top               68.90
5       Bolonhesa               48.00
6       Feijoada                64.90
7       Caipirinha              49.90
-------------------------------------

        Por favor escolha seu Combo:)
        Digite:Cod>Espaco>Quant>Enter:
        Pedir Conta , Digite 'c':)
6 1
        Vc escolheu: 1 x Feijoada
7 1
        Vc escolheu: 1 x Caipirinha
c
        Boa Escolha!

        Aqui esta sua conta:

______________Despesas:_______________
Quant   Preco   Produto         Total
--------------------------------------
1 x     64.90   Feijoada        64.90
1 x     49.90   Caipirinha      49.90
---------------------------------------
                        Total = 114.80
--------------------------------------

        Obrigado pela visita
         Tenha um bom apetite!
********************************************
  Editor J3
  Date: Jan, 03/2021
  
*/
#include <stdio.h>

int main()
{
	int seq[1][7] = {1, 2, 3, 4, 5, 6, 7};
	int code[1][7] = {100, 101, 102, 103, 104, 105, 106};
	char menu[7][10] = { "Tropeiro ", "Camarao ", "Picanha ", "Peixe Top", "Bolonhesa", "Feijoada", "Caipirinha" };
	float p[1][7] = {50.0, 87.9, 99.9, 68.9, 48.0, 64.9, 49.9}, t[1][7] = {0}, debit;
	int q[7][1] = {0,0,0,0,0,0,0};
	int prows = 1, pcolumns = 7, qrows = 7, qcolumns = 1, trows = 1, tcolumns = 7;
	int i,j,k;
	float res = 0, sum = 0;
	int prod = 0;
    int quant = 0;
	
	/* Menu  splash */
	printf("\n-------------------------------------");
	printf("\n::::::::::::Daniel's Resto:::::::::::");	
	printf("\n--------------Bem Vindo--------------");	
	printf("\n-----------------MENU----------------\n");
  	printf("Cod\tProduto\t\tPreco\n");
  	printf("-------------------------------------\n");
  	
	for( i = 0; i < 1; i++)
  	{
  		for( j=0; j < 7; j++)
  		{
			printf("%i\t", seq[i][j]);
			printf("%s\t\t", menu[j] );
			printf("%.2f\t\t\n", p[i][j] );
		}
  		printf("-------------------------------------");	  		 	
	}
	printf("\n\n\tPor favor escolha seu Combo:)\n\tDigite:Cod>Espaco>Quant>Enter:\n");
	printf("\tPedir Conta , Digite 'c':)\n");
	scanf("%i %i", &prod, &quant);
	

	while(getchar()!= 'c')
	{
		switch (prod) 
	    {
	   	 case 1:
         		printf("\tVc escolheu: %d x Tropeiro\n", quant); 
		 		q[0][0] += quant;				
				break;

    	         case 2:
        		printf("\tVc escolheu: %d x Camarao\n", quant); 
				q[1][0] += quant;      	
        		break;

    	         case 3:
        		printf("\tVc escolheu: %d x Picanha\n", quant); 
				q[2][0] += quant;       	
        		break;
	
	   	 case 4:
        		printf("\tVc escolheu: %d x Peixe Top\n", quant);        	
        		q[3][0] += quant;	
				break;
        	
    	         case 5:
        		printf ("\tVc escolheu: %d x Bolonhesa\n", quant);
        		q[4][0] += quant;
        		break;
        	
    	         case 6:
        		printf ("\tVc escolheu: %d x Feijoada\n", quant);
        		q[5][0] += quant;
        		break;
        	
                 case 7:
        		printf ("\tVc escolheu: %d x Caipirinha\n", quant);
        		q[6][0] += quant;
        		break;
        	
    	         default:
		        printf("\tProduto Invalido:/\n");
				break;
             }
         
	     scanf("%i %i", &prod, &quant);     
	}

    printf("\tBoa Escolha!\n");	

    /* Calculando o total do debito */
    int m = 0;	
    for (i=0; i<prows; i++)
		{	
		    for(j=0; j<qcolumns; j++)
			{
				
				for(k=0; k<qrows; k++)
				{
					res += p[i][k] * q[k][j];
					t[i][m] = res;
					m++;
					sum += res;
					res = 0;
					
				}
				debit = sum;
				sum = 0;
		}
	}
    /* Emite o debito do cliente - Despesas */
    printf ("\n\tAqui esta sua conta:\n\n"); 
    printf("______________Despesas:_______________\n");
    printf("Quant\tPreco\tProduto\t\tTotal\n");
    printf("--------------------------------------\n");
    for( i=0; i<trows; i++ )
	{
		for(j=0; j<tcolumns; j++)
		{
			if( t[i][j] != 0)
			{
				printf("%d x\t", q[i][j]);
				printf("%.2f\t", p[i][j]);
				printf("%s\t", menu[j] );
				printf("%.2f\t\n", t[i][j]);
			}			

		}
		printf("---------------------------------------\n");
		printf("\t\t\tTotal = %.2f\t\t", debit);
		printf("\t\t\n--------------------------------------");
		printf("\t\t\n");
	}
    printf("\n\tObrigado pela visita\n\t Tenha um bom apetite!\n");
    return 0;
}

