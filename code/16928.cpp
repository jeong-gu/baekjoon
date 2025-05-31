#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> vec;
vector<int> e;
int d[101];
bool func(int t){
    bool swt=false;
    for(auto l:vec){
        if(t==l.first){
            swt=true;
            if(d[l.second]) continue;
            d[l.second]++;
            e.push_back(l.second);
            func(l.second);
        }
    }
    return swt;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;

    for(int i=0;i<n+m;i++){
        int a,b; cin>>a>>b;
        vec.push_back({a,b});
    }
    d[1]=1;
    e.push_back(1);
    int cnt=0;
    while(1){
        if(d[100]) break;   
        int size=e.size();
        for(int x=0;x<size;x++){
            for(int k=1;k<=6;k++){
                int nxt=e[x]+k;
                if(nxt>100||d[nxt]) continue;
                if(!func(nxt)){
                    e.push_back(nxt);
                }
                d[nxt]++;
            }
        }
        cnt++;
    }
    cout<<cnt;

    return 0;
}