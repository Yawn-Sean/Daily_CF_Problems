#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    vector<long long> outs;

    while (t--) {
        long long v;
        cin >> v;
        v *= 100;

        int a, b, c;
        cin >> a >> b >> c;

        int p1, p2, p3;
        cin >> p1 >> p2 >> p3;

        auto f = [&](int i, int j, int k) {
            return (i * (p2 + 1) + j) * (p3 + 1) + k;
        };

        int total_size = (p1 + 1) * (p2 + 1) * (p3 + 1);
        vector<long long> dp(total_size, LLONG_MIN);
        vector<long long> resid(total_size, 0);

        for (int i = 0; i <= p1; ++i) {
            for (int j = 0; j <= p2; ++j) {
                for (int k = 0; k <= p3; ++k) {
                    long long val = i * 1LL * a + j * 1LL * b + k * 1LL * c;
                    if (val * 5 > v) {
                        long long nx = v - val * 5;
                        long long ny = 0;
                        int mask = f(i, j, k);
                        if (dp[mask] < nx || (dp[mask] == nx && resid[mask] < ny)) {
                            dp[mask] = nx;
                            resid[mask] = ny;
                        }

                        long long x = dp[mask];
                        long long y = resid[mask];

                        if (i < p1) {
                            nx = x;
                            ny = y;
                            int nmask = f(i + 1, j, k);
                            if (ny + a < 100) ny += a;
                            else {
                                nx = nx + v - (ny + a) * 5;
                                ny = 0;
                            }
                            if (dp[nmask] < nx || (dp[nmask] == nx && resid[nmask] < ny)) {
                                dp[nmask] = nx;
                                resid[nmask] = ny;
                            }
                        }

                        if (j < p2) {
                            nx = x;
                            ny = y;
                            int nmask = f(i, j + 1, k);
                            if (ny + b < 100) ny += b;
                            else {
                                nx = nx + v - (ny + b) * 5;
                                ny = 0;
                            }
                            if (dp[nmask] < nx || (dp[nmask] == nx && resid[nmask] < ny)) {
                                dp[nmask] = nx;
                                resid[nmask] = ny;
                            }
                        }

                        if (k < p3) {
                            nx = x;
                            ny = y;
                            int nmask = f(i, j, k + 1);
                            if (ny + c < 100) ny += c;
                            else {
                                nx = nx + v - (ny + c) * 5;
                                ny = 0;
                            }
                            if (dp[nmask] < nx || (dp[nmask] == nx && resid[nmask] < ny)) {
                                dp[nmask] = nx;
                                resid[nmask] = ny;
                            }
                        }
                    }
                }
            }
        }

        long long res = *max_element(dp.begin(), dp.end());
        outs.push_back(res);
    }

    for (auto x : outs) cout << x << '\n';

    return 0;
}
