#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define endl '\n'
#define int long long
#define lowbit(x) x & -x
#define PII pair<int, int>
#define PIII pair<int, PII>
#define ctzll(x) __builtin_ctzll(x)
#define popcount(x) __builtin_popcount(x)

const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7; // 998244353;

void solve() {
    int n, q, m;
    cin >> n >> q >> m;
    vector<int> a(n), b(m);
    vector<array<int, 3>> question(q);
    for (int &ai : a) {
        cin >> ai;
    }
    for (array<int, 3> &qi : question) {
        cin >> qi[0] >> qi[1] >> qi[2];
        --qi[0];
        --qi[1];
        --qi[2];
    }
    reverse(question.begin(), question.end());
    while (m--) {
        int x;
        cin >> x;
        --x;
        for (auto [t, l, r] : question) {
            if (l <= x and x <= r) {
                if (t) {
                    x = l + r - x;
                } else {
                    if (x > l) {
                        --x;
                    } else {
                        x = r;
                    }
                }
            }
        }
        cout << a[x] << " ";
    }
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}
