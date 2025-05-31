#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        string str; cin>>str;
        vector<int> tpos;
        for(int i=0;i<str.size();i++){
            if(str[i]=='T'){
                tpos.push_back(i);
            }
        }
        int sz=tpos.size();
        if(sz%2==1){
            cout<<"-1\n";
            continue;
        }
        stack<int> stk;
        ll ans=0;
        for(int i=0;i<sz;i++){
            if(stk.empty()){
                stk.push(i);
                continue;
            }    
            int cur=stk.top();
            if((tpos[i]-tpos[cur])%2==1){
                stk.pop();
                ans+=(tpos[i]-tpos[cur]);
            }
            else{
                stk.push(i);
            }
        }
        if(!stk.empty()){
            cout<<"-1\n";
            continue;
        }
        else{
            cout<<ans<<"\n";
        }
    }

    return 0;
}