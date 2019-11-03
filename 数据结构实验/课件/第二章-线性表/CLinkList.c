
#include "malloc.h"
#include "conio.h"
#include "stdio.h"

#define OK 1
#define ERROR -1
typedef int ElemType;
typedef int Status;
typedef struct  LNode {
      ElemType      data;  // ������
      struct LNode   *next;  // ָ����
} LNode, *LinkList;
LinkList L;

void CreateList_L() //LinkList L, 
{    // �������� n ������Ԫ�أ�������ͷ���ĵ�����
  int i, n;
  LinkList p;
  printf("\n\t\t\t����������ĳ��ȣ�");
  scanf("%d",&n);
  if(n==0){printf("\n\t\t\t�˱�Ϊ�ձ�");return; }
  printf("\n\t\t\t������%d��Ԫ��",n);

  L = (LinkList)malloc(sizeof(LNode));
  L->next = NULL;
  for (i = n; i > 0; --i) {
    p = (LinkList)malloc(sizeof(LNode));
    scanf("%d",&p->data);    // ����Ԫ��ֵ
    p->next = L->next;  L->next = p;  // ����
  }
} // CreateList_L

void PrintList_L(LinkList L)
{
	L=L->next;
	printf("\n\t\t\t�����е�Ԫ��Ϊ��");
	while(L)
	{
		printf("%d  ",L->data);
		L=L->next;
	}
	return;
}

Status ListInsert_L(int i, ElemType e) //LinkList &L, 
{ // L Ϊ��ͷ���ĵ������ͷָ�룬���㷨��������
   // ��i �����֮ǰ�����µ�Ԫ�� e
   LinkList p, s;
   int j;     
   p = L;  j = 0;
   while (p && j < i-1) 
     { p = p->next;  ++j; }   // Ѱ�ҵ� i-1 �����
   if (!p || j > i-1)
      return ERROR;      // i ���ڱ�����С��1 
   s=(LinkList)malloc(sizeof(LNode)); 
   s->data = e; 
   s->next = p->next;  p->next = s; // ����
   return OK;
} // ListInsert_L


int main()
{
	int n, i;
	ElemType e;
	CreateList_L();
	printf("\n\t\t\t�����е�Ԫ��Ϊ��");
	PrintList_L(L);
	
	printf("\n\t\t\t�������ڵڼ���Ԫ��֮ǰ����һ����Ԫ�أ�");
	scanf("%d",&i);	
	
	printf("\n\t\t\t����������Ԫ�ص�ֵ��");
	scanf("%d",&e);	
	ListInsert_L(i,e);

	printf("\n\t\t\t������Ԫ��֮�������е�Ԫ��Ϊ��");
	PrintList_L(L);
	return OK;
}
