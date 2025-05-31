#include "testlib.h"
#include <iostream>
using namespace std;
int main(int argc,char*argv[]){
    registerGen(argc,argv,1);
    int n=100000;
    cout<<n<<"\n";
    
    int x;
    if(opt<int>(1)==0){
        x=0;
    }
    else x=1;
    for(int i=0;i<n;i++){
        cout<<x;
        if(i<n-1) cout<<" ";
    }
    cout<<"\n";

    return 0;
}