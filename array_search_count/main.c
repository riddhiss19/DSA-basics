#include <stdio.h>
#include <stdlib.h>
//program to count how many times search element found in array
int main()
{
    int i,x,cnt=0;
    int a[10]={45,25,15,5,35,55,5,25,45};
    printf("Enter search element=");
    scanf("%d",&x);
    for(i=0;i<10;i++)
    {
        if(a[i]==x)
        {
            cnt++;
        }
    }
    if(cnt>0)
    {
        printf("Element %d found %d times",x,cnt);
    }
    else
    {
        printf("Element not found");
    }
    return 0;
}
