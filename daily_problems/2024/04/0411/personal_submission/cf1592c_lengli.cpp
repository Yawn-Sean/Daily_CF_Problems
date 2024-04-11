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
    vector<int> a(n+1);
    int sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum^=a[i];
    }

    vector<vector<int>> eg(n+1);

    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        eg[a].pb(b);
        eg[b].pb(a);
    }

    if(!sum){
        bool flag=0;

        function<int(int,int)> dfs=[&](int u,int f){
            int xo=a[u];
            for(auto x:eg[u]){
                if(x==f) continue;
                xo^=dfs(x,u);
            }
            if(xo==(sum^xo)) flag=1;
            return xo;
        };
        dfs(1,0);
        cout<<(flag ? "YES" : "NO")<<endl;
    }else{
        vector<int> q;
        function<int(int,int)> dfs=[&](int u,int f){
            int xo=a[u];
            for(auto x:eg[u]){
                if(x==f) continue;
                xo^=dfs(x,u);
            }
            if(xo==sum and u!=1){
                q.pb(xo);
                xo=0;
            }
            return xo;
        };
        auto t=dfs(1,0);
        if(!t){
            if(q.size()>=2){
                q.pop_back();
                while(q.size()>=3) q.pop_back(),q.pop_back();
                int m=q.size();
                if(m>=1 and m<k) cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            }else cout<<"NO"<<endl;
        }else{
            while(q.size()>=3) q.pop_back(),q.pop_back();
            int m=q.size();
            if(m>=1 and m<k) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
}

signed main(){
    fastio;
    int T;
    cin>>T;
    while(T--) solve();
    
    return 0;
}
