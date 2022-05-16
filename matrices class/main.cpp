#include <iostream>

using namespace std;
class Diagonal
{
private:
    int n;
    int *s;
public:
    Diagonal(){
        n=2;
        s=new int[2];
    }
    Diagonal(int n){
        this->n=n;
        s=new int[n];
    }
    ~Diagonal(){
    delete []s;
    }
    void set(int i,int j,int x);
    int get(int i,int j);
    void display();
    };
void Diagonal::set(int i,int j,int x){
if(i==j){
    s[i]=x;
}

}
int Diagonal::get(int i,int j){
if(i==j){
    cout<<s[i]<<endl;
}
else
    cout<<0;

}
void Diagonal::display(){
int i,j;
 for(i=0;i<n;i++){
    for(j=0;j<n;j++){
        if(i==j){
            cout<<s[i];
        }
        else
            cout<<"0";
    }
    cout<<endl;
 }
}

class Lowertri
{
private:
    int n;
    int *s;
public:
    Lowertri(){
        n=2;
        s=new int[2*(2+1)/2];
    }
    Lowertri(int n){
        this->n=n;
        s=new int[n*(n+1)/2];
    }
    ~Lowertri(){
    delete []s;
    }
    void set(int i,int j,int x);
    int get(int i,int j);
    void display();
    int getdimension(){return n;}
    };
void Lowertri::set(int i,int j,int x){
if(i>=j){
    s[i*(i-1)/2 +j-1]=x;
}

}
int Lowertri::get(int i,int j){
if(i>=j){
    cout<<s[i*(i-1)/2 +j-1]<<endl;
}
else
    cout<<0;

}
void Lowertri::display(){
int i,j;
 for(i=0;i<n;i++){
    for(j=0;j<n;j++){
        if(i>=j){
            cout<<s[i*(i-1)/2 +j-1];
        }
        else
            cout<<"0";
    }
    cout<<endl;
 }
}
class Uppertri
{
private:
    int n;
    int *s;
public:
    Uppertri(){
        n=2;
        s=new int[2*(2+1)/2];
    }
    Uppertri(int n){
        this->n=n;
        s=new int[n*(n+1)/2];
    }
    ~Uppertri(){
    delete []s;
    }
    void set(int i,int j,int x);
    int get(int i,int j);
    void display();
    int getdimension(){return n;}
    };
void Uppertri::set(int i,int j,int x){
if(i<=j){
    s[((i-1)*n-((i-2)*(i-1))/2)+(j-i)]=x;
}

}
int Uppertri::get(int i,int j){
if(i<=j){
    cout<<s[((i-1)*n-((i-2)*(i-1))/2)+(j-i)]<<endl;
}
else
    cout<<0;

}
void Uppertri::display(){
int i,j;
 for(i=0;i<n;i++){
    for(j=0;j<n;j++){
        if(i<=j){
            cout<<s[(i-1)*n-((i-2)*(i-1))/2+(j-i)];
        }
        else
            cout<<"0";
    }
    cout<<endl;
 }
}

class Sym

{

public:

    int n;

    int *s;



    Sym(){

        n=2;

        s=new int[2*(2+1)/2];

    }

    Sym(int n){

        this->n=n;

        s=new int[n*(n+1)/2];

    }

    ~Sym(){

    delete []s;

    }

    void set(int i,int j,int x);

    int get(int i,int j);

    void display();

    int getdimension(){return n;}

    };

void Sym::set(int i,int j,int x){

if(i<=j){

    s[j*(j-1)/2 +i-1]=x; //changes as formula you were using was storing is wrong way

}

else if(i>j){

    s[i*(i-1)/2 +j-1]=x;

}



}

int Sym::get(int i,int j){

if(i<=j){

    cout<<s[j*(j-1)/2 +i-1]<<endl; //changes

}

else if(i>j){

    cout<<s[i*(i-1)/2 +j-1];

}





}

void Sym::display(){

int i,j;

for(i=1;i<=n;i++){ //changes

    for(j=1;j<=n;j++){ //changes

        if(i<=j){

            cout<<s[j*(j-1)/2 +i-1];

        }

        else if(i>j)

            cout<<s[i*(i-1)/2 +j-1];

    }

    cout<<endl;

}

}

int main()
{Diagonal d(4);

d.set(0,0,5);
d.set(1,1,4);
d.set(2,2,3);
d.set(3,3,1);
d.display();
int n;
cout<<"dimension of matrix: "<<endl;
cin>>n;
Sym s(n);
int x;
cout<<"Elements of matrix: "<<endl;
for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
        cin>>x;
        s.set(i,j,x);
    }
}

s.display();


    return 0;
}
