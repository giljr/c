#include <stdio.h>
int sum(int n);

int main() {
    int number, result;

    printf("Enter a positive integer: ");
    scanf("%d", &number);

    result = sum(number);

    printf("sum = %d", result);
    return 0;
}

int sum(int n) {
	printf("inside sum() n = %d\n", n);
    if (n != 0)
    {
	
        // sum() function calls itself        
        return n + sum(n-1); 
    }
    else 
	{
		printf("inside sum() else n = %d\n", n);
        return n;
	}
        
}
