
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
  printf("\n\t\t\t请输入顺序表的长度：");
  scanf("%d",&L.length);
  if(L.length==0){printf("\n\t\t\t此表为空表");return; }
  printf("\n\t\t\t请输入%d个元素",L.length);
  for(i=1;i<=L.length;i++)
    scanf("%d",p++);
  //clrscr();
  //system("CLS");
  printf("\n\t\t\t原始顺序表为：");
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
    {printf("\n\t\t\t表中无要删除的元素");
     return;
    }
 if(L.length==0)
   {printf("\n\t\t\t删除操作后的顺序表表为空表");
    return;
   }
 printf("\n\t\t\t删除操作后的顺序表为：");
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
       printf("\n\t\t\t please input the value to be deleted"); //请输入要删除的元素值
       scanf("%d",&x);
       delete(x);
       getchar();
      }
       printf("\n\t\t\t继续操作输入Y或y，退出按任意键");
       c=getchar();
   }while(c=='Y'||c=='y');
}
