/**
 * https://codeforces.com/problemset/problem/766/C
 * C. Mahmoud and a Message
 * Solver: nhant
 * 2025-04-03 03:56:22
 */
#include <bits/stdc++.h>

using namespace std;

void solve() {
    const int MD = (int)1e9 + 7;
    int n;
    string s;
    cin >> n >> s;
    array<int, 26> a;
    for (int& x : a) cin >> x;
    vector<int> f(n), g(n);
    int maxLen = 1;
    for (int i = 0; i < n; i++) {
        g[i] = n;
        int maxSubLen = a[s[i] - 'a'];
        for (int j = i - 1; j >= -1 && i - j <= maxSubLen; j--) {
            maxLen = max(maxLen, i - j);
            if (j == -1) {
                f[i] = (f[i] + 1) % MD;
                g[i] = 1;
            } else {
                f[i] = (f[i] + f[j]) % MD;
                g[i] = min(g[i], g[j] + 1);
                maxSubLen = min(maxSubLen, a[s[j] - 'a']);
            }
        }
    }
    cout << f[n - 1] << '\n' << maxLen << '\n' << g[n - 1] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
