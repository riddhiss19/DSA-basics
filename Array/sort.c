#include<stdio.h>
#include<stdlib.h>

void sort()
{
    /*int n,i;
    printf("Enter size of array=");
    scanf("%d",&n);
    int arr[n];
    printf("Enter array elements=");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }*/
    int temp=arr[0];
    for(i=0;i<n;i++)
    {
        if(arr[i]<temp)
        {
            temp=arr[i];
        }
        printf("%d",temp);
    }
}
