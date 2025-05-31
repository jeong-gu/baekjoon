#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
    string s; int k;
    cin>>s>>k;
    auto x=getp(s);
    int L=s.size();
    cout << ((ll)k-1)*(L-x[L-1])+L;

    return 0;
}