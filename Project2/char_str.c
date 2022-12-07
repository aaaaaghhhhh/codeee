#define _CRT_SECURE_NO_WARNINGS 1

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

接收和返回的都是该字符的ASCII码，用的时候直接输入字符就可以，C++内部会自动转换

将一个字符转换为大写

2.tolower()

int tolower(int)

接收和返回的都是该字符的ASCII码，用的时候直接输入字符就可以，C++内部会自动转换

3.isalpha()

int isalpha(int)

判断输入的字符是否为字母，即是否在 “A – Z” 或者 "a – z"之间

是字母则返回非0整数，不是字符则返回0

4.isalnum

int isalnum(int)

判断输入的字符是否为字母或者数字，即是否在 “A – Z” 或者 “a – z” 或者"0 – 9"之间

在这些范围内返回非0，不在则返回0

5.isdigit()

int isdigit(int)

判断输入的字符是否是数字

6.islower()

int islower(int)

判断字符是否小写字母

7.isupper()

int isupper(int)

判断字符是否大写字母

8.isblank()

判断输入字符是否为 空格，或者tab键制表符，即space 和 \t

是则返回非0，不是则返回0

9.isspace()

判断输入字符是否为空格 ’ '，tab键制表符’\t’、回车’\r’ 、换行’\n’、换页’\f’和垂直制表符’\v’ 等

是则返回非0，不是则返回0

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
//	//注意输入双引号会报错
//	// NOTE: isblank returns true for any blank character that seprates words
//	//isblank 对于分隔单词的任何空白字符返回 true，返回 true(不是0的任何数字)
//	printf("%d\n", isspace(' '));
//	//printf("%d\n", isspace(" "));
//	printf("%d\n", isspace('\t'));
//	printf("%d\n", isspace('\n'));
//
//	// NOTE: isspace returns true for any white space characters
//	//isspace 对于任何空格字符都返回 true
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
//	// NOTE: arr is array of characters arr是字符数组
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
//#include <stdio.h>
//
//int main()
//{
//	// different functions for output
//	printf("%s", "Hello World!\n");
//	puts("Hello World!");
//	// note there is no \n in puts, but it gets added automatically注意这个
//
//	char arr[15] = { '\0' };
//	sprintf(arr, "Hello World!\n");
//	printf("%s", arr);
//	// note that without printf, the string is stored only in the array but 
//	// not display注意看这个
//	/*sprintf的作用是将一个格式化的字符串输出到一个目的字符串中，而printf是将一个格式化的字符串输出到屏幕。
//
//sprintf的第一个参数是目的字符串，如果不指定这个参数，执行过程中出现 "该程序产生非法操作,即将被关闭...."的
//
//提示。
//
//	因为C语言在进行字符串操作时不检查字符串的空间是否够大，所以可能会出现数组越界而导致程序崩溃的问题。
//
//即使碰巧，程序没有出错，也不要这么用，因为早晚会出错。所以一定要在调用sprintf之前分配足够大的空间给目的字符串*/
//
//
//
//// different functions for input
//	printf("\n\nGetting two integer inputs:\n");
//	scanf("%[^\n]", arr);
//	// get every character excluding \n ，获取除 \n 之外的每个字符
//	printf("arr contains %s\n", arr);
//
//	int a = 0;
//	int b = 0;
//	printf("\n\nGetting two integer inputs from arr:\n");
//	sscanf(arr, "%d %d", &a, &b);
//	// split the numbers into two variables 将数字分成两个变量
//	// sscanf() - 从一个字符串中读进与指定格式相符的数据.
//	printf("arr contains %s, a =  %d, b = %d\n", arr, a, b);
//
//
//	while (getchar() != '\n');
//	// consume the left over \n from scanf in line 101，在第 101 行中使用 scanf 中剩余的 \n
//
//	printf("\n\nEnter a sentence longer than 15 characters: ");
//	fgets(arr, 15, stdin);
//	printf("%s\n", arr);
//	// note that without printf, the string is stored only in the array 
//	// when fgets is used，注意这个
//
//	printf("\n\n");
//	putchar('a');
//
//	return 0;
//}

//-------------------------------- example 5 ----------------------------------
//#include <stdio.h>
//#include <string.h>
//
//int main()
//{
//	char s1[10] = "Happy\0";
//	char s2[10] = "Hip\0";
//	char s3[11] = "Hippotamus\0";
//
//	printf("s1: %s\n", s1);
//	printf("s2: %s\n", s2);
//	printf("s3: %s\n", s3);
//
//	strcpy(s1, s2); // destination <- source 将s2的内容拷到s1，储存在s1中
//
//	printf("\n\ns1: %s\n", s1);
//	printf("s2: %s\n", s2);
//	printf("s3: %s\n", s3);
//
//	int i = 0;
//	printf("s1 using %%c: ");
//	for(i = 0; i < 10; i++)
//	{
//		if(s1[i] == '\0')
//		{
//			printf("* ");
//		}
//		else
//		{
//			printf("%c ", s1[i]);
//		}
//
//	}
//	printf("\n");
//	// note that some of the characters originally in s1 is still there
//
//	strcpy(s1, "awesome"); // destination <- source
//
//	printf("\n\ns1: %s\n", s1);
//	printf("s2: %s\n", s2);
//	printf("s3: %s\n", s3);
//
//	printf("s1 using %%c: ");
//	for(i = 0; i < 10; i++)
//	{
//		if(s1[i] == '\0')
//		{
//			printf("* ");
//		}
//		else
//		{
//			printf("%c ", s1[i]);
//		}
//
//	}
//	printf("\n");
//	// note that some of the characters originally in s1 is still there
//
//	strncpy(s1, s2, 2); // destination <- source
//
//	printf("\n\ns1: %s\n", s1);
//	printf("s2: %s\n", s2);
//	printf("s3: %s\n", s3);
//
//
//	return 0;
//}


//-------------------------------- example 6 ----------------------------------
//#include <stdio.h>
//#include <string.h>
//
//int main()
//{
//	char s1[10] = "Happy\0";
//	char s2[10] = "Hip\0";
//	char s3[11] = "Hippotamus\0";
//
//	printf("s1: %s\n", s1);
//	printf("s2: %s\n", s2);
//	printf("s3: %s\n", s3);
//
//	strcat(s1, s2); // destination <- source，合并两个字符串
//
//	printf("\n\ns1: %s\n", s1);
//	printf("s2: %s\n", s2);
//	printf("s3: %s\n", s3);
//
//	int i = 0;
//	printf("s1 using %%c: ");
//	for(i = 0; i < 10; i++)
//	{
//		if(s1[i] == '\0')
//		{
//			printf("* ");
//		}
//		else
//		{
//			printf("%c ", s1[i]);
//		}
//
//	}
//	printf("\n");
//	// note that some of the characters originally in s1 is still there
//
//	strcat(s3, s2); // destination <- source
//
//	printf("\n\ns1: %s\n", s1);
//	printf("s2: %s\n", s2);
//	printf("s3: %s\n", s3);
//	// note the overwritten part，注意这个
//
//	printf("s2 using %%c: ");
//	for(i = 0; i < 10; i++)
//	{
//		if(s2[i] == '\0')
//		{
//			printf("* ");
//		}
//		else
//		{
//			printf("%c ", s2[i]);
//		}
//
//	}
//	printf("\n");
//
//	printf("s3 using %%c: ");
//	for(i = 0; i < 11; i++)
//	{
//		if(s3[i] == '\0')
//		{
//			printf("* ");
//		}
//		else
//		{
//			printf("%c ", s3[i]);
//		}
//
//	}
//	printf("\n");
//
//
//
//	strncat(s3, s2, 2); // destination <- source
//
//	printf("\n\ns1: %s\n", s1);
//	printf("s2: %s\n", s2);
//	printf("s3: %s\n", s3);
//	// note the overwritten part
//
//	printf("s2 using %%c: ");
//	for(i = 0; i < 10; i++)
//	{
//		if(s2[i] == '\0')
//		{
//			printf("* ");
//		}
//		else
//		{
//			printf("%c ", s2[i]);
//		}
//
//	}
//	printf("\n");
//
//	printf("s3 using %%c: ");
//	for(i = 0; i < 11; i++)
//	{
//		if(s3[i] == '\0')
//		{
//			printf("* ");
//		}
//		else
//		{
//			printf("%c ", s3[i]);
//		}
//
//	}
//	printf("\n");
//
//	printf("\n\ns1: %p\n", &s1[0]);
//	printf("s2: %p\n", &s2[0]);
//	printf("s3: %p\n", &s3[0]);
//
//	return 0;
//}

//-------------------------------- example 7 ----------------------------------
//#include <stdio.h>
//#include <string.h>
//
//int main()
//{
//	const char *s1 = "Happy";
//	const char *s2 = "Happy";
//	const char *s3 = "Hippo";
//
//	printf("strcmp s1, s2 = %d\n", strcmp(s1, s2)); // equal is zero
//	printf("strcmp s1, s3 = %d\n", strcmp(s1, s3)); //比较两个字符串是否相同
//	// less than is negative i.e a < i
//	printf("strcmp s3, s1 = %d\n", strcmp(s3, s1));
//	// greater than is positive i.e. i >  a
//
//	printf("strncmp s1, s3, char 1 = %d\n", strncmp(s1, s3, 1)); //比较两个字符串的第一位是否相等
//	printf("strncmp s1, s2, char 2 = %d\n", strncmp(s1, s2, 2));
//	// NOTE: comparing 2 of same characters from s1 and s2
//	printf("strncmp s1, s3, char 2 = %d\n", strncmp(s1, s3, 2));
//	printf("strncmp s3, s1, char 2 = %d\n", strncmp(s3, s1, 2));
//	// for strncomp some compilers will return 0, -1, 1
//	// some compilers will return the difference
//	// between the numeric code e.g. 0, -8, 8
//
//	return 0;
//}


//-------------------------------- example 8 ----------------------------------
//#include <stdio.h>
//#include <string.h>
//
//// Instruction:
//// - run the program and observe the output
//// - try a different character and observe the output
//
//int main()
//{
//	const char *str = "This is a bat\n";
//	char c1 = 'a';
//
//	char *cPtr;
//
//	printf("The first appearance of 'a': ");
//	if((cPtr = strchr(str, c1)) != NULL)
//	{
//		// strchr return a pointer to the first occurance of that character
//		// or NULL if not found 注意看这个
//		while(*cPtr != '\n')
//		{
//			printf("%c", *cPtr);
//			cPtr++;
//		}
//		printf("\n");
//	}
//	else
//	{
//		printf("Unable to find %c\n", c1);
//	}
//
//	printf("The last appearance of 'a': ");
//	if((cPtr = strrchr(str, c1)) != NULL)
//	{
//		// strchr return a pointer to the last occurance of that character
//		// or NULL if not found
//		while(*cPtr != '\n')
//		{
//			printf("%c", *cPtr);
//			cPtr++;
//		}
//		printf("\n");
//	}
//	else
//	{
//		printf("Unable to find %c\n", c1);
//	}
//
//	c1 = 'z';
//	printf("The first appearance of 'z': ");
//	if((cPtr = strchr(str, c1)) != NULL)
//	{
//		// strchr return a pointer to the first occurance of that character or NULL if not found
//		while(*cPtr != '\n')
//		{
//			printf("%c", *cPtr);
//			cPtr++;
//		}
//		printf("\n");
//	}
//	else
//	{
//		printf("Unable to find %c\n", c1);
//	}
//
//	printf("The last appearance of 'z': ");
//	if((cPtr = strrchr(str, c1)) != NULL)
//	{
//		// strchr return a pointer to the last occurance of that character or NULL if not found
//		while(*cPtr != '\n')
//		{
//			printf("%c", *cPtr);
//			cPtr++;
//		}
//		printf("\n");
//	}
//	else
//	{
//		printf("Unable to find %c\n", c1);
//	}
//
//
//	return 0;
//}


//-------------------------------- example 9 ----------------------------------
//#include <stdio.h>
//#include <string.h>
//
//int main()
//{
//	const char *str1 = "This is a bat and not a batman\n";
//	const char *str2 = "bat";
//
//	char *cPtr;
//
//	if((cPtr = strstr(str1, str2)) != NULL)
//	{
//		// strstr return a pointer to the first occurance of that string
//		// or NULL if not found
//		while(*cPtr != '\n')
//		{
//			printf("%c", *cPtr);
//			cPtr++;
//		}
//		printf("\n");
//	}
//
//	return 0;
//}


//-------------------------------- example 10 ----------------------------------
//#include <stdio.h>
//#include <string.h>
//
//int main()
//{
//	char str[] = "This is a bat and not a batman\n";
//
//	char *cPtr = strtok(str, " ");//以“ ”分解str,该函数返回被分解的第一个子字符串，如果没有可检索的字符串，则返回一个空指针
//
//	while(cPtr != NULL)
//	{
//		printf("%s\n", cPtr);
//		cPtr = strtok(NULL, " "); 
//		// this is important, NULL indicates that strtok should continue
//		// tokenising from the last strtok call
//	}
//
//	return 0;
//}


//-------------------------------- example 11 ----------------------------------
//#include <stdio.h>
//#include <string.h>
//
//int main()
//{
//	const char str[] = "This is a bat and not a batman\n";
//	const char str2[] = "bat";
//	const char str3[] = "bap";
//
//	// find the size of matched character of str_left in str_right
//	printf("%d\n", strspn("This is a bat and not a batman", "bat"));
//	printf("%d\n", strspn("bat", "This is a bat and not a batman"));
//	printf("%d\n", strspn(str3, str)); // ba is matched
//	printf("%d\n", strspn("cat", str)); // stops when it is not matched
//
//	//从参数str1字符串的开头计算连续的字符,而这些字符都完全是str2所指字符串中的字符
//	//4个printf分别显示0 3 2 0
//
//	return 0;
//}
