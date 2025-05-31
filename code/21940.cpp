#include <bits/stdc++.h>
using namespace std;
int INF=0x3f3f3f3f;
int n,m;
int d[201][201];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        fill(d[i],d[i]+n+1,INF);
    }
    while(m--){
        int a,b,c; cin>>a>>b>>c;
        d[a][b]=c;
    }
    for(int i=1;i<=n;i++){
        d[i][i]=0;
    }
    vector<int> frd;
    int num; cin>>num;
    while(num--){
        int input; cin>>input;
        frd.push_back(input);
    }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(d[i][j]>d[i][k]+d[k][j]){
                    d[i][j]=d[i][k]+d[k][j];
                }
            }
        }
    }
    int mn=INF;
    vector<int> vec;
    for(int i=1;i<=n;i++){
        int mx=0;
        for(auto f:frd){
            mx=max(mx,d[f][i]+d[i][f]);
        }
        if(mn>mx){
            mn=mx;
            vec.clear();
            vec.push_back(i);
        }
        else if(mn==mx){
            vec.push_back(i);
        }
    }
    for(auto v:vec){
        cout<<v<<" ";
    }
    return 0;
}