#include<stdio.h>
#include<conio.h>
#include<process.h>
typedef struct dlinklst
{
	int info;
	struct dlinklst *next;
	struct dlinklst *prev;
}node;

void main()
{
	void insert_at_begning(node **,node **,int);
	void insert_at_end(node **,node **,int);
	void traversing(node *);
	void traversing_revorder(node *);
	void insert_after_element(node **,node **,int ,int );
	void insert_before_element(node **,node **,int ,int );
	node * search(node *,int )
	int item,choice,after;
	node *head,*tail;
	head=NULL;
	tail=NULL;
	while(1)
	{
		clrscr();
		printf("IN DOUBLY LINKED LIST\n");
		printf("--------------------------------\n");
		printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
		printf("--------------------------------\n\n");
		printf("1:Insert of begining\n2:Insert of end\n3:Insert after element\n");
		printf("4:Traversing\n5:Traversing in reverse order\n");
		printf("6:Delete at begining\n7:Delete at end\n8:Delete after element\n");
		printf("9:Delete entire list\n10:Delete at before\n11:Insert at before\n12:Exit\n");
		printf("enter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
		   case 1:  // Insert of begining
			printf("enter an item");
			scanf("%d",&item);
			insert_at_begning(&head,&tail,item);//call by pointer
			printf("operation successfully occured");
		   break;
		   case 2:  // Insert of end
			printf("enter an item");
			scanf("%d",&item);
			insert_at_end(&head,&tail,item);//call by pointer
			printf("operation successfully occured");
		   break;
		 case 3:  // Insert at after element
			printf("enter item to insert");
			scanf("%d",&item);
			printf("enter value after which you want to insert");
			scanf("%d",&after);
			insert_after_element(head,tail,item,after);
		   break;
		   case 4:  // Traversing
			if(head==NULL)
				printf("list is empty");
			else
				traversing(head);
		   break;
		   case 5:  // Traversing in reverse order
			traversing_revorder(tail);
		   break;
		  /* case 6:  // Delete at begining
			 if(head==NULL)
				 printf("list is empty");
			 else
			 {
				 delete_at_begning(&head);
				 printf("successfully deleted");
			 }
		   break;
		   case 7:  //Delete at end
			 delete_at_end(&head);
			 printf("successfully deleted");
		   break;
		   case 8:  //Delete after element
			printf("enter value after which you want to delete");
			scanf("%d",&after);
			delete_after_element(&head,after);
		   break;
		   case 9: //Delete entire list
			delete_entire_list(&head);
			printf("entire has been deleted");
		   break;*/
		   case 10: // delete before element
		   break;
		   case 11: // insert at before element
		   break;
		   case 12: //Exit
			     exit(0);


		}
		getch();
	}
}
void insert_at_begning(node **head,node **tail,int item)
{
	node *ptr;
	ptr=(node *)malloc(sizeof(node));
	ptr->info=item;
	ptr->prev=NULL;
	ptr->next=(*head);
	if(*head==NULL&&*tail==NULL)
		(*head)=(*tail)=ptr;
	else
	{
		(*head)->prev=ptr;
		(*head)=ptr;
	}
}
void insert_at_end(node **head,node **tail,int item)
{
	node *ptr;
	ptr=(node *)malloc(sizeof(node));
	ptr->info=item;
	ptr->next=NULL;
	ptr->prev=(*tail);
	if(*head==NULL&&*tail==NULL)
		*head=*tail=ptr;
	else
	{
		ptr->next=NULL;
		(*tail)->next=ptr;
		*tail=ptr;
	}
}
void traversing(node *head)
{
	while(head!=NULL)
	{
	printf("%d",head->info);
	head=head->next;
	}
}

void traversing_revorder(node *tail)
{
	while(tail!=NULL)
	{
		printf("%d",tail->info);
		tail=tail->prev;
	}
}
node * search(node *head,int item)
{
	node *loc;
	loc=head;
	while(loc!=NULL)
	{
		if(loc->info==item)
		return loc;
		loc=loc->next;
	}
	return NULL;
}
void insert_after_element(node **head,node **tail,int item,int after)
{
	node *ptr,*loc;
	loc=search(head,after);
	if(loc==NULL)
	{
		printf("not found");
		return;
	}
	ptr=(node *)malloc(sizeof(node))


}