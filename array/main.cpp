#include <iostream>

using namespace std;
struct array
{
    int A[10];
    int size;
    int length;
};

void display(struct array arr){
int i;
cout<<"numbers are: "<<endl;
for(i=0;i<arr.length;i++){
    cout<<arr.A[i]<<endl;
}
}
void insert(struct array *arr,int index,int n){
    int i;
    for(i=arr->length;i>index;i--)
    {
        arr[i]=arr[i-1];

    }
arr->A[index]=n;
arr->length++;
}
int del(struct array *arr,int index){
int i;
for (i=index;i<arr->length-1;i++){
    arr->A[i]=arr->A[i+1];
}
arr->length--;
return 0;
}
void append(struct array *arr,int x){
if (arr->length<arr->size){
    arr->A[arr->length++]=x;
}

}
void swap(int *x,int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
int linearsearch(struct array *arr,int key ){
int i;
for(i=0;i<arr->length;i++)
    {
    if(key==arr->A[i]){
     swap(&arr->A[i],&arr->A[0]);
    return i;
     }
    }
    return -1;
}
int binarysearch(struct array arr,int key)
{
    int l=0;
    int h=arr.length-1;
    while(l<=h){
        int mid=(l+h)/2;
        if(key==arr.A[mid])
            return mid;
        else if(key<arr.A[mid])
            h=mid-1;
        else
            l=mid+1;
    }
    return -1;
}
int get(struct array arr, int index){
    if(index>=0 && index<arr.length){
    return arr.A[index];
    }
    else
        return -1;

}
void set(struct array *arr,int index,int x){
    if(index>=0 && index<arr->length){
       arr->A[index]=x;
    }
}
int max(struct array arr){

        int i;
       int  M=arr.A[0];
        for(i=1;i<arr.length;i++){
            if(arr.A[i]>M){
                M=arr.A[i];
            }
        }

     return M;
}
int min(struct array arr){

        int i;
       int m=arr.A[0];
        for(i=1;i<arr.length;i++){
            if(arr.A[i]<m){
                m=arr.A[i];
            }
        }

     return m;
}
int sum(struct array arr){
int s=0;
int i;
for(i=0;i<arr.length;i++){
s=s+arr.A[i];
}
return s;
}
float avg(struct array arr){
return (float) sum(arr)/arr.length;
}
void rev(struct array *arr){
int i,j,temp;
for(i=0,j=arr->length-1;i<j;i++,j--)
    {
        temp=arr->A[i];
        arr->A[i]=arr->A[j];
        arr->A[j]=temp;
    }
}
void lshift(struct array *arr){
int i;
for(i=0;i<=arr->length;i++)
    {
        arr->A[i-1]=arr->A[i];
    }

}
void rshift(struct array *arr){
int i;
for(i=arr->length-1;i>=0;i--)
    {
        arr->A[i]=arr->A[i-1];
    }
}
void lrota(struct array *arr)
{
  int temp=arr->A[0];
  lshift(arr);
  arr->A[arr->length-1]=temp;


}
void rrota(struct array *arr)
{
  int temp=arr->A[arr->length-1];
  rshift(arr);
  arr->A[0]=temp;


}
void inserts(struct array *arr,int x){
int i=arr->length-1;
while(i>=0 && arr->A[i]>x){
    arr->A[i+1]=arr->A[i];
    i--;
}
arr->A[i+1]=x;
arr->length++;
}
int issorted(struct array arr){
    int i;
    for(i=0;i<arr.length-1;i++){
       if(arr.A[i]>arr.A[i+1])
           return 0;
         }
    return 1;
}
void rearrange(struct array *arr){
int i,j;
i=0;
j=arr->length-1;
while(i<j){
    while(arr->A[i]<0){
        i++;
    }
    while(arr->A[j]>=0){
        j--;
    }
    if(i<j){
        swap(&arr->A[i],&arr->A[j]);
    }
}
}
struct array* merge(struct array *arr1,struct array *arr2){
int i,j,k;
i=j=k=0;
struct array *arr3=new array;
while(i<arr1->length && j<arr2->length){
    if(arr1->A[i]<arr2->A[j]){
        arr3->A[k++]=arr1->A[i++];
    }
    else
         arr3->A[k++]=arr2->A[j++];
}
    for(;i<arr1->length;i++){
      arr3->A[k++]=arr1->A[i++];
    }
    for(;j<arr2->length;j++){
      arr3->A[k++]=arr2->A[j++];
    }
    arr3->length=arr1->length+arr2->length;
    arr3->size=20;

return arr3;

}
struct array* Union(struct array *arr1,struct array *arr2){
int i,j,k;
i=j=k=0;
struct array *arr3=new array;
while(i<arr1->length && j<arr2->length){
    if(arr1->A[i]<arr2->A[j]){
        arr3->A[k++]=arr1->A[i++];
    }
    else if (arr2->A[j]<arr1->A[i]){
         arr3->A[k++]=arr2->A[j++];
    }
    else {
        arr3->A[k++]=arr1->A[i++];
        j++;
    }
}
    for(;i<arr1->length;i++){
      arr3->A[k++]=arr1->A[i++];
    }
    for(;j<arr2->length;j++){
      arr3->A[k++]=arr2->A[j++];
    }
    arr3->length=k;
    arr3->size=20;

return arr3;

}
struct array* intersection(struct array *arr1,struct array *arr2){
int i,j,k;
i=j=k=0;
struct array *arr3=new array;
while(i<arr1->length && j<arr2->length){
    if(arr1->A[i]<arr2->A[j]){
        i++;
    }
    else if (arr2->A[j]<arr1->A[i]){
         j++;
    }
    else {
        arr3->A[k++]=arr1->A[i++];
        j++;
    }
}

    arr3->length=k;
    arr3->size=20;

return arr3;

}
struct array* diff(struct array *arr1,struct array *arr2){
int i,j,k;
i=j=k=0;
struct array *arr3=new array;
while(i<arr1->length && j<arr2->length){
    if(arr1->A[i]<arr2->A[j]){
        arr3->A[k++]=arr1->A[i++];

    }
    else  if(arr2->A[j]<arr1->A[i]){
        j++;
    }
    else{
        i++;
        j++;
    }
}
    for(;i<arr1->length;i++){
      arr3->A[k++]=arr1->A[i];
    }
    arr3->length=k;
    arr3->size=20;

return arr3;

}
int missing(struct array arr1){
int i;
int sum=0;
int s;
for(i=0;i<arr1.length;i++){
    sum=sum+arr1.A[i];
}
s=(arr1.length)*(arr1.length+1)/2;
if(s-sum!=0){
      cout<<"missing no. is :"<<s-sum;
}
else
      cout<<"no missing numbers!";
}
int miss(struct array arr1){
int diff,i;
diff=arr1.A[0]-0;
for(i=0;i<arr1.length;i++){
    if(arr1.A[i]-i!=diff){
        while(diff<arr1.A[i]-i){
            cout<<"the missing numbers are: "<<i+diff<<endl;
            diff++;

        }

    }

}
}
int miss1(struct array arr1,struct array arr2){
int i;
for(i=0;i<arr1.length;i++){
    arr2.A[arr1.A[i]]++;
}
for(i=arr1.A[0];i<arr2.length;i++){
    if(arr2.A[i]==0){
        cout<<"the missing no is : "<<i<<endl;
    }
}
}
int dup(struct array arr1){
int i,ld=0,c=0;
for(i=0;i<arr1.length;i++){
    if(arr1.A[i]==arr1.A[i+1] && arr1.A[i]!=ld){
        cout<<"duplicate entry found: "<<arr1.A[i]<<endl;
        ld=arr1.A[i];
        c++;
    }

}
cout<<"no. of duplicate entries: "<<c<<endl;
}
int dupunsorted(struct array arr1){
int i,j;
for(i=0;i<arr1.length-1;i++){

   int c=1;
    for(j=i+1;j<arr1.length;j++){
        if(arr1.A[i]==arr1.A[j]){
            if(arr1.A[i]==-1){break;}
            c++;
            arr1.A[j]=-1;
        }
    }
    if(c>1){
        cout<<"numbers are: "<<arr1.A[i]<<endl;
        cout<<"no of duplicates are:"<<c<<endl;
    }
}

}
int sum10(struct array arr1){
int i,j;
for(i=0;i<arr1.length-1;i++){
    for(j=1+i;j<arr1.length;j++){
        if(arr1.A[i]+arr1.A[j]==10){
            cout<<"number 1 is: "<<arr1.A[i];
            cout<<" number 2 is: "<<arr1.A[j]<<endl;

        }
    }
}
}
int maxmin(struct array arr1){
int i,mx=arr1.A[0],mn=arr1.A[0];
for(i=0;i<arr1.length;i++){
         if(arr1.A[i]<mn){
         mn=arr1.A[i];
    }
             else if(arr1.A[i]>mx){
              mx=arr1.A[i];
    }

}
cout<<"minimum number in array is: "<<mn<<endl;
cout<<"maximum number in array is: "<<mx<<endl;
}
int main(){
struct array arr1={{1,2,3,4,5,6,7,8,-1,10},15,10};
struct array arr2={{},10,7};
struct array *arr3;
maxmin(arr1);

    return 0;
}
