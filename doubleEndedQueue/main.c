#include <stdio.h>
#include <stdlib.h>
#define max 5

int front=-1,rear=-1;
int queue[max];

void insert_front(int x)
{
    if((front==0 && rear==max-1)||(front==rear+1))
    {
        printf("Queue overflow");
    }
    else if((front==-1)&&(rear==-1))
    {
        front=rear=0;
        queue[front]=x;
    }
        queue[front]=x;
    else if(front==0)
    {
        front=max-1;
    }
    else
    {
        front--;
        queue[front]=x;
    }
}
void insert_rear(int x)
{
    if((front==0 && rear==max-1)||(front==rear+1))
    {
        printf("Queue overflow");
    }
    else if((front==-1)&&(rear==-1))
    {
        rear=0;
        queue[rear]=x;
    }
    else if(rear==max-1)
    {
        rear=0;
        queue[rear]=x;
    }
    else{
        rear++;
        queue[rear]=x;
    }
}
void Display()
{
    int i=front;
    printf("\nElements in Double Ended Queue=");
    while(i!=rear)
    {
        printf("\n%d",queue[i]);
        i=(i+1)%max;
    }
    printf("\n%d",queue[rear]);
}
int main()
{
    while(1)
    {
        int ch,n;
        printf("\n1.Insert at front\n2.Insert at rear\n3.Display\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter element to be inserted at front=");
                scanf("%d",&n);
                insert_front(n);
            break;
            case 2:
                printf("Enter element to be inserted at rear=");
                scanf("%d",&n);
                insert_rear(n);
            break;
            case 3:
                Display();
            break;
            default:
                exit(0);
                printf("\nInvalid choice");
        }
    }
    return 0;
}
