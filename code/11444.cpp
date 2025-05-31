#include <bits/stdc++.h>
using namespace std;

class mat{
public:
    long long int data[2][2];
    mat(){
        data[0][0]=1; data[0][1]=1; data[1][0]=1; data[1][1]=0;
    }
};

mat matMult(mat m1,mat m2){
    mat result;
    result.data[0][0]=(m1.data[0][0]*m2.data[0][0]+m1.data[0][1]*m2.data[1][0])%1000000007;
    result.data[0][1]=(m1.data[0][0]*m2.data[0][1]+m1.data[0][1]*m2.data[1][1])%1000000007;
    result.data[1][0]=(m1.data[1][0]*m2.data[0][0]+m1.data[1][1]*m2.data[1][0])%1000000007;
    result.data[1][1]=(m1.data[1][0]*m2.data[0][1]+m1.data[1][1]*m2.data[1][1])%1000000007;
    return result;
}
mat func(mat mt, long long int n){
    if(n>1){
        mat half;
        half=func(mt,n/2);
        mat result;
        result=matMult(half,half);
        if(n%2==1){
            mat one;
            result=matMult(result,one);
        }
        return result;
    }
    return mt;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    //1,000,000,007
    long long int n; cin>>n;
    mat answer;
    answer=func(answer, n);
    cout<<answer.data[0][1];
    return 0;   
}

