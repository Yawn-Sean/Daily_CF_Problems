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

const int N=100010,inf=1e9;

void solve(){
    int m,a,b;
    cin>>m>>a>>b;
    int n=min(a+b,m);
    vector<int> st(n+2,0);
    vector<int> mi(n+2,inf);

    priority_queue<array<int,2>,vector<array<int,2>>,greater<array<int,2>>> q;
    q.push({0,0});
    while(q.size()){
        auto [v,idx]=q.top();
        q.pop();
        mi[v]=min(mi[v],idx);
        if(st[v]) continue;
        st[v]=1;
        if(v+a<=n) q.push({v+a,max(v+a,mi[v])}); 
        if(v-b>=0) q.push({v-b,mi[v]});
    }
    int res=0;
    for(int i=0;i<=n;i++){
        if(st[i]) res+=(m-mi[i]+1);
    }
    if(n!=m){
        int g=gcd(a,b);
        int st=(n/g+1)*g;
        int ed=(m/g)*g;
        int d=(ed-st)/g+1;
        int l=m-st+1,r=m-ed+1;
        res+=d*(l+r)/2;
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
