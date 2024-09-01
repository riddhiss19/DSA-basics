#include <stdio.h>
#include <stdlib.h>
//code to take input of array elements and display it
int main()
{
    int n,i;
    printf("Enter size of array=");
    scanf("%d",&n);
    int arr[n];
    printf("Enter array elements=");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
     for(i=0;i<n;i++)
    {
        printf("Array element at %d position is %d\n",i,arr[i]);
    }

    return 0;
}
