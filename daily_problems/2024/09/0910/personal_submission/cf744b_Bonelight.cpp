#include <bits/stdc++.h>
using namespace std;
// #define endl '\n'
#define int long long
#define ll long long
#define pii pair<int, int>

void solve()
{
    int n; cin >> n;
    int k = 64 - __builtin_clzll(n);
    vector<vector<int>> num0(k, vector<int>(n)), num1(k, vector<int>(n));

    auto query = [&](vector<int> &que) -> vector<int>
    {
        cout << que.size() << endl;
        for (auto i : que) cout << i << ' ';
        cout << endl;

        vector<int> res(n);
        for (auto &i : res) cin >> i;
        return res;
    };

    for (int i = 0; i < k; i++)
    {
        vector<int> que;
        for (int j = 1; j <= n; j++)
        {
            if ((j >> i & 1) == 0) que.push_back(j);
        }

        num0[i] = query(que);
        que.clear();
        for (int j = 1; j <= n; j++)
        {
            if ((j >> i & 1) == 1) que.push_back(j);
        }
        num1[i] = query(que);
    }

    cout << -1 << endl;
    for (int i = 0; i < n; i++)
    {
        int mi = 2e18;
        for (int j = 0; j < k; j++)
        {
            if (((i + 1) >> j) & 1) mi = min(mi, num0[j][i]);
            else mi = min(mi, num1[j][i]);
        }
        cout << mi << ' ';
    }
    cout << endl;
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
