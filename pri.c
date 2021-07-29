#include <stdio.h>
#include <math.h>
int pri(int n)//素数判断 
{
	int i=0;
	if(n==2)
	{
	 return 1;
    }
   else
   {
   for(i=2;i<=sqrt(n);i++)
   {
      if(n%i==0)
      {
	     return 0;
	  }
   }
   return 1;
    }
}

int main()
{
	int a;
	printf("输入需要判断是否为素数的数>：");
	scanf("%d",&a); 
   int m=pri(a);//当返回1为素数，返回0不是素数 
   if(m==1)
   {
   printf("素数");
   }
   else
   {
   printf("不是素数");
   }
   return 0;
}





