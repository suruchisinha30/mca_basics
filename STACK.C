#include<stdio.h>
#include<conio.h>
#include<process.h>
#define MAX_STACK 10  /*for max size of stack*/
#define NIL -1         /*because array index in c begins with 0*/
typedef struct stacktype     /*typedef is a keyword*/
{
 int a[MAX_STACK]; 
 int TOP;
 } stack;

void main()  /*main function*/
{
int x, item, choice;
stack S1;

void PUSH(stack *, int); 
int POP(stack *);
int isoverflow(stack *);
int isunderflow(stack *);
int PEEP(stack *);
S1.TOP=NIL;
clrscr();
while(1)
{
printf("Menu");
printf("/n 1.PUSH 2.POP 3.PEEP 4.Exit");
scanf("%d", &choice);
switch(choice)  /*function calling*/
{
case 1:
 x=isoverflow(&S1);
 if(x==1)
 {
 printf("Stack is getting Overflow");
 }
 else
 {
 printf("Enter the item to be pushed:");
 scanf("%d", &item);
 PUSH(&S1, item);
 printf("Item is pushed");
 }
 break;
case 2:
 x= isunderflow(&S1);
 if(x==1)
 {
  printf("Stack is getting Underflow");
  }
 else
 {
  item= POP(&S1);
  printf("Poped element is=%d", item);
  }
 break;
case 3:
 x= isunderflow(&S1);
 if(x==1)
 {
  printf("Stack is getting Underflow");
  }
 else
 {
  item= PEEP(&S1);
  printf("Peeped element is=%d", item);
  }
 break;
case 4:
 exit(1);
default:
 printf("Entered choice is incorret");
 }
 getch();
 }
}/*Main closed*/

void PUSH(stack *P, int item)  /*define push operation*/
{
 P-> TOP= P-> TOP+1;
 P-> a[P-> TOP]= item;
}
 int POP(stack *P)  /*define peep operation*/
 {
  int item;
  item= P-> TOP=(P-> TOP);
  P-> TOP= P-> TOP-1;
  return item;
 }

 int PEEP(stack *P)  /*define peep operation*/
 {
  int item;
  item= P-> TOP=(P-> TOP);
  return item;
 }

 int isoverflow(stack *P)  /*define isoverflow function*/
 {
  if(P-> TOP==MAX_STACK)
   return 1;
  else
   return 0;
  }

  int isunderflow(stack *P)  /*define isunderflow function*/
 {
  if(P-> TOP==NIL)
   return 1;
  else
   return 0;
  }