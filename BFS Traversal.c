#include<stdio.h>
int n,start;
int queue[100];
int status[100];
int front=-1,rear=-1;
int adj_mat[100][100];
int main()
{
    printf("Graph Traversal Using BFS.\n");
    printf("Enter Number of Vertices in Graph.\n");
    scanf("%d",&n);
    create_graph(n);
    printf("Enter Start Vertice for BFS.\n");
    scanf("%d",&start);
    BFS(start);
}
void BFS(int s)
{
    printf("Graph Traversal Using BFS : ");
    push(s);
    status[s]=1;
    while(!isEmpty_queue())
    {

        int x;
        for(x=0;x<n;x++)
        {

            if(adj_mat[queue[front]][x]==1)
            {
                if(status[x]==1)
                    continue;
                push(x);
                status[x]=1;
            }

        }
        int y=pop();
        printf("%d ",y);
    }


}



void create_graph(int v)
{
    int i,j;
    int reply;
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            if(i==j)
            {
                adj_mat[i][j]=0;
                continue;
            }
            printf("\nVertices %d and %d are Adjacent? (1/0) : ",i,j);
            scanf("%d",&reply);
            if(reply==1)
                adj_mat[i][j]=1;
            else if(reply==0)
                adj_mat[i][j]=0;

        }
    }
}
void push(int vertex)
{
    if(rear == 99)
        printf("Queue Overflow\n");
    else
    {
        if(front == -1)
            front = 0;
        rear = rear+1;
        queue[rear] = vertex ;
    }
}
int pop()
{
    int delete_item;
    if(front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
        exit(1);
    }

    delete_item = queue[front];
    front = front+1;
    return delete_item;
}
int isEmpty_queue()
{
    if(front == -1 || front > rear)
        return 1;
    else
        return 0;
}
