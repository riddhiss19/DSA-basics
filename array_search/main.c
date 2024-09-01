#include <stdio.h>
#include <stdlib.h>
//linear array search
int main()
{
    int i,x,flag=0;
    int n;
    printf("Enter size of the array=");
    scanf("%d",&n);
    int a[n];
    printf("Enter array elements=\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter search element=");
    scanf("%d",&x);
    for(i=0;i<n;i++)
    {
        if(a[i]==x)
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
    {
        printf("Element %d found at %d th position",x,i);
    }
    else
    {
        printf("Element not found");
    }
    return 0;
}
