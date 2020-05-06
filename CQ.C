#include<stdio.h>
#include<conio.h>
#include<process.h>
#define MAX 4
#define NIL -1
typedef struct Queuetype
{
 int a[MAX];
 int front;
 int rear;
 } Queue;

void main()
{
void insertionincqueue(Queue *, int);
int deletionincqueue(Queue *);
int isfullcq(Queue *);
int isemptycq(Queue *);
int choice,x,item,i;
Queue cq;
cq.front= NIL;
cq.rear= NIL;
clrscr();
while(1)
{
printf("Menu");
printf("/n 1.Insertion 2.Deletion 3.Exit");
printf("Enter your choice:");
scanf("%d", &choice);
switch(choice)
{
case 1:
 x=isfullcq(&cq);
 if(x==1)
 {
  printf("Queue is Full");
 }
 else
 {
  printf("Enter the elemnt to be inserted:");
  scanf("%d",&item);
  insertionincqueue(&cq,item);
  printf("Inserted element is=%d", item);
  }
 break;
case 2:
 x= isemptycq(&cq);
 if(x==1)
 {
  printf("Queue is Empty");
  }
 else
 {
 item=deletionincqueue(&cq);
 printf("Deleted element is=%d", item);
  }
  break;
case 3:
 exit(1);
default:
 printf("Entered choice is incorret");
 }
 getch();
 }
}/*Main closed*/

void insertionincqueue(Queue *cq, int item)
{
 int i, front, rear;
 if(cq->front==-1 && cq->rear== -1)
 {
 (cq->front= cq->front+1);
 (cq->rear= cq->rear+1);
 }

 else if(cq->rear==MAX-1)
 {
  cq->rear=0;
  }

 else
 {
 cq->rear= cq->rear+1;
 }
 cq->a[cq->rear]=item;
}

 int deletionincqueue(Queue *cq)
 {
  int item;
  item= cq->a[cq->front];
  if(cq->front== cq->rear)
  {
   cq->front= cq->rear= -1;
   }

   else if(cq-> front== MAX-1)
   {
     cq-> front=0;
   }

   else
    {
    cq->front= cq->front+1;
    }
    return item;

}

 int isfullcq(Queue *cq)
 {
  if((cq-> front==0 && cq-> rear== MAX-1) || (cq-> front-cq-> rear==1))
   return 1;
  else
   return 0;
  }

  int isemptycq(Queue *cq)
 {
  if(cq-> front==-1 && cq-> rear== -1)
   return 1;
  else
   return 0;
  }