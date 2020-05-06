#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<alloc.h>

typedef struct lklist //self refrential structure for single linear linked list
{
 int info;
 struct lklist *next;
 } node;

void main()
{
 int choice, item, after;
 void insertinbeginning(node**, int);
 void insertatend(node**, int);
 void traversing(node*);
 void traversing_in_reverse_order(node*);
 void deletefrombeginning(node**);
 void delete_from_end(node**);
 void delete_after_element(node**, int);
 void delete_entire_list(node**);
 int insert_after_element(node*, int, int);
 node* search(node*, int);
 node *head, *loc; //starting pointer to point first node of linked list
 head= NULL; //creation of empty linked list
 while(1)
 {
 clrscr();

  printf("Single Linked List\n");
  printf("1.Insert in Beginning\n 2. Insert at End\n 3.Insert after an element\n 4.Searching\n 5.Traversing\n 6.Traversing in Reverse order\n 7.Delete from Beginning\n 8.Delete from End\n 9.Delete after an element\n 10.Delete entire list\n 11.Insert at nth position\n 12.Exit\n");
  printf("Enter your choice:");
  scanf("%d", &choice);
  switch(choice)
  {
   case 1:
   //Insert in Beginning
   printf("Enter an item:");
   scanf("%d", &item);
   insertinbeginning(&head, item); //call by pointer
   printf("Insertion done successfully");
   break;

   case 2:
   //Insert at End
   printf("Enter an item:");
   scanf("%d", &item);
   insertatend(&head, item); //call by value
   printf("Insertion done successfully");

    break;

   case 3:
   //Insert after element
    printf("Enter item to be inserted:");
    scanf("%d", &item);
    printf("Enter value after which you want to insert:");
    scanf("%d", &after);
    insert_after_element(head, item, after);
    break;

   case 4:
   //Searching
   printf("Enter item to be searched:");
   scanf("%d", &item);
   loc= search(head, item);
   if(loc!=NULL)
    printf("Item found");
   else
    printf("Item not found");
   break;

   case 5:
   //Traversing
   if(head==NULL)
    printf("List is empty");
   else
    traversing(head);
    break;

   case 6:
   //Traversing in Reverse order
    if(head==NULL)
     printf("List is empty");
    else
     traversing_in_reverse_order(head);

    break;

   case 7:
   //Delete from Beginning
   if(head==NULL)
    printf("List is empty");
   else
   {
     deletefrombeginning(&head); //call by pointer
     printf("Deletion done successfully");
   }
   break;

   case 8:
   //Delete from end
   if(head==NULL)
    printf("List is empty");
   else
   {
    delete_from_end(&head); //call by pointer
    printf("Deletion done successfully");
   }
   break;

   case 9:
   //Delete after an element
   if(head==NULL)
    printf("List is empty");
   else
    {
     printf("Enter value after which you want to delete:");
     scanf("%d", &after);
     delete_after_element(&head, after);
     printf("Deletion done successfully");
    }
    break;

   case 10:
   //Delete Entire list
   if(head==NULL)
    printf("List is empty");
   else
   {
    delete_entire_list(&head); //garbage collection
    printf("Deletion done successfully");
   }
    break;

   case 11:
   //Insert at nth position
  //  printf("Enter an item:");
  //  scanf("%d", &item);
  //  printf("Enter the location at which you want to insert:");
  //  scanf("%d",&value);
  //  insertatnthposition(&head, item); //call by value
  //  printf("Insertion done successfully");
    break;

   case 12:
   exit(0);

   }
   getch();
  }
 }

 void insertinbeginning(node **head, int item)
 {
  node *ptr;
  ptr= (node*)malloc (sizeof(node));
  ptr-> info= item;
  if(*head==NULL)
  {
   ptr->next=NULL;
  }
  else
  {
   ptr->next=*head;
  }
   *head=ptr;
  }

 void traversing(node *loc)
 {
  while(loc!= NULL)
  {
   printf("%d->", loc->info);
   loc= loc->next;
  }
 }

 void insertatend(node **head, int item)
 {
  node *ptr, *loc;
  ptr= (node*)malloc (sizeof(node));
  ptr-> info= item;
  ptr->next=NULL;
  if(*head==NULL)
  {
   *head=ptr;
  }
  else
  {
   for(loc=*head; loc->next!=NULL; loc=loc->next);
  }
   loc->next=ptr;
  }


 node* search(node *head, int item)
  {
   node *loc;
   loc= head;
   while(loc!= NULL)
   {
    if(loc->info==item)
     return loc;
     loc= loc->next;
    }
     return NULL;
    }

 int insert_after_element(node *head, int item, int after)
 {
  node *ptr, *loc;
  loc= search(head, after);
  if(loc== NULL)
  {
   printf("Searched item is not found");
   return loc;
  }
  ptr= (node*)malloc(sizeof(node));
  ptr->info= item;
  ptr->next= loc->next;
  loc->next=ptr;
 }

 void deletefrombeginning(node **head)
 {
  node *ptr;
  ptr= *head;
  if(ptr->next==NULL)  //Single node
   *head=NULL;
  else
   *head=(*head)->next;  //more than one node
   free (ptr);
  }

  void delete_from_end(node **head)
  {
   node *loc, *bptr;   //*bptr= backfoot pointer
   loc= *head;
   if(loc->next==NULL)
    *head=NULL;
   else
   {
    bptr=NULL;
    while(loc->next!=NULL)
    {
     bptr=loc;
     loc=loc->next;
    }
     bptr->next= NULL;
    }
     free (loc);
   }

   void delete_after_element(node **head, int after)
   {
    node *ptr, *loc;
    loc= search(*head, after);
    if(loc==NULL)
     return;
    if(loc->next!=NULL)
     {
      ptr=loc->next;
      loc->next=ptr->next;
      free(ptr);
     }
    else
     {
       printf("Insufficient node");
     }
    }

  void delete_entire_list(node **head)
  {
   node *loc, *ptr;
   loc= *head;
   while(loc!=NULL)
   {
    ptr=loc;
    loc=loc->next;
    free(ptr);
   }
    *head=NULL;
  }

  void traversing_in_reverse_order(node *head)
  {
   if(head==NULL)
    return;
   else
   {
    traversing_in_reverse_order(head->next);
    printf("%d->",head->info);
   }
  }