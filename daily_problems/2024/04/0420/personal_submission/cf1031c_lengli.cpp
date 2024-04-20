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

const int N=200010;

void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> l,r;
    int k=0;
    set<int> s;
    for(int i=1,sl=0;i<N and sl+i<=n+m;i++){
        sl+=i;
        k=i;
        s.insert(i);
    }
    for(int j=k;j>=1 and n>0;j--){
        if(n-j>=0){
            s.erase(j);
            l.pb(j);
            n-=j;
        }
    }
    for(auto x:s) r.pb(x);
    cout<<l.size()<<endl;
    for(auto x:l) cout<<x<<" ";cout<<endl;
    cout<<r.size()<<endl;
    for(auto x:r) cout<<x<<" ";cout<<endl;
}

signed main(){
    fastio;
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
