#include <bits/stdc++.h>
using namespace std;
int arr[5];
vector<pair<int,int>> vec;
int main(){
    int num,dir,x;
    cin>>num;
    for(int i=0;i<6;i++){
        cin>>dir>>x;
        arr[dir]++;       
        vec.push_back({dir,x}); 
    }
    int entire=1;
    int part=1;
    for(int i=0;i<6;i++){
        if(arr[vec[i].first]==1){
            entire*=vec[i].second;
            continue;
        }
        int next=(i+1)%6;
        int nnext=(i+2)%6;
        if(vec[i].first==vec[nnext].first){
            part*=vec[next].second;
        }
    }
    cout<<num*(entire-part);
    return 0;
}