#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left,*right;
};
struct node *create(int data1)
{
    struct node *temp;
    temp=(struct node*) malloc(sizeof(struct node));
    temp->data=data1;
    temp->left=temp->right=NULL;
    return temp;
    printf("\nNode created!!");
};
struct node *findminimum(struct node *node)
{
    struct node *cur;
    while(cur->left!=NULL && cur)
        cur=cur->left;
    printf("%d",cur);
    return cur;
};
void search(struct node* cur,int data1,struct node* parent)
{
    while(cur!=NULL && cur->data!=data1)
    {
        parent=cur;
        if(data1<cur->data)
            cur=cur->left;
        else
            cur=cur->right;
    }
}
void display(struct node *root)
{
    if(root!=NULL)
    {
        display(root->left);
        printf("%d\n",root->data);
        display(root->right);
    }
}
void traversePreorder(struct node* root)
{
    if(root==NULL)
        return;
    printf("%d\n",root->data);
    traversePreorder(root->left);
    traversePreorder(root->right);
}
void traverseInorder(struct node* root)
{
    if(root==NULL)
        return;
    traversePreorder(root->left);
    printf("%d\n",root->data);
    traversePreorder(root->right);
}
void traversePostorder(struct node* root)
{
    if(root==NULL)
        return;
    traversePreorder(root->left);
    traversePreorder(root->right);
    printf("%d\n",root->data);
}

void main()
{
    struct node *root=create(36);
    root->left=create(26);
    root->right=create(46);
    root->left->left=create(21);
    root->left->right=create(31);
    root->left->left->left=create(11);
    root->left->left->right=create(24);
    root->right->left=create(41);
    root->right->right=create(56);
    display(root);
    printf("\nPreorder=\n");
    traversePreorder(root);
    printf("\nInorder=\n");
    traverseInorder(root);
    printf("\nPostorder=\n");
    traversePostorder(root);
   // findminimum(root);
    search(root,21,26);
    return 0;
}
