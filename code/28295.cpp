#include <bits/stdc++.h>    
using namespace std;
char arr[4]={'N','E','S','W'};
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int idx=0;
    for(int i=0;i<10;i++){
        int a; cin>>a;
        if(a==1){
            idx=(idx+1)%4;
        }
        else if(a==2){
            idx=(idx+2)%4;
        }
        else if(a==3){
            idx=(idx+3)%4;
        }
    }

    cout<<arr[idx];

    return 0;
}