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

    int n;
    cin >> n;

    long long inf = 1e11;
    vector<long long> dp(10, -inf), ndp(10, -inf);
    dp[0] = 0;

    while (n --) {
        int k;
        cin >> k;
        vector<vector<int>> tmp(4);

        while (k --) {
            int c, d;
            cin >> c >> d;
            tmp[c].emplace_back(d);
        }

        for (int i = 1; i <= 3; i ++)
            sort(tmp[i].begin(), tmp[i].end(), greater<long long>());
        
        for (int c1 = 0; c1 <= 3 && c1 <= tmp[1].size(); c1 ++) {
            for (int c2 = 0; c2 * 2 + c1 <= 3 && c2 <= tmp[2].size(); c2 ++) {
                for (int c3 = 0; c3 * 3 + c2 * 2 + c1 <= 3 && c3 <= tmp[3].size(); c3 ++) {
                    long long tot = 0;
                    int ma = 0;
                    for (int i = 0; i < c1; i ++) {
                        tot += tmp[1][i];
                        ma = max(ma, tmp[1][i]);
                    }
                    for (int i = 0; i < c2; i ++) {
                        tot += tmp[2][i];
                        ma = max(ma, tmp[2][i]);
                    }
                    for (int i = 0; i < c3; i ++) {
                        tot += tmp[3][i];
                        ma = max(ma, tmp[3][i]);
                    }

                    for (int i = 0; i < 10; i ++) {
                        long long v = dp[i] + tot, ni = i + c1 + c2 + c3;
                        if (ni >= 10) {
                            v += ma;
                            ni -= 10;
                        }
                        ndp[ni] = max(ndp[ni], v);
                    }
                }
            }
        }

        for (int i = 0; i < 10; i ++) {
            dp[i] = ndp[i], ndp[i] = -inf;
        }
    }
    cout << *max_element(dp.begin(), dp.end());

    return 0;
}