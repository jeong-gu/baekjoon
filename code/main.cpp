#include <bits/stdc++.h>
using namespace std;
int adj[1001][1001];
struct point
{
    int x;
    int y;
};

double eucliean_dist(const point& a, const point& b)
{
   double x = a.x - b.x;
   double y = a.y - b.y;  
   x = x < 0.0 ? -x : x;
   y = y < 0.0 ? -y : y;

   return sqrt(x*x + y*y);
}
void func(int stX,int stY,int enX,int enY){
    
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>adj[i][j];
        }
    }    
    int stX,stY; cin>>stX>>stY;
    int enX,enY; cin>>enX>>enY;
    void func(stX,stY,enX,enY);

    return 0;
}