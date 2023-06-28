#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"

#define MAX_BUCKETS 100
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

/*创建一个节点*/
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

/*计算哈希值*/
static unsigned long hashstring(const char *str)
{

}

/*在一个链表中查找人名，找到返回指针，找不到返回NULL*/
static PNode find(PNode wp , const char *str)
{

}

/*将在散列表中查找相应节点，并进行相应操作，找到返回指针，没找到则创建节点并加入散列表,并返回指针*/
static PNode lookup(const char *str)
{

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

    memset(table, 0, sizeof(table));

    int count = 0;
    while (1) {
        if (fscanf(fp, "%s", word) != 1)
            break;
        name = strtok(word, ",");
        ////begin
        //加入散列表，2条语句实现

        ////end
 
        count++;
    }
    printf("%d \n", count);
    fclose(fp);
}

/*将散列表写入文件*/
void file_write_ht()
{
    FILE *fp;
    int count = 0;

    if((fp=fopen("output.txt","wt")) == NULL ) {
        printf("Fail to open file!\n");    
        exit(0);  
    }

    ////begin


    ////end
    printf("%d\n", count);   
}

/*搜索功能*/
void search_ht()
{
    char name[LENGTH]; 
    printf("Enter name, 'q' to exit：\n");
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




