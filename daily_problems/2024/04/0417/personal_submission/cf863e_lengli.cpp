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
    vector<array<int,2>> a(n);
    vector<int> q;
    int ma=0,mi=2e9;
    for(auto &[l,r]:a){
        cin>>l>>r;
        q.pb(l),q.pb(r);
        mi=min(mi,l),ma=max(ma,r);
    }
    for(auto &[l,r]:a){
        if(l-1>=mi) q.pb(l-1);
        if(r+1<=ma) q.pb(r+1);
    }


    sort(all(q));
    q.erase(unique(all(q)),q.end());
    auto get=[&](int x){
        return lower_bound(all(q),x)-q.begin()+1;
    };
    vector<int> b(q.size()+10,0);
    vector<int> c(q.size()+10,0);
    int m=q.size();
    for(auto &[l,r]:a){
        l=get(l),r=get(r);
        b[l]++,b[r+1]--;
    }

    for(int i=1;i<=m;i++){
        b[i]+=b[i-1];
        if(b[i]==1) c[i]++;
    }
    for(int i=1;i<=m;i++){
        c[i]+=c[i-1];
    }
    for(int i=1;i<=n;i++){
        auto [l,r]=a[i-1];
        if(c[r]-c[l-1]==0){
            cout<<i<<endl;
            return;
        }
    }
    cout<<-1;
}

signed main(){
    fastio;
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
