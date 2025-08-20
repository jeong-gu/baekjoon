#include <bits/stdc++.h>
using namespace std;
vector<int> vec;

int func(int a,int b,int x,int i){
    return b*x+(a-x)*(i+1);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,a,b; cin>>n>>a>>b;
    int ans=0;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        vec.push_back(x);
    }
    sort(vec.begin(),vec.end());
    for(int i=0;i<n;i++){
        int x=0;
        int res=func(a,b,x,i);
        if(res<=vec[i]){
            if(b-(i+1)==0){
                if(a*(i+1)<=vec[i]){
                    x=0;
                    int swt=0;
                    for(int j=0;j<i+1;j++){
                        if(func(a,b,x,j)<=vec[j]){
                            swt++;
                        }
                    }
                    ans=max(ans,swt);
                }
                continue;
            }
            x=(vec[i]-a*(i+1))/(b-(i+1));
            int swt=0;
            for(int j=0;j<i+1;j++){
                if(func(a,b,x,j)<=vec[j]){
                    swt++;
                }
            }
            ans=max(ans,swt);
            continue;
        }
        x=a-1;
        res=func(a,b,x,i);
        if(res<=vec[i]){
            if(b-(i+1)==0){
                if(a*(i+1)<=vec[i]){
                    x=0;
                    int swt=0;
                    for(int j=0;j<i+1;j++){
                        if(func(a,b,x,j)<=vec[j]){
                            swt++;
                        }
                    }
                    ans=max(ans,swt);
                }
                continue;
            }
            x=(vec[i]-a*(i+1))/(b-(i+1));
            int swt=0;
            for(int j=0;j<i+1;j++){
                if(func(a,b,x,j)<=vec[j]){
                    swt++;
                }
            }
            ans=max(ans,swt);
            continue;
        }
    }
    cout<<ans;

}