#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *start=NULL;
void create()
{
    struct node *temp,*ptr;
    temp=(struct node*) malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("Out of memory");
    }
    printf("\nEnter value for node=");
    scanf("%d",&temp->data);
    temp->next=NULL;
    if(start==NULL)
    {
        start=temp;
    }
    else
    {
        ptr=start;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=temp;
    }
}
void display()
{
    struct node *ptr;
    if(start==NULL)
    {
        printf("\nList is empty");
        return;
    }
    else
    {
        ptr=start;
        printf("\nLinked List elements=");
        while(ptr!=NULL)
        {
            printf("\n%d",ptr->data);
            ptr=ptr->next;
        }
        printf("\n");
    }

}
void insert_begin()
{
    struct node *temp;
    temp=(struct node*) malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("\nOut of Memory");
    }

        printf("\nEnter data value for node=");
        scanf("%d",&temp->data);
        temp->next=NULL;
        if(start==NULL)
        {
            start=temp;
        }
        else
        {
            temp->next=start;
            start=temp;
        }
}
void insert_end()
{
    struct node *temp,*ptr;
    temp=(struct node*) malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("\nOut of Memory");
    }
    printf("\nEnter data value for node=");
    scanf("%d",&temp->data);
    temp->next=NULL;
    if(start==NULL)
    {
        start=temp;
    }
    else
    {
        ptr=start;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=temp;
    }
}
void insert_pos()
{
    struct node *temp,*ptr;
    int i,pos;
    temp=(struct node*) malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("\nOut of Memory");
    }
    printf("\nEnter position for new node=");
    scanf("%d",&pos);
    printf("\nEnter data value for node=");
    scanf("%d",&temp->data);
    temp->next=NULL;
    if(pos==0)
    {
        temp->next=start;
        start=temp;
    }
    else
    {
        for(i=0,ptr=start;i<pos-1;i++)
        {
            ptr=ptr->next;
            if(ptr==NULL)
            {
                printf("\nPosition not found");
            }

        }
        temp->next=ptr->next;
        ptr->next=temp;
    }
}
void delete_begin()
{
    struct node *ptr;
    if(ptr==NULL)
    {
        printf("\nLinked list is empty");
    }
    else
    {
        ptr=start;
        start=start->next;
        printf("\nDeleted Element is %d",ptr->data);
        free(ptr);
    }
}
void delete_end()
{
    struct node *temp,*ptr;
    if(start==NULL)
    {
        printf("\nLinked list is empty");
    }
    else if(start->next==NULL )
    {
        ptr=start;
        start=NULL;
        printf("\nDeleted element is %d",ptr->data);
        free(ptr);
    }
    else
    {
        ptr=start;
        while(ptr->next!=NULL)
        {
            temp=ptr;
            ptr=ptr->next;
        }
        temp->next=NULL;
        printf("\nDeleted element is %d",ptr->data);
        free(ptr);
    }
}
void delete_pos()
{
    int i,pos;
    struct node *temp,*ptr;
    if(start==NULL)
    {
        printf("\nLinked list is empty");
    }
    else
    {
        printf("\nEnter position of node to be deleted=");
        scanf("%d",&pos);
        if(pos==0)
        {
            ptr=start;
            while(temp->next!=start)
                temp=temp->next;
            start=start->next;
            printf("\nDeleted Element is %d",ptr->data);
            free(ptr);
        }
        else
        {
            ptr=start;
            for(i=0;i<pos-1;i++)
            {
                temp=ptr;
                ptr=ptr->next;
                if(ptr==NULL)
                {
                    printf("\nPosition not found");
                }
            }
            temp->next=ptr->next;
            printf("\nDeleted Element is %d",ptr->data);
            free(ptr);
        }
    }
/*
    int pos;
    printf("\nEnter position of node to be deleted=");
    scanf("%d",&pos);
    if(start == NULL)
      printf("List is Empty!!! Deletion not possible!!!");
   else
   {
      struct node *ptr = start, temp;
      while(ptr -> data != pos)
      {
         if(ptr-> next== start)
         {
            printf("\nGiven node is not found in the list!");
         }
         else
         {
            temp = ptr;
            ptr = ptr -> next;
         }
      }
      if(ptr -> next == start){
         start = NULL;
         free(ptr);
      }
      else{
         if(ptr == start)
         {
            temp = start;
            while(temp -> next != start)
               temp = temp -> next;
            start = start -> next;
            temp -> next = start;
            free(ptr);
         }
         else
         {
            if(ptr -> next == start)
            {
               temp -> next = start;
            }
            else
            {
               temp -> next = ptr -> next;
            }
            free(ptr);
         }
      }
      printf("\nDeletion success!");
   }
*/
}
int main()
{
    int ch;
    while(1)
    {
        printf("\n1.Create\n2.Display\n3.Insert at beginning\n4.Insert at end\n5.Insert at specific position\n6.Delete From beginning\n7.Delete from end\n8.Delete from specific position\n");
        printf("\nEnter your choice=");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            create();
        break;

        case 2:
            display();
        break;

        case 3:
            insert_begin();
        break;

        case 4:
            insert_end();
        break;

        case 5:
            insert_pos();
        break;

        case 6:
            delete_begin();
        break;

        case 7:
            delete_end();
        break;

        case 8:
            delete_pos();
        break;

        default:
            exit(0);
        }
    }
    return 0;
}
