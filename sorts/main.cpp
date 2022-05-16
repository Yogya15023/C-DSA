#include <iostream>

using namespace std;
void swap(int *x,int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
void bubblesort(int a[],int n)
{
    int i,j,flag;
    for(i=0;i<n-1;i++)
    { flag =0;
        for(j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1]){
                swap(&a[j],&a[j+1]);
                flag=1;}
        }
        if(flag==0)
            break;
    }
    for(int i=0;i<n;i++)
{
    cout<<a[i]<<endl;
}
}
void insertionsort(int a[],int n)
{
    int i,j,x;
    for(i=1;i<n;i++)
    {x=a[i];
    j=i-1;
        while(j>-1 && a[j]>x)
        {a[j+1]=a[j];
        j--;
        }
        a[j+1]=x;
    }
    for(int i=0;i<n;i++)
{
    cout<<a[i]<<endl;
}
}
void selectionsort(int a[],int n)
{
    int i,j,k,temp;

    for(i=0;i<n-1;i++)
    {
    for(j=k=i;j<n;j++){
    if(a[j]<a[k])
    {
        k=j;
    }
    }
    temp=a[i];
    a[i]=a[k];
    a[k]=temp;

    }
    for(int i=0;i<n;i++)
{
    cout<<a[i]<<endl;
}
}
int partitioning(int a[],int l,int h)
{
    int pivot=a[l];
    int i=l,j=h;
    do{
    do{i++;}while(a[i]<=pivot);
    do{j--;}while(a[j]>pivot);

    if(i<j){
        swap(&a[i],&a[j]);
    }
    }while(i<j);
    swap(&a[l],&a[j]);
    return j;
}
void quicksort(int a[],int l,int h){
    int j;
    if(l<h)
    {
        j=partitioning(a,l,h);
        quicksort(a,l,j);
        quicksort(a,j+1,h);
    }
}
void merge(int a[],int l,int mid,int h)
{//for sorted inputs of two different lists
    int i,j,k=l;
    int b[100];
    i=l;
    j=mid+1;
    while(i<=mid && j<=h)
    {
        if(a[i]<a[j])
        {
            b[k++]=a[i++];
        }
        else if(a[j]<a[i])
        {
            b[k++]=a[j++];
        }
    }
    for(;i<=mid;i++)
        b[k++]=a[i];
    for(;j<=h;j++)
        b[k++]=a[j];
    for(i=l;i<=h;i++)
        a[i]=b[i];
}
void imergesort(int a[],int n)//n= nos. of elements;
{
    int p,l,mid,h,i;
    for(p=2;p<=n;p=p*2)
    {
        for(i=0;i+p-1<n;i=i+p)
        {
            l=i;
            h=i+p-1;
            mid=(l+h)/2;
            merge(a,l,mid,h);
        }
    }
    if(p/2<n)
        {
            merge(a,0,p/2-1,n-1);
        }
}
int maxi(int a[],int n)
{
    int max=-1,i;
    for(i=0;i<n;i++)
    {
        if(a[i]>max)
            max=a[i];
    }
    return max;
}
void countsort(int a[],int n)
{
    int i,j,p;
    int *s;
    p=maxi(a,n);
    s=new int[p+1];
    for(i=0;i<p+1;i++)
    {
        s[i]=0;
    }
    for(i=0;i<n;i++)
    {
        s[a[i]]++;
    }
    i=0,j=0;
    while(i<p+1)
    {
        if(s[i]>0)
        {
            a[j++]=i;
            s[i]--;
        }
        else
            i++;
    }
}
int main()
{int n;
cin>>n;
int z[n];
for(int i=0;i<n;i++)
{
    cin>>z[i];
}
countsort(z,n);
for(int i=0;i<n;i++)
{
    cout<<z[i]<<endl;
}
    return 0;
}
