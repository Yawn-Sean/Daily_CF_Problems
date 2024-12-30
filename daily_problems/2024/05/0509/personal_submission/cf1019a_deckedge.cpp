#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using pi = pair<int, int>;

const int64_t inf = 1e12;

inline int red() {
    int x;
    cin >> x;
    return x;
}

void solve() {
    int n = red(), m = red(), cnt = 0;
    vector<pi> a(n);
    vector<int> b(m);
    rep(i, 0, n) {
        cin >> a[i].se >> a[i].fi;
        a[i].se--;
    }
    sort(all(a), greater<>());
    rep(i, 0, n) {
        b[a[i].se]++;
    }
    rep(i, 1, m) {
        if (b[i] >= b[0]) {
            cnt++;
        }
    }
    if (!cnt) {
        cout << 0 << '\n';
        return ;
    }
    int64_t res = inf;
    rep(k, b[0], n) {
        cnt = n - k;
        b.assign(m, 0);
        int64_t t = 0;
        rep(j, 0, n) {
            if (a[j].se && cnt) {
                if (b[a[j].se] + 1 >= k) {
                    t += a[j].fi;
                } else {
                    b[a[j].se]++;
                    cnt--;
                }
            } else if (a[j].se) {
                t += a[j].fi;
            }
        }
        res = min(res, t);
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
枚举下标索引为0的州的最后票数，则其它州都不能超过这个票数，然后将不投给0州的票按花费从大到小排序，花费较大的肯定不修改，贪心做一下即可。
https://codeforces.com/problemset/problem/1019/A
*/