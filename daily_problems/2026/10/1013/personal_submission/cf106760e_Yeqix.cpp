#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
namespace rgs = ranges;

template <class T>
struct BIT {
    int n;
    vector<T> w;
    BIT(int n) {
        w.resize(n + 1);
        this->n = n;
    }

    void add(int x, T v) {
        while (x <= n) {
            w[x] = max(w[x], v);
            x += x & -x;
        }
    }

    T ask(int x) {
        T ans = 0;
        while (x) {
            ans = max(ans, w[x]);
            x -= x & -x;
        }
        return ans;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<i64> a(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    BIT<int> bt(n + 1);
    vector<int> q(n + 1);
    for (int i = 1; i <= n; i++) {
        if (i >= 3 && q[i - 2]) {
            bt.add(a[i - 2], bt.ask(a[i - 1] - 1) + 2);
        }
        bt.add(a[i], bt.ask(a[i] - 1) + 1);
        if (i < n && a[i] > a[i + 1]) {
            q[i] = 1;
        }
        if (i == n && q[i - 1]) {
            bt.add(a[i - 1], bt.ask(a[i] - 1) + 2);
        }
    }

    cout << bt.ask(n) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}