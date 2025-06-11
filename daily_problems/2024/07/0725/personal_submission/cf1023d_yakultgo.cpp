#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
template <typename T>
struct RMQ {
    int n;
    vector<T> a;
    vector<array<T, 30>> f;
    function<T(T, T)> func;
    RMQ(vector<T> _a) {
        init(_a, [&](T a, T b) { return min(a, b); });
    }
    RMQ(vector<T> _a, function<T(T, T)> _func) {
        init(_a, _func);
    }
    void init(vector<T> _a, function<T(T, T)> _func) {
        a = _a;
        n = a.size();
        func = _func;
        f.resize(n);
        for (int i = 0; i < n; i++) {
            f[i][0] = a[i];
        }
        for (int j = 1; (1 << j) <= n; j++) {
            for (int i = 0; i + (1 << j) - 1 < n; i++) {
                f[i][j] = func(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    T query(int l, int r) {
        int k = 31 - __builtin_clz(r - l + 1);
        return func(f[l][k], f[r - (1 << k) + 1][k]);
    }
};
void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n), b(n);
    map<int, pair<int, int>> mp;
    int mx = 0, pos = -1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
        if (b[i] == 0) b[i] = INT_MAX;
        if (mp.count(a[i])) {
            mp[a[i]].first = min(mp[a[i]].first, i);
            mp[a[i]].second = max(mp[a[i]].second, i);
        } else {
            mp[a[i]] = {i, i};
        }
        mx = max(mx, a[i]);
        if (a[i] == 0 && pos == -1) pos = i;
    }
    if (mx < q && pos != -1) {
        a[pos] = q;
    } else if (mx < q && pos == -1) {
        cout << "NO" << endl;
        return;
    }
    if (mx == 0 && pos != -1) {
        cout << "YES" << endl;
        for (int i = 0; i < n; i++) cout << q << " ";
        return;
    }
    RMQ<int> rmq(b);
    for (int i = 1; i <= q; i++) {
        if (!mp.count(i)) continue;
        auto [l, r] = mp[i];
        if (rmq.query(l, r) < i) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            if (i == 0) {
                for (int j = i + 1; j < n; j++) {
                    if (a[j] != 0) {
                        a[i] = a[j];
                        break;
                    }
                }
            } else {
                a[i] = a[i - 1];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}