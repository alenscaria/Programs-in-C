#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *nextaddr;
};
struct node *ptr=NULL,*Head=NULL;

void display()
{
    if(Head==NULL)
    {
        printf("\nList is Empty.");
    }
    else
    {
    ptr=Head;
    while(ptr!=NULL)
    {
    printf("%d\t",ptr->data);
    ptr=ptr->nextaddr;
    }
    }
}

void insert_beg()
{
     printf("\ninsertion at front\n");
            struct node *temp2;
            int item;
            temp2=(struct node *)malloc(1*sizeof(struct node));
            printf("Enter the item to be entered:");
            scanf("%d",&item);
            temp2->data=item;
            temp2->nextaddr=NULL;
            if(Head==NULL)
            {
            Head=temp2;
            }
            else
            {
            temp2->nextaddr=Head;
            Head=temp2;
            }
}

void insert_end()
{
     printf("\ninsertion at end\n");
            int item;
            struct node *temp;
            temp=(struct node *)malloc(sizeof(struct node));
            printf("\nEnter the item to be entered:\n");
            scanf("%d",&item);
            temp->data=item;
            temp->nextaddr=NULL;
            if(Head==NULL)
            {
                Head=temp;
            }
            else 
            {
                ptr=Head;
                while (ptr->nextaddr!=NULL)
                {
                    ptr=ptr->nextaddr;
                }
                ptr->nextaddr=temp;
            }
}

void insert_pos()
{
   printf("\nInsertion at a Particular Position");
            int item;
            struct node *temp;
            temp=(struct node *)malloc(sizeof(struct node));
            printf("\nEnter the item to be inserted:\n");
            scanf("%d",&item);
            temp->data=item;
            temp->nextaddr=NULL;
            printf("\nEnter a key value to insert at a particular position:\n");
            int key;
            scanf("%d",&key);
            if(Head==NULL)
            {
                Head=temp;
            }
            else
            {
                ptr=Head;
                while(ptr->nextaddr!=NULL&&ptr->data!=key)
                {
                    ptr=ptr->nextaddr;
                }
                if(ptr->nextaddr==NULL)
                printf("Key not Found\n");
                else
                {
                temp->nextaddr=ptr->nextaddr;
                ptr->nextaddr=temp;
                }
            } 
}


//delete

void delete_beg()
{
     printf("\ndeletion at front\n");
            if(Head==NULL)
            {
            printf("\nEmpty");
            }
            else
            {
            printf("Element deleted = %d \n",Head->data);
            Head=Head->nextaddr;
            }
}

void delete_end()
{
    struct node * prev=NULL;
     printf("\ndeletion at end\n");
            if(Head==NULL)
            {
            printf("\nEmpty");
            }
            else 
            {
                ptr=Head;
                while (ptr->nextaddr!=NULL)
                {
                    prev=ptr;
                    ptr=ptr->nextaddr;
                }
                printf("Element Deleted = %d\n",ptr->data);
                prev->nextaddr=NULL;
            }
}

void delete_pos()
{
    struct node * prev=NULL;
    int flag=0;
   printf("\nDeletion at a Particular Position");
            printf("\nEnter a key value to insert at a particular position:\n");
            int key;
            scanf("%d",&key);
            if(Head==NULL)
            {
            printf("\nEmpty");
            }
            else
            {
                ptr=Head;
                while(ptr->nextaddr!=NULL&&ptr->data!=key)
                {
                    prev=ptr;
                    ptr=ptr->nextaddr;
                    if(ptr->data==key)
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                printf("Key not Found\n");
                else
                {
                printf("Element deleted=%d\n",ptr->data);
                prev->nextaddr=ptr->nextaddr;
                }
            } 
}

//delete

void main()
{
    
    do
{
    printf("\nMENU\nEnter the Choice:\n1.Insertion at Front\n2.Insertion at End\n3.Insertion at Particular position\n4.Deletion at Front \n5.Deletion at End\n6.Deletion at a Particular Position\n7.Exit\n");
    int choice;
    scanf("%d",&choice);
switch(choice)
{
  case 1:   //insertion at front 
           insert_beg();
            display();
            break;

  case 2:   //insertion at end
           insert_end();
            display();
            break;
    case 3://Insertion at a Particulat Position
            insert_pos();
            display();
            break;
    case 4://Insertion at a Particulat Position
            delete_beg();
            display();
            break;
    case 5://Insertion at a Particulat Position
            delete_end();
            display();
            break;
    case 6://Insertion at a Particulat Position
            delete_pos();
            display();
            break;
    case 7:exit(0);
}
}while(1);
}