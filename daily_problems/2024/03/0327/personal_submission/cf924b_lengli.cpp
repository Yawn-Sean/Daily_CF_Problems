#/*
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
    int n,u;
    cin>>n>>u;
    vector<int> a(n+2);
    for(int i=1;i<=n;i++) cin>>a[i];
    double res=-1;
    for(int i=2,j=i+1;i<n;i++){
        while(j<=n and a[j]-a[i-1]<=u) j++;
        double ans=(double)(a[j-1]-a[i])/(double)(a[j-1]-a[i-1]);
        if(j-1>i) res=max(res,ans);
    }
    cout<<fixed<<setprecision(10);
    cout<<res;
}

signed main(){
    fastio;
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
