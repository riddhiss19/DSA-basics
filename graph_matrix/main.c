#include <stdio.h>
#include <stdlib.h>
#define v 4
void init(int arr[][v])
{
    int i,j;
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            arr[i][j]=0;
        }
    }
}
void addEdge(int arr[][v],int i,int j)
{
    arr[i][j]=1;
    arr[j][i]=1;
}
void printMatrix(int arr[][v])
{
    int i,j;
    for(i=0;i<v;i++)
    {
     printf(" %d",i)   ;
        for(j=0;j<v;j++)
        {
            printf(" %d",arr[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int a[v][v];
    init(a);
    addEdge(a,0,1);
    addEdge(a,0,2);
    addEdge(a,1,2);
    addEdge(a,2,0);
    addEdge(a,2,3);
    printMatrix(a);
    return 0;
}
