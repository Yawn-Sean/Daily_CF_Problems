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
    vector<int> a(n);
    map<int,vector<int>> q;

    int sz=-1,id=-1;
    for(auto &x:a){
        cin>>x;
        int cnt=0;
        int cx=x;
        while(cx%2==0) cx/=2,cnt++;
        q[cnt].pb(x);
        if((int)q[cnt].size()>sz) sz=(int)q[cnt].size(),id=cnt;
    }
    vector<int> ans;
    for(auto [c,v]:q){
        if(c==id) continue;
        for(auto x:v) ans.pb(x); 
    }
    cout<<ans.size()<<endl;
    for(auto x:ans) cout<<x<<" ";
}

signed main(){
    fastio;
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
