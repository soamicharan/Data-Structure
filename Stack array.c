#include<stdio.h>
#define MAX 100
struct stack_info
{
    int data;
};
struct stack_info stack[MAX];
int top=-1;
int main()
{
    printf("1-Push element.\n2-Pop element.\n3-Print stack.\n4-Exit.\n");
    int choice;
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:{
        push();
        break;
        }
        case 2:{
        pop();
        break;
        }
        case 3:{
        print();
        break;
        }
        case 4:{
        return 0;
        }
    }
}
void push()
{
    if(top==MAX-1)
    {
        printf("Stack is full.");
        exit(1);
    }
    printf("Enter a value to push.\n");
    int item;
    scanf("%d",&item);
    stack[++top].data=item;

    return main();
}
void pop()
{
    if(top==-1)
    {
        printf("Stack is empty.");
        exit(2);
    }
    int item=stack[top].data;
    top--;
    printf("Poped element = %d\n",item);
    return main();
}
void print()
{
    int a;
    for(a=0;a<=top;a++)
        printf("%d\n",stack[a].data);
    return main();
}
