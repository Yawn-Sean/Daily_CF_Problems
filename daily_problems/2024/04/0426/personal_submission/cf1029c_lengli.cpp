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
    multiset<int> p,q;
    vector<array<int,2>> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i][0]>>a[i][1];
        p.insert(-a[i][0]);
        q.insert(a[i][1]);
    }

    int res=0;
    for(int i=1;i<=n;i++){
        auto [l,r]=a[i];
        p.erase(p.find(-l));
        q.erase(q.find(r));
        auto ll=-(*p.begin()),rr=*q.begin();
        if(ll<rr) res=max(res,rr-ll);
        p.insert(-l),q.insert(r);
    }
    cout<<res;
}

signed main(){
    fastio;
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
