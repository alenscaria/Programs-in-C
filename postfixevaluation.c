#include<stdio.h>
int stack[20];
int top=-1;
void push(int x)
{
    stack[++top]=x;
}
int pop()
{
    if(top==-1)
    return -1;
    else
    return stack[top--];
}
void main()
{
    char exp[20];
    char ch;
    int result;
    printf("Enter the Expression:");
    scanf("%s",exp);
    for(int i=0;exp[i]!='\0';i++)
    {
        ch=exp[i];
        if(isdigit(ch))
        push(ch-'0');
        else if(ch=='+'||ch=='-'||ch=='^'||ch=='*'||ch=='/')
        {
            a=pop();
            b=pop();
            switch (ch)
            {
            case '+' : result=b+a;
                break;
            case '-' : result=b-a;
                break;
            case '*' : result=b*a;
                break;
            case '/' : result=b/a;
                break;
            case '^' : result=b^a;
                break;
            }
            push(result);
        }
    }
    printf("\nThe result of expression is %d ",pop());
}