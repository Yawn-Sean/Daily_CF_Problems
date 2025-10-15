#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;cin>>n;
    vector<int>a(n);
    map<int,int>mp;
    for(auto&i:a){
        cin>>i;
        mp[i]++;
    }
    priority_queue<pair<int,int>>pq;
    for(auto[x,y]:mp){
        pq.push({y,x});
    }
    vector<tuple<int,int,int>>res;
    while(pq.size()>=3){
        auto [a1,b1]=pq.top();pq.pop();
        auto [a2,b2]=pq.top();pq.pop();
        auto [a3,b3]=pq.top();pq.pop();
        vector<int>t{b1,b2,b3};
        sort(t.begin(),t.end(),greater<>());
        res.push_back(make_tuple(t[0],t[1],t[2]));
        if((a1-1))pq.push({a1-1,b1});
        if((a2-1))pq.push({a2-1,b2});
        if((a3-1))pq.push({a3-1,b3});
    }
    cout<<res.size()<<'\n';
    for(auto&[a,b,c]:res)cout<<a<<' '<<b<<' '<<c<<'\n';
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
}