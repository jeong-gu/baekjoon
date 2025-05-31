#include <bits/stdc++.h>
using namespace std;
int n,m;
int maze[51][51];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    vector<pair<int,int>> house;
    vector<pair<int,int>> chicken;
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++){
        cin>>maze[i][j];
        if(maze[i][j]==1){
            house.push_back({i,j});
        }
        else if(maze[i][j]==2){
            chicken.push_back({i,j});
        }
    }
    vector<int> brute(chicken.size(),1);
    fill(brute.begin(),brute.begin()+chicken.size()-m,0);
    int mn=0x7f7f7f7f;
    do{
        int dist=0;
        for(auto h:house){
            int tmp=0x7f7f7f7f;
            for(int i=0;i<chicken.size();i++){
                if(brute[i]==0) continue;
                tmp=min(tmp,abs(h.first-chicken[i].first)+abs(h.second-chicken[i].second));
            }
            dist+=tmp;
        }
        mn=min(mn,dist);
    }while(next_permutation(brute.begin(),brute.end()));
    cout<<mn;
    return 0;
}

