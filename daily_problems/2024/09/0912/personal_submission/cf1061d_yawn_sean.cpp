#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include <bits/extc++.h>
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, x, y;
    cin >> n >> x >> y;

    vector<int> ls(n), rs(n);
    int ans = 0, mod = 1e9 + 7;

    for (int i = 0; i < n; i ++) {
        cin >> ls[i] >> rs[i];
        rs[i] ++;
        ans += 1ll * (rs[i] - ls[i]) * y % mod;
        if (ans >= mod) ans -= mod;
    }

    vector<int> st_range(n);
    iota(st_range.begin(), st_range.end(), 0);
    sort(st_range.begin(), st_range.end(), [&](int i, int j) {return ls[i] < ls[j];});

    priority_queue<int, vector<int>, greater<int>> pq_using;
    priority_queue<int> pq_used;

    for (auto &i: st_range) {
        while (!pq_using.empty() && pq_using.top() <= ls[i]) {
            int v = pq_using.top();
            pq_using.pop();
            pq_used.push(v);
        }
        if (!pq_used.empty() && (x - y) / y >= ls[i] - pq_used.top()) {
            int v = pq_used.top();
            pq_used.pop();
            ans += (ls[i] - v) * y;
        }
        else ans += x - y;

        if (ans >= mod) ans -= mod;
        pq_using.push(rs[i]);
    }

    cout << ans;

    return 0;
}