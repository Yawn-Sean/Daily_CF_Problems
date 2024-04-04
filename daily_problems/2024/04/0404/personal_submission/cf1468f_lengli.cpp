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
    int n;
    cin>>n;
    map<array<int,2>,int> q;
    for(int i=1;i<=n;i++){
        int x,y,l,r;
        cin>>x>>y>>l>>r;
        array<int,2> t={l-x,r-y};
        int d=gcd(abs(t[0]),abs(t[1]));
        t[0]/=d,t[1]/=d;
        q[t]++;
    }

    int res=0;
    for(auto [c,v]:q){
        array<int,2> t={-c[0],-c[1]};
        res+=q[t]*v;
    }
    res/=2;
    cout<<res<<endl;
}

signed main(){
    fastio;
    int T;
    cin>>T;
    while(T--) solve();
    
    return 0;
}
