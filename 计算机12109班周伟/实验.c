#include<stdio.h>
#include<string.h>

int wei=0;

void nextl(int next[],char str[])
{
	next[0]=-1;
	next[1]=0;
	int i=2;
	int index=0;
	while(i<strlen(str))
	{
		if(str[index]==str[i-1])
		{
			next[i++]=++index;
		}
		else if(index>0)
		{
			index=next[index];
			
		}else
		{
			next[i++]=0;
		}
		
	}
}

void kmp(char a[],char b[]);

int main(void)
{
	
	int n;
	scanf("%d",&n);
	getchar();
	int i;
	char a[n][200];
	for(i=0;i<n*2;i++)
	{
		gets(a[i]);
		
	}
	for(i=0;i<2*n;i+=2)
	{
		kmp(a[i+1],a[i]);
		printf("%d",wei);
		printf("weiweiwei");
	}
	

	
	return 0;
}

void kmp(char a[],char b[])
{
	int i,j;
	i=j=0;
	int next[strlen(b)];
	nextl(next,b);
	while(i<strlen(a))//&&j<(signed int)strlen(b))
	{
		
		if(a[i]==b[j]||j==-1)
		{
			i++;
			j++;
			
			if(j>=strlen(b))
			{
				wei++;
			}
			
		}else
		{
		
			j=next[j];
		}	
	}
	
}
