#include <bits/stdc++.h>

#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
#define pii pair<int, int>
using namespace std;
const int N = 2e5 + 5, MOD = 1e9 + 7;
int qmi(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1)
            res = res * a % MOD;
        b >>= 1;
        a = a * a % MOD;
    }
    return res;
}
struct Tree {
    vector<int> T;
    Tree(int n) : T(n + 1) {}
    inline int lowbit(int x) { return x & -x; }
    void add(int i, int v) {
        for (; i < T.size(); i += lowbit(i))
            T[i] = (T[i] + v) % MOD;
    }
    int sum(int i) {
        int res = 0;
        for (; i > 0; i -= lowbit(i))
            res = (res + T[i]) % MOD;
        return res;
    }
};
void solve() {
    int n, q;
    double p;
    cin >> n >> q >> p;
    p = (1 - p) * 1000000;
    int P = p + 0.3;
    P = P * qmi(1000000, MOD - 2) % MOD;
    int rP = qmi(P, MOD - 2);
    vector<int> pows(n + 2, 1), revPows(n + 2, 1);
    for (int i = 1; i < n + 1; i++) {
        pows[i] = pows[i - 1] * P % MOD;
        revPows[i] = revPows[i - 1] * rP % MOD;
    }
    Tree left(n), right(n);
    while (q--) {
        char op;
        cin >> op;
        if (op == '+') {
            int b, x;
            cin >> b >> x;
            left.add(x, b * revPows[x] % MOD);
            right.add(x, b * pows[x] % MOD);
        } else if (op == '-') {
            int b, x;
            cin >> b >> x;
            left.add(x, -b * revPows[x] % MOD);
            right.add(x, -b * pows[x] % MOD);
        } else {
            int x;
            cin >> x;
            int ans = 0;
            ans += (right.sum(n) - right.sum(x)) * revPows[x] % MOD;
            ans += left.sum(x) * pows[x] % MOD;
            cout << (ans % MOD + MOD) % MOD << endl;
        }
    }
}

signed main() {
    IOS;
    int tt = 1;
    // cin >> tt;
    while (tt--)
        solve();
    return 0;
}