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

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> dp(k + 1, 0);
    int ans = 0;

    while (n --) {
        string s;
        cin >> s;
        vector<int> idxs;
        for (int i = 0; i < m; i ++)
            if (s[i] == '1') idxs.emplace_back(i);
        int l = idxs.size();

        if (l > 0) {
            vector<int> saved(l + 1, 0);
            int v = idxs.back() - idxs.front() + 1;
            
            ans += v;
            saved[l] = v;

            for (int i = 0; i < l; i ++) {
                for (int j = i; j < l; j ++) {
                    saved[l - (j - i + 1)] = max(saved[l - (j - i + 1)], v - (idxs[j] - idxs[i] + 1));
                }
            }

            for (int i = k; i > 0; i --) {
                for (int j = 1; j <= l; j ++) {
                    if (i < j) break;
                    dp[i] = max(dp[i], dp[i - j] + saved[j]);
                }
            }
        }
    }

    cout << ans - dp[k] << '\n';

    return 0;
}