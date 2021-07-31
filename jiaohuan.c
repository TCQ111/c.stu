#include <stdio.h>

int main()
{
	int a=19;
	int b=20;
    a=a^b;
    b=a^b;
    a=a^b;
	printf("%d  %d",a,b);
   return 0;
} 
