#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

inline int red() {
    int x;
    cin >> x;
    return x;
}

void solve() {
    int n = red(), k = red(), x = -1, res = 1e9, i;
    vector<int> a(n);
    generate(all(a), red);
    for (i = 0; i < n - k; i++) {
        int cur = a[i + k] - a[i];
        if (cur < res) {
            res = cur;
            x = (a[i + k] + a[i]) / 2;
        }
    }
    cout << x << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = red();
    while (t--) {
        solve();
    }

    return 0;
}