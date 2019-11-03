
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
LinkList L;

void CreateList_L() //LinkList L, 
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

Status ListInsert_L(int i, ElemType e) //LinkList &L, 
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


int main()
{
	int n, i;
	ElemType e;
	CreateList_L();
	printf("\n\t\t\t链表中的元素为：");
	PrintList_L(L);
	
	printf("\n\t\t\t请输入在第几个元素之前插入一个新元素：");
	scanf("%d",&i);	
	
	printf("\n\t\t\t请输入在新元素的值：");
	scanf("%d",&e);	
	ListInsert_L(i,e);

	printf("\n\t\t\t插入新元素之后链表中的元素为：");
	PrintList_L(L);
	return OK;
}
