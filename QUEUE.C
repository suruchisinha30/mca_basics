#include<stdio.h>
#include<conio.h>
#include<process.h>
#define MAX 10
#define NIL -1
typedef struct Queuetype
{
 int a[MAX];
 int front;
 int rear;
 } Queue;

void main()
{
void InsertioninQueue(Queue *, int);
int DeletioninQueue(Queue *);
int isfull(Queue *);
int isempty(Queue *);
int choice,x,item,i;
Queue Q1,Q2;
Q1.front= NIL;
Q1.rear= NIL;
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
 x=isfull(&Q1);
 if(x==1)
 {
  printf("Queue is Full");
  break;
 }
 else
 {
  printf("Enter the elemnt to be inserted:");
  scanf("%d",&item);
  InsertioninQueue(&Q1,item);
  printf("Inserted element is=%d", item);
  }

 break;
case 2:
 x= isempty(&Q1);
 if(x==1)
 {
  printf("Queue is Empty");
  }
 else
 {
 item=DeletioninQueue(&Q1);
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

void InsertioninQueue(Queue *Q1, int item)
{
 int i, front, rear;
 if(Q1->front==-1 && Q1->rear== -1)
 {
 (Q1->front= Q1->front+1);
 (Q1->rear= Q1->rear+1);
 }

 else if(Q1->rear==MAX-1)
 {
  for(i=Q1->front; i<=Q1->rear; i++)
  {
   Q1->a[i-(Q1->front)]= Q1->a[i];
  }
   Q1->rear= Q1->rear- Q1->front;
   Q1->front=0;
   Q1->rear= Q1->rear+1;
  }

 else
 {
 Q1->rear= Q1->rear+1;
 }
 Q1->a[Q1->rear]=item;
}
 int DeletioninQueue(Queue *Q1)
 {
  int item;
  item= Q1->a[Q1->front];
  if(Q1->front== Q1->rear)
   Q1->front= Q1->rear= -1;
   else
    Q1->front= Q1->front+1;
    return item;
 }

 int isfull(Queue *Q1)
 {
  if(Q1-> front==0 && Q1-> rear== MAX-1)
   return 1;
  else
   return 0;
  }

  int isempty(Queue *Q1)
 {
  if(Q1-> front==-1 && Q1-> rear== -1)
   return 1;
  else
   return 0;
  }