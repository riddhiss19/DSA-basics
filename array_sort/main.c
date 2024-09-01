#include <stdio.h>
#include <stdlib.h>
//sorting the array-linear
//ascending sort
int main()
{
    int n,i;
    printf("Enter size of array=");
    scanf("%d",&n);
    int arr[n];
    printf("Enter array elements=\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int temp=0;
    for(i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]>arr[j])
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    printf("Array in sorted order=\n");
    for(i=0;i<n;i++)
    {
        printf("%d\n",arr[i]);
    }
    return 0;
}
