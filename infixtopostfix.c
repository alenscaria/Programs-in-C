#include<stdio.h>
#include<ctype.h>
char stack[25];
int top=-1;
void push(char x)
{
stack[++top]=x;
}
char pop()
{
    if(top==-1)
    return -1;
    else
    return stack[top--];
}
int priority(char x)
{
    if(x=='(')
    return 0;
    else if(x=='+'||x=='-')
    return 1;
    else if(x=='*'||x=='/')
    return 2;
    else if(x=='^')
    return 3;
}
void main()
{
    char exp[25];
    printf("\nEnter the expression:");
    scanf("%s",&exp);
    int i=0;char x;
    while(exp[i]!='\0')
    {
        if(isalnum(exp[i]))
        {
            printf("%c",exp[i]);
        }
        else if(exp[i]=='(')
        {
            push(exp[i]);
        }
        else if(exp[i]==')')
        {
            while((x=pop())!='(')
            {
                printf("%c",x);
            }
        }
        else
        {
            while(priority(stack[top])>=priority(exp[i]))
            {
                printf("%c",pop())
            }
            push(exp[i]);
            
        }
        i++;
    }
    while(top!=-1)
    {
        printf("%c",pop());
    }
}