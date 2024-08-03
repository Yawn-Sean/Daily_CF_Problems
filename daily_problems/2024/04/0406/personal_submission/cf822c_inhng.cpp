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

const int N = 2e5 + 10;

vector<PII> a[N], b[N];
vector<int> c(N, INF);

void solve() {
    int n, x, ans = 2 * INF;
    cin >> n >> x;
    while (n--) {
        int l, r, cost;
        cin >> l >> r >> cost;
        a[l].emplace_back(r - l + 1, cost);
        b[r].emplace_back(r - l + 1, cost);
    }
    for (int i = 0; i < N; i++) {
        for (PII t : a[i]) {
            if (t.first >= x) continue;
            if (c[x - t.first] < INF)
                ans = min(ans, c[x - t.first] + t.second);
        }
        for (PII t : b[i])
            c[t.first] = min(c[t.first], t.second);
    }
    if (ans == 2 * INF) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}
