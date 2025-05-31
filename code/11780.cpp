#include <bits/stdc++.h>
using namespace std;
int INF=0x3f3f3f3f;
int n,m;
int arr[101][101];
int nxt[101][101];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        fill(arr[i],arr[i]+1+n,INF);
    }
    while(m--){
        int a,b,c; cin>>a>>b>>c;
        arr[a][b]=min(arr[a][b],c);
        nxt[a][b]=b;
    }

    for(int i=1;i<=n;i++){
        arr[i][i]=0;
    }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(arr[i][j]>arr[i][k]+arr[k][j]){
                    arr[i][j]=arr[i][k]+arr[k][j];
                    nxt[i][j]=nxt[i][k];
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(arr[i][j]==INF){
                cout<<"0 ";
            }
            else{
                cout<<arr[i][j]<<" ";
            }
        }
        cout<<"\n";
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int tmp=nxt[i][j];
            queue<int> q;
            q.push(i);
            while(tmp!=j&&tmp!=0){
                q.push(tmp);
                tmp=nxt[tmp][j];
            }
            if(tmp!=0){
                q.push(tmp);
                cout<<q.size()<<" ";
                while(!q.empty()){
                    int x=q.front();
                    q.pop();
                    cout<<x<<" ";
                }
                cout<<"\n";
            }
            else{
                cout<<"0\n";
            }
        }
    }
}

