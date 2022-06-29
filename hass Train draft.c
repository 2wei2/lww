#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"
#include  <math.h>
#define MAX_BUCKETS 1000				//����ĳ�1000 
#define MULTIPLIER 31

#define LENGTH 30
typedef struct User_login{
   char name[LENGTH];  
   int totalcount;
}ELementType;                 //����Ľڵ� 

typedef struct SListNode
{
 ELementType data;
 struct SListNode* next;
}Node, *PNode, *List;              //��װ����ڵ��nextָ�� 


static PNode table[MAX_BUCKETS];

static unsigned long hashstring(const char *str);
static void cleartable();
static PNode walloc(const char *str);
static PNode lookup(const char *str);
static PNode find(PNode wp , const char *str);

//����һ���ڵ� 
static PNode walloc(const char *str)
{
    PNode p = (PNode)malloc(sizeof(Node));
    if (p != NULL) {
        strcpy(p->data.name, str);
        p->data.totalcount = 0;
        p->next = NULL;
    }
    return p;
}

//�����ϣֵ 
static unsigned long hashstring(const char *str)
{
		unsigned long h=0;
		int i,n;
		n=strlen(str);
		for(i=0;i<n;i++)
		{
			h+=str[i]*pow(31,i);
		}
		return h%1000;
	
}

/*��һ�������в����������ҵ�����ָ�룬�Ҳ�������NULL*/
static PNode find(PNode wp , const char *str)
{
	
	
	while(wp!=NULL&&strcmp(wp->data.name,str))
	{
		wp=wp->next;
	}
	
	return wp;

}

/*����ɢ�б��в�����Ӧ�ڵ㣬��������Ӧ�������ҵ�����ָ�룬û�ҵ��򴴽��ڵ㲢����ɢ�б�������ָ��*/
static PNode lookup(const char *str)
{
	PNode wp=NULL;
	char word[100];
	strcpy(word,str);
	char *name;
	name = strtok(word, ",");
	signed long pos=hashstring(name);
	PNode p=table[pos];
	while(p!=NULL&&strcmp(p->data.name,str))
	{
		p=p->next;
	}
	
	if(p!=NULL)
	{
		return p;
	}
	else
	{
		wp=walloc(str);
		wp->next=table[pos];
		table[pos]=wp;
	}
}

/*ɾ��ɢ�б�*/
static void cleartable()
{
    PNode wp = NULL, p = NULL;
    int i = 0;

    for (i = 0; i < MAX_BUCKETS; i++) {
        wp = table[i];
        while (wp) {
            p = wp;
            wp = wp->next;
            free(p);
        }
    }
}

/*��ȡ�ļ�������ɢ�б�*/
void file_read_ht()
{
    FILE *fp = fopen("user_login.txt", "r");
    char word[1024];
    char *name;
    PNode wp = NULL;
	int i;
	for(i=0;i<MAX_BUCKETS;i++)
	{
		table[i]=NULL;
	}
	
    memset(table, 0, sizeof(table));

    int count = 0;
    while (!feof(fp)) {								//����while���������� 
        
            
        fscanf(fp, "%s", word);
        name = strtok(word, ",");
        ////begin
        //����ɢ�б�2�����ʵ�� 
			signed long wei=hashstring(name);
			wp=walloc(word);
			wp->next=table[wei];
			table[wei]=wp;
				
        ////end
 
        count++;
    }
    printf("%d \n", count);
    fclose(fp);
}

/*������д���ļ�*/
void file_write_ht()
{
    FILE *fp;
    int count = 0;
	int count = 0;
	char ch[30];
    if((fp=fopen("output.txt","wt")) == NULL ) {
        printf("Fail to open file!\n");    
        exit(0);  
    }

    ////begin
	for(i=0;i<1000;i++)								//����Ϊ�˱�֤��ӡ�ĵ�ʱ�����ۣ����ǵ�����һ�£��ÿո�ͻس����ָ�; 
    {
    	itoa(i,ch,10);
    	fputs("table[i]=",fp);
    	fputs(ch,fp);
    	fputs("    ",fp);
    	while(table[i])
    	{
    		fputs(table[i]->data.name,fp);
    		fputs("    ",fp);
    		table[i]=table[i]->next;
		}
		fputc('\n',fp);
		fputc('\n',fp);
		fputc('\n',fp);
	}		
			

    ////end
    printf("%d\n", count);   
}

/*��������*/
void search_ht()
{
    char name[LENGTH]; 
    printf("Enter name, 'q' to exit:\n");
    scanf("%s", name);    
     
    while (strcmp(name, "q")) {
        unsigned long hash = hashstring(name);
        PNode wp = table[hash];
        PNode curr = NULL;

        ////begin


        ////end

        scanf("%s", name);
    }    

    cleartable();     
}




