#include<stdio.h>
typedef struct linked_stack *stack;
typedef struct linked_stack
{
    int data;
    stack link;
};
stack top=NULL;
void push(int x)
{
    stack temp;
    temp=(stack )malloc(sizeof(struct linked_stack));
    temp->data=x;
    temp->link=top;
    top=temp;
    printf("Pushed element = %d.\n",x);
}
void pop()
{
    int item;
    if(top==NULL)
    {
        printf("Stack is empty.\n");
        return 0;
    }
    item=top->data;
    top=top->link;
    printf("Poped element = %d\n",item);
}
void printstack()
{
    stack seek=top;
    while(seek!=NULL)
    {
        printf("%d\n|\n",seek->data);
        seek=seek->link;
    }
    printf("NULL\n");
}
int main()
{
    int choice;
    printf("1 - Push Element in stack.\n2 - Pop element from stack.\n3 - print stack.\n4 - exit.\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:{
        int item;
        printf("Enter a element to push.\n");
        scanf("%d",&item);
        push(item);
        return main();
        }
        case 2:{
        int poped;
        poped=pop();
        printf("Poped element = %d\n",poped);
        return main();
        }
        case 3:{
        printstack();
        return main();
        }
        case 4:{
        return 0;
        }
        default:{
        printf("Wrong input. please try again.\n");
        return main();
        }
    }
}
