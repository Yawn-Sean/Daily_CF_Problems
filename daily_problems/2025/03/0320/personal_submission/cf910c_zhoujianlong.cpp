#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MAXN int(2e5 + 10)
#define MOD int(1e9 + 7)
#define rep(i, start, end) for (int i = start; i <= end; ++i)
#define erp(i, end, start) for (int i = end; i >= start; --i)

using i64 = long long;
using pii = pair<int, int>;
using pll = pair<i64, i64>;

void solve() {
    int n;
    cin >> n;
    vector<int> w(10, 0), start(10, 0);
    rep(i, 0, n - 1) {
        string s;
        cin >> s;
        int len = s.size();
        for (int j = len - 1, k = 1; j >= 0; --j, k *= 10) {
            w[s[j] - 'a'] += k;
        }
        start[s[0] - 'a'] = 1;
    }
    vector<int> id(10, 0);
    iota(id.begin(), id.end(), 0);
    sort(id.begin(), id.end(), [&](int x, int y) { return w[x] > w[y]; });

    int ans = 0;
    vector<bool> used(10, false);
    rep(i, 0, 9) {
        int j = 0;
        while (used[j] || (i == 0 && start[id[j]]))
            ++j;
        used[j] = true;
        ans += i * w[id[j]];
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
