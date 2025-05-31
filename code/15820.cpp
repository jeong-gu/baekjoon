#include <bits/stdc++.h>
using namespace std;
int main(){
    int sample,system,tmp1,tmp2;
    cin>>sample>>system;
    for(int i=0;i<sample;i++){
        cin>>tmp1>>tmp2;
        if(tmp1!=tmp2){
            cout<<"Wrong Answer";
            return 0;
        }
    }
    for(int i=0;i<system;i++){
        cin>>tmp1>>tmp2;
        if(tmp1!=tmp2){
            cout<<"Why Wrong!!!";
            return 0;
        }
    }
    cout<<"Accepted";
    return 0;
}