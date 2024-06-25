#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define ve vector
#define eb emplace_back
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
    int n = red(), q = red(), res = 0, s = 0;
    ve<int> l(q + 1), r(q + 1), cnt(n + 1), pre(n + 1);
    rep(i, 1, q + 1) {
        l[i] = red(), r[i] = red();
        rep(j, l[i], r[i] + 1) {
            cnt[j]++;
        }
    }

    rep(i, 1, q + 1) {
        rep(j, l[i], r[i] + 1) {
            cnt[j]--;
        }
        s = 0;
        rep(j, 1, n + 1) {
            if (cnt[j] == 1) {
                pre[j] = pre[j - 1] + 1;
            } else {
                pre[j] = pre[j - 1];
            }
            if (cnt[j]) {
                s += 1;
            }
        }
        rep(j, i + 1, q + 1) {
            res = max(res, s - pre[r[j]] + pre[l[j] - 1]);
        }
        rep(j, l[i], r[i] + 1) {
            cnt[j]++;
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
可暴力：记录左端点、右端点、点的覆盖次数、覆盖次数为1的前缀和。
q次循环，首先去掉该线段，最后恢复该线段；去掉该线段后得再去掉第一条线段之后的线段中的一条线段取得最大值，
s记录去掉一条线段后的可覆盖的点的个数，覆盖次数为1的是需要记录的前缀和，因为覆盖次数再多一点的话，去不掉没影响；
https://codeforces.com/problemset/problem/1132/C
*/