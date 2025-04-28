#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define int long long
#define all(v) v.begin(), v.end()
//#define x first
//#define y second

using namespace std;
typedef pair<int, int> PII;

const int N = 1e5 + 10;

void solve() {
    int n;
    cin>>n;
    vector<vector<int>>p(n+1);
    map<PII,int>id;

    for(int i=1;i<=n-1;i++){
        int a,b;
        cin>>a>>b;
        p[a].push_back(b);
        p[b].push_back(a);
        if(a>b) swap(a,b);
        id[{a,b}]=i;
    }
    // cout<<id[{1,3}]<<endl;
    map<int,vector<int>>ans;

    auto dfs=[&](auto &&dfs,int u,int fa,int x)->void{
        int d=1;
        if(d==x) d++;
        for(auto v:p[u]){
            if(v==fa) continue;
            int l=u,r=v;
            // if(l==1&&r==3) cout<<d<<' '<<id[{l,r}]<<endl;
            if(l>r) swap(l,r);
            ans[d].push_back(id[{l,r}]);
            // for(auto x:ans[1]) cout<<x<<' ';
            // cout<<endl;
            dfs(dfs,v,u,d);
            d++;
            if(d==x) d++;
        }
    };
    dfs(dfs,1,0,0);

    cout<<ans.size()<<endl;
    for(auto [x,y]:ans){
        // cout<<x<<endl;
        cout<<y.size()<<' ';
        for(auto u:y) cout<<u<<' ';
        cout<<endl;
    }
}
signed main() {
    fastio;
    int T;
 T = 1;
    // cin>>T;
    while (T--) solve();

    return 0;
}
