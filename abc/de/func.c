//-------------------------------- example 1 ----------------------------------
//#include <stdio.h>
//#include <stdlib.h>
//
//int my_max(int a, int b);
//
//int main(int argc, char *argv[])
//{
//	if(argc == 3)
//	{
//		printf("Max value between %s and %s is: ", argv[1], argv[2]);
//		printf("%d\n", my_max(atoi(argv[1]), atoi(argv[2])));
//	}
//	else
//	{
//		printf("Please enter two numbers\n");
//	}
//	
//	return 0;
//}
//
//int my_max(int a, int b)
//{
//	if(a > b)
//	{
//		return a;
//	}
//	else
//	{
//		return b;
//	}
//}


//-------------------------------- example 2 ----------------------------------
//#include <stdio.h>
//
//int avg(float a, float b);
//
//int main(void)
//{
//	printf("Outside function: %f\n\n", avg(4.9, 2.0));
//	printf("Outside function: %d\n", avg(4.9, 2.0));
//	
//	return 0;
//}
//
//int avg(float a, float b)
//{
//	printf("Inside function: %f\n", (a/b));
//	return (a/b);
//	// NOTE: the difference in output from both inside and outside of the function
//}


//-------------------------------- example 3 ----------------------------------
/*#include <stdio.h>
#include <stdlib.h>

int odd(int a);

int main(int argc, char *argv[])
{
	if(argc == 2)
	{
		printf("The number you've entered is %s, and %s is an ", 
			argv[1], argv[1]);
		switch(odd(atoi(argv[1])))
		{
			case 1:
				printf("odd number.\n");
				break;
			case 0:
				printf("even number.\n");
				break;
			default:
				printf("This is impossible!!\n");
				break;
		}
		
	}	
	else
	{
		printf("Please enter one number\n");
	}
	
	return 0;
}

int odd(int a)
{
	if((a % 2) != 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}*/


//-------------------------------- example 4 ----------------------------------
/*#include <stdio.h>
#include <stdlib.h>

void odd(int a);

int main(int argc, char *argv[])
{
	if(argc == 2)
	{
		printf("The number you've entered is %s, and %s is an ", 
			argv[1], argv[1]);
		odd(atoi(argv[1]));		
	}
	else
	{
		printf("Please enter one number\n");
	}
	
	return 0;
}

void odd(int a)
{	
	if((a % 2) != 0)
	{
		printf("odd number.\n");
	}
	else
	{
		printf("even number.\n");
	}
	// NOTE: example 4 is very similar to example 3 except that example 3 use
	//       switch statement to print outside of function odd
}*/


//-------------------------------- example 5 ----------------------------------
/*#include <stdio.h>
#include <stdlib.h>

void odd(int a);

int main(int argc, char *argv[])
{
	if(argc == 2)
	{
		printf("The number you've entered is %s, and %s is an ", 
			argv[1], argv[1]);
		odd(atoi(argv[1]));		
	}
	else
	{
		printf("Please enter one number\n");
	}
	
	return 0;
}

void odd(int a)
{	
	int isOdd = 0;

	if((a % 2) != 0)
	{
		isOdd = 1;
	}
	else
	{
		isOdd = 0;
	}
	
	switch(isOdd)
		{
			case 1:
				printf("odd number.\n");
				break;
			case 0:
				printf("even number.\n");
				break;
			default:
				printf("This is impossible!!\n");
				break;
		}
	// NOTE: example 4 is very similar to example 5 except that example 5 use
	//       switch statement to print 
}*/


//-------------------------------- example 6 ----------------------------------
//#include <stdio.h>
//#include <stdlib.h>
//
//int max(int a, int b);
//
//int main(int argc, char *argv[])
//{
//	if(argc == 3)
//	{		
//		int m = max(atoi(argv[1]), atoi(argv[2]));
//		printf("Max value between %s and %s is: ", argv[1], argv[2]);
//		printf("%d\n", m);
//		// NOTE: argv[1] and argv[2] is the same as was entered by the user
//	}	
//	else
//	{
//		printf("Please enter two numbers\n");
//	}
//	
//	printf("argv[1] is %s, and argv[2] is %s\n", argv[1], argv[2]);
//	
//	return 0;
//}
//
//int max(int a, int b)
//{
//	if(a > b)
//	{
//		printf("a is %d, and b is %d\n", a, b);
//		a = 11;
//		b = 12;
//		printf("a is %d, and b is %d\n", a, b);
//		return a;
//	}
//	else
//	{
//		printf("a is %d, and b is %d\n", a, b);
//		a = 13;
//		b = 14;
//		printf("a is %d, and b is %d\n", a, b);
//		return b;
//	}
//	// NOTE: see pass by reference in example 9
//}


//-------------------------------- example 7 ----------------------------------
/*#include <stdio.h>
#include <stdlib.h>

int max(int a, int b);

int main(void)
{
	int x = 3;
	int y = 4;
	int m = max(x, y);	
	printf("Between %d and %d, max is %d\n", x, y, m);
	
	return 0;
}

int max(int a, int b)
{	
	if(a > b)
	{
		printf("a is %d, and b is %d\n", a, b);
		a = 1;
		b = 2;
		printf("a is %d, and b is %d\n", a, b);
		return a;
	}
	else
	{
		printf("a is %d, and b is %d\n", a, b);
		a = 5;
		b = 6;
		printf("a is %d, and b is %d\n", a, b);
		return b;
	}
	// NOTE: example 6 is very similar to example 7, except that example 7 
	//       does not use argc and argv
}*/


//-------------------------------- example 8 ----------------------------------
/*#include <stdio.h>

int max(int *a, int *b);

int main(void)
{
	int x = 3;
	int y = 4;
	int m = max(&x, &y);	
	printf("Between %d and %d, max is %d\n", x, y, m);
	
	return 0;
}

int max(int *a, int *b)
{	
	if(*a > *b)
	{
		// NOTE: dereference the pointer to compare the value, not the memory address
		printf("a is %d, and b is %d\n", *a, *b);
		*a = 1;
		*b = 2;
		printf("a is %d, and b is %d\n", *a, *b);
		return *a;
	}
	else
	{
		printf("a is %d, and b is %d\n", *a, *b);
		*a = 5;
		*b = 6;
		printf("a is %d, and b is %d\n", *a, *b);
		return *b;
	}
	// NOTE: example 7 is very similar to example 8, except that example 8 
	//       a and b are passed by reference
}*/


//-------------------------------- example 9 ----------------------------------
/*#include <stdio.h>
#include <stdlib.h>

int max(char *a, char *b);

int main(int argc, char *argv[])
{
	if(argc == 3)
	{		
		int m = max(&argv[1][0], &argv[2][0]);
		printf("Max value between %s and %s is: ", argv[1], argv[2]);
		printf("%d\n", m);
	}
	else
	{
		printf("Please enter two numbers\n");
	}
	
	printf("argv[1] is %s, and argv[2] is %s\n", argv[1], argv[2]);
	
	return 0;
}

int max(char *a, char *b)
{
	int ai = atoi(a);
	int bi = atoi(b);
	
	if(ai > bi)
	{
		printf("a is %s, and b is %s\n", a, b);
		*a = '1';
		*b = '2';
		printf("a is %s, and b is %s\n", a, b);
		return ai;
	}
	else
	{
		printf("a is %s, and b is %s\n", a, b);
		*a = '4';
		*b = '5';
		printf("a is %s, and b is %s\n", a, b);
		return bi;
	}
	
	// NOTE: example 6 is very similar to example 9, except that example 9 
	//       is passed by reference
}*/


//-------------------------------- example 10 ----------------------------------
/*#include <stdio.h>

int add(int a);

int main(void)
{
	int b = 2;
	printf("b = %d, return value from add() is %d\n", b, add(b));
	
	return 0;
}

int add(int a)
{	
	return (++a);
}*/


//-------------------------------- example 11 ----------------------------------
/*#include <stdio.h>

int add(int *a);

int main(void)
{
	int b = 2;
	printf("b = %d, return value from add() is %d\n", b, add(&b));
	// NOTE: comma is left associative
	
	return 0;
}

int add(int *a)
{	
	return (++(*a));
}*/


