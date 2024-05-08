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

using LL = long long;

int qmi(int a,int b){
    int res=1;
    while(b){
        if(b&1) res*=a;
        a*=a;
        b/=2;
    }
    return res;
}

void solve(){
    int n,b;
    cin>>n>>b;
    analyze(b);
    int res=1e18;
    for(auto [x,cnt]:divs){
        int ans=0;
        int k=0;
        for(int j=1;j<=n;){
            if((__int128)j*x<=(__int128)n) j*=x,k++;
            else break;
        }
        for(int i=1,sum=0;i<=k;i++){
            int t=n/qmi(x,i);
            ans+=t;
        }
        res=min(res,ans/cnt);
    }
    cout<<res<<endl;
}

signed main(){
    fastio;
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
