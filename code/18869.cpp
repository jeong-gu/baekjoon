#include <bits/stdc++.h>
using namespace std;
int m,n;
int universe[101][10001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>m>>n;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>universe[i][j];
        }
        //좌표압축
        vector<int> tmp;
        for(int k=0;k<n;k++){
            tmp.push_back(universe[i][k]);
        }
        sort(tmp.begin(),tmp.end());
        tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());

        for(int j=0;j<n;j++){
            int idx=lower_bound(tmp.begin(),tmp.end(),universe[i][j])-tmp.begin();
            universe[i][j]=idx;
        }
    }
    int cnt=0;
    for(int i=0;i<m;i++){
        for(int j=i+1;j<m;j++){
            bool flag=true;
            for(int k=0;k<n;k++){
                if(universe[i][k]!=universe[j][k]){
                    flag=false;
                }
            }
            if(flag){
                cnt++;
            }
        }
    }
    cout<<cnt;
    return 0;
}