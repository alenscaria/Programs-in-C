#include<stdio.h>
void main()
{
    int a[10],n,i,j,key;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\nSorting..");
    for(i=1;i<n;i++)
    {
        key=a[i];
        j=i-1;
        while(j>=0&&a[j]>key)
        {
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=key;
    }
    printf("\n...Sorted\n");
    for(i=0;i<n;i++)
    {
        printf("\t%d",a[i]);
    }
}