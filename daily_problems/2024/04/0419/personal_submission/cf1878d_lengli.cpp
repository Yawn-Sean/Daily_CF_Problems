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
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<array<int,2>> a(k+1);
    for(int i=1;i<=k;i++) cin>>a[i][0];
    for(int i=1;i<=k;i++) cin>>a[i][1];
    int m;
    cin>>m;
    vector<int> q(m);
    for(auto &x:q) cin>>x;
    sort(all(q));
    vector<int> b(n+2,0);
    for(int i=1,j=0;i<=k and j<m;i++){
        auto [l,r]=a[i];
        while(j<m and q[j]>=l and q[j]<=r){
            int ll=min(q[j],l+r-q[j]);
            int rr=max(q[j],l+r-q[j]);
            b[ll]++,b[rr+1]--;
            j++;
        }
    }
    for(int i=1;i<=n;i++) b[i]+=b[i-1];
    for(int i=1;i<=k;i++){
        auto [l,r]=a[i];
        for(int j=l;j<=r;j++){
            if(b[j]&1){
                int t=max(j,l+r-j);
                swap(s[j-1],s[t-1]);
                b[t]=0;
            }
        }
    }
    cout<<s<<endl;
}

signed main(){
    fastio;
    int T;
    cin>>T;
    while(T--) solve();
    
    return 0;
}
