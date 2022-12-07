//-------------------------------- example 1 ----------------------------------
#include <stdio.h>

int main(void)
{	
	int var = 0;
	int *ptr = NULL;

	var = 10;	
	ptr = &var;
	// NOTE: the difference between declaration and assignment of value for a pointer
	//      and a variable
	
	printf("Memory address of var is: %p\n", &var);
	printf("Memory address of ptr is: %p\n\n", &ptr);
	
	printf("Memory address of var is: %p\n\n", ptr);
	// NOTE: this value in ptr is the same as the address of var
	
	printf("The value of var is: %d\n", var);	
	printf("The value of var is: %d\n", *ptr);
	
	return 0;
}

//-------------------------------- example 2 ----------------------------------
/*#include <stdio.h>

int main(void)
{
	double *ptr, p;
	
	p = 0;
	ptr = &p;
	
	printf("Size of ptr is: %d\n", sizeof(ptr));
	printf("Size of p is: %d\n", sizeof(p));	
	// NOTE: the difference in size between pointer and the actual variable of 
	//       the same data type	
	
	//p = &ptr;
	//p = ptr;
	//ptr = p;	
	// DIY: uncomment these three lines and note the error messages
	
	return 0;
}*/

//-------------------------------- example 3 ----------------------------------
/*#include <stdio.h>

int main(void)
{
	int x = 5;
	int y = 7;	
	int *p = NULL;
	
	// memory address of
	printf("Memory address of x: %p\n", &x);
	printf("Memory address of y: %p\n", &y);
	printf("Memory address of p: %p\n", &p);  
	
	p = &x;
	
	// memory address of
	printf("\nMemory address of x: %p\n", &x);
	printf("Memory address of y: %p\n", &y);
	printf("Memory address of p: %p\n", &p);  
	
	// value of
	printf("\nValue stores in x: %d\n", x);
	printf("Value stores in y: %d\n", y);
	printf("Value stores in p: %p\n", p);
	
	// dereference
	printf("Dereference p gets: %d\n", *p); 
	
	p = &y;
	
	// memory address of
	printf("\nMemory address of x: %p\n", &x);
	printf("Memory address of y: %p\n", &y);
	printf("Memory address of p: %p\n", &p);  
	
	// value of
	printf("\nValue stores in x: %d\n", x);
	printf("Value stores in y: %d\n", y);
	printf("Value stores in p: %p\n", p);
	
	// dereference
	printf("Dereference p gets: %d\n", *p); 
	
	return 0;
}*/

//-------------------------------- example 4 ----------------------------------
/*#include <stdio.h>

int main(void)
{
	int x = 5;
	int *p = NULL;
	
	p = &x;
	
	printf("%d\n", *p); // dereference
	
	printf("%p\n", &p);
	printf("%p\n", p);
	printf("%p\n", &x);
	
	// NOTE: the output when printing out p and &x is the same because p is a pointer
	//       and it is pointing to x, therefore memory address of x is sotred in p
	
	return 0;
}*/

//-------------------------------- example 5 ----------------------------------
/*#include <stdio.h>

int main(void)
{
	int x = 5;
	int *p = NULL;
	
	p = &x;
	
	printf("%d\n", *p); // dereference
	printf("%p\n", p);
	printf("x is %d\n", x); 
	
	*p = 7; // dereference
	printf("\n%d\n", *p); // dereference
	printf("%p\n", p);
	printf("x is %d\n", x); 
	
	
	return 0;
}*/

//-------------------------------- example 6 ----------------------------------
/*#include <stdio.h>

int main(void)
{
	int x = 5;
	int* p = NULL;
	// NOTE: the only difference between example 5 and example 6 is this line,
	//       however, there is no difference in the outcome
	
	p = &x;
	
	printf("%d\n", *p); // dereference
	printf("%p\n", p);
	printf("x is %d\n", x); 
	
	*p = 7; // dereference
	printf("%d\n", *p); // dereference
	printf("%p\n", p);
	printf("x is %d\n", x); 
	
	
	return 0;
}*/

//-------------------------------- example 7 ----------------------------------
/*#include <stdio.h>

int main(void)
{
        double *p;
        double q;
        printf("%d %d\n", sizeof(p), sizeof(q));

        double* r;
        double s;
        printf("%d %d\n", sizeof(r), sizeof(s));
		// NOTE: the space after or before * at declaration makes no difference,
		//       both p and r are pointers

        int b = 100;
        int* t, u; // t is pointer, u is integer
        printf("\n%d %d\n", sizeof(t), sizeof(u));

        t = &b;
		printf("%d %d\n", *t, b);

        u = &b;
		// NOTE: the warning is caused by this line
		//       this statement is trying to assign the memory address of b to
		//       variable u, don't do this 
		printf("%p %p %d\n", u, &b, b);

        int *v, w; // v is pointer, w is integer
		// NOTE: the space after or before * at declaration makes no difference,
		//       both t (line 182) and v are pointers
		w = 10;
        printf("\n%d %d\n", sizeof(v), sizeof(w));

        v = &w;
		printf("%d %d\n", *v, w);
		
		w = &b; 
		// NOTE: the warning is caused by this line
		//       this statement is trying to assign the memory address of b to
		//       variable w, don't do this
		printf("%p %p %p\n", v, &w, &b);
}*/

//-------------------------------- example 8 ----------------------------------
/*#include <stdio.h>

int main(void)
{
	int x = 5, y = 6, z = 7;
	int *p, *q, *r;
	p = &x;
	q = &y;
	r = &z;
	
	printf("x = %d\n", *p); // dereference
	printf("y = %d\n", *q); // dereference
	printf("z = %d\n", *r); // dereference
	
	printf("x = %d\n", x); 
	printf("y = %d\n", y); 
	printf("z = %d\n", z); 
	
	*p = *q / *r;	
	//*p=*q/*r; 
	// DIY: uncomment this line, compile, run the program and note the error, 
	//      which is caused by bad spacing
	
	printf("\n\nx = %d\n", *p); // dereference
	printf("y = %d\n", *q); // dereference
	printf("z = %d\n", *r); // dereference
	
	printf("x = %d\n", x); 
	printf("y = %d\n", y); 
	printf("z = %d\n", z); 
	
	
	return 0;
}*/

//-------------------------------- example 9 ----------------------------
/*#include <stdio.h>

int main(void)
{
	int x = 5, y = 6;
	int *p = &x;
	
	printf("de-p is %d\n", *p); // dereference
	printf("x is %d\n", x); 
	printf("y is %d\n", y); 

	
	*p = 7;	
	printf("\n\nde-p is %d\n", *p); // dereference
	printf("x is %d\n", x); 
	printf("y is %d\n", y); 
	
	p = &y;
	printf("\n\nde-p is %d\n", *p); // dereference
	printf("x is %d\n", x); // dereference
	printf("y is %d\n", y); 
	
	
	return 0;
}*/

//-------------------------------- example 10 ----------------------------
/*#include <stdio.h>

int main(void)
{
	const int x = 5, y = 6;
	// NOTE: compare to example 9, this line is the only difference
	//       this program has a pointer that point to a const variable
	int *p = &x;
	// NOTE: the warning is because *p = &x allow changes to be made to the constant
	//       via a pointer
	
	// NOTE: Bad idea to use a pointer to point to a constant!!
	
	printf("de-p is %d\n", *p); // dereference
	printf("x is %d\n", x); 
	printf("y is %d\n", y); 

	//x = 7;
	// DIY: uncomment this line and you will see an error!!
	*p = 7;	
	// NOTE: no error, the program change the value of x from 5 to 7 here
	printf("\n\nde-p is %d\n", *p); // dereference
	printf("x is %d\n", x); 
	printf("y is %d\n", y); 
	
	p = &y;
	// NOTE: the warning is because *p = &y allow changes to be made to the constant
	//       via a pointer 
	printf("\n\nde-p is %d\n", *p); // dereference
	printf("x is %d\n", x); 
	printf("y is %d\n", y); 
	
	
	return 0;
}*/

//-------------------------------- example 11 ----------------------------
/*#include <stdio.h>

int main(void)
{
	const int x = 5, y = 6;
	const int *p = &x; // p is pointer to constant
	// NOTE: compare to example 9, example 11 has x and y as constant whereas
	//       example 9 does not. 
	//       compare to example 10, example 11 has p as a pointer to constant
	//       whereas example 10 does not. 
	
	printf("de-p is %d\n", *p); // dereference
	printf("x is %d\n", x); 
	printf("y is %d\n", y); 

	x = 7; 
	*p = 7;	
	// NOTE: the error because x = 7 is trying to modify the constant variable
	//       and *p = 7 is trying to change the value of x through a pointer to
	//       constant
	printf("\n\nde-p is %d\n", *p); // dereference
	printf("x is %d\n", x); 
	printf("y is %d\n", y); 
	
	p = &y;
	printf("\n\nde-p is %d\n", *p); // dereference
	printf("x is %d\n", x); 
	printf("y is %d\n", y); 	
	
	return 0;
}*/

//-------------------------------- example 12 ----------------------------
/*#include <stdio.h>

int main(void)
{
	int x = 5, y = 6;
	const int *p = &x; // p is pointer to constant
	// NOTE: compare to example 10, example 10 has x and y as constant whereas
	//       example 12 does not. 
	//       compare to example 9, example 9 does not have p as a pointer to constant
	//       but example 12 does. 
	
	printf("de-p is %d\n", *p); // dereference
	printf("x is %d\n", x); 
	printf("y is %d\n", y); 

	x = 7; 
	*p = 7;	// compile error
	// NOTE: the error because *p = 7 is trying to change the value of x through 
	//       a pointer to constant
	printf("\n\nde-p is %d\n", *p); // dereference
	printf("x is %d\n", x); 
	printf("y is %d\n", y); 
	
	p = &y;
	printf("\n\nde-p is %d\n", *p); // dereference
	printf("x is %d\n", x); 
	printf("y is %d\n", y); 
	
	
	return 0;
}*/

//-------------------------------- example 13 ----------------------------
/*#include <stdio.h>

int main(void)
{
	int x = 5, y = 6;
	int *const p = &x; // p is a const pointer
	// NOTE: compare to example 12, example 12 has p as pointer to constant but
	//       example 13 p is a const pointer
	
	printf("de-p is %d\n", *p); // dereference
	printf("x is %d\n", x); 
	printf("y is %d\n", y); 

	//x = 7; 
	*p = 7;	
	printf("\n\nde-p is %d\n", *p); // dereference
	printf("x is %d\n", x); 
	printf("y is %d\n", y); 
	
	p = &y; // compile error
	// NOTE: the error because p = &y is trying to change the location where
	//       p is pointing at but p here is a const pointer 
	printf("\n\nde-p is %d\n", *p); // dereference
	printf("x is %d\n", x); 
	printf("y is %d\n", y); 
	
	
	return 0;
}*/

//-------------------------------- example 14 ----------------------------
/*#include <stdio.h>

int main(void)
{
	const int x = 5, y = 6;
	int *const p = &x;
	// NOTE: compare to example 12, example 12 has p as pointer to constant but
	//       example 14 p is a const pointer
	// NOTE: compare to example 12, example 14 has x and y as constant but
	//       example 12 doesn't
	
	// NOTE: warning because this program has a const pointer to point at a constant
	//       this means the value of x can be changed indirectly
	
	printf("de-p is %d\n", *p); // dereference
	printf("x is %d\n", x); 
	printf("y is %d\n", y); 

	//x = 7; // compile error
	*p = 7;	
	printf("\n\nde-p is %d\n", *p); // dereference
	printf("x is %d\n", x); 
	printf("y is %d\n", y); 
	
	//p = &y; // compile error
	printf("\n\nde-p is %d\n", *p); // dereference
	printf("x is %d\n", x); 
	printf("y is %d\n", y); 
	
	
	return 0;
}*/

//-------------------------------- example 15 ----------------------------------
/*#include <stdio.h>

int main(void)
{
	int i = 0;
	int *int_p = &i;
	
	char c = 'a';
	char *char_p = &c;
	
	double d = 5.5;
	double *double_p = &d;
	
	printf("int %4d %p\n", *int_p, int_p);
	printf("chr %4c %p\n", *char_p, char_p);
	printf("dou %.2lf %p\n", *double_p, double_p);
	
	*int_p = *int_p + 1; // add one to existing value
	*char_p = *char_p + 1; // add one to existing value
	*double_p = *double_p + 1; // add one to existing value
	
	printf("\n\nint %4d %p\n", *int_p, int_p);
	printf("chr %4c %p\n", *char_p, char_p);
	printf("dou %.2lf %p\n", *double_p, double_p);
	
	int_p = int_p + 1;
	char_p = char_p + 1;
	double_p = double_p + 1;
	
	// best not to print the values as it could clash the program
	// as you have no idea where pinters are pointing to
	printf("\n\nint %4d %p\n", *int_p, int_p);
	printf("chr %4c %p\n", *char_p, char_p);
	printf("dou %.2lf %p\n", *double_p, double_p);
	
	return 0;
}*/


//-------------------------------- example 16 ----------------------------------
/*#include <stdio.h>

int main(void)
{
	int x[] = {9, 11, 13};
	int *p;
	p = x; // array name is a pointer, and pointer stores memory address!!
	
	int y = 10;
	int *q;
	q = &y; // note the difference when pointer is pointing to an array
			// and when pointer is pointing to a normal variable
	
	printf("%p\n", x);
	printf("%p\n", &x[0]);
	printf("%p\n", p);
	printf("%p\n", &p);
	
	int i = 0;
	printf("\n\nPrint from x:\n");
	for(i = 0; i < 3; i++)
	{
		printf("%d ", x[i]); // value of each element in x
	}
	printf("\n");

	for(i = 0; i < 3; i++)
	{
		printf("%p ", &x[i]); // memeory address of each element of x
	}
	printf("\n");
	
	printf("\n\nPrint from p:\n");
	for(i = 0; i < 3; i++)
	{
		printf("%d ", *(p + i)); // move pointer by i and then get the value
	}
	printf("\n");
	
	for(i = 0; i < 3; i++)
	{
		printf("%d ", p[i]);
	}
	printf("\n");
	// NOTE: different representation than the for loop above, but achieve the same
	//       thing
	
	for(i = 0; i < 3; i++)
	{
		printf("%p ", &*(p + i)); 
	}
	printf("\n");
	
	for(i = 0; i < 3; i++)
	{
		printf("%p ", &p[i]); 
	}
	printf("\n");
	// NOTE: different representation than the for loop above, but achieve the same
	//       thing	
	
	return 0;
}*/

//-------------------------------- example 17 ----------------------------------
/*#include <stdio.h>

int main(void)
{
	int *ptr, i, arr[5] = {10, 20, 30, 40, 50};
	ptr = arr;
	
	for(i = 0; i < 5; i++)
	{
		printf("Addr = %p Val = %d\n", ptr, *ptr);
		ptr++; // same as ptr = ptr + 1;
	}

	ptr = arr; // reset the point to the original location
	for(i = 0; i < 5; i++)
	{
		printf("Addr = %p Val = %d\n", &ptr[i], ptr[i]);
	}
	
	return 0;
}*/

//-------------------------------- example 18 ----------------------------------
/*#include <stdio.h>

int main(void)
{
	printf("%c %c\n", "message"[4], *("message"+4));
	
	char *p = "This is text";
	printf("%c %c\n", p[5], *(p+5));
	printf("%s\n", p);
	printf("%s\n", p+5);
	
	return 0;
}*/

//-------------------------------- example 19 ----------------------------------
/*#include <stdio.h>

int main(void)
{
	// Can declare your string as char *
	// The const keyword enforces the fact you are not allowed to change 
	// a string literal. 
	// const char *str = "Paul";
	
	// Or you could declare the string as an array of characters.
	// Try changing the nul character at the end to something else to see
	// what happens with string not ending in \0.
	char name[] = {'P','a','u','l','\0'};
	char *str = name;  // "name" equivalent to "&name[0]"
	
	// First version that uses array notation.
	int n = 0;
	while(str[n] != '\0')
	{
		//printf("%c", str[n]);  // Comment out to print characters 1 by 1 
								 // while counting.
		n = n + 1;
	}
	printf("\nArray notation length %d.\n", n);
	
	// Second version that uses pointer arithmetic.
	int len = 0;
	while(*str != '\0')
	{
		//printf("%c", *str);  // Comment out to print characters 1 by 1 
							   // while counting.
		str = str + 1;
		len = len + 1;
	}
	printf("\nPointer arithmetic length %d.\n", len);
	
	return 0;
}*/

//-------------------------------- example 20 ----------------------------------
/*#include <stdio.h>

int main(void)
{
	int *ptr, i = 10;
	ptr = &i;
		
	printf("%p\n", &i);
	printf("%d\n", i);
	
	printf("\n\n%p\n", ptr);
	ptr++;
	printf("%p\n", ptr);
	
	ptr = &i;
	(*ptr)++;
	printf("\n\n%p\n", ptr);
	printf("%d\n", *ptr);
	
	ptr = &i;
	++*ptr;
	printf("\n\n%p\n", ptr);
	printf("%d\n", *ptr);
	
	int *ptr2 = ptr;
	ptr2++;
	printf("\n\n%p %p\n", ptr2, ptr);
	printf("%d\n", (ptr2 - ptr));
	
	
	return 0;
}*/

//-------------------------------- example 21 ----------------------------------
/*#include <stdio.h>

int main(int argc, char *argv[])
{
   printf("%d arguments:\n", argc);
   int i;
   for(i = 0; i < argc; i++)
   {
      printf("%s\n", argv[i]);
   }
   
   return 0;
}*/

