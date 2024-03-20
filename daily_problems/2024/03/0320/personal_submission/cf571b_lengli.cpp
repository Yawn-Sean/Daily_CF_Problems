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

const int N=300010,inf=1e18;

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a.begin()+1,a.begin()+1+n);
    vector<vector<int>> f(k+2,vector<int> (k+2,inf));
    f[0][0]=0;
    auto get=[&](int x,int y){
        return x*(n/k)+y;
    };
    for(int i=1;i<=k;i++){
        for(int j=0;j<=min(i,n%k);j++){
            if(j) f[i][j]=min(f[i-1][j-1]+a[get(i,j)]-a[get(i-1,j-1)+1],f[i-1][j]+a[get(i,j)]-a[get(i-1,j)+1]);
            else f[i][j]=f[i-1][j]+a[get(i,j)]-a[get(i-1,j)+1];
        }
    }
    cout<<f[k][n%k];
}

signed main(){
    fastio;
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
