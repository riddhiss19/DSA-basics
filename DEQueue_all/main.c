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
    else if(front==0)
    {
        front=max-1;
        queue[front]=x;
    }
    else{
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
void getFront()
{
    if((front==-1)&&(rear==-1))
    {
        printf("\nQueue is empty");
    }
    else
    {
        printf("\nFront is=%d",queue[front]);
    }
}
void getRear()
{
    if((front==-1)&&(rear==-1))
    {
        printf("\nQueue is empty");
    }
    else
    {
        printf("\nRear is=%d",queue[rear]);
    }
}
void delete_front()
{
    if((front==-1)&&(rear==-1))
    {
        printf("\nQueue is empty");
    }
    else if(front==rear)
    {
        printf("\nDeleted Element is=%d",queue[front]);
        front=-1;
        rear=-1;
    }
    else if(front==max-1)
    {
        printf("\nDeleted Element is=%d",queue[front]);
        front++;
    }
}
void delete_rear()
{
    if((front==-1)&&(rear==-1))
    {
        printf("\nQueue is empty");
    }
    else if(front==rear)
    {
        printf("\nDeleted Element is=%d",queue[rear]);
        front=-1;
        rear=-1;
    }
    else if(rear==0)
    {
        printf("\nDeleted Element is=%d",queue[rear]);
        rear=max-1;
    }
    else
    {
        printf("\nDeleted Element is=%d",queue[rear]);
        rear=rear-1;
    }
}
int main()
{
    while(1)
    {
        int ch,n;
        printf("\n1.Insert at front\n2.Insert at rear\n3.Delete at front\n4.Delete at rear\n5.Display\n6.Get Front\n7.Get Rear\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("\nEnter element to be inserted at front=");
                scanf("%d",&n);
                insert_front(n);
            break;
            case 2:
                printf("\nEnter element to be inserted at rear=");
                scanf("%d",&n);
                insert_rear(n);
            break;
            case 3:
                delete_front();
            break;
            case 4:
                delete_rear();
            break;
            case 5:
                Display();
            break;
            case 6:
                getFront();
            break;
            case 7:
                getRear();
            break;
            default:
                exit(0);
                printf("\nInvalid choice");
        }
    }
    return 0;
}
