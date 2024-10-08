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

    int t;
    cin >> t;

    while (t --) {
        int n;
        cin >> n;

        vector<int> nums(n);
        for (auto &v: nums)
            cin >> v;
        
        vector<int> prev(n), suff(n);

        iota(prev.begin(), prev.end(), -1);
        iota(suff.begin(), suff.end(), 1);

        prev[0] = n - 1;
        suff[n - 1] = 0;

        vector<int> deleted(n, 0), ans;

        queue<int> que;
        for (int i = 0; i < n; i ++) que.push(i);

        while (!que.empty()) {
            int u = que.front();
            que.pop();

            if (deleted[u]) continue;

            int v = suff[u];
            if (__gcd(nums[u], nums[v]) == 1) {
                ans.emplace_back(v);
                deleted[v] = 1;
                prev[suff[v]] = prev[v];
                suff[prev[v]] = suff[v];
                que.push(u);
            }
        }
        cout << ans.size() << ' ';
        for (auto &x: ans) cout << x + 1 << ' ';
        cout << '\n';
    }

    return 0;
}