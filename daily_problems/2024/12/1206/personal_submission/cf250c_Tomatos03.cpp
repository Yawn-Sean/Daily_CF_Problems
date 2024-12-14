#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for(int i = start; i <= end; ++i)

void solve() {
    int n, k;
    cin >> n >> k;

    int a[n + 1] = {0};
    rep(i, 1, n) cin >> a[i];

    vector<int> b;
    rep(i, 1, n) {
        b.push_back(a[i]);
        while(i + 1 <= n && a[i + 1] == a[i]) ++i;
    }

    vector<vector<int>> c(k + 1);
    int n_b = b.size();
    rep(i, 0, n_b - 1) {
        c[b[i]].push_back(i);
    }

    int mi = INT_MAX, ans = k;
    rep(i, 1, k) {
        int cnt = 0;
        for(int& j : c[i]) {
            ++cnt;
            if(j == 0 || j == n_b - 1) continue;

            cnt += b[j - 1] == b[j + 1];
        }
        int res = n_b - cnt - 1;
        if(res < mi) {
            mi = res;
            ans = i;
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
