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
    int n,m;
    cin>>n>>m;
    vector<int> cnt(n+1,0);
    vector<int> mi(n+1,1e9);
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        mi[a]=min(mi[a],((b+n)-a)%n);
        cnt[a]++;
    }
    vector<int> res(n+1,0);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(cnt[j]){
                int d=(j+n-i)%n+mi[j]+(cnt[j]-1)*n;
                res[i]=max(res[i],d);
            }
        }
    }
    for(int i=1;i<=n;i++) cout<<res[i]<<" ";
}

signed main(){
    fastio;
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
