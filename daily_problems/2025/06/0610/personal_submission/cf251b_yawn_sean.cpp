#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> p(n), target(n);

    for (auto &x: p) cin >> x, x --;
    for (auto &x: target) cin >> x, x --;

    auto check = [&] (vector<int> &a, vector<int> &b) -> bool {
        for (int i = 0; i < n; i ++)
            if (a[i] != b[i]) return false;
        return true;
    };

    auto operate = [&] (vector<int> &val, vector<int> &op) -> vector<int> {
        vector<int> ans(n);
        for (int i = 0; i < n; i ++)
            ans[i] = op[val[i]];
        return ans;
    };

    vector<int> q(n);
    for (int i = 0; i < n; i ++)
        q[p[i]] = i;

    vector<int> cur(n);

    iota(cur.begin(), cur.end(), 0);

    if (check(cur, target)) return cout << "NO", 0;

    for (int i = 1; i <= k; i ++) {
        cur = operate(cur, p);
        if (check(cur, target)) {
            if ((k - i) % 2 == 0 && (i > 1 || k == 1 || !check(q, target)))
                return cout << "YES", 0;
            break;
        }
    }

    iota(cur.begin(), cur.end(), 0);

    for (int i = 1; i <= k; i ++) {
        cur = operate(cur, q);
        if (check(cur, target)) {
            if ((k - i) % 2 == 0 && (i > 1 || k == 1 || !check(p, target)))
                return cout << "YES", 0;
            break;
        }
    }

    cout << "NO";

    return 0;
}