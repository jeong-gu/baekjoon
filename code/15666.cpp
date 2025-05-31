#include <bits/stdc++.h>
using namespace std;
int n,m;
int box[10];
int arr[10];
int isused[10001];
void func(int x,int min){
    if(x==m){
        for(int i=0;i<m;i++)
            cout<<arr[i]<<" ";
        cout<<"\n";
        return;
    }
    int tmp=0;
    for(int i=min;i<n;i++){
        if(isused[i]!=m&&tmp!=box[i]){
            arr[x]=box[i];
            isused[i]++;
            tmp=box[i];
            func(x+1,i);
            isused[i]--;
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