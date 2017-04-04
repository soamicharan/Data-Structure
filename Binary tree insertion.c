#include<stdio.h>
typedef struct bin_tree *ptr;
typedef struct bin_tree
{
    int data;
    ptr left;
    ptr right;
};
ptr root=NULL;
ptr seek=NULL;
ptr trace=NULL;
void insert(ptr p,int val,int l,int r)
{
    ptr temp;
    if(p==NULL)
    {
        temp=(ptr)malloc(sizeof(struct bin_tree));
        temp->left=temp->right=NULL;
        temp->data=val;
        if(l==1)
        {
            trace->left=temp;
        }
        else if(r==1)
            trace->right=temp;
        if (root==NULL)
                root=temp;
        return;
    }
    else
        trace=p;
    if(val<(p->data))
        insert(p->left,val,1,0);
    else if(val>(p->data))
        insert(p->right,val,0,1);
}
void deletenode(ptr node)
{
    if(node->left==NULL&&node->right==NULL){
        printf("Deleted node = %d\n",node->data);
        node=NULL;
        printf("Node = %d",node->data);
        return;
    }
    deletenode(node->left);
    deletenode(node->right);
}
void printinorder(ptr node)
{
    if (node==NULL)
        return;
    printinorder(node->left);
    printf("%d ",node->data);
    printinorder(node->right);
}
int main()
{
    int choice;
    printf("1 - Insert Node in Binary Tree.\n2 - Delete Node\n3 - Exit.\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        {
            printf("Enter data.\n");
            int d;
            scanf("%d",&d);
            insert(root,d,0,0);
            return main();
        }
        case 2:
            {
                deletenode(root);
                return main();
            }
        case 3: break;
    }
    printf("%d",root->left);

}
