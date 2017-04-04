#include<stdio.h>
#include<time.h>
#include<conio.h>
int main()
{
    int m_r,m_c;

    printf("Enter Number of rows and columns.\n");
    scanf("%d%d",&m_r,&m_c);//scanning number or rows and columns in original matrix

    int a,b,mat[m_r][m_c],count=0;


    for(a=0;a<m_r;a++)
    {
        for(b=0;b<m_c;b++)
        {
            mat[a][b]=rand()%10;//we initializing our matrix with random values
            if(mat[a][b]!=0) //we keep count of non zero values
                count++;
        }
    }

    int smat[count+1][3];  //initializing sparse matrix
    smat[0][0]=m_r; //giving heading values to sparse matrix
    smat[0][1]=m_c;

    int pc[m_c];
    for(a=0;a<m_c;a++)
        pc[a]=0;        //position counter array pc initializing with zero

    int mcount=1;
    for(a=0;a<m_r;a++)
    {
        for(b=0;b<m_c;b++)
        {
            if(mat[a][b]!=0)   //if value of matrix is non zero then it initialize in sparse matrix smat
                {
                    smat[mcount][0]=a;  //rows store in 0th column
                    smat[mcount][1]=b;   //columns store in 1st column
                    smat[mcount][2]=mat[a][b];   //values are store in 2nd column
                    pc[b]++;       //we increment our position counter index value
                    mcount++;
                }
        }
    }

    smat[0][2]=count-1;

    int pt[m_c];
    pt[0]=1;       //position tracer array pt and pt[0] is initialize with 1

    for(a=1;a<m_c;a++)
    {
        pt[a]=pt[a-1]+pc[a-1];   //the for loop traces the occurance of columns in sparse matrix and give index numbers according to position counting and index spacing
    }

    printf("No. of Non Zero Values in matrix = %d\n",count-1);

    printf("\n\n");

    printf("Sparse Matrix is -\n");
    printf("Index\tRow\tColumn\tValue\n");
    for(a=1;a<count;a++)
    {
            printf("%d\t%d\t%d\t%d\n",a,smat[a][0],smat[a][1],smat[a][2]);
    }
    printf("\n\n");

    printf("Position counter array-\nIndex\tValue\n");
    for(b=0;b<m_c;b++)
        printf("%d\t%d\n",b,pc[b]);

    printf("\n\n");

    printf("Position Tracer array - \nIndex\tValue\n");
    for(b=0;b<m_c;b++)
        printf("%d\t%d\n",b,pt[b]);

    printf("\n\n");

    int tsmat[count+1][3],currenti;
    for(a=1;a<count;a++)
    {
       currenti=pt[smat[a][1]];  //current index for transposing sparse matrix is determined by smat[a][1] so currenti represents the index of transposed matrix where value should be stored in acending order
       tsmat[currenti][0]=smat[a][1];
       tsmat[currenti][1]=smat[a][0];
       tsmat[currenti][2]=smat[a][2];
       pt[smat[a][1]]++;         //we increment the position tracer index so if any same number of column exist then it will initialize just next after it
       pc[smat[a][1]]--;
    }
    printf("\n\n");
    printf("Transpose Sparse Matrix is - \nIndex\tColumns\tRows\tValue\n");
    for(a=1;a<count;a++)
    {
        printf("%d\t%d\t%d\t%d\n",a,tsmat[a][0],tsmat[a][1],tsmat[a][2]);
    }
    printf("\n\n");

}
