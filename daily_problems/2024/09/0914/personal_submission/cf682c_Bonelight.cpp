#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define ll long long
#define pii pair<int, int>

void solve()
{
    int n; cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++) cin >> a[i];

    vector<vector<pii>> g(n + 1, vector<pii>());
    for(int y = 2; y <= n; y ++){
        int x,w; cin >> x >> w;
        g[x].emplace_back(y,w);
    }

    vector<int> sz(n + 1, 1);
    function<void(int)> dfs_cnt = [&](int o){
        for(auto [p,w]:g[o]){
            dfs_cnt(p);
            sz[o] += sz[p];
        }
    }; dfs_cnt(1);

    function<int(int, int)> dfs_ans = [&](int o, int dist){
        int res = 0;
        for(auto [p,w]:g[o]){
            if(dist + w > a[p]){
                res += sz[p];
                // cout << p << endl;
            } 
            else{
                res += dfs_ans(p, max(0ll, dist + w));
            }
        }
        return res;
    };

    cout << dfs_ans(1,0) << endl;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin), freopen("out.txt", "wt", stdout);
#endif
    int T = 1;
    while (T--)
        solve();
}
