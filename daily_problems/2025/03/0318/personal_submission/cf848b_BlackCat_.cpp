#include <iostream>
#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<queue>
#include<vector>
#include<utility>
#include<algorithm>
#include<map>
#include<unordered_map>
using namespace std;
#define endl '\n'
struct node{
    int x,y,t;
    int num;
};
bool cmp(const node &a1,const node &a2){
    if(a1.x!=a2.x)
    return a1.x<a2.x;
    else
    return a1.t<a2.t;
}
bool cmp1(const node &a1,const node &a2){
    if(a1.y!=a2.y)
    return a1.y<a2.y;
else
    return a1.t<a2.t;
}
bool cmp2(const node &a1,const node &a2){
    return a1.num<a2.num;
}
void slove(){
    int n,w,h;
    cin>>n>>w>>h;
    node a;
    unordered_map<int,vector<node>> mp2;
    vector<node> x1;
    for(int i=1;i<=n;i++){
        int b;
        cin>>b;
        if(b==1){
            cin>>a.x>>a.t;
            a.y=h;
            a.num=i;
            x1.push_back(a);
        }
        else{
            cin>>a.y>>a.t;
            a.x=w;
            a.num=i;
            mp2[a.y-a.t].push_back(a);
        }
    } 
    sort(x1.begin(),x1.end(),cmp);
    for(auto &y:mp2){
        sort(y.second.begin(),y.second.end(),cmp1);
    }
    for(auto &x:x1){
        int m=x.x-x.t;
        auto it = mp2.find(m);
        if (it != mp2.end()) {
            auto &vec = it->second;
            for (auto &y : vec) {
                swap(x.num, y.num);
            }
        }
    }
    for(auto &y:mp2){
        for(auto &yy:y.second){
            x1.emplace_back(move(yy));
        }
    }
    sort(x1.begin(),x1.end(),cmp2);
    for(const auto &x:x1){
        cout<<x.x<<" "<<x.y<<endl;
    }
}
int main() {
    std::cin.tie(0);
    std::cout.tie(0);
    std::ios::sync_with_stdio(false);
    int t=1;
    while(t--){
        slove();
    }
    return 0;
}
