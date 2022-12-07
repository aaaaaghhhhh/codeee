
#define _CRT_SECURE_WARNINGS 1
//-------------------------------- example 1 ----------------------------------
//#include <stdio.h>
//#include <ctype.h> // isdigit, to lower
//
//// Intruction: 
//// - run the program and note the difference between the first and 
////   the second printf
//// - try to use isspace, iscntrl, ispunct, isprint, and isgraph 
//
//int main()
//{
//	printf("%d\n", isdigit('8'));	
//	printf("%d\n", isdigit(8));
//	// note the important of single quotes here
//	
//	printf("%c\n", tolower('A'));
//	
//	return 0;
//}


//-------------------------------- example 2 ----------------------------------
/*1.toupper()

int toupper(int)

���պͷ��صĶ��Ǹ��ַ���ASCII�룬�õ�ʱ��ֱ�������ַ��Ϳ��ԣ�C++�ڲ����Զ�ת��

��һ���ַ�ת��Ϊ��д

2.tolower()

int tolower(int)

���պͷ��صĶ��Ǹ��ַ���ASCII�룬�õ�ʱ��ֱ�������ַ��Ϳ��ԣ�C++�ڲ����Զ�ת��

3.isalpha()

int isalpha(int)

�ж�������ַ��Ƿ�Ϊ��ĸ�����Ƿ��� ��A �C Z�� ���� "a �C z"֮��

����ĸ�򷵻ط�0�����������ַ��򷵻�0

4.isalnum

int isalnum(int)

�ж�������ַ��Ƿ�Ϊ��ĸ�������֣����Ƿ��� ��A �C Z�� ���� ��a �C z�� ����"0 �C 9"֮��

����Щ��Χ�ڷ��ط�0�������򷵻�0

5.isdigit()

int isdigit(int)

�ж�������ַ��Ƿ�������

6.islower()

int islower(int)

�ж��ַ��Ƿ�Сд��ĸ

7.isupper()

int isupper(int)

�ж��ַ��Ƿ��д��ĸ

8.isblank()

�ж������ַ��Ƿ�Ϊ �ո񣬻���tab���Ʊ�������space �� \t

���򷵻ط�0�������򷵻�0

9.isspace()

�ж������ַ��Ƿ�Ϊ�ո� �� '��tab���Ʊ�����\t�����س���\r�� �����С�\n������ҳ��\f���ʹ�ֱ�Ʊ�����\v�� ��

���򷵻ط�0�������򷵻�0

*/


//#include <stdio.h>
//#include <ctype.h> // isblank, isalpha, isspace
//
//int main()
//{
//	printf("%d\n", isblank(' '));
//	//printf("%d\n", isblank(" "));
//	// DIY: uncomment the line above, compile and note the error
//	printf("%d\n", isblank('\t'));
//	printf("%d\n", isblank('\n')); // not seperate words
//	// note the important of single quotes here
//	//ע������˫���Żᱨ��
//	// NOTE: isblank returns true for any blank character that seprates words
//	//isblank ���ڷָ����ʵ��κοհ��ַ����� true������ true(����0���κ�����)
//	printf("%d\n", isspace(' '));
//	//printf("%d\n", isspace(" "));
//	printf("%d\n", isspace('\t'));
//	printf("%d\n", isspace('\n'));
//
//	// NOTE: isspace returns true for any white space characters
//	//isspace �����κοո��ַ������� true
//	printf("%d\n", isalpha(' '));
//	printf("%d\n", isalpha('A'));
//	//printf("%d\n", isalpha("A"));
//
//	printf("%c\n", toupper('a'));
//
//	return 0;
//}


//-------------------------------- example 3 ----------------------------------
//#include <stdio.h>
//#include <stdlib.h> // strtod
//
//// Instruction: try to use strtol and strtoul
//
//int main()
//{
//	const char *str = "51.2% are admitted";
//	const char *str2 = "41.5";
//	const char *str3 = "My number is 1.23 not 4.56";
//	char arr[10] = "10.2";
//	
//	char *sPtr;
//	
//	double d = 0.0;
//	d = strtod(str, &sPtr);
//	printf("double value is %f, and the string is %s\n", d, sPtr);
//	
//	d = strtod(str2, &sPtr);
//	printf("double value is %f, and the string is %s\n", d, sPtr);
//	
//	d = strtod(str3, &sPtr);
//	printf("double value is %f, and the string is %s\n", d, sPtr);
//	
//	d = strtod(arr, &sPtr);
//	printf("double value is %f, and the string is %s\n", d, sPtr);
//	// NOTE: arr is array of characters arr���ַ�����
//	
//	float f = 0.0;
//	f = atof("51.2");
//	printf("float value is %f\n", f);
//	
//	f = atof(str);
//	printf("float value is %f\n", f);
//	
//	f = atof(str2);
//	printf("float value is %f\n", f);
//	
//	f = atof(str3);
//	printf("float value is %f\n", f);
//	
//	f = atof("1.23");
//	printf("float value is %f\n", f);
//	
//	f = atof(arr);
//	printf("float value is %f\n", f);
//	// NOTE: arr is array of characters
//	
//	return 0;
//}


//-------------------------------- example 4 ----------------------------------
#include <stdio.h>

int main()
{
	// different functions for output
	printf("%s", "Hello World!\n");
	puts("Hello World!");
	// note there is no \n in puts, but it gets added automaticallyע�����
	
	char arr[15] = {'\0'};
	sprintf(arr, "Hello World!\n");
	printf("%s", arr);
	// note that without printf, the string is stored only in the array but 
	// not displayע�⿴���
	/*sprintf�������ǽ�һ����ʽ�����ַ��������һ��Ŀ���ַ����У���printf�ǽ�һ����ʽ�����ַ����������Ļ��

sprintf�ĵ�һ��������Ŀ���ַ����������ָ�����������ִ�й����г��� "�ó�������Ƿ�����,�������ر�...."��

��ʾ��

    ��ΪC�����ڽ����ַ�������ʱ������ַ����Ŀռ��Ƿ񹻴����Կ��ܻ��������Խ������³�����������⡣

��ʹ���ɣ�����û�г�����Ҳ��Ҫ��ô�ã���Ϊ���������������һ��Ҫ�ڵ���sprintf֮ǰ�����㹻��Ŀռ��Ŀ���ַ���*/
	
	
	
	// different functions for input
	printf("\n\nGetting two integer inputs:\n");
	scanf("%[^\n]", arr);
	// get every character excluding \n ����ȡ�� \n ֮���ÿ���ַ�
	printf("arr contains %s\n", arr);
	
	int a = 0;
	int b = 0;
	printf("\n\nGetting two integer inputs from arr:\n");
	sscanf(arr, "%d %d", &a, &b);
	// split the numbers into two variables �����ֳַ���������
	printf("arr contains %s, a =  %d, b = %d\n", arr, a, b);
	

	while ( getchar() != '\n' );
	// consume the left over \n from scanf in line 101���ڵ� 101 ����ʹ�� scanf ��ʣ��� \n
	
	printf("\n\nEnter a sentence longer than 15 characters: ");
	fgets(arr, 15, stdin);
	printf("%s\n", arr);
	// note that without printf, the string is stored only in the array 
	// when fgets is used��ע�����
	
	printf("\n\n");
	putchar('a');
	
	return 0;
}

//-------------------------------- example 5 ----------------------------------
/*#include <stdio.h>
#include <string.h>

int main()
{
	char s1[10] = "Happy\0";
	char s2[10] = "Hip\0";
	char s3[11] = "Hippotamus\0";
	
	printf("s1: %s\n", s1);
	printf("s2: %s\n", s2);
	printf("s3: %s\n", s3);
	
	strcpy(s1, s2); // destination <- source
	
	printf("\n\ns1: %s\n", s1);
	printf("s2: %s\n", s2);
	printf("s3: %s\n", s3);
	
	int i = 0;
	printf("s1 using %%c: ");
	for(i = 0; i < 10; i++)
	{
		if(s1[i] == '\0')
		{
			printf("* ");
		}
		else
		{
			printf("%c ", s1[i]);
		}
		
	}
	printf("\n");
	// note that some of the characters originally in s1 is still there
	
	strcpy(s1, "awesome"); // destination <- source
	
	printf("\n\ns1: %s\n", s1);
	printf("s2: %s\n", s2);
	printf("s3: %s\n", s3);
	
	printf("s1 using %%c: ");
	for(i = 0; i < 10; i++)
	{
		if(s1[i] == '\0')
		{
			printf("* ");
		}
		else
		{
			printf("%c ", s1[i]);
		}
		
	}
	printf("\n");
	// note that some of the characters originally in s1 is still there
	
	strncpy(s1, s2, 2); // destination <- source
	
	printf("\n\ns1: %s\n", s1);
	printf("s2: %s\n", s2);
	printf("s3: %s\n", s3);
	
	
	return 0;
}*/


//-------------------------------- example 6 ----------------------------------
/*#include <stdio.h>
#include <string.h>

int main()
{
	char s1[10] = "Happy\0";
	char s2[10] = "Hip\0";
	char s3[11] = "Hippotamus\0";
	
	printf("s1: %s\n", s1);
	printf("s2: %s\n", s2);
	printf("s3: %s\n", s3);
	
	strcat(s1, s2); // destination <- source
	
	printf("\n\ns1: %s\n", s1);
	printf("s2: %s\n", s2);
	printf("s3: %s\n", s3);
	
	int i = 0;
	printf("s1 using %%c: ");
	for(i = 0; i < 10; i++)
	{
		if(s1[i] == '\0')
		{
			printf("* ");
		}
		else
		{
			printf("%c ", s1[i]);
		}
		
	}
	printf("\n");
	// note that some of the characters originally in s1 is still there
	
	strcat(s3, s2); // destination <- source
	
	printf("\n\ns1: %s\n", s1);
	printf("s2: %s\n", s2);
	printf("s3: %s\n", s3);
	// note the overwritten part
	
	printf("s2 using %%c: ");
	for(i = 0; i < 10; i++)
	{
		if(s2[i] == '\0')
		{
			printf("* ");
		}
		else
		{
			printf("%c ", s2[i]);
		}
		
	}
	printf("\n");
	
	printf("s3 using %%c: ");
	for(i = 0; i < 11; i++)
	{
		if(s3[i] == '\0')
		{
			printf("* ");
		}
		else
		{
			printf("%c ", s3[i]);
		}
		
	}
	printf("\n");
	
	
	
	strncat(s3, s2, 2); // destination <- source
	
	printf("\n\ns1: %s\n", s1);
	printf("s2: %s\n", s2);
	printf("s3: %s\n", s3);
	// note the overwritten part
	
	printf("s2 using %%c: ");
	for(i = 0; i < 10; i++)
	{
		if(s2[i] == '\0')
		{
			printf("* ");
		}
		else
		{
			printf("%c ", s2[i]);
		}
		
	}
	printf("\n");
	
	printf("s3 using %%c: ");
	for(i = 0; i < 11; i++)
	{
		if(s3[i] == '\0')
		{
			printf("* ");
		}
		else
		{
			printf("%c ", s3[i]);
		}
		
	}
	printf("\n");
	
	printf("\n\ns1: %p\n", &s1[0]);
	printf("s2: %p\n", &s2[0]);
	printf("s3: %p\n", &s3[0]);
	
	return 0;
}*/

//-------------------------------- example 7 ----------------------------------
/*#include <stdio.h>
#include <string.h>

int main()
{
	const char *s1 = "Happy";
	const char *s2 = "Happy";
	const char *s3 = "Hippo";
	
	printf("strcmp s1, s2 = %d\n", strcmp(s1, s2)); // equal is zero
	printf("strcmp s1, s3 = %d\n", strcmp(s1, s3)); 
	// less than is negative i.e a < i
	printf("strcmp s3, s1 = %d\n", strcmp(s3, s1)); 
	// greater than is positive i.e. i >  a
	
	printf("strncmp s1, s3, char 1 = %d\n", strncmp(s1, s3, 1));
	printf("strncmp s1, s2, char 2 = %d\n", strncmp(s1, s2, 2));
	// NOTE: comparing 2 of same characters from s1 and s2
	printf("strncmp s1, s3, char 2 = %d\n", strncmp(s1, s3, 2));
	printf("strncmp s3, s1, char 2 = %d\n", strncmp(s3, s1, 2)); 
	// for strncomp some compilers will return 0, -1, 1
	// some compilers will return the difference
	// between the numeric code e.g. 0, -8, 8
	
	return 0;
}*/


//-------------------------------- example 8 ----------------------------------
/*#include <stdio.h>
#include <string.h>

// Instruction:
// - run the program and observe the output
// - try a different character and observe the output

int main()
{
	const char *str = "This is a bat\n";
	char c1 = 'a';
	
	char *cPtr;
	
	printf("The first appearance of 'a': ");
	if((cPtr = strchr(str, c1)) != NULL)
	{
		// strchr return a pointer to the first occurance of that character 
		// or NULL if not found
		while(*cPtr != '\n')
		{
			printf("%c", *cPtr);
			cPtr++;
		}
		printf("\n");
	}
	else
	{
		printf("Unable to find %c\n", c1);
	}
	
	printf("The last appearance of 'a': ");
	if((cPtr = strrchr(str, c1)) != NULL)
	{
		// strchr return a pointer to the last occurance of that character 
		// or NULL if not found
		while(*cPtr != '\n')
		{
			printf("%c", *cPtr);
			cPtr++;
		}
		printf("\n");
	}
	else
	{
		printf("Unable to find %c\n", c1);
	}
	
	c1 = 'z';
	printf("The first appearance of 'z': ");
	if((cPtr = strchr(str, c1)) != NULL)
	{
		// strchr return a pointer to the first occurance of that character or NULL if not found
		while(*cPtr != '\n')
		{
			printf("%c", *cPtr);
			cPtr++;
		}
		printf("\n");
	}
	else
	{
		printf("Unable to find %c\n", c1);
	}
	
	printf("The last appearance of 'z': ");
	if((cPtr = strrchr(str, c1)) != NULL)
	{
		// strchr return a pointer to the last occurance of that character or NULL if not found
		while(*cPtr != '\n')
		{
			printf("%c", *cPtr);
			cPtr++;
		}
		printf("\n");
	}
	else
	{
		printf("Unable to find %c\n", c1);
	}
	
	
	return 0;
}*/


//-------------------------------- example 9 ----------------------------------
/*#include <stdio.h>
#include <string.h>

int main()
{
	const char *str1 = "This is a bat and not a batman\n";
	const char *str2 = "bat";
	
	char *cPtr;
	
	if((cPtr = strstr(str1, str2)) != NULL)
	{
		// strstr return a pointer to the first occurance of that string 
		// or NULL if not found
		while(*cPtr != '\n')
		{
			printf("%c", *cPtr);
			cPtr++;
		}
		printf("\n");
	}
	
	return 0;
}*/


//-------------------------------- example 10 ----------------------------------
/*#include <stdio.h>
#include <string.h>

int main()
{
	char str[] = "This is a bat and not a batman\n";
	
	char *cPtr = strtok(str, " ");
	
	while(cPtr != NULL)
	{
		printf("%s\n", cPtr);
		cPtr = strtok(NULL, " "); 
		// this is important, NULL indicates that strtok should continue 
		// tokenising from the last strtok call
	}
	
	return 0;
}*/


//-------------------------------- example 11 ----------------------------------
#include <stdio.h>
#include <string.h>

int main()
{
	const char str[] = "This is a bat and not a batman\n";
	const char str2[] = "bat";
	const char str3[] = "bap";
	
	// find the size of matched character of str_left in str_right
	printf("%d\n", strspn("This is a bat and not a batman", "bat"));
	printf("%d\n", strspn("bat", "This is a bat and not a batman"));
	printf("%d\n", strspn(str3, str)); // ba is matched
	printf("%d\n", strspn("cat", str)); // stops when it is not matched

	
	return 0;
}



