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
    vector<int> a(2*n-1);
    int k=0;
    int res=0,mi=1e9;
    for(auto &x:a) {
        cin>>x;
        res+=abs(x);
        mi=min(abs(x),mi);
        if(x<0) k++;
    }
    if(n%2==0) {
        if(k&1) cout<<res-mi*2;
        else cout<<res;
    }
    else cout<<res;
}

signed main(){
    fastio;
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
