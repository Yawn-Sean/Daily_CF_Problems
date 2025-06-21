#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n;cin>>n;
    vector<pair<int,int>>p(n);
    for(auto&[x,y]:p)cin>>x>>y;
    vector<pair<int,pair<int,int>>>t;
    for(int i=1;i<n;i++){
        t.push_back({i,p[i]});
    }
    vector<int>res{0};
    sort(t.begin(),t.end(),[&](pair<int,pair<int,int>>a,pair<int,pair<int,int>>b){
        auto&[_,t1]=a;auto&[_2,t2]=b;
        auto&[x1,y1]=t1;auto&[x2,y2]=t2;
        x1-=p[0].first,y1-=p[0].second;
        x2-=p[0].first,y2-=p[0].second;
        return x1*x1+y1*y1<x2*x2+y2*y2;
    });
    res.push_back(t[0].first);
    int x1=p[res[0]].first,y1=p[res[0]].second;
    int x2=p[res[1]].first,y2=p[res[1]].second;
    int subx=x2-x1,suby=y2-y1;
    for(int i=1;i<(int)t.size();i++){
        auto&[id,_]=t[i];
        auto&[x,y]=_;
        int sx=x-x1,sy=y-y1;
        if(sx*suby==sy*subx)continue;
        res.push_back(id);break;
    }
    for(auto i:res)cout<<i+1<<' ';
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
}
