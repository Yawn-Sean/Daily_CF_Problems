/**
 * https://codeforces.com/problemset/problem/925/B
 * B. Resource Distribution
 * Solver: nhant
 * 2025-04-11 05:36:00
 * Submission: https://codeforces.com/problemset/submission/925/314940197
 */
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, x1, x2;
    cin >> n >> x1 >> x2;
    vector<int> c(n), k1Min(n), k2Min(n), ord(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        k1Min[i] = (x1 + c[i] - 1) / c[i];
        k2Min[i] = (x2 + c[i] - 1) / c[i];
        ord[i] = i;
    }
    sort(ord.begin(), ord.end(), [&](int i, int j) { return c[i] < c[j]; });
    bool yes = false;
    int k1 = 1, k2 = 1;
    for (; k1 < n; k1++) {
        if (k1Min[ord[n - k1]] <= k1) break;
    }
    if (k1 < n) {
        for (; k1 + k2 <= n; k2++) {
            if (k2Min[ord[n - k1 - k2]] <= k2) break;
        }
        if (k1 + k2 <= n) {
            yes = true;
            cout << "Yes\n" << k1 << " " << k2 << "\n";
            for (int i = 0; i < k1; i++) {
                cout << (ord[n - 1 - i] + 1) << " ";
            }
            cout << '\n';
            for (int i = 0; i < k2; i++) {
                cout << (ord[n - 1 - k1 - i] + 1) << " ";
            }
            cout << '\n';
        }
    }
    if (!yes) {
        k1 = k2 = 1;
        for (; k2 < n; k2++) {
            if (k2Min[ord[n - k2]] <= k2) break;
        }
        if (k2 < n) {
            for (; k1 + k2 <= n; k1++) {
                if (k1Min[ord[n - k2 - k1]] <= k1) break;
            }
            if (k1 + k2 <= n) {
                yes = true;
                cout << "Yes\n" << k1 << " " << k2 << '\n';
                for (int i = 0; i < k1; i++) {
                    cout << (ord[n - 1 - k2 - i] + 1) << " ";
                }
                cout << '\n';
                for (int i = 0; i < k2; i++) {
                    cout << (ord[n - 1 - i] + 1) << ' ';
                }
                cout << '\n';
            }
        }
    }
    if (!yes) cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
