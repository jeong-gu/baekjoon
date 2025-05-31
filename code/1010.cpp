#include <bits/stdc++.h>
using namespace std;
string dp[101][101];

string add(string n1,string n2){
    string res="";
    int len=max(n1.size(),n2.size());   
    int sum=0;
    for(int i=0;i<len||sum;i++){
        if(n1.size()>i) sum+=n1[i]-'0';
        if(n2.size()>i) sum+=n2[i]-'0';
        res+=(sum%10)+'0';
        sum/=10;
    }
    return res;
}
string comb(int n,int r){
    if(r==0||n==r) return dp[n][r]="1";
    if(dp[n][r]!="") return dp[n][r];
    return dp[n][r]=add(comb(n-1,r-1),comb(n-1,r));
}

int main(){
    int a,b;
    cin>>a>>b;
    comb(a,b);
    reverse(dp[a][b].begin(),dp[a][b].end());
    cout<<dp[a][b];
    return 0;
}