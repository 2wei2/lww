#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"
#include  <math.h>
#define MAX_BUCKETS 1000				//这里改成1000 
#define MULTIPLIER 31

#define LENGTH 30
typedef struct User_login{
   char name[LENGTH];  
   int totalcount;
}ELementType;                 //链表的节点 

typedef struct SListNode
{
 ELementType data;
 struct SListNode* next;
}Node, *PNode, *List;              //封装链表节点和next指针 


static PNode table[MAX_BUCKETS];

static unsigned long hashstring(const char *str);
static void cleartable();
static PNode walloc(const char *str);
static PNode lookup(const char *str);
static PNode find(PNode wp , const char *str);

//创建一个节点 
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

//计算哈希值 
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

/*在一个链表中查找人名，找到返回指针，找不到返回NULL*/
static PNode find(PNode wp , const char *str)
{
	
	
	while(wp!=NULL&&strcmp(wp->data.name,str))
	{
		wp=wp->next;
	}
	
	return wp;

}

/*将在散列表中查找相应节点，并进行相应操作，找到返回指针，没找到则创建节点并加入散列表，并返回指针*/
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

/*删除散列表*/
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

/*读取文件，创建散列表*/
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
    while (!feof(fp)) {								//这里while的条件改了 
        
            
        fscanf(fp, "%s", word);
        name = strtok(word, ",");
        ////begin
        //加入散列表，2条语句实现 
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

/*将链表写入文件*/
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
	for(i=0;i<1000;i++)								//这里为了保证打印文档时的美观，我们调整了一下，用空格和回车来分割; 
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

/*搜索功能*/
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




