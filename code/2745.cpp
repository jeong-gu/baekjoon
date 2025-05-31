#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    string n; int b;
    cin>>n>>b;
    int result=0;
    for(int i=0;i<n.length();i++){
        result*=b;
        if(n[i]>='A'&&n[i]<='Z'){
            n[i]=n[i]-'A'+10;
        }
        else{
            n[i]=n[i]-'0';
        }
        result+=n[i];
    }
    cout<<result;


    return 0;
}