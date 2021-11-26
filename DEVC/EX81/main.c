#include <stdio.h>
#include <stdlib.h>

/* This is part of my assessment of Programming Language Course 
Output:
---------------------------------------
Entre com um string: Prova

Veja o que foi armazenado: Prova
--------------------------------------
Date: - 30/07/2021 
Author: J3
*/

int main(int argc, char *argv[]) {
	
	char str1[100], str2[100], str3[100];
	printf("Entre com um string: ");
	gets(str1);
	strcpy(str2, str1);
	strcpy(str3, "Veja o que foi armazenado: ");
	printf("\n%s%s", str3, str2);
	return 0;
}
