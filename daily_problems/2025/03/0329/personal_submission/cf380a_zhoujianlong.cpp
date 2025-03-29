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
    int m;
    cin >> m;
    vector<pll> b, c;
    vector<int> type(m + 1, 0), a;
    b.emplace_back(0, 0);
    c.emplace_back(0, 0);
    a.push_back(0);

    const int mx_v = 1e5;
    rep (i, 1, m) {
        int op;
        cin >> op;
        type[i] = op;

        if (op == 1) {
            i64 x;
            cin >> x;
            i64 r0 = b.back().second + 1;
            b.emplace_back(r0, r0);
            c.emplace_back(x, x);
            if (a.size() > mx_v)
                continue;
            a.push_back(x);
        } else {
            i64 l, num;
            cin >> l >> num;
            i64 len = l * num;
            if (len == 0)
                continue;
            i64 r0 = b.back().second + 1;
            b.emplace_back(r0, r0 + len - 1);
            c.emplace_back(l, num);

            rep (j, 0, len - 1) {
                if (a.size() > mx_v)
                    break;
                a.push_back(a[1 + j % l]);
            }
        }
    }
    int n;
    cin >> n;
    rep (i, 1, n) {
        i64 id;
        cin >> id;
        if (id <= mx_v) {
            cout << a[id] << " ";
            continue;
        }

        int l = 1, r = b.size() - 1;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (b[mid].first > id)
                r = mid - 1;
            else
                l = mid;
        }
        if (type[l] == 1) {
            cout << c[l].first << " ";
        } else {
            id = (id - b[l].first) % c[l].first + 1;
            cout << a[id] << " ";
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
