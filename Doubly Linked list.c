#include<stdio.h>
typedef struct d_linked_list *list_pointer;
typedef struct d_linked_list
{
    int data;
    list_pointer llink;
    list_pointer rlink;
};
list_pointer last,ptr=NULL;
list_pointer first=NULL;
int main()
{
    printf("1-Add node at last.\n2-Add node between the nodes.\n3-Delete a node.\n4-Print list.\n");
    int choice;
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:{
        insert();
        break;
        }
        case 2:{
        insert_at_mid();
        break;
        }
        case 3:{
        deletenode();
        break;
        }
        case 4:{
        print();
        break;
        }
    }
}
void insert()
{
    last=(list_pointer)malloc(sizeof(struct d_linked_list));
    printf("Enter a value to insert.\n");
    int x;
    scanf("%d",&x);
    last->data=x;
    if(first!=NULL)
    {
        ptr->rlink=last;
        last->llink=ptr;
        ptr=last;
        ptr->rlink=NULL;
    }
    else
    {
        first=last;
        ptr=last;
        last->llink=NULL;
        last->rlink=NULL;
    }
    return main();
}
void print()
{
    list_pointer seek=first;
    while(seek!=NULL)
    {
        printf("%d=>",seek->data);
        seek=seek->rlink;
    }
    printf("NULL");
}
void insert_at_mid()
{
    printf("Provide a node data then a new node insert after it.\n");
    int x;
    scanf("%d",&x);
    list_pointer seek=first;
    while(seek->data!=x)
        seek=seek->rlink;
    list_pointer temp=(list_pointer)malloc(sizeof(struct d_linked_list));
    printf("Enter a value to node.\n");
    int y;
    scanf("%d",&y);
    temp->data=y;
    temp->rlink=seek->rlink;
    seek->rlink=temp;
    temp->llink=seek;

    if(seek!=last)
    {
    seek=temp->rlink;
    seek->llink=temp;
    }
    return main();

}
void deletenode()
{
    printf("Provide a node data which will be deleted.\n");
    int x;
    scanf("%d",&x);
    list_pointer seek=first;
    while(seek->data!=x)
        seek=seek->rlink;
    if(seek!=first){
    list_pointer temp=seek->llink;
    temp->rlink=seek->rlink;
    seek=seek->rlink;
    seek->llink=temp;
    }
    else
    {
        first=seek->rlink;
        first->llink=NULL;
    }
    return main();
}
