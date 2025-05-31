#include <bits/stdc++.h>
using namespace std;
int d[1000001];
int vec[1000001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    d[1]=0;
    vec[1]=0;
    for(int i=2;i<=n;i++){
        d[i]=d[i-1]+1;
        vec[i]=i-1;    
        if(i%3==0){
            if(d[i]>d[i/3]+1){
                d[i]=d[i/3]+1;
                vec[i]=i/3;
            }
        }
        if(i%2==0){
            if(d[i]>d[i/2]+1){
                d[i]=d[i/2]+1;
                vec[i]=i/2;
            }
        }
    }
    cout<<d[n]<<"\n"; 
    cout<<n<<" ";
    while(vec[n]!=0){
        cout<<vec[n]<<" ";
        n=vec[n];
    }
    return 0;
}