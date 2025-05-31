#include <bits/stdc++.h>
using namespace std;
int d[50001];
vector<int> vec;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    for(int i=1;i*i<50001;i++){
        d[i*i]=1;
        vec.push_back(i*i);
    }
    vector<int> tmp;
    for(auto x:vec){
        for(int i=1;x+i*i<50001;i++){
            if(d[x+i*i]) continue;
            d[x+i*i]=d[x]+1;
            tmp.push_back(x+i*i);
        }    
    }
    for(auto x:tmp){
        vec.push_back(x);
    }

    for(auto x:vec){
        for(int i=1;x+i*i<50001;i++){
            if(d[x+i*i]) continue;
            d[x+i*i]=d[x]+1;
        }    
    }
    if(d[n]) {
        cout<< d[n];
        return 0;
    }
    else{
        cout<<4;
    }
    return 0;
}