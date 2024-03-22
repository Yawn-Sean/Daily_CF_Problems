/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define all(x) x.begin(),x.end()
#define pb push_back
#define int long long

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
    vector<int> a(n);
    for(auto &x:a) cin>>x;
    vector<int> b(n);b[0]=a[0];
    for(int i=1;i<n;i++) b[i]=min(a[i],b[i-1]*2);
    int res=1e18,sum=0,cnt=0;
    for(int i=n-1;i>=0;i--){
        int nd=m/(1<<i);
        sum+=nd*b[i];
        m&=(1<<i)-1;
        if(m) res=min(res,sum+b[i]);
        else res=min(res,sum);
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
