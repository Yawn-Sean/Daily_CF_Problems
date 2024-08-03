#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i].first >> a[i].second;
    }
    auto check = [&](int x) {
        vector<int> in(n + 1, 0);
        vector<int> g[n + 1];
        for (int i = 0; i < x; i++) {
            in[a[i].second]++;
            g[a[i].first].push_back(a[i].second);
        }
        queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (in[i] == 0) {
                q.push(i);
            }
        }
        int cnt = 0;
        while (!q.empty()) {
            if (q.size() != 1) return false;
            int u = q.front();
            q.pop();
            cnt++;
            for (int v : g[u]) {
                in[v]--;
                if (in[v] == 0) {
                    q.push(v);
                }
            }
        }
        return cnt == n;
    };
    int left = 1, right = m + 1;
    while (left < right) {
        int mid = (left + right) / 2;
        if (check(mid))
            right = mid;
        else
            left = mid + 1;
    }
    if (left == m + 1) {
        cout << -1 << endl;
    } else {
        cout << left << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}