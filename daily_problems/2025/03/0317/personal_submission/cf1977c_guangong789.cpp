#include <bits/stdc++.h>
using namespace std;

int check(vector<int>& vec, int x, int n) {
    int tmp = 1, cnt = 0;
    auto it = lower_bound(vec.begin(), vec.end(), x);
    if (it != vec.end() && *it == x) {
        return cnt;
    }
    for (int i = 0; i < n; ++i) {
        int a = lcm(tmp, vec[i]);
        if (x % a == 0) {
            cnt++;
            tmp = a;
        }
    }
    return (tmp == x) ? cnt : 0;
}

void solve() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }
    ranges::sort(vec);
    int mx = vec[n-1];
    for (int i = 0; i < n-1; ++i) {
        if (mx % vec[i]) {
            cout << n << '\n';
            return;
        }
    }
    int ans = 0;
    for (int i = 1; i*i <= mx; ++i) {
        if (mx % i == 0) {
            ans = max(ans, check(vec, i, n));
            ans = max(ans, check(vec, mx / i, n));
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}