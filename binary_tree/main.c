#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left,*right;
};
struct node* create()
{
    struct node *temp;
    int data;
    temp=(struct node*) malloc(sizeof(struct node));
    printf("\nEnter data=");
    scanf("%d",&data);
    temp->data=data;
    printf("\nEnter left child of %d",data);
    temp->left=create();
    printf("\nEnter right child of %d",data);
    temp->right=create();
    return temp;
};
void main()
{
    struct node *root=create();
}
