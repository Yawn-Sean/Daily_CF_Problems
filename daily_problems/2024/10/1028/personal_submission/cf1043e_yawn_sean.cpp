#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include <bits/extc++.h>
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
using namespace std; 

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> xs(n), ys(n);
    long long totx = 0, toty = 0;

    for (int i = 0; i < n; i ++) {
        cin >> xs[i] >> ys[i];
        toty += ys[i];
    }
    
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&] (int i, int j) {return xs[i] - ys[i] < xs[j] - ys[j];});

    vector<long long> ans(n);
    for (int i = 0; i < n; i ++) {
        int p = order[i];
        toty -= ys[p];
        ans[p] = totx + 1ll * i * ys[p] + toty + 1ll * (n - i - 1) * xs[p];
        totx += xs[p];
    }

    while (m --) {
        int u, v, val;
        cin >> u >> v;
        u --, v --;
        val = min(xs[u] + ys[v], xs[v] + ys[u]);
        ans[u] -= val;
        ans[v] -= val;
    }

    for (auto &x: ans)
        cout << x << ' ';

    return 0;
}