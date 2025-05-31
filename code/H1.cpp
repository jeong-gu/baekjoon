#include <bits/stdc++.h>
using namespace std;
int arr[14];
int input[9];
int tmp[9];
int cnt=0;
void func(){
    for(int i=1;i<=13;i++){ // i:3
        for(int j=1;j<14;j++) arr[j]=0;   
        arr[i]=1;
        if(tmp[8]-i<0||arr[tmp[8]-i]==1) {arr[i]=0; continue;} // tmp[8]-i: 11
        arr[tmp[8]-i]=1;

        
        for(int j=1;j<=13;j++){     //j:5
            if(arr[j]==1) {continue;}
            arr[j]=1;
            if(tmp[4]-j<0||arr[tmp[4]-j]==1) {arr[j]=0; continue;} //tmp[4]-j: 4
            arr[tmp[4]-j]=1;
            
            for(int k=1;k<=13;k++){ // k:12
                if(arr[k]==1) continue;
                arr[k]=1;
                int l;
                for(l=1;l<=13;l++){ // l: 7
                    if(arr[l]==1) {arr[k]=0; continue;}
                    arr[l]=1;

                    if(tmp[7]-(k+l)<0||arr[tmp[7]-(k+l)]==1) {arr[l]=0; continue;}//tmp[7]-(k+l):8
                    arr[tmp[7]-(k+l)]=1;
                }
                int x;
                for(x=1;x<=13;x++){ // x: 6
                    if(arr[x]==1) { arr[k]=0; continue;}
                    arr[x]=1;

                    if(tmp[3]-(k+x)<0||arr[tmp[3]-(k+x)]==1) {arr[x]=0; continue;}//tmp[3]-(k+x):9
                    arr[tmp[3]-(k+x)]=1;
                }
                int t;
                for(t=1;t<=13;t++){ // t:10
                    if(arr[t]==1)continue;
                    arr[t]=1;

                    if(tmp[6]-t<0||arr[tmp[6]-(t+x+j)]==1) {arr[t]=0; continue; }//tmp[6]-(t+x+j): 13
                    arr[tmp[6]-t]=1;

                    if(tmp[2]-t<0||arr[tmp[2]-(t+l+i)]==1) {//tmp[2]-(t+l+i): 2
                        arr[t]=0;
                        arr[tmp[6]-t]=0;
                        continue;
                    } 
                    arr[tmp[2]-t]=1;

                    int cmp1=tmp[1]-(tmp[6]-(t+x+j))-(tmp[7]-(k+l))-(tmp[8]-i);
                    int cmp2=tmp[5]-(tmp[4]-j)-(tmp[3]-(k+x))-(tmp[2]-(t+l+i));
                    if(cmp1==cmp2&&arr[cmp1]==1){
                        cnt++;
                    }
                    arr[t]=0;
                    arr[tmp[6]-t]=0;
                    arr[tmp[2]-t]=0;
                }
                arr[k]=0;
                arr[l]=0;
                arr[x]=0;
                arr[t]=0;
                arr[tmp[6]-t]=0;
                arr[tmp[7]-(k+l)]=0;
                arr[tmp[3]-(k+x)]=0;
            }
            arr[j]=0;
            arr[tmp[4]-j]=1;
        }
        arr[i]=0;
        arr[tmp[8]-i]=0;
    }
}
int main(void){
    for(int i=1;i<9;i++) cin>>input[i];
    int a,b,c,d,e,f,g,h,i,j,k,l,m;

    
    for(int i=1;i<=9;i++){
        tmp[i]=input[i];
    }
    // for(int i=1;i<14;i++)
    //     arr[i]=i;

    // for(int ii=1;ii<=13;ii++){
    //     l=H-ii;
    //     m=ii;
    //     if(A<l+6)   continue;
    //     for(jj=1<14;)
    // }
    func();
    cout<<cnt;


    return 0;
}