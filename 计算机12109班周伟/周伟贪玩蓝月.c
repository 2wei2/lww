#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void wei1(void);

struct film{
		char a[80];
		char b[4];
		char c[4];
		struct film *next;
	}movies;
struct film* creat(struct film*p);
struct film* p;
struct film* head=NULL;
int add(char n[4],struct film*p);
int de_ete(char n[4],struct film*p);
void empty(struct film*p);
int change(char n[4],struct film* p);
int query(char n[4],struct film*p);
void expor_t(struct film*p);
int load();
int main(void)
{	
	char wen=1,wen3=1,wen5=1,wen6=0,wen7=1;
	int a1=8,jie=0;
	int a3,a4,wei=0,a9;
	char a5[4],a6[4],a7[4],a8[4];
	while(a1>0)
	{
	
		printf("����"); 
		a1--;
	}
	a1=8;
	printf("��ӭ����̰������");
		while(a1>0)
	{
	
		printf("����"); 
		a1--;
	}
	printf("\n(�밴�س�����ʼ)");
	getchar();
 while(1)
 {
	wen=1;
	wen3=1;
	wen5=1;
	wen6=1;
	printf("                            1.�µ���Ϸ   2.��ȡ�浵\n"); 
    printf("                            3.�������   4.�˳���Ϸ\n"); 
    scanf("%d",&a3);
    if(a3==4)
    {
    	wei1();
	}else
	if(a3==1)
	{
		wen7=0;
		printf("                            1.��������   2.����\n");
		scanf("%d",&a9);
		if(a9==1)
		{
		   printf("                            ��ӭ����ʿ���������ǵ�ս��������ѡ����Ľ�ɫ��ȡ�����ְ�\n");
		   printf("                            (���ڵ�һ�λ��������ָ���ʹ�á��µ���Ϸ��)\n");
		   printf("                            �밴���� id �������˳�����루over -1 -1��ʾ������idΪ������999����������\n");
	       head=creat(head);
		}else
		if(a9==2)
		{
		   jie=load();
		}   	
	}
	else
	if(a3==2)
	{
		if(wen7)
		printf("                            ��Ǹ������δ������ɫ\n");
		else
		{
		printf("                            1.�鿴   2.���\n");
		printf("                            3.ɾ��   4.���\n");
		printf("                            5.����   6.��ѯ\n");
		printf("                            7.����\n");
		scanf("%d",&a4);
		switch(a4)
		{
			case 1:
					if(jie)
					{
						p=head;
			     		while(p->next)
	             	 	{
	               			 printf("%s %s %s \n",p->a,p->b,p->c);
	    	        		 p=p->next;
    	         		}
					}else
					{
						p=head;
			     		while(p)
	             	 	{
	               			 printf("%s %s %s \n",p->a,p->b,p->c);
	    	        		 p=p->next;
    	         		}
					}
						
			break;
			case 2:printf("������id�ţ�������������µ����ݣ�");
				   p=head;
				   scanf("%s",a5);
				   wen=add(a5,p);
				   while(wen)
				   {
				   	printf("��Ǹ����id���������룺");
				   	scanf("%s",a5);
				    wen=add(a5,p);
				   	
				   }
			break;
			case 3:printf("������id�ţ����ǽ���ɾ����");
				   scanf("%s",a6);
				   p=head;
				   wen3=de_ete(a6,p);
				   while(wen3)
				   {
				   	printf("��Ǹ����id���������룺");
				   	scanf("%s",a6);
				   	wen3=de_ete(a6,p);
				   }
			break;
			case 4: p=head;
					empty(p);
					wen7=1;
			break;
			case 5:printf("������id�ţ����ǽ�����ģ�");
				   scanf("%s",a7);
				   p=head;
				   wen5=change(a7,p);
				   while(wen5)
				   {
				   	printf("��Ǹ����id���������룺");
				   	scanf("%s",a7);
				   	wen5=change(a7,p);
				   }
			break;
			case 6:printf("������Ҫ��ѯ��id�ţ�");
				   scanf("%s",a8);
				   p=head;
				   wen6=query(a8,p);
				   while(wen6)
				   {
				   		printf("��Ǹ����id���������룻");
				   		scanf("%s",a8);
				   		wen6=query(a8,p);
				   }
			break;
			case 7:p=head;
					expor_t(p);
			break;
			
		}
		
		}
	
	  
	}else
	if(a3==3)
	{
		printf("                          	δ�����,�����ڴ�\n");
	}
 }
	
	return 0;
}

void wei1(void)
{
	int a,b,c;
	

		printf("                            ��������������뿪��");
		printf("                            1.�����¿��� 2.�����˳�\n");
	
	scanf("%d",&a);
	if(a==2)
	exit(1);
	
}
struct film* creat(struct film*p)
{
	struct film *pre,*current,*old;
	int m=3;
	char x[4],y[4];
	char ch[80];
	scanf("%s %s %s",ch,x,y);
	
	while(strcmp(ch,"over")&&strcmp(x,"-1")&&strcmp(y,"-1"))
	{
		current=(struct film*)malloc(sizeof(struct film));
		if(p==NULL)
		{
			p=current;
			old=current;
		}
				
		else
		pre->next=current;
		strcpy(current->b,x);
		strcpy(current->c,y);
		strcpy(current->a,ch);
		current->next=NULL;
		pre=current; 
		getchar();
		scanf("%s %s %s",ch,x,y);
	} 
	printf("�����������Ľ�ɫ��\n");
	while(p)
	{
		printf("%s %s %s \n",p->a,p->b,p->c);
		p=p->next;
	}
	return old;
}

int add(char n[4],struct film*p)
{
	struct film *current,*fir;
	current=(struct film*)malloc(sizeof(struct film));
	current->next=NULL;
	int i;
	fir=p;
	int wen=1;
	scanf("%s %s %s",current->a,current->b,current->c);
	while(p)
	{
		if(strcmp(p->b,n)==0)
		{
			p=p->next;
			current->next=p;
			break;	
		}
		else
		p=p->next;
	}
	while(fir)
	{
		if(strcmp(fir->b,n)==0)
		{
			fir->next=current;
			wen=0;
			break;
		}
		else
		fir=fir->next;
	}
	return wen;
}

int de_ete(char n[4],struct film*p)
{
	int wen=1;
		struct film *fir;
	fir=p;
	while(p)
	{
		if(strcmp(p->b,n)==0)
		{
			wen=0;
			break;
		}else
		fir=p;
		p=p->next;
	} 
	if(p==NULL)
	{
		printf("��Ǹ�������ݴ���:");
	}
	else
	{
		if(p==head)
		{
			head=head->next;
			wen=0;
			free(p);
		}else
		{
			fir->next=p->next;
			free(p);
			wen=0;
		}
		
	}
	return wen;
}

void empty(struct film*p)
{
	while(p->next)
	{
		p=head;
		head=p->next;
		free(p);
	}
}

int change(char n[4],struct film* p)
{
	int wen=1;
	char ch[20],x[4],y[4];
	printf("�������µ����ݣ�");
	scanf("%s %s %s",ch,x,y);
	while(p)
	{
		if(strcmp(p->b,n)==0)
		{
			strcpy(p->a,ch);
			strcpy(p->b,x);
			strcpy(p->c,y);
			wen=0;
			break;
		}else
		p=p->next;
	}
	return wen;
}

int query(char n[4],struct film*p)
{
	int wen;
	while(p)
	{
		if(strcmp(p->b,n)==0)
		{
			printf("%s %s %s\n",p->a,p->b,p->c);
			wen=0;
			break;
		}else
		p=p->next;
	}
	return wen;
}
	
void expor_t(struct film*p)
{
	FILE *fp=fopen("wei.txt","w");
	while(p)
	{
		fprintf(fp,"%s %s %s\n",p->a,p->b,p->c);
		p=p->next;
	}
	
	fclose(fp);
}

 int load()
{
	int jie=1;
		FILE *fp;
	char x[100];
    char y[20];
    char z[20];
    struct film *cur;
    if((fp=fopen("wei.txt","r"))==NULL)
    {
       printf("File open error!\n"); 
       exit(0);
    }
    while(!feof(fp))
    {
       fscanf(fp,"%s%s%s",x,y,z); 
       p = (struct film *)malloc(sizeof(struct film));
       p->next = NULL;
       strcpy(p->a,x);
       strcpy(p->b,y);
       strcpy(p->c,z);
       if(head==NULL)
       {
           head = p;
           cur = head;       
       }
       else
       {
           cur->next = p;
           cur = p;
       }   
    }
    if(fclose(fp)){
       printf( "Can not close the file!\n" );
       exit(0);
   }
   return jie;
}
	
