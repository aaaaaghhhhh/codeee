#include"stdio.h"

int full_div(int a, int b, int array[]);

int main()
{
    while (1)
    {
        int a, b, array[2];
        
        printf("Enter a: ");
        scanf("%d", &a);
        if (a == -1)
        {
            return 0;
        }
        
        printf("Enter b: ");
        scanf("%d", &b);
        if (b == 0)
        	printf("Impossible.\n");
        else
        {
			full_div(a, b, array);
			printf("Quotient %d\n", array[0]);
            printf("Remainder %d\n", array[1]);
        }
    }
    return 0;
}

int full_div(int a, int b, int array[])
{
    array[0] = a / b;
    array[1] = a % b;
    return 0;
}
