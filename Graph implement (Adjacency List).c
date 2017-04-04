#include<stdio.h>
struct head_node
{
    int vertex;
    struct head_node* link;

};
struct adj_node
{
    int vertices;
    struct adj_node* link;
};
struct head_node* h_ptr=NULL;
struct adj_node* l_ptr=NULL;
int main()
{
    printf("Graph Implementation using Adjacency List.\n");
    printf("How many vertices?\n");
    int v;
    scanf("%d",&v);
    int i;
    for(i=1;i<=v;i++)
    {
        h_ptr=(struct head_node*)malloc(sizeof(struct head_node));
        h_ptr->vertex=i;
        l_ptr=(struct adj_node*)malloc(sizeof(struct adj_node));
        l_ptr->link=NULL;
        h_ptr->link=l_ptr;
        int j;
        for(j=1;j<=v;j++)
        {
            printf("Vertices %d and %d are adjacent?(1/0)\n",i,j);
            int c;
            scanf("%d",&c);
            if(c==1)
            {
                l_ptr->vertices=j;
                struct adj_node* temp=(struct adj_node*)malloc(sizeof(struct adj_node));
                l_ptr->link=temp;
                temp->link=NULL;
                l_ptr=temp;
            }
        }
        struct adj_node* seek=h_ptr->link;
        printf("Vertice   Adjacents\n");
        printf("%d         ",h_ptr->vertex);
        while(seek->link!=NULL)
        {
            printf("%d --> ",seek->vertices);
            seek=seek->link;
        }
        printf("NULL\n");
    }
}
