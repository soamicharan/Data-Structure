#include<stdio.h>
#include<string.h>
int adj_mat[50][50];
int main()
{
    printf("Program to present graph using Adjacency Matrix.\n");
    printf("Choose the options.\n1 - Create Directed Graph.\n2 - Create Undirected Graph.\n3 - Exit.\n");
    int choice;
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        {
            dir_graph();
            break;
        }
    case 2:
        {
            undir_graph();
            break;
        }
    case 3:
        exit(2);
    default:
        {
            printf("Wring input.\nPlease Try Again.\n");
            return main();
        }
    }
}
void undir_graph()
{
    printf("How many vertices in graph\n");
    int ver;
    scanf("%d",&ver);
    read_mat(ver);
    printf("\n Vertices\tDegree\n");
    int deg;
    int i,j;
    for(i=1;i<=ver;i++)
    {
        deg=0;
        for(j=1;j<=ver;j++)
        {
            if(adj_mat[i][j]==1)
                deg++;
        }
        printf("\n\n %5d \t\t %d",i,deg);
    }
}
void dir_graph()
{
     int in_deg, out_deg, i, j,n;
    printf("\nHow Many Vertices ? : ");
    scanf("%d", &n);
    read_mat(n);
    printf("\n Vertex \t In_Degree \t Out_Degree \t Total_Degree ");
    for (i = 1; i <= n ; i++ )
    {
        in_deg = out_deg = 0;
	for ( j = 1 ; j <= n ; j++ )
	{
            if ( adj_mat[j][i] == 1 )
                in_deg++;
	}
        for ( j = 1 ; j <= n ; j++ )
            if (adj_mat[i][j] == 1 )
                out_deg++;
            printf("\n\n %5d\t\t\t%d\t\t%d\t\t%d\n\n",i,in_deg,out_deg,in_deg+out_deg);
    }
}
void read_mat(int v)
{
    int i,j;
    int reply;
    for(i=1;i<=v;i++)
    {
        for(j=1;j<=v;j++)
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
