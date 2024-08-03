/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define all(x) x.begin(),x.end()
#define pb push_back

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) "lengli"
#endif

const int N=100010;

void solve(){
    int n;
    cin>>n;
    vector<int> l(n+1,-1),r(n+1,-1);
    vector<vector<int>> g(n+1);
    for(int i=1;i<=n;i++){
        int a,b;
        cin>>a>>b;
        g[a].pb(b);
        if(l[a]==-1) l[a]=r[a]=b;
        else r[a]=b;
    }
    set<array<int,2>> s;
    for(int i=1;i<=n;i++){
        if(r[i]!=-1){
            s.insert({-r[i],i});
        }
    }
    int q;
    cin>>q;
    while(q--){
        int k;
        cin>>k;
        vector<int> qr(k);
        for(auto &x:qr){
            cin>>x;
            if(r[x]!=-1) s.erase({-r[x],x});
        } 
        if(s.empty()) cout<<"0 0"<<endl;
        else if(s.size()==1){
            auto id=(*s.begin())[1];
            cout<<id<<" "<<l[id]<<endl;
        }else{
            int id=(*s.begin())[1];
            qr.pb(id);
            s.erase(s.begin());
            int v=-(*s.begin())[0];
            auto it=upper_bound(all(g[id]),v)-g[id].begin();
            cout<<id<<" "<<g[id][it]<<endl;
        }
        for(auto &x:qr){
            if(r[x]!=-1) s.insert({-r[x],x});
        } 
    }
}

signed main(){
    fastio;
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
