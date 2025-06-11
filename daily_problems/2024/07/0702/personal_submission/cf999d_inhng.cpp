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
    int n, m, ans = 0;
    cin >> n >> m;
    vector<int> a(n);
    vector cur(m, vector<int>());
    stack<int> s;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        cur[a[i] % m].emplace_back(i);
    }
    for (int i = 0; i < 2 * m; ++i) {
        int x = i % m;
        while (s.size() and cur[x].size() < n / m) {
            int j = s.top();
            s.pop();
            int y = (x - a[j] % m + m) % m;
            ans += y;
            a[j] += y;
            cur[x].emplace_back(j);
        }
        while (cur[x].size() > n / m) {
            s.emplace(cur[x].back());
            cur[x].pop_back();
        }
    }
    cout << ans << endl;
    for (int ai : a) {
        cout << ai << " ";
    }
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
