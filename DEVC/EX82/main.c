#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int numero;
	int linha, coluna, profundidade;
	int MATRIX3D[linha][coluna][profundidade];
	
	for(int i = 0; i < linha; i++)
	{
		for(int j = 0; j < coluna; j ++)
		{
			for(int k = 0; k < profundidade; k ++)
			{
				MATRIX3D[i][j][k] = scanf("%d", numero);
			}
		}
	}
	return 0;
}
