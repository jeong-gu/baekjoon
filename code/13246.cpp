#include <bits/stdc++.h>
using namespace std;
long long int n,b;
class mat{
public:
    long long int data[6][6];
    mat(){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                data[i][j]=0;
            }
        }    
    }
};
mat iMat;
mat input;
mat matMult(mat m1,mat m2){
    mat result;
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                result.data[k][i]+=(m1.data[k][j]*m2.data[j][i])%1000;
                result.data[k][i]%=1000;
            }
        }
    }
    return result;
}
mat matAdd(mat m1,mat m2){
    mat result;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            result.data[i][j]=(m1.data[i][j]+m2.data[i][j])%1000;
        }
    }
    return result;
}
mat getAn(long long int n){
    mat result=input;
    if(n>1){
        mat half;
        half=getAn(n/2);
        result=matMult(half,half);
        if(n%2==1){
            result=matMult(result,input);
        }
    }
    return result;
}
mat func(long long int b){
    if(b==1){
        return input;
    }
    if(b%2==0){
        return matMult(func(b/2),matAdd(iMat,getAn(b/2)));
    }
    else{
        mat sTmp=func(b-1);
        mat An=getAn(b);
        return matAdd(sTmp,An);
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>b;
    for(int i=0;i<n;i++){
        iMat.data[i][i]=1;    
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>input.data[i][j];
        }
    }    
    mat answer=func(b);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<answer.data[i][j]%1000<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
