#include <bits/stdc++.h>    
using namespace std;
priority_queue<int,vector<int>,greater<int>> Minpq;
priority_queue<int, vector<int>,less<int>> Maxpq;
map<int,int> mp;
void insert(int x){
    Minpq.push(x);
    Maxpq.push(x);        
    mp[x]++;
}
void eraseMin(){
    if(Minpq.empty()) return;
    mp[Minpq.top()]--;
    Minpq.pop();
}
void eraseMax(){
    if(Maxpq.empty()) return;
    mp[Maxpq.top()]--;
    Maxpq.pop();
}
void ft(){
    while(!Minpq.empty()&&mp[Minpq.top()]==0){
        Minpq.pop();
    }
    while(!Maxpq.empty()&&mp[Maxpq.top()]==0){
        Maxpq.pop();
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n; cin>>n;
        while(!Minpq.empty()) Minpq.pop();
        while(!Maxpq.empty()) Maxpq.pop();
        mp.clear();

        while(n--){
            char c; int x;
            cin>>c>>x;
            if(c=='I'){
                insert(x);
            }
            else if(c=='D'){
                if(Minpq.empty()||Maxpq.empty()) continue;
                if(x==1){
                    eraseMax();
                }
                else if(x==-1){
                    eraseMin();
                }
                ft();
            }
        }
        ft();
        if(Minpq.empty()||Maxpq.empty()) cout<<"EMPTY\n";
        else cout<<Maxpq.top()<<" "<<Minpq.top()<<"\n";
    }



    return 0;
}