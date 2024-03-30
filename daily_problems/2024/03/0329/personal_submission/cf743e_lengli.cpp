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

const int N=100010,inf=1e9;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    vector<vector<int>> idx(9);
    for(int i=0;i<n;i++){
        cin>>a[i];
        idx[a[i]].pb(i+1);
    }

    auto get=[&](int x,int s,int len){
        if(!len) return s;
        auto it=upper_bound(all(idx[x]),s)-idx[x].begin();
        it+=len-1;
        if(it>=idx[x].size()) return -1;
        return idx[x][it];
    };

    vector<vector<int>> f(n+1,vector<int> (1<<8,-inf));

    auto check=[&](int len){
        for(int i=0;i<=n;i++)
            for(int j=0;j<(1<<8);j++) f[i][j]=-inf;
        f[0][0]=0;
        for(int i=0;i<=n;i++){
            for(int j=0;j<(1<<8);j++){
                if(f[i][j]<0) continue;
                for(int k=1;k<=8;k++){
                    if(j>>(k-1)&1) continue;
                    int t=get(k,i,len);
                    if(t!=-1) f[t][j|(1<<(k-1))] = max(f[t][j|(1<<(k-1))],f[i][j]);
                    t=get(k,i,len+1);
                    if(t!=-1) f[t][j|(1<<(k-1))] = max(f[t][j|(1<<(k-1))],f[i][j]+1);
                }
            }
        }
        int res=-inf;
        for(int i=1;i<=n;i++) res=max(res,f[i].back());
        if(res<0) return 0;
        return 8*len+res;
    };
    int l=0,r=n;
    while(l<r){
        int mid=(l+r+1)/2;
        if(check(mid)) l=mid;
        else r=mid-1;
    }
    cout<<check(l)<<endl;
}

signed main(){
    fastio;
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
