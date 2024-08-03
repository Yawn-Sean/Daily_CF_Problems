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
    int n;
    cin >> n;
    vector<int> t(n), w(n), idx(n - 1);
    for (int i = 0; i < n; ++i) {
        cin >> t[i] >> w[i];
    }
    iota(idx.begin(), idx.end(), 1);
    ranges::sort(idx, [&](int i, int j) {
        return t[i] > t[j];
    });
    priority_queue<int, vector<int>, greater<int>> q;
    int ans = n;
    for (int i = 0, j = 0; ; ++i) {
        while (j < n - 1 and t[idx[j]] > t[0]) {
            q.emplace(w[idx[j]] - t[idx[j]] + 1);
            ++j;
        }
        ans = min(ans, j - i + 1);
        if (q.empty() or q.top() > t[0]) {
            break;
        }
        t[0] -= q.top();
        q.pop();
    }
    cout << ans << endl;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    time_t begin = clock();
    solve();
    time_t end = clock();
    double solve_time = double(end - begin) / CLOCKS_PER_SEC;
    // cout << "runtime: " << solve_time << endl;
    return 0;
}
