// #pragma GCC optimize("O2,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define int long long
using i64 = long long;
#define double long double
#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define ull unsigned long long
#define f first
#define s second
#define pqi priority_queue<int,vector<int>,greater<int>>
#define pqpii priority_queue<pii,vector<pii>,greater<pii>>
//#define endl '\n'
#define vi vector<int>
#define vii vector<vector<int>>
#define vc vector
#define vpii vector<pair<int, int>>
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define mp make_pair
#define INF 1e18
#define exp 1e-12
const int N = 3e5 + 5;
vi g[N];
int dp[N];
int ans=0;
void dfs(int u, int p){ 
    dp[u]=g[u].size()+1;
    for(int v:g[u]){ 
        if(v==p) continue;
        dfs(v, u);
        ans=max(ans, dp[u]+dp[v]-1);
        dp[u]=max(dp[u], (int)g[u].size()+ dp[v]);
    }
    ans=max(ans, dp[u]);
    if(p!=-1)dp[u]--;
    //cout<<u<<" "<<dp[u]<<" "<<ans<<endl;
}
void slove(){
    int n;
    cin >> n;
    ans=0;
    for(int i = 1; i <= n; i++){
        g[i].clear();
        dp[i]=0;
    }
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1,-1);
    cout << ans << endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin>>t;
    //cout<<fixed<<setprecision(15);
    while (t--)slove();
    return 0;
}
