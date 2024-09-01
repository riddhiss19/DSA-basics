#include <stdio.h>
#include <stdlib.h>
//iterative search

int bin(int arr[],int l,int r,int x)
{
    while(l<=r)
    {
        int m=l+(r-1)/2;
        if(arr[m]==x)
            return m;
        if(arr[m]<x)
            l=m+1;
        else
            r=m-1;
    }
    return -1;
}
int main()
{
    int arr[]={2,3,4,10,40};
    int x=4;
    int n=5;
    int res=bin(arr,0,n-1,x);
    (res==-1)?printf("Element not found"):printf("Element found at %d position",res);
    return 0;
}
