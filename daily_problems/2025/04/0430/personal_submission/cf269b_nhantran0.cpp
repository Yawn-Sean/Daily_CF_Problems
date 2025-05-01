/*
 https://codeforces.com/problemset/problem/269/B
 B. Greenhouse Effect
 Solver: nhant
 2025-05-01 00:44:06
 https://codeforces.com/problemset/submission/269/317864873, 218 ms, 100 KB
*/
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> s(n), l(n);
    int lmx = 1;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        double x;
        cin >> x;
        l[i] = 1;
        for (int j = 0; j < i; j++) {
            if (s[j] <= s[i] && l[j] + 1 > l[i]) {
                l[i] = l[j] + 1;
                if (lmx < l[i]) {
                    lmx = l[i];
                }
            }
        }
    }
    cout << (n - lmx) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
