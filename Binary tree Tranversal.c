#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node* newnode(int data)
{
    struct node* node=(struct node*)malloc(sizeof(struct node));
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    return (node);
};
void printpostorder(struct node* node)
{
    if (node==NULL)
    {
        return;
    }
    printpostorder(node->left);
    printpostorder(node->right);
    printf("%d ",node->data);
}
void printinorder(struct node* node)
{
    if (node==NULL)
        return;
    printinorder(node->left);
    printf("%d ",node->data);
    printinorder(node->right);
}
void printpreorder(struct node* node)
{
    if (node==NULL)
        return;
    printf("%d ",node->data);
    printpreorder(node->left);
    printpreorder(node->right);
}
int main()
{
    struct node *root= newnode(1);
    root->left=newnode(2);
    root->right=newnode(3);
    root->left->left=newnode(4);
    root->left->right=newnode(5);
    printf("\npreorder tranversal\n");
    printpreorder(root);
    printf("\n");
    printf("post order tranversal\n");
    printpostorder(root);
    printf("\n");
    printf("\ninorder tranversal\n");
    printinorder(root);
}
