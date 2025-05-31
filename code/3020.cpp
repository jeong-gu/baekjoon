#include <bits/stdc++.h>
using namespace std;
int d[500001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,h; cin>>n>>h;
    bool swt=0;
    while(n--){
        int x; cin>>x;
        if(swt==0){ //석순
            d[1]++;
            d[x+1]--;
        }
        else{   //종유석
            d[h-x+1]++;
        }
        swt=!swt;
    }
    int now=0;
    for(int i=1;i<=h;i++){
        now+=d[i];
        d[i]=now;
    }
    int mn=*min_element(d+1,d+h);
    int cnt=0;
    for(int i=1;i<=h;i++){
        if(d[i]==mn){
            cnt++;
        }
    }
    cout<<mn<<" "<<cnt;

    return 0;
}