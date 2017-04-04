#include<stdio.h>
typedef struct list_node *list_pointer;
typedef struct list_node
{   // structure for linked list node
    int data;
    list_pointer link;
};
list_pointer head,first,ptr = NULL;

int main()
{
 printf("1 - insert element at end\n2 - insert element at middle of list\n3 - delete element\n4 - Reverse Linked List.\n5 - print linked list.\n0 - to exit.\n");
 int choice;
 scanf("%d",&choice);
 if(choice==1)  //to add an node to end of the list
 {
     int num;
     printf("Enter number.\n");
     scanf("%d",&num);
     insert(num);
 }
 else if(choice==2)  //to insert an node in middile of list
    {
         printf("press 1 for value search.\npress 2 for address search.\n"); //the given data can be value of node or address of that node
         int d;
         scanf("%d",&d);  //so choose basis of search
         if(d==1)   //if given data is searched by value of node
        {
            int val;
            printf("Enter value of element.\n");
            scanf("%d",&val);
            insertbyval(val);
        }
        else if(d==2)   //if given data is address of node
        {
            int add;
            printf("Enter address of node.\n");
            scanf("%d",&add);
            insertbyadd(add);
        }
    }
    else if(choice==3)  //if we want to delete an node from list
    {
        printf("press 1 for value search.\npress 2 for address search.\n"); //the given data can be value of node or address of that node
        int c;
        scanf("%d",&c);
        if(c==1)
        {
            int val;
            printf("Enter value of element.\n");
            scanf("%d",&val);
            deletebyval(val);
        }
        else if(c==2)
        {
            int add;
            printf("Enter address of node.\n");
            scanf("%d",&add);
            deletebyadd(add);
        }
    }
    else if(choice == 4)
        reverselist();
    else if(choice==5)
        printlist();
    else if(choice == 0)
        return 0;
}
/*to insert an element at end on node*/
int insert(int x)
{
     head=(list_pointer)malloc(sizeof(struct list_node));
     head->data=x;
     if(first!=NULL)
        {
          ptr->link=head;
          ptr=head;
          ptr->link=NULL;
        }
     else
     {
        first=head;
        ptr=head;
        ptr->link=NULL;

     }
return main();
}
/*to print the linked list*/
void printlist()
{
    list_pointer seek=first;
    while(seek!=NULL)
    {
        printf("%d -->",seek->data);
        seek=seek->link;
    }
    printf("NULL\n");
    return main();
}

/*to delete node by given value*/
int deletebyval(int x)
{
    list_pointer seek1=first;
    list_pointer seek2=first;
    int check=0;
    while(seek1!=NULL)
    {
        if(seek1->data==x)
            {
                check=1;
                break;
            }
            else
            seek1=seek1->link;
    }
    if(seek1==first)
    {
        first=seek1->link;
        free(seek1);
    }
    else if(check==0){
        printf("Entered value is not matched with any linked list node.\n");
        return main();
    }
    else
    {
        while(seek2->link!=seek1)
        seek2=seek2->link;
      seek2->link=seek1->link;
    free(seek1);
    }

    printf("Deletion sucessfully.\n");
    return main();
}

/*delete value by given address of node*/
int deletebyadd(int x)
{
    list_pointer seek=first;
    if(seek==x)
    {
        first=seek->link;
        free(seek);
        printf("Deletion sucessfully.\n");
        return main();
    }
    else
    {
        while(seek->link!=x)
            seek=seek->link;
        list_pointer nextnode=seek->link;
        seek->link=nextnode->link;
        free(nextnode);
        printf("Deletion Successfully.\n");
        return main();
    }
}

/*insert an element by given value*/
int insertbyval(int x)
{


        list_pointer seek1=first,temp;
        list_pointer seek2=first;
        int check=0;
        temp=(list_pointer)malloc(sizeof(struct list_node));
        int newval;
        printf("Enter a value which will be inserted.\n");
        scanf("%d",&newval);
        temp->data=newval;
    while(seek1!=NULL)
    {
        if(seek1->data==x)
            {
                check=1;
                break;
            }
            else
            seek1=seek1->link;
    }
    if(seek1==first)
    {
        first=temp;
        temp->link=seek1->link;
        printf("Insertion sucessfully.\n");
        return main();
    }
    else if(check==0){
        printf("Entered value is not matched with any linked list node.\n");
        return main();
    }
    else
    {
        while(seek2->link!=seek1)
        seek2=seek2->link;
        int c;
        printf("Press 1 to insert before the value or 2 to insert after the value.\n");//now given node can be insert before or after the given node
        scanf("%d",&c);
        if(c==1){
        temp->link=seek2->link;
      seek2->link=temp;
       printf("Insertion sucessfully.\n");
       return main();
        }
        else{
            seek2=seek2->link;
            temp->link=seek2->link;
            seek2->link=temp;
            printf("Insertion sucessfully.\n");
            return main();
        }

    }

}

/*insert an node by address*/
int insertbyadd(int x)
{
    list_pointer seek=first,temp;
     temp=(list_pointer)malloc(sizeof(struct list_node));
    if(seek==x)
    {
        temp->link=seek->link;
        first=temp;

        printf("Insertion successfully.\n");
        return main();
    }
    else
    {
        while(seek->link!=x)
            seek=seek->link;
        int c;
        printf("Press 1 to insert before the value or 2 to insert after the value.\n");
        scanf("%d",&c);
        if(c==1)
        {
            temp->link=seek->link;
            seek->link=temp;
            printf("Insertion Successfully.\n");
        return main();
        }
        else{
        seek=seek->link;
        temp->link=seek->link;
        seek->link=temp;
        printf("Insertion Successfully.\n");
        return main();
        }
    }
}
void reverselist()
{
    list_pointer temp;
    temp=first;
    do
    {
        if(head->link==NULL)
        {
            head->link=first;
            first=first->link;
            temp->link=NULL;
            temp=first;
        }
        else
        {
            temp=first->link;
            first->link=head->link;
            head->link=first;
            first=temp;
        }
    }
    while(first!=head);
    printf("List reversed successfully\n");
    return main();
}
