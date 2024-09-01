#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *start;
void display()
{
    struct node *ptr;
    ptr=start;
    if(start==NULL)
    {
        printf("\nLinked list empty");
    }
    else
    {
        while(ptr->next!=start)
        {
            printf("%d\n",ptr->data);
            ptr=ptr->next;
        }
         printf("%d\n",ptr->data);
    }
}
void insert_begin()
{
    struct node *ptr,*temp;
    ptr=(struct node *)malloc(sizeof(struct node));
    if(ptr==NULL)
    {
         printf("\nLinked list is empty");
    }
    else
    {
        printf("\nEnter node value=");
        scanf("%d",&ptr->data);
        if(start==NULL)
        {
            start=ptr;
            ptr->next=start;
        }
        else
        {
            temp=start;
            while(temp->next!=start)
            {
                temp=temp->next;
            }
            ptr->next=start;
            temp->next=ptr;
            start=ptr;
        }
        printf("\nNode inserted %d",ptr->data);
    }
}
void insert_end()
{
    struct node *ptr,*temp;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    if(ptr==NULL)
    {
        printf("\nLinked list is full");
    }
    else
    {
        printf("\nEnter node Data=");
        scanf("%d",&ptr->data);
        if(start==NULL)
        {
            start=ptr;
            ptr->next=start;
        }
        else
        {
            temp=start;
            while(temp->next!=start)
            {
                temp=temp->next;
            }
            temp->next=ptr;
            ptr->next=start;
        }
        printf("\nNode inserted %d",ptr->data);
    }
}
void delete_begin()
{
    struct node *ptr;
    if(start == NULL)
    {
        printf("\nLinked list is empty");
    }
    else if(start->next==start)
    {
        start = NULL;
        free(start);
        printf("\nNode deleted");
    }

    else
    {   ptr=start;
        while(ptr->next!=start)
            ptr=ptr->next;
        ptr->next = start->next;
        free(start);
        start = ptr->next;
        printf("\nNode deleted");

    }
}
void delete_end()
{
    struct node *ptr, *preptr;
    if(start==NULL)
    {
        printf("\nLinked list is empty");
    }
    else if (start ->next == start)
    {
        start = NULL;
        free(start);
        printf("\nNode deleted\n");

    }
    else
    {
        ptr = start;
        while(ptr ->next != start)
        {
            preptr=ptr;
            ptr = ptr->next;
        }
        preptr->next = ptr -> next;
        free(ptr);
        printf("\nNode deleted");

    }
}
void insert_pos()
{
    struct node *temp,*ptr;
    int pos,i;
    temp=(struct node*) malloc(sizeof(struct node));
     if(start == NULL)
    {
       start=temp;
       temp->next=start;
    }
    printf("\nEnter position to insert node=");
    scanf("%d",&pos);
    printf("\nEnter node data=");
    scanf("%d",&temp->data);
  /*  if(pos==0)
    {
       temp=start;
       temp->next=start;
       ptr->next=temp;
    }
    */
//else
 //   {
        ptr=start;
        for(i=0;i<pos-1;i++)
        {
            ptr=ptr->next;
        }
        temp->next=ptr->next;
        ptr->next=temp;
  //  }
}
void delete_pos()
{
    int i,pos;
    struct node *temp,*ptr;
    if(start==NULL)
    {
        printf("\nLinked list is empty");
    }
    printf("\nEnter position to insert node=");
    scanf("%d",&pos);
   /* if(pos==0)
    {
         ptr=start;
         start=start->next;
         printf("\nDeleted Element is %d",ptr->data);
         free(ptr);
    }
    else
    {*/
        ptr=start;
        for(i=0;i<pos-1;i++)
        {
            temp=ptr;
            ptr=ptr->next;
        }
        temp->next=ptr->next;
        printf("\nDeleted Element is %d",ptr->data);
        free(ptr);
//    }
}
int main()
{
    int ch;
    while(1)
    {
        printf("\n1.Display\n2.Insert at beginning\n3.Insert at end\n4.Delete at beginning\n5.Delete at end\n6.Insert at position\n7.Delete at position");
        printf("\nEnter your choice=");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            display();
        break;
        case 2:
            insert_begin();
        break;
        case 3:
            insert_end();
        break;
        case 4:
            delete_begin();
        break;
        case 5:
            delete_end();
        break;
        case 6:
            insert_pos();
        break;
        case 7:
            delete_pos();
        break;
        default:
            exit(0);
        }
    }
    return 0;
}
