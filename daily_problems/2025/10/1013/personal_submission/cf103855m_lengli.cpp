#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
using i128 = __int128_t;

int64 calc_value(vector<int64> v) {
    sort(v.begin(), v.end());
    int n = v.size();
    i128 ans = 0;
    for (int i = 0; i < n; i++) {
        ans += (i128)v[i] * (2LL * (i + 1) - n - 1);
    }
    return (int64)(2 * ans); 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int64> p(n), q(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    for (int i = 0; i < n; i++) cin >> q[i];

    vector<int64> a(n), b(n);
    for (int i = 0; i < n; i++) {
        a[i] = p[i] + q[i];
        b[i] = p[i] - q[i];
    }

    i128 vp = calc_value(p);
    i128 vq = calc_value(q);
    i128 va = calc_value(a);
    i128 vb = calc_value(b);

    i128 ans = vp + vq - (va + vb) / 2;
    cout << (int64)ans << "\n";
    return 0;
}
