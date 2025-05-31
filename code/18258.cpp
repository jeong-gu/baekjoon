#include <bits/stdc++.h>
using namespace std;
#define max 2000000
int node[max];
class que{
private:
    int head;
    int rear;
public:
    que():head(0),rear(0){}
    bool isEmpty(){
        return head==rear;
    }
    void push(int x){
        node[rear++]=x;
    }
    int pop(){
        if(this->isEmpty()){
            return -1;
        }
        return node[head++];
    }
    int size(){
        return rear-head;
    }
    int front(){
        if(isEmpty()){
            return -1;
        }
        return node[head];
    }
    int back(){
        if(this->isEmpty()){
            return -1;
        }
        return node[rear-1];
    }

};

int main(){
    int n;
    que q;
    cin>>n;
    while(n--){
        string order;
        cin>>order;
        if(order=="push"){
            int x;
            cin>>x;
            q.push(x);
        }
        else if(order=="pop"){
            cout<<q.pop()<<"\n";
        }
        else if(order=="size"){
            cout<<q.size()<<"\n";
        }
        else if(order=="empty"){
            cout<<q.isEmpty()<<"\n";
        }
        else if(order=="front"){
            cout<<q.front()<<"\n";
        }
        else if(order=="back"){
            cout<<q.back()<<"\n";
        }
    }
    return 0;
}