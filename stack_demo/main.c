#include <stdio.h>
#include <stdlib.h>
#define max 5
struct stack
{
    int top;
    int st[max];
}s;
void push(int a[])
{
    s.top=-1;
    if(s.top==max-1)
    {
        printf("Stack overflowed");
    }
    else{
        s.top++;
        int i,item,n;
       // printf("How many elements to push onto stack=");
       // scanf("%d",&n);


        printf("\nEnter stack element=");
        scanf("%d",&item);
        s.st[s.top]=item;
        printf("\nElement %d pushed onto stack",item);


    }
}

int main()
{

    push(s.st);
    return 0;
}
