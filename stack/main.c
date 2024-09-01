#include<stdio.h>
#include<stdlib.h>

#define max 4

struct stud
{
    int top, arr[max];
}s;

void Push();
int isFull();
void Pop();
int isEmpty();
void show();

int main()
{
    s.top=-1;
    int choice;
    while(1)
    {
        printf("\n1.Push the element\n2.Pop the element\n3.Display");
        printf("\n\nEnter the choice:");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: Push();
                    break;
            case 2: Pop();
                    break;
            case 3: show();
                    break;
            default: exit(0);
        }
    }
}
int isFull()
{
   if(s.top==max-1)
    {
        printf("\nStack Overflow\n");
        return 0;
    }
    else
    {
        return 1;
    }
}
int isEmpty()
{
    if(s.top==-1)
    {
        printf("\nStack Underflow\n");
        return 0;
    }
    else
    {
        return 1;
    }
}
void Push()
{
    int x;
    if(isFull()==1)

    {
        printf("\nEnter element to be inserted onto the stack:");
        scanf("%d",&x);
        s.top=s.top+1;
        s.arr[s.top]=x;
    }
}

void Pop()
{
    if(isEmpty()==1)
    {
        printf("\nPopped element:  %d",s.arr[s.top]);
        s.top=s.top-1;
    }
}

void show()
{
    if(isEmpty()==1)
    {
        printf("\nElements in the stack: \n");
        for(int i=s.top;i>=0;--i)
            printf("%d\n",s.arr[i]);
    }
}
