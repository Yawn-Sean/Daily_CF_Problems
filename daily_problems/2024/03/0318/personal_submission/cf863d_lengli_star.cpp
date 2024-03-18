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
    int n,q,m;
    cin>>n>>q>>m;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<array<int,3>> op(q);
    for(auto &[x,y,z]:op) cin>>x>>y>>z;
    vector<int> qr(m);
    for(auto &x:qr) cin>>x;
    reverse(all(op));
    for(auto [t,l,r]:op){
        if(t==1){
            for(auto &x:qr){
                if(x<l or x>r) continue;
                if(x==l) x=r;
                else x--;
            }
        }else{
            for(auto &x:qr){
                if(x<l or x>r) continue;
                int len=x-l;
                x=r-len;
            }
        }
    }
    for(auto x:qr) cout<<a[x]<<" ";
}


signed main(){
    fastio;
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
