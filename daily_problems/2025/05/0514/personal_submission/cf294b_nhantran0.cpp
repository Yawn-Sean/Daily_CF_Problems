/*
 https://codeforces.com/problemset/problem/294/B
 B. Shaass and Bookshelf
 Solver: nhant
 2025-05-14 23:29:11
 https://codeforces.com/problemset/submission/294/319665565
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> t(n), w(n);
    int tsum = 0;
    for (int i = 0; i < n; i++) {
        cin >> t[i] >> w[i];
        tsum += t[i];
    }
    vector<vector<bool>> d(tsum + 1, vector<bool>(tsum + 1));
    d[tsum][0] = true;
    int res = tsum;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= tsum; j++) {
            for (int k = j - t[i] - w[i]; k >= 0; k--) {
                if (d[j][k]) {
                    d[j - t[i]][k + w[i]] = true;
                    res = min(res, j - t[i]);
                }
            }
        }
    }
    cout << res << '\n';
}
