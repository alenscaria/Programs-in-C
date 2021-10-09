#include<stdio.h>
#define size 5
int queue[size];
int front=-1,rear=-1;
void insert()
{
 if(front>rear||rear==size-1)
 printf("Queue is full");
 else
 {
     if(front=-1)
     {
         front=0;
     }
     printf("Enter the item to be inserted:");
     int item;
     scanf("%d",&item);
     queue[++rear]=item;
 }
}
int delete()
{
    if(front==-1)
    {
        printf("Queue is empty")
    }
    else
    {
        
    }
}
void main()
{
    printf("\nMENU\n1.Insert\n2.Delete\n3.Display\n");
    int choice;char ch=='y';
    scanf("%d",&choice);
    while(ch=='y')
    {
        switch (choice)
        {
        case 1:insert();display();
               break;
        
        case 2:printf("\nElement deleted : %d",delete());
                display();
            break;
        case 3:display();
            break;
        default:printf("Wrong Choice..")
        }
        printf("\nContinue...(y/n)..%c",ch);
    }
}