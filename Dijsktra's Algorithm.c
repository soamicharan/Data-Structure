#include<stdio.h>
#define INF -1
#define visited 1
int vertices,start;
int dist[100];
int queue[100];
int front=-1,rear=-1;
int status[100];
int adj_mat[100][100];
int weightinfo[100][100];
int main()
{
    printf("Dijsktra's Algorithm to find shortest path from one vertex to all vertices.\n");
    printf("Enter No. of Vertices in Graph.\n");
    scanf("%d",&vertices);
    createGraph();
    printf("Enter Source Vertex.\n");
    scanf("%d",&start);
    shortest_path();
    int l;
    for(l=0;l<vertices;l++)
        printf("%d ",dist[l]);

}
void createGraph()
{
    int i=0,j=0,w=0,a,b;
    for(a=0;a<vertices;a++){
        for(b=0;b<vertices;b++){
            adj_mat[a][b]=0;
            weightinfo[a][b]=0;
        }
        dist[a]=INF;
    }
    while(1)
    {
        printf("\nEnter Vertices with edges.(Enter -1 and -1 to exit) : ");
        scanf("%d%d",&i,&j);
        printf("\nEnter weight of edge : ");
        scanf("%d",&w);
        if(i==-1&&j==-1)
            break;
        else if(i==j)
            printf("Invalid veritces. Try Again\n");
        else if (i>vertices||j>vertices)
            printf("Invalid vertices. Try Again\n");
        else
        {
            adj_mat[i][j]=1;
            weightinfo[i][j]=w;
        }
    }
}
void shortest_path()
{
    dist[start]=0;
    status[start]=visited;
    push(start);
    while(!isEmpty_queue())
    {
        int x,min_v;
        for(x=0;x<vertices;x++)
        {
            if(adj_mat[queue[front]][x]==1)
            {
                if(status[x]==1)
                    continue;
                push(x);
                status[x]=1;
            }
        }
        min_v=findMinimum();
        pop();
        swap_vertices(min_v);
    }

}
int isEmpty_queue()
{
    if(front==-1||front>rear)
        return 1;
    else
        return 0;
}
int findMinimum()
{
    int min_w=1000,min_i=front,total_d=dist[queue[front]];
    int temp=front+1;
    while(temp!=rear+1)
    {
        int edge_d=weightinfo[queue[front]][queue[temp]];
        if(dist[queue[temp]]==INF)
             dist[queue[temp]]=total_d+edge_d;
        else if(edge_d+total_d<dist[queue[temp]]&&edge_d!=0)
                dist[queue[temp]]=total_d+edge_d;
        if(dist[queue[temp]]<min_w&&dist[queue[temp]]!=INF)
        {
            min_w=dist[queue[temp]];
            min_i=temp;

        }
        temp++;
    }
    return min_i;
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
void pop()
{
    int delete_item;
    if(front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
        exit(1);
    }

    delete_item = queue[front];
    front = front+1;
}
void swap_vertices(int x)
{
    int temp=queue[front];
    queue[front]=queue[x];
    queue[x]=temp;
}
