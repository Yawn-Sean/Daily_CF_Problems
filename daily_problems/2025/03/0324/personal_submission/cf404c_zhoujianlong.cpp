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
    int n, k;
    cin >> n >> k;
    vector<int> d(n + 1, 0);
    rep(i, 1, n) cin >> d[i];
    map<int, vector<int>> mp;
    rep(i, 1, n) {
        mp[d[i]].push_back(i);
    }

    if (mp[0].size() != 1) {
        cout << -1 << endl;
        return;
    }

    rep(i, 1, n - 1) {
        i64 w = i == 1 ? k : (k - 1);
        int size = mp[i].size();
        int size0 = mp[i - 1].size();
        if (size > size0 * w) {
            cout << -1 << endl;
            return;
        }
    }

    cout << (n - 1) << endl;
    queue<int> que;
    que.push(mp[0][0]);
    int t = 1;
    while (!que.empty()) {
        int size = que.size();

        int size0 = mp[t].size();
        for (int i = 0, j = 0; i < size; ++i) {
            int u = que.front();
            que.pop();

            int num = t == 1 ? k : k - 1;
            while (num && j < size0) {
                cout << u << " " << mp[t][j] << endl;
                que.push(mp[t][j]);
                --num;
                ++j;
            }
        }
        ++t;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
