#include <bits/stdc++.h>
using namespace std;
int n,m;
int box[10];
bool isused[10001];
int arr[10];
void func(int x,int min){
    if(x==m){
        for(int i=0;i<m;i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }
    int tmp=0;
    for(int i=min;i<n;i++){
        if(tmp!=box[i]){
            tmp=box[i];
            arr[x]=box[i];
            func(x+1,i+1);
        }
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>box[i];
    sort(box,box+n);
    func(0,0);
    return 0;
}