
#include "malloc.h"
#include "conio.h"
#include "stdio.h"
//#include<windows.h>
#define overflow 0
#define ok 1
#define initsize 50
#define listincrement 10
typedef int Elemtype;
typedef int Status;
struct{
 Elemtype *elem;
 int length;
 int listsize;
}L;

Status initlist()
{ L.elem=(Elemtype*)malloc(initsize*sizeof(Elemtype));
  if(!L.elem)exit(overflow);
  L.length=0;
  L.listsize=initsize;
  return ok;
}

create()
{ Elemtype *p=L.elem;
  int i;
  printf("\n\t\t\t������˳���ĳ��ȣ�");
  scanf("%d",&L.length);
  if(L.length==0){printf("\n\t\t\t�˱�Ϊ�ձ�");return; }
  printf("\n\t\t\t������%d��Ԫ��",L.length);
  for(i=1;i<=L.length;i++)
    scanf("%d",p++);
  //clrscr();
  //system("CLS");
  printf("\n\t\t\tԭʼ˳���Ϊ��");
  for(i=1;i<=L.length;i++)
    printf("%d   ",L.elem[i-1]);
}

delete(int x)
{ int i,flag=0;
  Elemtype *q,*p,*r;
  p=L.elem;
  q=p;
  q=q+L.length-1;
  while(p<=q)
    {
      while(x!=*p&&p<=q) ++p;
	if(x!=*p) break;
	else {  r=p;
		for(++p;p<=q;++p) *(p-1)=*p;
		L.length--;
	     }
      r++;
      p=r;
      q=q+L.length-1;
    }
  if(L.length==0)
    {printf("\n\t\t\t������Ҫɾ����Ԫ��");
     return;
    }
 if(L.length==0)
   {printf("\n\t\t\tɾ���������˳����Ϊ�ձ�");
    return;
   }
 printf("\n\t\t\tɾ���������˳���Ϊ��");
 for(i=1;i<=L.length;i++)
   printf("%d   ",L.elem[i-1]);
 return;
}

main()
{int x,i;
 char c;
 do{
    //clrscr();
    initlist();
    create();
    getchar();
    if(L.length!=0)
      {
       printf("\n\t\t\t please input the value to be deleted"); //������Ҫɾ����Ԫ��ֵ
       scanf("%d",&x);
       delete(x);
       getchar();
      }
       printf("\n\t\t\t������������Y��y���˳��������");
       c=getchar();
   }while(c=='Y'||c=='y');
}
