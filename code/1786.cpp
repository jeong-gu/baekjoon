#include <bits/stdc++.h>
using namespace std;
vector<int> getp(string p){
    int sz=p.size(); int j=0;
    vector<int> pi(sz,0);
    for(int i=1;i<sz;i++){
        while(j>0&&p[i]!=p[j]){
            j=pi[j-1];
        }
        if(p[i]==p[j]){
            pi[i]=++j;
        }
    }
    return pi;

}
vector<int> kmp(string s,string p){
    vector<int> ret;
    auto pi=getp(p);
    int n=s.size(); int m=p.size(); int j=0;
    for(int i=0;i<n;i++){
        while(j>0&&s[i]!=p[j]){
            j=pi[j-1];
        }
        if(s[i]==p[j]){
            if(j==m-1){
                ret.push_back(i-m+1);
                j=pi[j];
            }
            else{
                j++;
            }
        }
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    string s,p;
    getline(cin,s);
    getline(cin,p);
    auto ans=kmp(s,p);
    cout<<ans.size()<<"\n";
    for(auto x:ans) 
        cout<<x+1<<" ";


    return 0;
}