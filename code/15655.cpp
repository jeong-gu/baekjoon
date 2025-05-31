#include <bits/stdc++.h>
using namespace std;
int n,m;
int arr[10];
bool isused[10010];
vector<int> vec;
void func(int x,int min){
    if(x==m){
        for(int i=0;i<m;i++)
            cout<<arr[i]<<" ";
        cout<<"\n";
        return;
    }
    for(auto i :vec){
        if(!isused[i]&&i>min){
            arr[x]=i;
            isused[i]=true;
            func(x+1,i);
            isused[i]=false;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;  
    for(int i=0;i<n;i++){
        int tmp; cin>>tmp;
        vec.push_back(tmp);
    }
    sort(vec.begin(),vec.end());
    func(0,0);
    return 0;
}