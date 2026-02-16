//  F. Parabola Independence
#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

template<class T>
bool chmax(T &a, T b) {
    if (a >= b) return false;
    a = b;
    return true;
}

void solve() {
    int n;
    cin >> n;
    vector<array<i64, 4>> f(n);
    for (int i = 0; i < n; i++) {
        cin >> f[i][0] >> f[i][1] >> f[i][2];
        f[i][3] = i;
    }
    sort(f.begin(), f.end());
    auto check = [&](auto& a, auto& b) {
        if (a[0] == b[0] && a[1] == b[1] && a[2] != b[2]) {
            return true;
        }
        return (a[1] - b[1]) * (a[1] - b[1]) - 4 * (a[0] - b[0]) * (a[2] - b[2]) < 0;
    };

    vector<int> dp1(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (check(f[j], f[i])) {
                chmax(dp1[i], dp1[j] + 1);
            }
        }
    }
    vector<int> dp2(n);
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            if (check(f[i], f[j])) {
                chmax(dp2[i], dp2[j] + 1);
            }
        }
    }
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
        res[f[i][3]] = dp1[i] + dp2[i] + 1;
    }
    for (int i = 0; i < n; i++) {
        cout << res[i] << " \n"[i == n - 1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
