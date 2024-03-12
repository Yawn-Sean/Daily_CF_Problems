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
    vector<int> ch(n+1,0),cl(m+1,0);
    vector<vector<int>> a(n,vector<int>(m,0));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) cin>>a[i][j];
    int tt=1000;
    while(tt--){
        vector<array<int,2>> q;
        for(int i=0;i<n;i++) {
            int t=0;
            for(auto x:a[i]) t+=x;
            if(t<0) q.pb({i,0});
        }
        for(int j=0;j<m;j++){
            int t=0;
            for(int i=0;i<n;i++) t+=a[i][j];
            if(t<0) q.pb({j,1});
        }
        if(q.empty()) break;
        random_shuffle(all(q));
        auto idx=q[0][0],st=q[0][1];
        if(st==0){
            ch[idx]^=1;
            for(int j=0;j<m;j++) a[idx][j]*=-1;
        }else{
            cl[idx]^=1;
            for(int j=0;j<n;j++) a[j][idx]*=-1;
            
        }
    }
    vector<int> l,r;
    for(int i=0;i<n;i++) if(ch[i]) l.pb(i+1);
    for(int i=0;i<m;i++) if(cl[i]) r.pb(i+1);
    cout<<l.size()<<" ";for(auto x:l) cout<<x<<" ";cout<<endl;
    cout<<r.size()<<" ";for(auto x:r) cout<<x<<" ";cout<<endl;

}

signed main(){
    fastio;
    srand(time(0));
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
