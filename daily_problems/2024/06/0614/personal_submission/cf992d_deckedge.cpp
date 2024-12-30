#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define ve vector
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--) 
using pi = pair<int, int>;

inline int red() {
    int x;
    cin >> x;
    return x;
}

void solve() {
    int n = red(), k = red(), res = 0;
    int64_t sum = 0;
    ve<int> a(n), nxt(n);
    rep(i, 0, n) {
        a[i] = red();
        sum += a[i];
    }
    per(i, n - 1, 0) {
        nxt[i] = (i < n - 1 && a[i] == 1 ? nxt[i + 1] : i);
    }
    sum *= k;
    rep(i, 0, n) {
        int cur = i;
        int64_t p = 1, s = 0;
        while (cur < n) {
            if (nxt[cur] != cur) {
                if (p % k == 0 && p / k - s > 0 && p / k - s <= nxt[cur] - cur) {
                    res++;
                }
                s += nxt[cur] - cur;
                cur = nxt[cur];
            } else {
                if (sum / a[cur] < p) {
                    break;
                }
                p *= a[cur];
                s += a[cur];
                if (p == s * k) {
                    res++;
                }
                cur += 1;
            }
        }
    }
    cout << res << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}

/*
https://codeforces.com/problemset/problem/992/D
*/