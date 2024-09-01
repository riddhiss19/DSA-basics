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
struct node *search(struct node* cur,int data1)
{
    while(cur!=NULL && cur->data!=data1)
    {
        if(data1<cur->data)
            cur=cur->left;
        else
            cur=cur->right;
    }
    return cur;
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
struct node *findminimum(struct node *node)
{
    struct node *cur;
    while(cur->left!=NULL && cur)
        cur=cur->left;

    return cur;
};
struct node *deletion(struct node* root,int item)
{
    struct node *parent=NULL;
    struct node *cur=root;
    search(cur,item);
    if(cur==NULL)
        return;
    if(cur->left==NULL && cur->right==NULL)
    {
        if(cur!=root)
        {
            if(parent->left==cur)
                parent->left=NULL;
            else
                parent->right=NULL;
        }
        else
            root=NULL;
        free(cur);
    }
    else if(cur->left && cur->right)
    {
        struct node *suc=findminimum(cur->right);
        int val=suc->data;
        deletion(root,suc->data);
        cur->data=val;
    }
    else
    {
        struct node *child=(cur->left)?cur->left:cur->right;
        if(cur!=root)
        {
            if(cur==parent->left)
                parent->left=child;
            else
                parent->right=child;
        }
        else
            root=child;
        free(cur);
    }
    return cur;
}
int main()
{
    struct node *root=create(36);
    struct node *parent=NULL;
    root->left=create(26);
    root->right=create(46);
    root->left->left=create(21);
    root->left->right=create(31);
    root->left->left->left=create(11);
    root->left->left->right=create(24);
    root->right->left=create(41);
    root->right->right=create(56);
    display(root);
   /* struct node *temp=search(root,44);
    if(temp!=NULL)
      printf("found %d",temp->data);
    else
        printf("not found");
        */
   // struct node *temp=
    deletion(root,41);
    //printf("Deleted %d",temp->data);
    return 0;
}
