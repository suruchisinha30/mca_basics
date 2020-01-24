#include<stdio.h>
#include<conio.h>
#include<process.h>
void main()
{
int a[50],choice,n,item,loc;
void getdata(int [],int);
void putdata(int [],int);
int linear_search(int [],int,int);
int binary_search(int [],int,int);
printf("Enter the size of the array:");
scanf("%d", &n);
getdata(a,n);
putdata(a,n);
while(1)
{
clrscr();
printf("1.Linear Search 2.Binary Search 3.Recursive Binary Search 4.Exit");

printf("Enter your choice:");
scanf("%d", &choice);
switch(choice)
{
case 1:
 printf("Enter item to be Searched:");
 scanf("%d",&item);
 loc=linear_search(a,n,item);
 break;
case 2:
 printf("Enter item t be searched:");
 scanf("%d",item);
 loc=binary_search(a,n,item);
 break;
case 3:
 printf("Enter item t be searched:");
 scanf("%d",item);
 loc=recursive_binarysearch(a,0,n-1,item);
 break;
case 4:
 exit(1);
 default:
 printf("Entered element does not exist");
 exit(1);
 }
 if(loc>=0)
 {
  printf("Item found at %d",loc);
}
 else
 {
 printf("Item not available");
 }
 getch();
}
}
void getdata(int x[],int n)
{
int i;
printf("Enter the elements in array:");
for(i=0;i<=n;i++)
{
 scanf("%d",&x[i]);
 }
 }
 void putdata(int x[],int n)
 {
 int i;
 printf("array is:");
 for(i=0;i<n;i++)
 {
 printf("%d",x[i]);
 }
 }
 int linear_search(int a[], int n, int item)
 {
 int i;
 for(i=0;i<n;i++)
 {
if(a[i]==item)
{
return i;
}
}
return -1;
}
int binary_search(int a[], int n, int item)
 {
 int beg, end,mid;
 beg=0;
 end=n-1;
 while(beg<=end)
 {
 mid=(beg+end)/2;
 if(a[mid]==item)
 {
  return mid;
  }
 else if(a[mid]>item)
 {
  end=mid-1;
 }
 else
 {
  beg=mid+1;
 }
 }
 return -1;
 }
 int recursive_binarysearch(int a[], int beg, int end, int item)
  {
   int mid;
   if(beg<=end)
   {
    mid=(beg+end)/2;
   if(a[mid]==item)
   {
    return mid;
    }
   else if(a[mid]>item)
   {
    return recursive_binarysearch(a,beg,mid-1,item);
    }
   else
   {
    return recursive_binarysearch(a,mid+1,end,item);
   }
   }
  return -1;
  }