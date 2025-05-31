#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
 
int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(1, 100000, "N");
    inf.readEoln();

    for(int i=0;i<n;i++){
        int x=inf.readInt(0,1,"xx");
        if(i<n-1) inf.readSpace();
    }

    
    inf.readEoln();

    inf.readEof(); 

    quitf(_ok, "Valid input: N = %d", n);
}