#include <bits/stdc++.h>
using namespace std;
int arr[301][301];
int dx[8]={1,1,2,2,-1,-1,-2,-2};
int dy[8]={2,-2,1,-1,2,-2,1,-1};
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        for(int i=0;i<301;i++){
            fill(arr[i],arr[i]+301,-1);
        }
        int x;
        cin>>x;
        int curx,cury,goalx,goaly;
        cin>>curx>>cury>>goalx>>goaly;
        queue<pair<int,int>> q;
        q.push({curx,cury});
        arr[curx][cury]=0;
        while(arr[goalx][goaly]==-1){
            pair<int,int> pair=q.front();
            q.pop();
            for(int i=0;i<8;i++){
                int nxtx=pair.first+dx[i];
                int nxty=pair.second+dy[i];
                if(nxtx<0||nxtx>=x||nxty<0||nxty>=x) continue;
                if(arr[nxtx][nxty]!=-1) continue;
                q.push({nxtx,nxty});
                arr[nxtx][nxty]=arr[pair.first][pair.second]+1;
            }
        }
        cout<<arr[goalx][goaly]<<"\n";
    }
    return 0;
}