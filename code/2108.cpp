#include <bits/stdc++.h>
using namespace std;
vector<int> vec;
int arr[2][4001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int num;    //1<=num<=500,000 | Odd 
    cin>>num;
    while(num--){
        int input;
        cin>>input;
        if(input>=0) arr[1][input]++; //0포함 양수
        else arr[0][-input]++;
        vec.push_back(input);
    }
    sort(vec.begin(),vec.end());
    int rst1=0,rst2,rst3,rst4;
    int order=0;
    int max=-1,maxi,maxi2=4001;
    for(auto i:vec){
        order++;
        rst1+=i;
        if(order==(vec.size()/2+1)){rst2=i;}
        if(i>=0){
            if(max<arr[1][i]){
                maxi=i;
                max=arr[1][i];
                maxi2=4001;
            }
            else if(maxi!=i&&max==arr[1][i]){
                if(maxi2==4001){
                    maxi2=i;
                }
                else continue;
            }
        }
        else{
            if(max<arr[0][-i]){
                maxi=i;
                max=arr[0][-i];
                maxi2=4001;
            }
            else if(maxi!=i&&max==arr[0][-i]){
                if(maxi2==4001){
                    maxi2=i;
                }
                else continue;
            }
        }
    }
    rst1=round(double(rst1)/vec.size());
    rst3=(maxi2==4001)?maxi:maxi2;
    rst4=vec.back()-vec.front();
    cout<<rst1<<"\n";
    cout<<rst2<<"\n";
    cout<<rst3<<"\n";
    cout<<rst4<<"\n";
    int a=10;
    char(a);
    return 0;
}