/**
 * https://codeforces.com/problemset/problem/847/C
 * C. Sum of Nestings
 * Solver: nhant
 * 2025-04-23 00:36:21
 * https://codeforces.com/problemset/submission/847/316714751
 */
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    int64_t k;
    cin >> n >> k;
    if (k > ((int64_t) n - 1) * n / 2) cout << "Impossible\n";
    else {
        string s(2 * n, '.');
        for (int i = 0, n2 = n * 2, bal = 0; i < n2; i++) {
            if (k >= bal || bal == 0) {
                s[i] = '(';
                k -= bal;
                bal++;
            } else {
                s[i] = ')';
                bal--;
            }
        }
        cout << s << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
