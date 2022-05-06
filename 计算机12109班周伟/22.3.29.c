#include<stdio.h>
#include<string.h>

int main(void)
{
	char a[]={"xIrCj~<r|2tWsv3PtIzndka"};
	char b[24];
	int i;
	for(i=0;i<0x18;++i)
	{
		b[i]=(a[i]^6)-1;	
		
	}	
	puts(b);
	
	return 0;
}
