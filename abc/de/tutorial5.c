//字符串结合函数
//---------例子一
#include<stdio.h>
#include<string.h>

int main()
{
	char src[20] = "hello PGA";
	
	int len = strlen(src);
	printf("Length of string: %d\n", len);	
	
	src[6] = '\0'; 
	
	len = strlen(src);
	printf("Length of string: %d\n", len);	
	printf("%s\n", src);
	
	for(int i=0;i<20;i++)
		printf("%d ",src[i]);
	
	return 0;
}



//------例子二

#include<stdio.h>
#include<string.h>

int main()
{
	char src[20] = "hello PGA";
	char *ptr = "hello PGA";     // what are the difference between ptr and src? 一个是字符串，一个是指针

	printf("Length of src: %ld\n", strlen(src));	
	printf("Length of ptr: %ld\n", strlen(ptr));	
	
	*(src+6) = '\0';  //字符串可以改变
	*(ptr+6) = '\0';  // Do you think this is correct? 不对，这个pointer不能变，除非用malloc 

	//src[6] = '\0';
	//ptr[6] = '\0';
	
	printf("Length of src: %ld\n", strlen(src));	
	printf("Length of ptr: %ld\n", strlen(ptr));	
	
	return 0;
}


//------例子三

#include <stdio.h>
 
void sort_array_ascending(float arr[], int length);
void sort_array_descending(float* arr, int length);
 
int main()
{
    int num, i;
 
    printf("Enter number of elements: ");
    scanf("%d", &num);
    float heap[num]; 
    printf("Enter the elements: ");
    for (i = 0; i < num; i++)
       scanf("%f", &heap[i]);

    printf("\nThe sorted array are:\n");
    printf("Ascending order: ");
    sort_array_ascending(heap, num);
    for (i = 0; i < num; i++)
       printf("%f ", heap[i]);

    printf("\nDescending order: ");
    sort_array_descending(heap, num);
    for (i = 0; i < num; i++)
       printf("%f ", heap[i]);
    printf("\n");
            
    return 0;
}

void sort_array_ascending(float arr[], int length)
{
	int i=0, j=0, min_idx;
 
    // One by one move boundary of unsorted subarray
    do
    {
         // Find the minimum element in unsorted array
        min_idx = i;
        j = i+1;
        do
        {
            if (arr[j] < arr[min_idx])
                min_idx = j;
            j++;
            
 		}while(j<length);
        // Swap the found minimum element
        // with the first element
        float temp = arr[min_idx];
    	arr[min_idx] = arr[i];
    	arr[i] = temp;
       	i++;
    }while(i < length); 
}

void sort_array_descending(float* arr, int length)
{
	int i=0, j=0, min_idx;
 
    // One by one move boundary of unsorted subarray
    do
    {
         // Find the minimum element in unsorted array
        min_idx = i;
        j = i+1;
        do
        {
            if (arr[j] > arr[min_idx])
                min_idx = j;
            j++;
            
 		}while(j<length);
        // Swap the found maximum element with the first element
        float temp = arr[min_idx];
    	arr[min_idx] = arr[i];
    	arr[i] = temp;
       	i++;
    }while(i < length); 
}
