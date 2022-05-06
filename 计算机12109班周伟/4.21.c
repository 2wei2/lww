#include<stdio.h>

int *wei(int *a);
int main(void)
{
	
	int *a=1;
	int *c;
	c=wei(a);
	
	printf("%d",*c);
	return 0;
}

int *wei(int *a)
{
	int *b;
	*b=*a+1;
	
	return b;
}
