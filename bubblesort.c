#include<stdio.h>
void main()
{
    int limit,i,j,temp;
    int a[20];
    scanf("%d",&limit);
    for(i=0;i<limit;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\nSorting..\n");
    i=0;
    while (i<limit-1)
    {
        j=0;
        while (j<limit-i-1)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
            j++;
        }
      i++;  
    }
    printf("\n");
    for(i=0;i<limit;i++)
    {
        printf("%d\t",a[i]);
    }
}