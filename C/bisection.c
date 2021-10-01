#include<stdio.h>
#include<conio.h>
#include<math.h>
float f(float x)
{
    return x*x*x-x-1;
}

int main()
{

    int i=0;
    float a,b,c,d;
    printf("enter the value of intervals at a,b:");
    scanf("%f%f",&a,&b);
    printf("enter the value of tolerance:");
    scanf("%f",&d);
    do
    {
    c=(a+b)/2;
    ++i;
    if(f(a)*f(c)<0 || f(a)<0)
    {
        b=c;
        printf("the value of a and b at %d iteration is %f %f", i ,a,b);
    }
    else 
    {
        a=c;
        printf("the value of a and b at %d iteration is %f %f", i,a,b);
    }
    } while (fabs(a-b)>d|| f(c)==0 );
    printf("the roots are :",c);
    return 0;
    
}