/**
 * https://codeforces.com/problemset/problem/757/D
 * D. Felicity's Big Secret Revealed
 * Solver: nhant
 * 2025-03-31 05:46:58
 */
#include <bits/stdc++.h>

using namespace std;

const int MD = (int) 1e9 + 7;
const int K = (1 << 20);
bool valid[K];

void solve() {
    valid[0] = true;
    for (int mask = 1; mask < K; mask++) {
        valid[mask] = mask == (1 << __builtin_popcount(mask)) - 1;
    }
    int n;
    string s;
    cin >> n >> s;
    vector<vector<int>> g(n + 1, vector<int>(K));
    int res = 0;
    for (int i = 0; i <= n; i++) {
        for (int mask = 1; mask < K; mask++) {
            if (valid[mask]) {
                res = (res + g[i][mask]) % MD;
            }
        }
        if (i == n) break;
        int x = 0;
        for (int j = i; j < n; j++) {
            x = (x << 1) | (s[j] == '1' ? 1 : 0);
            if (x == 0) continue;
            if (x > 20) break;
            for (int mask = 0; mask < K; mask++) {
                int newMask = mask | (1 << (x - 1));
                if (mask == 0) {
                    g[j + 1][newMask] = (g[j + 1][newMask] + 1) % MD;
                } else {
                    g[j + 1][newMask] = (g[j + 1][newMask] + g[i][mask]) % MD;
                }
            }
        }
    }
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
