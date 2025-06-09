#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define erp(i, a, b) for (int i = a; i >= b; --i)

using i64 = long long;
using pii = pair<int, int>;
using pll = pair<i64, i64>;

const int mod = 1000000007, mod0 = 998244353;

void solve() {
    i64 n, k;
    cin >> n >> k;
    vector<int> a(n + 1, 0);
    i64 sum = 0;
    rep (i, 1, n) {
        cin >> a[i];
        sum += a[i];
    }
    if (sum < k) {
        cout << -1 << endl;
        return;
    }
    queue<pii> que;
    rep (i, 1, n)
        que.push({a[i], i});

    int size = que.size();
    while (k > size) {
        i64 p = k / size;
        k -= p * size;
        rep (i, 1, size) {
            auto [x, j] = que.front();
            que.pop();
            if (x > p)
                que.push({x - p, j});
            else
                k += p - x;
        }
        size = que.size();
    }
    while (k != 0 && !que.empty()) {
        auto [x, j] = que.front();
        --k;
        que.pop();
        if (x > 1)
            que.push({x - 1, j});
    }
    while (!que.empty()) {
        auto [x, j] = que.front();
        que.pop();
        cout << j << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
