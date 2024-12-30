#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define rall(x) (x).rbegin(), (x).rend()
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using pi = pair<int, int>;

inline int red() {
    int x;
    cin >> x;
    return x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = red(), C = red(), D = red();
    vector<int> a(n), b(n);
    vector<char> c(n);
    rep(i, 0, n) {
        a[i] = red(), b[i] = red();
        cin >> c[i];
    }

    int res = 0;
    int x = 0, y = 0;
    rep(i, 0, n) {
        if (c[i] == 'D' && b[i] <= D) {
            y = max(y, a[i]);
        }
        if (c[i] == 'C' && b[i] <= C) {
            x = max(x, a[i]);
        }
    }
    if (x > 0 && y > 0) {
        res = max(res, x + y);
    }

    vector<pi> z;
    vector<int> pre;
    function<int(int)> solve = [&](int u) {
        sort(all(z));
        int n = z.size(), res = 0;
        if (n < 2) {
            return 0;
        }
        pre.assign(n + 1, 0);
        rep(i, 0, n) {
            pre[i + 1] = max(pre[i], z[i].se);
        }

        int i = 0;
        per(j, n - 1, 0) {
            while (i < j && z[i].fi + z[j].fi <= u) {
                i++;
            }
            i = min(i, j);
            if (i > 0) {
                res = max(res, pre[i] + z[j].se);
            }
        }
        return res;
    };
    rep(i, 0, n) {
        if (c[i] == 'C') {
            z.emplace_back(b[i], a[i]);
        }
    }
    res = max(res, solve(C));
    z.clear();
    rep(i, 0, n) {
        if (c[i] == 'D') {
            z.emplace_back(b[i], a[i]);
        }
    }
    res = max(res, solve(D));
    cout << res << '\n';
    return 0; 
}

/*
https://codeforces.com/contest/799/problem/C
*/