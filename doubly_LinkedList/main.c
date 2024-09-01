#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *start=NULL;
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
   struct node *ptr;
   int item;
   ptr = (struct node *)malloc(sizeof(struct node));
   if(ptr == NULL)
   {
       printf("\nOut of memory");
   }
   else
   {
       printf("\nEnter node value=");
       scanf("%d",&item);
       if(start==NULL)
       {
           ptr->next = NULL;
           ptr->prev=NULL;
           ptr->data=item;
           start=ptr;
       }
        else
       {
           ptr->prev=NULL;
           ptr->next = start;
           ptr->data=item;
           start->prev=ptr;
           start=ptr;
       }
   }
}
void insert_end()
{
   struct node *ptr,*temp;
   ptr = (struct node *) malloc(sizeof(struct node));
   if(ptr==NULL)
   {
       printf("\nOut of memory");
   }
   else
   {
       printf("\nEnter node value=");
       scanf("%d",&ptr->data);
       if(start == NULL)
       {
           ptr->next = NULL;
           ptr->prev = NULL;
           start = ptr;
       }
       else
       {
          temp=start;
          while(temp->next!=NULL)
          {
              temp=temp->next;
          }
          temp->next=ptr;
          ptr ->prev=temp;
          ptr->next = NULL;
          }
       }
}
void delete_begin()
{
    struct node *ptr;
    ptr=(struct node *)malloc(sizeof(struct node));
    ptr=start;
    if(ptr==NULL)
    {
        printf("\nLinked list is empty");
    }
    else if(ptr->next == NULL)
    {
        printf("\nDeleted Element is %d",start->data);
        start=NULL;
        free(start);
    }
    else
    {
        start=start->next;
        start->prev=NULL;
        printf("\nDeleted Element is %d",ptr->data);
        free(ptr);
    }
}
void delete_end()
{
    struct node *ptr,*temp;
    ptr=start;
    if(start==NULL)
    {
        printf("\nLinked list is empty");
    }
    else if(ptr->next==NULL)
    {
        printf("\nDeleted Element is %d",ptr->data);
        start=NULL;
        free(start);
    }
    else
    {
        while(ptr->next!=NULL)
        {
            temp=ptr;
            ptr=ptr->next;
        }
        temp->next=NULL;
        temp->prev=NULL;
        printf("\nDeleted Element is %d",ptr->data);
        free(ptr);
    }
}
void insert_pos()
{
   struct node *ptr,*temp;
   int item,loc,i;
   ptr = (struct node *)malloc(sizeof(struct node));
   if(ptr == NULL)
   {
        printf("\nLinked list is empty");
   }
   else
   {
       temp=start;
       printf("\nEnter location to insert node=");
       scanf("%d",&loc);
       for(i=0;i<loc;i++)
       {
           temp=temp->next;
           if(temp==NULL)
           {
               printf("\nThere are less than %d elements", loc);
               return;
           }
       }
       printf("\nEnter node value=");
       scanf("%d",&item);
       ptr->data = item;
       ptr->next = temp->next;
       ptr -> prev = temp;
       temp->next = ptr;
       temp->next->prev=ptr;
   }
}
/*
    struct node *ptr,*temp;
    int pos,i;
    printf("\nEnter position to delete node");
    scanf("%d",&pos);
    ptr=start;
    if(pos==0)
    {
      ptr=start;
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
        temp->next=ptr->prev;
        printf("\nDeleted Element is %d",ptr->data);
        free(ptr);
    }
*/
void delete_pos()
{
/*
    struct node *ptr, *temp;
    int val;
    printf("\nEnter the data after which the node is to be deleted= ");
    scanf("%d", &val);
    ptr = start;
    while(ptr->data!=val)
    {
        ptr = ptr -> next;
    }
    if(ptr->next==NULL)
    {
        printf("\nCan't delete\n");
    }
    else if(ptr->next->next==NULL)
    {
        ptr->next = NULL;
    }
    else
    {
        temp = ptr->next;
        ptr->next = temp->next;
        temp->next->prev = ptr;
        free(temp);
        printf("\nNode deleted");
    }

*/
struct node *ptr,*temp;
    int pos,i;
    printf("\nEnter position to delete node=");
    scanf("%d",&pos);
    ptr=start;
    if(pos==0)
    {
      ptr=start;
      start=start->next;
      printf("\nDeleted Element is %d",ptr->data);
      free(ptr);
    }
    else
    {
      ptr=start;
        for(i=0;i<pos;i++)
        {
            temp=ptr;
            ptr=ptr->next;
            if(ptr==NULL)
            {
                printf("\nPosition not found");
            }
           /* else if(ptr->next==NULL)
            {
                ptr->prev->next=NULL;
                printf("\nDeleted Element is %d",ptr->data);
                free(ptr);
            }
            */
        }
        temp->next=ptr->next;
        ptr->next->prev=ptr->prev;
        printf("\nDeleted Element is %d",ptr->data);
        free(ptr);
    }

}
void search()
{
    struct node *ptr;
    int item,i=0,flag;
    ptr = start;
    if(ptr == NULL)
    {
        printf("\nEmpty List\n");
    }
    else
    {
        printf("\nEnter item which you want to search?\n");
        scanf("%d",&item);
        while (ptr!=NULL)
        {
            if(ptr->data == item)
            {
                printf("\nItem found at location %d ",i+1);
                flag=0;
                break;
            }
            else
            {
                flag=1;
            }
            i++;
            ptr = ptr -> next;
        }
        if(flag==1)
        {
            printf("\nItem not found\n");
        }
    }
}
int main()
{
    int ch;
    while(1)
    {
        printf("\n1.Display\n2.Insert at beginning\n3.Insert at end\n4.Delete at beginning\n5.Delete at end\n6.Insert at specific position\n7.Delete at specific position\n8.Search");
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
        case 8:
            search();
        break;
        default:
            exit(0);
        }
    }
    return 0;
}
