#include <bits/stdc++.h>
using namespace std;
int INF=0x3f3f3f3f;
int arr[501][501];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m,b; cin>>n>>m>>b;
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
        cin>>arr[i][j];

    int time=INF;
    int height=0;
    for(int x=0;x<=256;x++){
        int timeTmp=0;
        int bTmp=b;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]>x){
                    timeTmp+=2*(arr[i][j]-x);
                    bTmp+=arr[i][j]-x;
                }
                else if(arr[i][j]<x){
                    timeTmp+=x-arr[i][j];
                    bTmp-=x-arr[i][j];
                }
                else{
                    continue;
                }
            }
        }
        if(bTmp<0) continue;
        if(time>=timeTmp){
            time=timeTmp;
            if(height<x){
                height=x;
            }
        }
    }
    cout<<time<<" "<<height;

    return 0;
}