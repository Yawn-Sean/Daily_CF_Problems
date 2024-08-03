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
    int n,l,m;
    cin>>n>>l>>m;
    matrix<Mint> res(1,m);
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        res[0][x%m]+=1;
    }
    matrix<Mint> a(m,m);
    vector<int> cost(n+1,0);
    vector<int> cnt(m+1,0);
    for(int i=1;i<=n;i++){
        cin>>cost[i];
        cnt[cost[i]]++;
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            int d=(i-j+m)%m;
            a[j][i]+=cnt[d];
        }
    }
    res*=a^(l-2);
    Mint ans=0;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        x+=cost[i];
        x%=m;
        ans+=(res[0][(m-x)%m]);
    }
    cout<<ans;
}

signed main(){
    fastio;
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
