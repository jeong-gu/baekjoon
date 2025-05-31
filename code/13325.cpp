#include <bits/stdc++.h>    
using namespace std;
int h; 
int d[(1<<20+1)];
int dp[(1<<20+1)];
int func(int x);
void func2(int b,int s);

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>h;
    for(int i=1;i<=(1<<h+1)-2;i++){
        cin>>d[i];
    }
    func(1);
    int ans=0;
    for(int i=1;i<=(1<<h+1)-2;i++){
        ans+=d[i];
    }
    cout<<ans;

    return 0;
}
void func2(int b,int s){
    d[s-1]=func(b)+d[b-1]-func(s);
}
int func(int x){
    if(dp[x]) {
        return dp[x];
    }

    int lchild=2*x, rchild=2*x+1;
    if(rchild>(1<<h+1)) return 0;
    int fl=func(lchild)+d[lchild-1],fr=func(rchild)+d[rchild-1];
    if(fl<fr){
        func2(rchild,lchild);
    }
    else{
        func2(lchild,rchild);
    }
    dp[x]=max(fl,fr);
    return dp[x];
    
}