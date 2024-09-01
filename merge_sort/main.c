#include <stdio.h>
#include <stdlib.h>

void merge(int a[],int beg,int mid,int end)
{
    int i,j,k;
    int n1=mid-beg+1;
    int n2=end-mid;

    int leftarray[n1],rightarray[n2];
    for(int i=0;i<n1;i++)
    {
        leftarray[i]=a[beg+i];
    }
    for(j=0;j<n2;j++)
    {
        rightarray[j]=a[mid+1+j];
    }
    i=0;
    j=0;
    k=beg;

    while(i<n1 && j<n2)
    {
        if(leftarray[i]<=rightarray[j])
        {
            a[k]=leftarray[i];
            i++;
        }
        else{
            a[k]=rightarray[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        a[k]=leftarray[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        a[k]=rightarray[j];
        j++;
        k++;
    }
}
void mergeSort(int a[],int beg,int end)
{
    if(beg<end)
    {
        int mid=(beg+end)/2;
        mergeSort(a,beg,mid);
        mergeSort(a,mid+1,end);
        merge(a,beg,mid,end);
    }
}

int main()
{
    int a[5],i;
    printf("Enter the array elements:\n");
    for(i=0;i<5;i++)
    {
        scanf("%d",&a[i]);
    }
    mergeSort(a,0,4);
    printf("The sorted array is:\n");
    for(i=0;i<5;i++)
    {
        printf("%d\n",a[i]);
    }
    return 0;
}
