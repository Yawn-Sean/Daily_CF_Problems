#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;cin>>n;
    vector<pair<int,int>>p(n-1);
    vector<tuple<int,int,int>>res;
    for(auto&[x,y]:p){
        cin>>x>>y;
        x--,y--;
    }
    for(int k=n;k>0&&p.size();k--){
        vector<int>st(k,1);
        for(int i=0;i<p.size();i++){
            st[p[i].second]=0;
        }
        int a1=0,b1=k-1;
        while(st[a1]==0)a1++;
        if(a1!=b1)
            res.push_back({2,a1,b1});
        int a2=p.back().first,b2=k-1;
        if(a2!=b2)
            res.push_back({1,a2,b2});
        vector<pair<int,int>>temp;
        for(auto&[x,y]:p){
            if(y==a1){
                y=b1;
            }else if(y==b1){
                y=a1;
            }
            if(x==a2){
                x=b2;
            }else if(x==b2){
                x=a2;
            }
            if(x!=k-1){
                temp.push_back({x,y});
            }
        }
        swap(temp,p);
    }
    cout<<res.size()<<'\n';
    for(auto&[x,y,z]:res)cout<<x<<' '<<y+1<<' '<<z+1<<'\n';
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
}