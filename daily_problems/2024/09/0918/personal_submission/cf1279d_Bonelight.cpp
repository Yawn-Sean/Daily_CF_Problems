#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define ll long long
#define pii pair<int, int>

void solve()
{
    const int mo = 998244353;
    auto mypow = [&](int x, int y){
        int res = 1;
        while(y){
            if(y & 1) res = res * x % mo;
            y >>= 1;
            x = x * x % mo;
        }
        return res;
    };
    auto ni = [&](int x){
        return mypow(x, mo - 2);
    };

    int n; cin >> n;
    vector<vector<int>> g(n, vector<int>());
    unordered_map<int,int> mp;
    for(int i = 0; i < n; i ++){
        int k; cin >> k;
        g[i] = vector<int>(k);
        for(auto &j:g[i]) cin >> j, mp[j] ++;
    }

    int ans = 0;
    for(int i = 0; i < n; i ++){
        int k = g[i].size();
        for(auto j:g[i]){
            ans += mp[j] * ni(k);
            ans %= mo;
        }
    } 
    cout << ans * ni(n) % mo * ni(n) % mo << endl;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    int T = 1;
    while (T--)
    {
        solve();
    }
}
