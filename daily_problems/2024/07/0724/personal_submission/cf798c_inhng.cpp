#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define endl '\n'
#define int long long
#define lowbit(x) x & -x
#define PII pair<int, int>
#define PIII pair<int, PII>

const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7; // 998244353;

void solve() {
    cout << "YES" << endl;
    int n, g = 0, ans = 0, cnt = 0;
    cin >> n;
    vector<int> a(n);
    for (int &ai : a) {
        cin >> ai;
        g = gcd(g, ai);
    }
    if (g > 1) {
        cout << 0 << endl;
        return;
    }
    for (int ai : a) {
        if (ai & 1) {
            ++cnt;
        } else {
            ans += cnt / 2 + cnt % 2 * 2;
            cnt = 0;
        }
    }
    cout << ans + cnt / 2 + cnt % 2 * 2 << endl;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}
