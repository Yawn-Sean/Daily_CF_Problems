#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,m;cin>>n>>m;
    int res=0;
    vector<pair<int,int>>p(m);
    for(auto&[x,y]:p){
        cin>>x>>y;
        x--,y--;
    }
    vector<int>v(n);
    set<pair<int,int>>st;
    for(int i=0;i<6;i++)for(int j=i;j<6;j++)st.insert({i,j});
    auto dfs=[&](auto&&dfs,int x)->void{
        if(x==n){
            auto temp=st;
            for(auto&[x,y]:p){
                int a=v[x],b=v[y];
                if(a>b)swap(a,b);
                temp.erase({a,b});
            }
            res=max(res,21-(int)temp.size());
            return;
        }
        for(int i=0;i<6;i++){
            v[x]=i;
            dfs(dfs,x+1);
        }
    };
    dfs(dfs,0);
    cout<<res;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
}