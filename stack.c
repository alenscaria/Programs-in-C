#include<stdio.h>
#define MAXSIZE 5
int stack[MAXSIZE];
int top=-1;
void push()
{
    int item;
    printf("\nPUSH\n");
    if(top>=MAXSIZE)
    {
        printf("\nStackOverflow...Pop some elements to push a new element");
    }
    else
    {
        printf("\nEnter the item to push into the stack:");
        scanf("%d",&item);
        top++;
        stack[top]=item;
    }

}
int pop()
{
    int item;
    if(top==-1)
    {
        printf("\nStackunderflow...Push some elements to pop it");
    }
    else
    {
        item=stack[top];
        top--;
        return item;
    }
    return 0;
}
void display()
{
    if(top==-1)
    {
        printf("\nStack is Empty");
    }
    else
    {
        if(top>=MAXSIZE-1)
        {
            printf("\nStack is Full");
        }
        else
        {
        printf("\n");
        for(int i=0;i<=top;i++)
            {
             printf("%d\t",stack[i]);
            }   
        printf("\nElement at top position:%d",stack[top]);
        printf("\nAvailable Freespace:%d%",((MAXSIZE-top-1)/MAXSIZE)*100);
        }
    }
}
void main()
{
    int choice;
    char ch='y';
    do
    {
        printf("\nMENU\n1.PUSH\n2.POP\n3.Display\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: push(); break;
            case 2: printf("\nThe element deleted : %d \n",pop());  break;
            case 3: display();break;
            default : printf("\nWrong Choice");
        }
        printf("\nContinue...(y/n)  :   ");
        fflush(stdin);
        scanf("%c",&ch);
    }    while(ch=='y');
}