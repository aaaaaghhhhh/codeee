#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//#include<math.h>

int main(void)
{
    float weight=0;
    float height=0;
    float BMI=0;
   //BMI= weight/(height*height); BMI不能写在这一行，否则会显示#IND00 表示不合法计算
    printf("Enter height(in meter) and weight(in kg) :");
    scanf("%f %f",&height,&weight);
    //printf("Enter weight(in kg):");
    //scanf("%f",&weight);
    // 也可以分开打印
    
    BMI= weight/(height*height);
    printf("BMI is %.1f\n",BMI);

    if (BMI<=18.4)
    {
        printf("You are Underweight");
    }
    else if(18.4<BMI<=24.9)
    {
        printf("You are Normal");
    }
    else if(24.9<BMI<30.0)
    {
        printf("You are Overweight");
    }
    else if(BMI>=30.0)
    {
        printf("You are Obese");
    }
    
    return 0;
}
     




