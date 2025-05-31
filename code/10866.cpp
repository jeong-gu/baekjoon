#include <bits/stdc++.h>
using namespace std;
deque<int> deq;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    while(n--){
        string order;
        cin>>order;
        if(order=="push_front"){
            int x;
            cin>>x;
            deq.push_front(x);
        }
        if(order=="push_back"){
            int x;
            cin>>x;
            deq.push_back(x);
        }
        else if(order=="pop_front"){
            if(deq.empty()){
                cout<<"-1\n";
                continue;
            }
            cout<<deq.front()<<"\n";
            deq.pop_front();
        }
        else if(order=="pop_back"){
            if(deq.empty()){
                cout<<"-1\n";
                continue;
            }
            cout<<deq.back()<<"\n";
            deq.pop_back();
        }
        else if(order=="size"){
            cout<<deq.size()<<"\n";
        }
        else if(order=="empty"){
            cout<<deq.empty()<<"\n";
        }
        else if(order=="front"){
            if(deq.empty()){
                cout<<"-1\n";
                continue;
            }
            cout<<deq.front()<<"\n";
        }
        else if(order=="back"){
            if(deq.empty()){
                cout<<"-1\n";
                continue;
            }
            cout<<deq.back()<<"\n";
        }
    }

    return 0;
}
