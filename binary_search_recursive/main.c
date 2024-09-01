#include <stdio.h>
#include <stdlib.h>
//recursive search
int bin(int arr[],int low,int high,int target)
{
    if(low>high)
    {
        return -1;
    }

    int mid=(low+high)/2;
    if(target<arr[mid])
    {
        return bin(arr,low,mid-1,target);
    }
    else if(target>arr[mid])
    {
        return bin(arr,mid+1,high,target);
    }
    else{
        return mid;
    }
}
int main()
{
    int ar[]={2,5,6,8,9,10};
    int target=5;
    int low=0,high=sizeof(ar);
    int index=bin(ar,low,high,target);
    if(index!=-1)
    {
        printf("Element found at %d position",index);
    }
    else{
        printf("Element not found");
    }

    return 0;
}
