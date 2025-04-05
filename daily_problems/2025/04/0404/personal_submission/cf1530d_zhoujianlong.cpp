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
    int n;
    cin >> n;
    vector<int> a(n + 1, 0), ans(n + 1), in(n + 1, 0), b(n + 1, 0);
    rep (i, 1, n) {
        cin >> a[i];
        in[a[i]]++;
        b[a[i]] = i;
    }
    vector<int> re;
    rep (i, 1, n) {
        if (in[i] == 0)
            re.push_back(i);
    }
    int k = 0;
    rep (i, 1, n) {
        if (in[a[i]] == 1) {
            ans[i] = a[i];
            ++k;
        } else {
            ans[i] = re.back();
            in[a[i]]--;
            re.pop_back();
        }
    }
    cout << k << endl;
    rep (i, 1, n) {
        if (i == ans[i]) {
            int j = b[a[i]];
            swap(ans[i], ans[j]);
        }
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}
