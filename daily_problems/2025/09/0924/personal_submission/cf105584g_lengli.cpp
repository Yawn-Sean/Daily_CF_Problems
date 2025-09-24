#include <bits/stdc++.h>
using namespace std;
using ll = long long;

static const int SHIFT = 10500;               
static const int W = SHIFT * 2 + 1;           

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (true) {
        int n;
        if (!(cin >> n)) return 0;
        if (n == 0) break;

        vector<int> s(n + 1);
        for (int i = 1; i <= n; ++i) cin >> s[i];

        long long tot = 0;
        for (int i = 1; i <= n; ++i) tot += s[i];

        if (tot & 1) { cout << "No\n"; continue; }

        vector<ll> a(n + 1, 0), b(n + 1, 0);
        vector<int> p(n + 1, -1);

        auto solve_odd_cycle = [&](const vector<int>& cyc) -> bool {
            int k = (int)cyc.size();
            if (k == 1) {
                int i = cyc[0];
                if (s[i] & 1) return false;
                a[i] = s[i] / 2;
                p[i] = i;
                return true;
            }
            long long alt = 0; // s1 - s2 + s3 - ... +/- sk
            for (int j = 0; j < k; ++j) alt += (j % 2 == 0 ? s[cyc[j]] : -s[cyc[j]]);
            if (alt & 1) return false;
            a[cyc[0]] = alt / 2;
            for (int j = 0; j < k; ++j) {
                int u = cyc[j], v = cyc[(j + 1) % k];
                p[u] = v;
                a[v] = s[u] - a[u];
            }
            return true;
        };

        auto solve_even_cycle = [&](const vector<int>& cyc) {
            int k = (int)cyc.size();
            for (int j = 0; j < k; ++j) p[cyc[j]] = cyc[(j + 1) % k];
            a[cyc[0]] = 0; 
            for (int j = 0; j < k - 1; ++j) {
                int u = cyc[j], v = cyc[j + 1];
                a[v] = s[u] - a[u];
            }

        };

        int any_even = -1;
        for (int i = 1; i <= n; ++i) if ((s[i] & 1) == 0) { any_even = i; break; }

        bool ok = true;

        if (any_even != -1) {
            vector<int> odd_idx, even_others;
            for (int i = 1; i <= n; ++i) {
                if (i == any_even) continue;
                if (s[i] & 1) odd_idx.push_back(i);
                else even_others.push_back(i);
            }
            vector<int> big = { any_even };
            big.insert(big.end(), odd_idx.begin(), odd_idx.end());
            if (!solve_odd_cycle(big)) ok = false;
            for (int x : even_others) if (!solve_odd_cycle(vector<int>{x})) ok = false;
        } else {
            if (n % 2 == 1) ok = false;
            if (ok) {
                int K = n / 2;
                static bitset<W> dp[71][36];
                for (int i = 0; i <= n; ++i)
                    for (int k = 0; k <= K; ++k)
                        dp[i][k].reset();
                dp[0][0].set(SHIFT); // sum = 0

                for (int i = 0; i < n; ++i) {
                    int val = s[i + 1];
                    for (int k = 0; k <= min(i, K); ++k) {
                        dp[i + 1][k] |= dp[i][k]; 
                        if (k + 1 <= K) {
                            if (val >= 0) dp[i + 1][k + 1] |= (dp[i][k] << val);
                            else          dp[i + 1][k + 1] |= (dp[i][k] >> (-val));
                        }
                    }
                }
                int target = (int)(tot / 2);
                int idx = SHIFT + target;
                if (idx < 0 || idx >= W || !dp[n][K].test(idx)) ok = false;
                else {
                    vector<int> T, U;
                    int i = n, k = K;
                    while (i > 0) {
                        if (dp[i - 1][k].test(idx)) { // 不选第 i 个
                            --i;
                        } else {
                            T.push_back(i);
                            idx -= s[i];
                            --k; --i;
                        }
                    }
                    reverse(T.begin(), T.end());
                    vector<int> inT(n + 1, 0);
                    for (int x : T) inT[x] = 1;
                    for (int i2 = 1; i2 <= n; ++i2) if (!inT[i2]) U.push_back(i2);
                    vector<int> cyc;
                    for (int j = 0; j < (int)T.size(); ++j) {
                        cyc.push_back(T[j]);
                        cyc.push_back(U[j]);
                    }
                    solve_even_cycle(cyc);
                }
            }
        }

        if (!ok) { cout << "No\n"; continue; }

        for (int i = 1; i <= n; ++i) b[i] = a[p[i]];

        cout << "Yes\n";
        for (int i = 1; i <= n; ++i) {
            if (i > 1) cout << ' ';
            cout << a[i];
        }
        cout << "\n";
        for (int i = 1; i <= n; ++i) {
            if (i > 1) cout << ' ';
            cout << b[i];
        }
        cout << "\n";
    }
    return 0;
}
