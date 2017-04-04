#include<stdio.h>
typedef struct linked_queue *queue;
typedef struct linked_queue
{   int data;
    queue link;
};
queue front=NULL;
queue rear=NULL;
void push(int x)
{
    queue temp;
    temp=(queue )malloc(sizeof(struct linked_queue));
    temp->data=x;
    temp->link=NULL;
    if(rear!=NULL)
        rear->link=temp;
    rear=temp;
    if(front==NULL)
        front=rear;
    printf("Pushed element = %d.\n",x);
}
void pop()
{
    int item;
    queue temp;
    temp=front;
    if(front==rear)
    {
        printf("queue is empty.\n");
        return 0;
    }
    item=front->data;
    front=front->link;
    printf("Poped element = %d\n",item);
    free(temp);
}
void printqueue()
{
    queue seek=front;
    while(seek!=NULL)
    {
        printf("%d\n|\n",seek->data);
        seek=seek->link;
    }
    printf("NULL\n");
}
int main()
{
    push(10);push(20);push(30);push(40);push(50);
    pop();pop();
    printqueue();
}
