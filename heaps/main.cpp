#include <iostream>

using namespace std;
void insert(int a[],int index)
{
    int i=index,temp;
    temp=a[i];
    while(i>1 && temp>a[i/2])
    {
        a[i]=a[i/2];
        i=i/2;
    }
    a[i]=temp;
}
int del(int a[],int z)
{
    int i,j,x,temp,val;
    val=a[1];
    x=a[z];
    a[1]=a[z];
    a[z]=val;
    i=1;
    j=i*2;
    while(j<z-1)
    {
        if(a[j+1]>a[j])
            j=j+1;
        if(a[i]<a[j]){
          temp=a[i];
          a[i]=a[j];
          a[j]=temp;
          i=j;
          j=2*j;
        }
        else
            break;
    }
    return val;
}
int main()
{
    int h[]={0,10,20,30,25,5,40,35};
    int i;
    for(i=2;i<=7;i++)
    {
        insert(h,i);
    }

    for(i=1;i<=7;i++)
    {
        cout<<h[i]<<endl;
    }
    return 0;
}
