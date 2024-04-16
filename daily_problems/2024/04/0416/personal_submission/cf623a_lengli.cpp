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
    vector<vector<int>> eg(n+1,vector<int>(n+1,0));
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        eg[a][b]=eg[b][a]=1;
    }
    
    vector<char> res(n+1,'*');
    vector<vector<int>> ne(n+1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(!eg[i][j] and i!=j) {
                ne[i].pb(j),ne[j].pb(i);
            }
        }
    }
    vector<int> c(n+1,-1);
    bool flag=1;
    function<void(int,int,int)> dfs=[&](int u,int f,int col){
        if(c[u]!=-1 or !flag){
            if(col!=c[u]) flag=0;
            return;
        }
        c[u]=col;
        for(auto x:ne[u]){
            dfs(x,u,col^1);
        }
    };

    for(int i=1;i<=n;i++){
        if(ne[i].size() and c[i]==-1 and flag){
            dfs(i,0,1);
        }
    }

    if(!flag){
        cout<<"No"<<endl;
        return;
    }

    for(int i=1;i<=n;i++){
        if(c[i]==-1){
            res[i]='b';
        }else if(c[i]==1) res[i]='a';
        else res[i]='c';
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            int d=abs(res[i]-res[j]);
            if(d<=1 and !eg[i][j]) flag=0;
            if(d==2 and eg[i][j]) flag=0;
        }
    }
    if(!flag){
        cout<<"No"<<endl;
        return;
    }

    cout<<"Yes"<<endl;
    for(int i=1;i<=n;i++) cout<<res[i];
}

signed main(){
    fastio;
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
