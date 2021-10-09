#include<stdio.h>
#include<stdlib.h>
struct node
{
    int coeff,expo;
    int nextaddr;
};
void insert(struct node **head,int c,int e)
{
struct node *temp,*prev,*current;
if(*head==NULL)
{
    temp=(struct node *)malloc(1*sizeof(struct node));
    temp->coeff=c;
    temp->expo=e;
    temp->nextaddr=NULL;
    *head=temp;
}
else
{
    current=*head;
    while(current!=NULL)
    {
        prev=current;
        current=current->nextaddr;
    }
    if(current==NULL)
    {
        temp=(struct node *)malloc(1*sizeof(struct node));
    temp->coeff=c;
    temp->expo=e;
    temp->nextaddr=NULL;
    prev->nextaddr=temp;
    }
    
}
}
void traverse(struct node *start)
{
struct node *temp;
temp=start;
if(temp==NULL)
printf("\nEmpty polynomial");
else
{
    while(temp!=NULL)
    {
        printf("%dX^%d",temp->coeff,temp->expo);
        if(temp->nextaddr!=NULL)
        {printf("+");}
        temp=temp->nextaddr;
    }
    printf("\n");
}
}
void add(struct node **p1head,struct node **p2head,struct node **rhead)
{
    struct node *p1current,*p2current,*rcurrent,*rprev;
    p1current=*p1head;
    p2current=*p2head;
    rcurrent=NULL;
    rprev=NULL;
    *rhead=NULL;
    int c,e;

    while(p1current!=NULL||p2current!=NULL)
    {
        if(p1current!=NULL&&p2current!=NULL)
        {
            if(p1current->expo==p2current->expo)
            {
                c=p1current->coeff+p2current->coeff;
                e=p1current->expo;
                insert(rhead,c,e);
                p1current->nextaddr;
                p2current->nextaddr;
            }
            else if(p1current->expo>p2current->expo)
            {
                c=p1current->coeff;
                e=p1current->expo;
                insert(rhead,c,e);
                p1current->nextaddr;
            }
            else if(p1current->expo<p2current->expo)
            {
                c=p2current->coeff;
                e=p2current->expo;
                insert(rhead,c,e);
                p2current->expo;
            }
            else if(p1current!=NULL)
            {
                c=p1current->coeff;
                e=p1current->expo;
                insert(rhead,c,e);
                p1current->nextaddr;
            }
            else if(p2current!=NULL)
            {
                c=p2current->coeff;
                e=p2current->expo;
                insert(rhead,c,e);
                p2current->nextaddr;
            }
            else
            exit(0);
        }
    }

}
void main()
{
    int i,n,c,e;
    struct node *p1=NULL,*p2=NULL,*r=NULL;
    printf("Enter the number of terms for polynomial 1:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\nEnter the coefficient:");
        scanf("%d",&c);
        printf("\nEnter the exponent:");
        scanf("%d",&e);
        insert(&p1,c,e);
    }
    printf("\nEnter the number of terms for polynomial 2:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\nEnter the coefficient:");
        scanf("%d",&c);
        printf("\nEnter the exponent:");
        scanf("%d",&e);
        insert(&p2,c,e);
    }

    //PRINTING POLYNOMIALS
    printf("\nPolynomial 1:\n");
    traverse(p1);
    printf("\nPolynomial 2:\n");
    traverse(p2);

    //printing polynomial after addition
    add(&p1,&p2,&r);
    printf("\nAdded Polynomial:");
    traverse(r);
}