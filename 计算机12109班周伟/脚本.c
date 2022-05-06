#include<stdio.h>
#include<string.h>




int main(void)
{
	int a=84;
	int i;
	char flag[6]={"[}eSSg"};
	a=a^0xDEADBEEF;
	//putchar(a^flag[0]); 
	int *ch;
	ch=&a;
	for(i=3;i>=0;i--)
	{
		putchar((char)*(ch+i));
	}
	return 0;
}
