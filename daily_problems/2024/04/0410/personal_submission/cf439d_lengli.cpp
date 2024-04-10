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
    int n,m;
    cin>>n>>m;
    vector<int> a(n+1);
    vector<int> b(m+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>b[i];
    sort(a.begin()+1,a.begin()+1+n);
    sort(b.begin()+1,b.begin()+1+m);
    int l=1,r=m;
    int cntl=1,cntr=1;
    int res=0;
    while(l<n and a[l]==a[l+1]) l++,cntl++;
    while(r>1 and b[r]==b[r-1]) r--,cntr++;
    while(a[l]<b[r]){
        if(a[l]==b[r]-1){
            res+=min(cntl,cntr);
            break;
        }
        if(cntl<cntr){
            if(l==n){
                res+=(b[r]-a[l])*cntl;
                break;
            }
            int d=a[l+1]-a[l];
            d=min(b[r]-a[l],d);
            res+=d*cntl;
            a[l]+=d;
        }else{
            if(r==1){
                res+=(b[r]-a[l])*cntr;
                break;
            }
            int d=b[r]-b[r-1];
            d=min(b[r]-a[l],d);
            res+=d*cntr;
            b[r]-=d;
        }
        while(l<n and a[l]==a[l+1]) l++,cntl++;
        while(r>1 and b[r]==b[r-1]) r--,cntr++;
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
