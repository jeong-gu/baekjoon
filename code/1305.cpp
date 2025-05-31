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
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int l; string str;
    cin>>l>>str;
    auto res=getp(str);
    cout<<l-res[l-1];

    return 0;
}