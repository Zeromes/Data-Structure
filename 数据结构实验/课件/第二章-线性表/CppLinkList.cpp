
#include "malloc.h"
#include "conio.h"
#include "stdio.h"

#define OK 1
#define ERROR -1
typedef int ElemType;
typedef int Status;
typedef struct  LNode {
      ElemType      data;  // 数据域
      struct LNode   *next;  // 指针域
} LNode, *LinkList;

void CreateList_L(LinkList &L) //LinkList L, 
{    // 逆序输入 n 个数据元素，建立带头结点的单链表
  int i, n;
  LinkList p;
  printf("\n\t\t\t请输入链表的长度：");
  scanf("%d",&n);
  if(n==0){printf("\n\t\t\t此表为空表");return; }
  printf("\n\t\t\t请输入%d个元素",n);

  L = (LinkList)malloc(sizeof(LNode));
  L->next = NULL;
  for (i = n; i > 0; --i) {
    p = (LinkList)malloc(sizeof(LNode));
    scanf("%d",&p->data);    // 输入元素值
    p->next = L->next;  L->next = p;  // 插入
  }
} // CreateList_L

void PrintList_L(LinkList L)
{
	L=L->next;
	printf("\n\t\t\t链表中的元素为：");
	while(L)
	{
		printf("%d  ",L->data);
		L=L->next;
	}
	return;
}

Status ListInsert_L(LinkList &L, int i, ElemType e) 
{ // L 为带头结点的单链表的头指针，本算法在链表中
   // 第i 个结点之前插入新的元素 e
   LinkList p, s;
   int j;     
   p = L;  j = 0;
   while (p && j < i-1) 
     { p = p->next;  ++j; }   // 寻找第 i-1 个结点
   if (!p || j > i-1)
      return ERROR;      // i 大于表长或者小于1 
   s=(LinkList)malloc(sizeof(LNode)); 
   s->data = e; 
   s->next = p->next;  p->next = s; // 插入
   return OK;
} // ListInsert_L

Status ListDelete_L(LinkList &L, int i, ElemType &e)
{   // 删除以 L 为头指针(带头结点)的单链表中第 i 个结点
   LinkList p, q;
   int j;
   p = L;    j = 0;
   while (p->next && j < i-1) {  p = p->next;   ++j; } 
                           // 寻找第 i 个结点，并令 p 指向其前驱
   if  (!(p->next) || j > i-1) 
     return ERROR;  // 删除位置不合理
   q = p->next;   p->next = q->next;  // 删除并释放结点
   e = q->data;   free(q);
   return OK;
} // ListDelete_L


int main()
{
	int n, i;
	ElemType e;
	LinkList L;
	CreateList_L(L);
	printf("\n\t\t\t 链表中的元素为：");
	PrintList_L(L);
	
	printf("\n\t\t\t 请输入在第几个元素之前插入一个新元素：");
	scanf("%d",&i);	
	
	printf("\n\t\t\t 请输入新元素的值：");
	scanf("%d",&e);	
	ListInsert_L(L,i,e);

	printf("\n\t\t\t 插入新元素之后链表中的元素为：");
	PrintList_L(L);
	
	printf("\n\t\t\t which one to be deleted?");
	scanf("%d",&i);	
	ListDelete_L(L,i,e);

	printf("\n\t\t\t The new list：");
	PrintList_L(L);

	printf("\n\t\t\t The deleted one is: %d", e);
	
	return OK;
}
