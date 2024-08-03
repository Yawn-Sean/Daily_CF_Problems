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
    vector<int> f(4);
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        f[0]=f[0]+(x==1);
        f[1]=max(f[0],f[1]+(x==2));
        f[2]=max(f[1],f[2]+(x==1));
        f[3]=max(f[2],f[3]+(x==2));
    }
    cout<<f[3]<<endl;
}

signed main(){
    fastio;
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
