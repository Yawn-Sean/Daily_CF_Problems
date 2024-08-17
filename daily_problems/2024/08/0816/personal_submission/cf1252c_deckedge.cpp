#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define ve vector
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using pi = pair<int, int>;
using i64 = long long;

inline int read() {
    int x;
    cin >> x;
    return x;
}



void solve() {
    int n = read(), q = read();
    ve<int> r(n), c(n), pre_r(n + 1), pre_c(n + 1);
    generate(all(r), read);
    generate(all(c), read);
    rep(i, 0, n) {
        r[i] %= 2;
        c[i] %= 2;
    }
    rep(i, 0, n) {
        pre_r[i + 1] = pre_r[i] + r[i];
        pre_c[i + 1] = pre_c[i] + c[i]; 
    }

    while (q--) {
        int stx = read(), sty = read(), edx = read(), edy = read();
        if (stx > edx) {
            swap(stx, edx);
        }
        if (sty > edy) {
            swap(sty, edy);
        }
        int cur_r = pre_r[edx] - pre_r[stx - 1];
        int cur_c = pre_c[edy] - pre_c[sty - 1];
        if (!(cur_r == edx - stx + 1 || !cur_r)) {
            cout << "NO\n";
            continue;
        } 
        if (!(cur_c == edy - sty + 1 || !cur_c)) {
            cout << "NO\n";
            continue;
        } 
        if (r[stx - 1] == c[sty - 1]) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}