#include <bits/stdc++.h>    
using namespace std;
typedef long long ll;

ll n; ll d;
ll negMax,posMax;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>d;
    for(ll i=0;i<n;i++){
        ll p; cin>>p;
        if(p>0){
            posMax=max(posMax,p);
        }   
        else{
            negMax=max(negMax,-p);
        }   
    }
    ll a=posMax; ll b=negMax;
    if(a>b){
        swap(a,b);
    }
    if(!a){
        cout<<2*b+d;
        return 0;
    }
    ll res[3];
    res[0]=ll(2*(a+b+d));
    res[1]=ll(2*a+2*(a+b)+d);
    if(2*(a+b)<d){
        res[2]=ll(2*(a+b)+d);
    }
    else{
        res[2]=ll(4*(a+b));
    }
    res[2]=ll(2*(a+b)+max(d,2*(a+b)));

    ll rres=*min_element(res,res+3);
    cout<<rres;
    return 0;
}