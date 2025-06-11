#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

int n, k;

void proc() {
    vector<pii> ans;
    vi p(n, -1);

    ans.push_back({0, 1});
    p[1] = 0;
    for (int i = 1; i < n - k; i++) {
        ans.push_back({i, i + 1});
    }

    for (int i = n - k + 1; i < n; i++) {
        ans.push_back({n - k, i});
    }

    cout << n - k + 1 << endl;
    for (auto &[a, b] : ans) {
        cout << a + 1 << ' ' << b + 1 << endl;
    }
}

void solve() {
    cin >> n >> k;
    if (n - k <= 2) {
        proc();
        return;
    }

    vector<pii> ans;
    auto add_edge = [&](int u, int v) -> void {
        ans.push_back({u, v});
    };

    int ave = (n - k - 1) / k;
    int extra = n - k - 1 - k * ave;
    int cur = 1;
    for (int i = 0; i < k; i++) {
        add_edge(0, cur);
        for (int j = 0; j < ave; j++) {
            add_edge(cur, cur + 1);
            cur++;
        }
        if (i < extra) {
            add_edge(cur, cur + 1);
            cur++;
        }
        cur++;
    }

    ll res;
    if (extra == 0) {
        res = 2 * (ave + 1);
    } else if (extra == 1) {
        res = 2 * (ave + 1) + 1;
    } else {
        res = 2 * (ave + 2);
    }
    cout << res << endl;
    for (auto [a, b] : ans) {
        cout << a + 1 << ' ' << b + 1 << endl;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
