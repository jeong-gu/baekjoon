#include <bits/stdc++.h>
using namespace std;
int a[31];
int main(){
    int t; cin>>t;
    
    while(t--){
        int n; cin>>n;
        vector<pair<string,int>> vec;
        for(int i=0;i<n;i++){
            string tmp; cin>>tmp;
            cin>>tmp;
            bool flag=false;
            for(auto &k:vec){
                if(tmp==k.first){
                    k.second++;
                    flag=true;
                }
            }
            if(!flag){
                vec.push_back({tmp,1});
            }
        }
        int result=1;
        for(auto k:vec){
            result*=(k.second+1);
        }
        cout<<result-1<<"\n";
    }



    return 0;
}