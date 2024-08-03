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
    int n,m;
    cin>>n>>m;
    vector<array<int,2>> a(m);
    vector<vector<int>> eg(n+1);
    vector<int> rd(n+1,0);
    for(auto &[x,y]:a) cin>>x>>y;

    auto check=[&](int k){
        for(int i=1;i<=n;i++) eg[i].clear(),rd[i]=0;
        for(int i=0;i<k;i++){
            auto [x,y]=a[i];
            eg[x].pb(y);
            rd[y]++;
        }
        queue<int> q;
        for(int i=1;i<=n;i++) if(rd[i]==0) q.push(i);
        while(q.size()){
            auto t=q.front();
            if(q.size()>1) return 0;
            q.pop();
            for(auto x:eg[t]){
                rd[x]--;
                if(!rd[x]) q.push(x);
            }
        }
        return 1;
    };

    int l=1,r=m;
    while(l<r){
        int mid=(l+r)/2;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    cout<<(check(r) ? r : -1);
    
}

signed main(){
    fastio;
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
