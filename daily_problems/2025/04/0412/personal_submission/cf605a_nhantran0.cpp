/**
 * https://codeforces.com/problemset/problem/605/A
 * A. Sorting Railway Cars
 * Solver: nhant
 * 2025-04-13 01:22:03
 * https://codeforces.com/problemset/submission/605/315191573
 */
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> len(n);
    vector<bool> saw(n);
    int res = n - 1;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        p--;
        saw[p] = true;
        len[p] = 1;
        if (p > 0 && saw[p - 1]) {
            len[p] = len[p - 1] + 1;
        }
        res = min(res, n - len[p]);
    }
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
