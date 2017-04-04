#include<stdio.h>
#define MAX 100
int queue[MAX];
int front=-1;
int rear=-1;
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
    if(rear==MAX-1)
    {
        printf("Queue is full.\n");
        exit(1);
    }
    else
    {
        if(front==-1)
            front=0;
        printf("Enter a element to push.\n");
        int item;
        scanf("%d",&item);
        queue[++rear]=item;
    }
    return main();
}
void pop()
{
    if(front==-1||front>rear)
    {
        printf("Queue is empty.\n");
        exit(2);
    }
    int item=queue[front];
    front++;
    printf("Poped element = %d\n",item);
    return main();
}
void print()
{
    int a;
    for(a=front;a<=rear;a++)
        printf("%d\n",queue[a]);
    return main();
}
