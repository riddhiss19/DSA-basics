#include <stdio.h>
#include <stdlib.h>

void insertionSort(int array[], int n)
{
    int i, element, j;
    for (i = 1; i < n; i++)
    {
        element = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > element)
        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = element;
    }
}
void display(int array[], int n)
{
    int i;
    printf("Sorted array is:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\n", array[i]);
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
    insertionSort(a,n);
    display(a,n);
    return 0;
}
