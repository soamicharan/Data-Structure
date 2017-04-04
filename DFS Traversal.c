#include<stdio.h>
int n,start;
int stack[100];
int status[100];
int top=-1;
int adj_mat[100][100];
int main()
{
    printf("Graph using DFS.\n");
    printf("Enter number of vertices in graph.\n");
    scanf("%d",&n);
    create_graph(n);
    printf("Enter start vertice for DFS.\n");
    scanf("%d",&start);
    DFS(start);
}
void DFS(int s)
{
    printf("Traversal using DFS : %d ",s);
    push(s);
    status[s]=1;
    while(!isEmpty_stack())
    {
        int x;
        for(x=0;x<n;x++)
        {
            if(status[x]==1)
                continue;
            if(adj_mat[stack[top]][x]==1)
            {
                printf("%d ",x);
                push(x);
                status[x]=1;
                x=0;
            }
        }
        pop();
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
void push(int e)
{
    top++;
    stack[top]=e;
}
int pop()
{
    int item=stack[top];
    top--;
    return item;
}
int isEmpty_stack()
{
    if(top==-1)
        return 1;
    else
        return 0;
}
