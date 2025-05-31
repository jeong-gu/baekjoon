#include <bits/stdc++.h>
using namespace std;
int n,m;
int arr[10];
int isused[10010];
vector<int> vec;
void func(int x){
    if(x==m){
        for(int i=0;i<m;i++)
            cout<<arr[i]<<" ";
        cout<<"\n";
        return;
    }
    for(auto i :vec){
        if(isused[i]!=m){
            arr[x]=i;
            isused[i]++;
            func(x+1);
            isused[i]--;
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
    func(0);
    return 0;
}