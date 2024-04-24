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
    vector<int> f(n+1),g(n+1,-1),idx(n+1,-1);
    vector<int> a;
    for(int i=1;i<=n;i++){
        cin>>f[i];
        a.pb(f[i]);
    }
    sort(all(a));
    a.erase(unique(all(a)),a.end());
    int m=a.size();
    vector<int> h(m+1);
    for(int i=1;i<=m;i++) {
        h[i]=a[i-1];
        if(idx[f[h[i]]]==-1){
            g[h[i]]=i;
            idx[f[h[i]]]=i;
        }else g[h[i]]=idx[f[h[i]]];
    }
    for(int i=1;i<=n;i++){
        g[i]=idx[f[i]];
    }
    bool flag=1;
    for(int i=1;i<=n and flag;i++){
        if(h[g[i]]!=f[i]) flag=0;
    }
    for(int i=1;i<=m and flag;i++){
        if(g[h[i]]!=i) flag=0;
    }
    if(!flag) cout<<-1;
    else{
        cout<<m<<endl;
        for(int i=1;i<=n;i++) cout<<g[i]<<" ";
        cout<<endl;
        for(int i=1;i<=m;i++) cout<<h[i]<<" ";
    }
}

signed main(){
    fastio;
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
