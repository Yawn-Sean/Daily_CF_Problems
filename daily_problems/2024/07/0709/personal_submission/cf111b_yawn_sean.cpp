#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int M = 1e5;
    vector<int> prime_factor(M + 1);
    iota(prime_factor.begin(), prime_factor.end(), 0);

    for (int i = 2; i <= M; i ++)
        if (prime_factor[i] == i)
            for (int j = i; j <= M; j += i)
                prime_factor[j] = i;
    
    function<vector<int>(int)> factors = [&] (int x) {
        vector<int> res = {1};
        while (x > 1) {
            int p = prime_factor[x], k = res.size();
            while (x % p == 0) {
                for (int i = 0; i < k; i ++)
                    res.push_back(res[res.size() - k] * p);
                x /= p;
            }
        }
        return res;
    };

    vector<int> last_vis(M + 1, -1);
    int q;
    cin >> q;

    for (int i = 0; i < q; i ++) {
        int x, y, ans = 0;
        cin >> x >> y;
        for (auto &f: factors(x))
            ans += (i - last_vis[f] > y), last_vis[f] = i;
        cout << ans << '\n';
    }

    return 0;
}