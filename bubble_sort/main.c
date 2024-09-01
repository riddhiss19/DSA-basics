#include <stdio.h>
#include <stdlib.h>
//bubble sort using function
void bubblesort(int a[],int n)
{
  int temp,i,j;
  for(i=0;i<n;i++)
  {
   for(j=0;j<n-1;j++)
   {
    if(a[j]>a[j+1])
    {
     temp=a[j];
     a[j]=a[j+1];
     a[j+1]=temp;
    }
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
    bubblesort(a,n);
    printf("The sorted array is:\n");
    for(i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }
    return 0;
}
