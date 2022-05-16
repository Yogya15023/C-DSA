#include <iostream>

using namespace std;
int hashs(int key)
{
    return key%10;
}
int probe(int h[],int key)
{
    int index=hashs(key);
    int i=0;
    while(h[(index+i)%10]!=0)
    {
        i++;
    }
    return (index+i)%10;
}
void inserts(int h[],int key)
{
    int index=hashs(key);
    if(h[index]!=0)
        index=probe(h,key);
    h[index]=key;
}
int searchs(int h[],int key)
{
    int index=hashs(key);
    int i=0;
    while(h[(index+i)%10]!=key)
        i++;
    return (index+i)%10;
}
int main()
{int ht[10];
inserts(ht,10);
inserts(ht,11);
inserts(ht,21);
cout<<"Key found at index: "<<searchs(ht,21);
    return 0;
}
// for quadratic probing change i in the program by i*i;
