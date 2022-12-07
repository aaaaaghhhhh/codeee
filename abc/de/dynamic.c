//-------------------------------- example 1 ----------------------------------
/*#include <stdio.h>

int main(void)
{		
	return 0;
}
// DIY: compile the program and use size filename.exe on Windows original
//      or size filename on Linux to view the size */


//-------------------------------- example 2 ----------------------------------
/*#include <stdio.h>

int global;

int main(void)
{		
	return 0;
}*/
// DIY: compile the program and use size filename.exe on Windows original
//      or size filename on Linux to view the size 


//-------------------------------- example 3 ----------------------------------
/*#include <stdio.h>

int global;

int main(void)
{	
	static int i;
	return 0;
}*/
// DIY: compile the program and use size filename.exe on Windows original
//      or size filename on Linux to view the size 


//-------------------------------- example 4 ----------------------------------
/*#include <stdio.h>

int global;

int main(void)
{	
	static int i = 100;
	return 0;
}*/
// DIY: compile the program and use size filename.exe on Windows original
//      or size filename on Linux to view the size 


//-------------------------------- example 5 ----------------------------------
/*#include <stdio.h>

int global;

int main(void)
{	
	int i = 100;
	return 0;
}*/
// DIY: compile the program and use size filename.exe on Windows original
//      or size filename on Linux to view the size 

// NOTE: compare the size of data in example 4 and example 5


//-------------------------------- example 6 ----------------------------------
/*#include <stdio.h>

int global;

int test(void);

int main(void)
{	
	static int i = 100;
	static int j;
	
	int k;
	
	printf("Address of k: \t\t\t\t%p\n", &k);	
	test();
	printf("Address of global: \t\t\t%p\n", &global);
	printf("Address of j (static uninitialised): \t%p\n", &j);	
	printf("Address of i (static initialised): \t%p\n", &i);
	printf("Address of test function: \t\t%p\n", test);
	printf("Address of main function: \t\t%p\n", main);	
	
	
	return 0;
}

int test(void)
{
	int l;
	printf("Address of l: \t\t\t\t%p\n", &l);
	return 0;
}*/


//-------------------------------- example 7 ----------------------------------
/*#include <stdio.h>
#include <stdlib.h>

int global;

int test(void);

int main(void)
{	
	static int i = 100;
	static int j;
	
	int k;
	
	int *p = malloc(sizeof(int));
	
	printf("Address of k: \t\t\t\t%p\n", &k);	
	printf("Address of p: \t\t\t\t%p\n", &p);	
	test();	
	printf("Address of malloc: \t\t\t%p\n", p);
	// DIY: compile and run the program multiple times, and note that
	//      the memory address change every time
	printf("Address of global: \t\t\t%p\n", &global);
	printf("Address of j (static uninitialised): \t%p\n", &j);	
	printf("Address of i (static initialised): \t%p\n", &i);
	printf("Address of test function: \t\t%p\n", test);
	printf("Address of main function: \t\t%p\n", main);	
	
	free(p);
	
	
	return 0;
}

int test(void)
{
	int l;
	printf("Address of l: \t\t\t\t%p\n", &l);
	return 0;
}*/


//-------------------------------- example 8 ----------------------------------
/*#include <stdio.h>
#include <stdlib.h>

int main(void)
{	
	int *p = malloc(sizeof(int));
	
	free(p);
	free(p);
	// NOTE: there maybe no error when you run this program on your machine,
	//       but error will appear on some machine
	
	return 0;
}*/


//-------------------------------- example 9 ----------------------------------
/*#include <stdio.h>
#include <stdlib.h>

char *prompt(const char *mesg, const int limit);

int main(int argc, char *argv[])
{
   char *name = prompt("Who are you?\n", 20);
   if(name == NULL)
   {
      printf("Error\n");
   }
   else
   {
      printf("Hello %s!\n", name);
      free(name);
   }
   
   return 0;
}

char *prompt(const char *mesg, const int limit)
{
   char *name;
   name = malloc(sizeof(char) * (limit + 1));
   if(name == NULL)
   {
      return NULL;
   }

   printf("%s", mesg);
   scanf("%s", name);
   return name;
}*/


//-------------------------------- example 10 ----------------------------------
/*#include <stdio.h>
#include <stdlib.h>

char *prompt(const char *mesg, const int limit);

int main(int argc, char *argv[])
{
	char *name = prompt("Who are you?\n", 20);
	
	if(name == NULL)
	{
		printf("Error\n");
	}
	else
	{
		printf("Hello %s!\n", name);
		free(name);
	}
}

char *prompt(const char *mesg, const int limit)
{
	char *name;
	name = malloc(sizeof(char) * (limit + 1));
	
	if(name == NULL)
	{
		return NULL;
	}
	
	printf("%s", mesg);
	
	int pos = 0;
	while(pos < limit)
	{
		char ch = '\0';
		scanf("%c", &ch);
		
		if(ch == '\n') // User pressed return/enter.
		{
			name[pos] = '\0';  // Terminate the string here.
			break;
		}
		
		name[pos] = ch;
		pos++;
	}
	
	// NOTE: the difference between example 9 and example 10 is that
	//       example 9 uses scanf %s and there is a chance that you overwrite 
	//       a part of your memory if the user's input is longer than 20
	//       example 10 uses scanf %c and read one character at a time up to "limit"
	//       to avoid overwriting a part of your memory
	
	name[limit] = '\0'; // Make sure last element is \0.
	
	return name;
}*/


//-------------------------------- example 11 ----------------------------------
/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *prompt(const char *mesg);

int main(int argc, char *argv[])
{
	char *name = prompt("Who are you?\n");
	
	if(name == NULL)
	{
		printf("Error\n");
	}
	else
	{
		printf("Hello %s!\n", name);
		printf("Length %d\n", (int)strlen(name));
		free(name);
	}
}

char *prompt(const char *mesg)
{
	char *name;
	int size = 8;	
	name = malloc(sizeof(char) * size);
	
	if(name == NULL)
	{
		return NULL;
	}
	
	printf("%s", mesg);
	
	int pos = 0;
	char ch = '\0';
	
	do
	{
		scanf("%c", &ch);
		if(ch != '\n') // User did not press return/enter.
		{
			name[pos] = ch;
			pos++;
			
			if(pos > size - 1)
			{
				// expand
				char *tmp = malloc(sizeof(char) * (size * 2));
				
				if(tmp == NULL)
				{
					free(name);  // free the current buffer before giving up.
					return NULL;
				}
				
				for(int i = 0; i < size; i++)
				{
					tmp[i] = name[i];
				}
				
				free(name);
				name = tmp;
				size = size * 2;
			}
		}
   }while(ch != '\n');
   
   // NOTE: the difference between example 10 and example 11 is that
   //       example 10 uses fixed size malloc whereas example 11 expand when
   //       needed using malloc
   
   name[pos] = '\0';  // terminate the string after the return/enter.
   
   return name;
}*/


//-------------------------------- example 12 ----------------------------------
/*#include <stdio.h>
#include <stdlib.h>

char *prompt(const char *mesg);


int main(int argc, char *argv[])
{
	char *name = prompt("Enter name: ");
	
	if(name != NULL)
	{
		printf("Your name was |%s|\n", name);
		free(name);
	}
	else
	{
		printf("Error in prompt function\n");
	}
}

char *prompt(const char *mesg)
{
	// print the prompt
	if(mesg != NULL)
	{
		printf("%s", mesg);
	}
	
	int buffer_size = 8;		// buffer size, includes terminator.
	int bidx = 0;		// index to store next character
	
	// allocate the starting buffer size
	char *buffer = malloc(sizeof(char) * buffer_size);
	if(buffer == NULL)
	{
		return NULL;
	}
	
	// read in a character at a time
	do
	{
		char tmp = '\0';
		scanf("%c", &tmp);
		
		if(tmp == '\n')
		{
			// Pressed return
			buffer[bidx] = '\0';   // Add nul byte at current location
			return buffer;
		}
		else
		{
			// Pressed a different key
			buffer[bidx] = tmp;
			bidx++;
			
			if(bidx == buffer_size)
			{
				// no room for the next character, so expand the buffer.
				// This version uses realloc instead of (malloc + loop 
				// to copy old string) so in some cases it will be faster, 
				// but in worst case it will be the same and
				// therefore should be used as sparingly as malloc would be.
				
				char *newbuf = realloc(buffer, sizeof(char) * (buffer_size * 2));
				
				// NOTE: the difference between example 11 and example 12 is that
				//       example 11 uses fixed malloc whereas example 12 uses realloc
				
				if(newbuf == NULL)
				{
					free(buffer);	// realloc doesn't automatically free 
									// original buffer on error
					return NULL;
				}
				else
				{
					buffer = newbuf;
					buffer_size = buffer_size * 2;
				}
			}
		}
   } while(1);			// loop forever
   
   return NULL;
}*/



