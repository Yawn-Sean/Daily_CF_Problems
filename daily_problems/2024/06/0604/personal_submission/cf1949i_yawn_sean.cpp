#include <bits/stdc++.h>
using namespace std;

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> x(n), y(n), r(n);
    for (int i = 0; i < n; i ++)
        cin >> x[i] >> y[i] >> r[i];
    
    vector<vector<int>> path(n);

    for (int i = 0; i < n; i ++)
        for (int j = 0; j < i; j ++) 
            if (1ll * (x[i] - x[j]) * (x[i] - x[j]) == 1ll * (r[i] + r[j]) * (r[i] + r[j]) - 1ll * (y[i] - y[j]) * (y[i] - y[j]))
                path[i].push_back(j), path[j].push_back(i);
    
    vector<int> col(n, -1);
    bool flg = false, f;
    int c0, c1;

    function<void(int)> dfs = [&](int u) {
        for (auto &v: path[u]) {
            if (col[v] == -1) {
                col[v] = col[u] ^ 1;
                col[v] ? c1 ++ : c0 ++;
                dfs(v);
            }
            else if (col[u] == col[v])
                f = false;
        }
    };

    for (int i = 0; i < n; i ++)
        if (col[i] == -1) {
            f = true;
            c0 = 1, c1 = 0, col[i] = 0;
            dfs(i);
            if (f && (c0 != c1)) {
                flg = true;
                break;
            }
        }
    
    cout << (flg ? "YES" : "NO") << '\n';
    return 0;
}