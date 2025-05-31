#include "testlib.h"
#include <iostream>
using namespace std;
int main(int argc,char*argv[]){
    registerGen(argc,argv,1);

    int n=opt<int>(1);
    cout<<n<<"\n";
    for(int i=0;i<n;i++){
        cout<<rnd.next(0,1);
        if(i<n-1) cout<<" ";
    }
    cout<<"\n";

    return 0;
}