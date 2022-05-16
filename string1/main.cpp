#include <iostream>

using namespace std;
void perm1(char s[],int k){
   static int h[10]={0};
   static char res[10];
   int i;
    if(s[k]=='\0'){
            res[k]='\0';
    cout<<res<<endl;
}
else{

    for(i=0;s[i]!='\0';i++){
            if(h[i]==0){
            res[k]=s[i];
            h[i]=1;
            perm1(s,k+1);
            h[i]=0;
            }
    }
    }
}
int main()
{char s[4]="abc";
perm1(s,0);

}
