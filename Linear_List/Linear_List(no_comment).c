#include <stdio.h>      
#include <stdlib.h> 
#define Maxsize 100

typedef int DataType;

struct SeqList
{
    DataType data[Maxsize];  
    int size;                
};

typedef struct SeqList List;

void ListInitiste(List* L);           
int ListInsert(List* L, int i, DataType x);  
int ListLength(List* L);              
int ListChange(List* L, int i, DataType x);  
int ListGet(List* L, int i, DataType* x);    
void ListPrint(List* L);              



void ListInitiste(List* L)
{
    L->size = 0;
}


int ListInsert(List* L, int i, DataType x)
{
    int j;  
    if (L->size >= Maxsize)
    {
        printf("错误：线性表已满，无法插入！\n");
        return 0; 
    }

    if (i < 1 || i > L->size + 1)
    {
        printf("错误：插入位置不合法！\n");
        return 0; 
    }


    for (j = L->size; j >= i; j--)  //设当前填充了0-9，此时j=10
    {
        L->data[j] = L->data[j - 1];  
    }
  
    L->data[i - 1] = x;  // 第i个位置对应数组下标i-1 
    L->size++;

    return 1; 
}


int ListLength(List* L)
{
    return L->size; 
}


int ListChange(List* L, int i, DataType x)
{
    int j; 

    if (i < 1 || i > L->size)
    {
        printf("错误：位置不合法！\n");
        return 0;  
    }


    if (x == -99999)  //-99999代表null，执行删除操作
    {
        for (j = i; j < L->size; j++)
        {
            L->data[j - 1] = L->data[j];    //设i=5，此时删除a[4](a[0]时i=1，则a[4]时i=5)
            //所以data[j-1]=data[4]，要替换成data[5]
        }
        L->size--; 
        printf("位置 %d 的元素已删除\n", i);
    }
    else 
    {
        L->data[i - 1] = x;
        printf("位置 %d 的元素已修改为 %d\n", i, x);
    }

    return 1; 
}


int ListGet(List* L, int i, DataType* x)
{
  
    if (i < 1 || i > L->size)
    {
        printf("错误：位置不合法！\n");
        return 0; 
    }

    *x = L->data[i - 1]; 

    return 1; 
}


void ListPrint(List* L)
{
    int i; 

    printf("线性表内容：[");
    for (i = 0; i < L->size; i++)
    {
        printf("%d", L->data[i]);
        if (i < L->size - 1)
        {
            printf(", ");
        }
    }
    printf("]\n");
    printf("当前元素个数：%d\n", L->size);
}


int main()
{
    List L;    /* 声明一个线性表变量L */
    int i;        
    DataType x;  

    printf("========== 线性表操作演示 ==========\n\n");

    printf("【步骤1】初始化线性表\n");
    ListInitiste(&L); 
    printf("初始化完成，当前元素个数：%d\n\n", ListLength(&L));


    printf("【步骤2】将正整数1至10存入表L的前十个位置\n");
    for (i = 1; i <= 10; i++)
    {
        ListInsert(&L, i, i);
    }
    printf("插入完成！\n");
    ListPrint(&L);
    printf("\n");


    printf("【步骤3】测试求长度函数\n");
    printf("当前线性表长度：%d\n\n", ListLength(&L));


    printf("【步骤4】测试提取函数\n");
    if (ListGet(&L, 5, &x))  
    {
        printf("第5个元素是：%d\n", x);
    }
    if (ListGet(&L, 1, &x))  
    {
        printf("第1个元素是：%d\n", x);
    }
    if (ListGet(&L, 10, &x)) 
    {
        printf("第10个元素是：%d\n", x);
    }
    printf("\n");

 
    printf("【步骤5】测试修改函数\n");
    ListChange(&L, 3, 100); 
    ListPrint(&L);
    printf("\n");


    printf("【步骤6】测试删除函数\n");
    ListChange(&L, 5, -99999); 
    ListPrint(&L);
    printf("\n");


    printf("【步骤7】测试在中间位置插入\n");
    ListInsert(&L, 3, 999); 
    ListPrint(&L);
    printf("\n");

    printf("========== 演示结束 ==========\n");

    return 0; 
}
