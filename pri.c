#include <stdio.h>
#include <math.h>
int pri(int n)//�����ж� 
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
	printf("������Ҫ�ж��Ƿ�Ϊ��������>��");
	scanf("%d",&a); 
   int m=pri(a);//������1Ϊ����������0�������� 
   if(m==1)
   {
   printf("����");
   }
   else
   {
   printf("��������");
   }
   return 0;
}





