//  C. Palindromic Matrix

#include<bits/stdc++.h>

using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> cnt(1001, 0);
    for (int i = 0; i < n * n; i ++) {
        int x;
        cin >> x;
        cnt[x] ++;
    }

    vector<vector<int>> ans(n, vector<int>(n));

    int pt;
    pt = 0;

    for (int i = 0; i < n / 2; i ++) {
        for (int j = 0; j < n / 2; j ++) {
            while (pt < 1001 && cnt[pt] < 4) pt ++;
            if (pt == 1001) return cout << "NO", 0;
            ans[i][j] = pt;
            ans[n - 1 - i][j] = pt;
            ans[i][n - 1 - j] = pt;
            ans[n - 1 - i][n - 1 - j] = pt;
            cnt[pt] -= 4;
        }
    }

    if (n & 1) {
        pt = 0;

        for (int i = 0; i < n / 2; i ++) {
            while (pt < 1001 && cnt[pt] < 2) pt ++;
            if (pt == 1001) return cout << "NO", 0;
            ans[i][n / 2] = pt;
            ans[n - 1 - i][n / 2] = pt;
            cnt[pt] -= 2;
        }

        for (int i = 0; i < n / 2; i ++) {
            while (pt < 1001 && cnt[pt] < 2) pt ++;
            if (pt == 1001) return cout << "NO", 0;
            ans[n / 2][i] = pt;
            ans[n / 2][n - 1 - i] = pt;
            cnt[pt] -= 2;
        }

        for (int i = 0; i <= 1000; i ++)
            if (cnt[i]) ans[n / 2][n / 2] = i;
    }

    cout << "YES\n";

    for (auto &x: ans) {
        for (auto &y: x) cout << y << ' ';
        cout << '\n';
    }

    return 0;
}
