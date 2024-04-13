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

const int N=200010,inf=1e18;

int n,m,k,q;

vector<int> treasure[N];

void solve(){
    cin>>n>>m>>k>>q;
    for(int i=1;i<=k;i++){
        int x,y;
        cin>>x>>y;
        treasure[x].pb(y);
    }
    treasure[1].pb(1);
    vector<int> ltd(N,-1),rtd(N,-1);
    vector<int> td;
    for(int i=1;i<=q;i++){
        int x;
        cin>>x;
        ltd[x]=rtd[x]=x;
        td.pb(x);
    }
    for(int i=1,la=-1;i<=m;i++){
        if(ltd[i]!=-1) la=ltd[i];
        ltd[i]=la;
        
    }
    for(int i=m,la=-1;i>=1;i--){
        if(rtd[i]!=-1) la=rtd[i];
        rtd[i]=la;
    }
    sort(all(td));
    vector<int> f(2);
    sort(all(treasure[1]));
    f[1]=treasure[1].back()-1;
    f[0]=f[1]+abs(treasure[1].back()-treasure[1][0]);

    for(int i=2,la=1;i<=n;i++){
        if(treasure[i].empty()) continue;
        sort(all(treasure[i]));
        vector<int> g(2,inf);
        int nl=treasure[i][0],nr=treasure[i].back();
        int ll=treasure[la][0],lr=treasure[la].back();

        auto get=[&](int l,int r,int idx){

            auto check=[&](int x){
                int ans=abs(r-x)+i-la;
                if(idx>x) ans+=idx-x;
                else ans+=x-idx;
                ans+=abs(l-idx);
                return ans; 
            };

            int res=inf;
            int it=ltd[r];
            if(it!=-1) res=min(res,check(it));
            it=rtd[r];
            if(it!=-1) res=min(res,check(it));
            return res;
        };
        g[0]=min(g[0],get(nl,ll,nr)+f[0]);
        g[0]=min(g[0],get(nl,lr,nr)+f[1]);
        g[1]=min(g[1],get(nr,ll,nl)+f[0]);
        g[1]=min(g[1],get(nr,lr,nl)+f[1]);
        la=i;
        swap(g,f);
    }
    cout<<min(f[0],f[1]);
}

signed main(){
    fastio;
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
