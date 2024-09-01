#include <stdio.h>
#include <stdlib.h>

int partition(int a[],int start,int end)
{
    int temp,j;
    int pivot=a[end];
    int i=(start-1);
    for(j=start;j<=end-1;j++)
    {
        if(a[j]<pivot)
        {
            i++;
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    int t=a[i+1];
    a[i+1]=a[end];
    a[end]=t;
    return (i+1);
}
void quick(int a[],int start,int end)
{

    if(start<end)
    {
        int p;
        p=partition(a,start,end);
        quick(a,start,p-1);
        quick(a,p+1,end);
    }

}
int main()
{
    int n,i;
   // printf("Enter the size of the array:\n");
   // scanf("%d",&n);
    int a[5];
    printf("Enter the array elements:\n");
    for(i=0;i<5;i++)
    {
        scanf("%d",&a[i]);
    }
    //int end=5;
    quick(a,0,4);
    printf("The sorted array is:\n");
    for(i=0;i<5;i++)
    {
        printf("%d\n",a[i]);
    }
    return 0;
}
