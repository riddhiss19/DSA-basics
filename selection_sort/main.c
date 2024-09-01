#include <stdio.h>
#include <stdlib.h>

void selection(int a[],int n)
{
    int i,j,small;
    for(i=0;i<n-1;i++)
    {
        small=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[small])
            {
                small=j;
            }
            int temp=a[small];
            a[small]=a[i];
            a[i]=temp;
        }
    }
}
int main()
{
    int n,i;
    printf("Enter the size of the array:\n");
    scanf("%d",&n);
    int a[n];
    printf("Enter the array elements:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    selection(a,n);
    printf("The sorted array is:\n");
    for(i=0;i<5;i++)
    {
        printf("%d\n",a[i]);
    }
    return 0;
}
