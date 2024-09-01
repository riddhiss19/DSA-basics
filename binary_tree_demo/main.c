#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left,*right;
};
struct node *newnode(int data1)
{
    struct node *temp;
    temp=(struct node*) malloc(sizeof(struct node));
    temp->data=data1;
    temp->left=temp->right=NULL;
    return temp;
    printf("\nNode created!!");
};
void display(struct node *root)
{
    if(root!=NULL)
    {
        display(root->left);
        printf("%d\n",root->data);
        display(root->right);
    }
}
struct node *insert(struct node* node,int data)
{
    if(node==NULL)
    {
        return newnode(data);
    }
    if(data<node->data)
    {
        node->left=insert(node->left,data);
    }
    else if(data>node->data)
    {
        node->right=insert(node->right,data);
    }
    return node;
};
void main()
{
    struct node *root=NULL;
    root=insert(root,10);
    insert(root,20);
    display(root);
    return 0;
}
