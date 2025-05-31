#include <bits/stdc++.h>
using namespace std;
pair<int,int> arr[100001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;  //n, m: 1이상 100,000미만 
    cin>>n>>m;
    arr[0].second=0;
    for(int i=0;i<n;i++){
        cin>>arr[i+1].first;
        arr[i+1].second=arr[i].second+arr[i+1].first;
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        cout<<arr[b].second-arr[a-1].second<<"\n";
    }

    return 0;
}