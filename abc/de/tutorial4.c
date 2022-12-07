//函数结合指针

//----------------------Pass by value---------------------------
#include<stdio.h>

int func(int arg1,int arg2);

int main()
{
    int a=1;
    int b=2;
    int c=func(a,b);
    printf("%d,%d,%d\n",a,b,c);
}

int func(int arg1,int arg2)
{
    arg1=arg1+arg2;
    return arg1;
}

//------------------------Pass by references-----------------------
#include<stdio.h>

void func(int* arg1,int* arg2)
{
    int value;
    value=*arg1;
    *arg1=*arg2;
    *arg2=value;
}

int main()
{
    int a=1;
    int b=2;
    func(&a,&b);
    printf("%d,%d\n",a,b);
}

//-------------按升序排列数组，并打印出数组中的唯一数字-------------------
#include <stdio.h>


void array_sort(int arr[], int length);
void array_unique_member_print(int arr[], int length);


int main()
{ 
	int len; //要先在main函数中求出length,相当于求出数组中元素的个数
	printf("Enter the length of an array: ");
	scanf("%d", &len);
	
	int array[len];
	for(int i=0; i<len; i++)
	{
		printf("Enter item %d: ", i);
		scanf("%d", &array[i]);
	}

	printf("Unique members of the array:\n");
	array_unique_member_print(array, len);
	
	array_sort(array, len);
	printf("\nSorted array:\n");
	for(int i=0; i<len; i++)
		printf("%d\n", array[i]);
}

// Bubble sort
void array_sort(int arr[], int length) //里面的int arr[]只是表示一个地址，
//int length才能表示出数组中有多少个元素
{
	int i,j;
	for(i=0; i<length-1; i++) //一共有几趟（10个数需要排9趟）
		for(j=0; j<length-1-i; j++)//一趟中冒泡排序的数量，
        //比如9个数字待排序，需要8对来比较
		{
			if(arr[j]>arr[j+1])
			{
				int value = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = value;
			}
		}
	
}


void array_unique_member_print(int arr[], int length)
{
	int i,j,k;
	for(i=0; i<length; i++)
	{
		k = 0;
		for(j=0; j<length; j++)
		{
			if(i!=j && arr[i] == arr[j])
				k = 1;
		}
		if(k==0)
			printf("%d\n", arr[i]);
	}
}


//--------------区分函数传参里面的是指针--------------------------
#include<stdio.h>

void pass_by_array(int arr[]);

int main(int argc,char* argv[])
{
    int arr[10];
    int value=sizeof(arr); //这里打印出来是40， 4x10
    printf("The size of array in main() is %d\n",value);

    pass_by_array(arr);
}

void pass_by_array(int arr[])//这里实际上是指针（相当于一个地址），不是数组
{
    int value=sizeof(arr);//而这里打印出来是4，相当于是指针的大小
    printf("The size of array passing to a function is %d\n",value);
}

