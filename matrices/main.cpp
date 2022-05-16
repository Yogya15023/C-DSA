#include <iostream>

using namespace std;

struct matrix {
int s[10];
int n;
};
void set(struct matrix *m,int i,int j,int x){
if(i==j){
    m->s[i]=x;
}

}
int get(struct matrix m,int i,int j){
if(i==j){
    cout<<m.s[i]<<endl;
}
else
    cout<<0;

}
void display(struct matrix m){
int i,j;
 for(i=0;i<m.n;i++){
    for(j=0;j<m.n;j++){
        if(i==j){
            cout<<m.s[i];
        }
        else
            cout<<"0";
    }
    cout<<endl;
 }
}
int main()
{struct matrix m;
m.n=4;
set(&m,0,0,3);set(&m,1,1,5);set(&m,2,2,4);set(&m,3,3,2);
display(m);
get(m,2,2);
    return 0;
}
