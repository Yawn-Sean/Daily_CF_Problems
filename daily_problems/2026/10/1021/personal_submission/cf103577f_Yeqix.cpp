#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
namespace rgs = ranges;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<deque<int>> f(n);
    vector<int> row(n), col(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;
            if (c == '1') {
                f[i].push_back(1);
                row[i]++, col[j]++;
            } else {
                f[i].push_back(0);
            }
        }
    }

    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x, y, v;
            cin >> x >> y >> v;
            x--, y--;
            row[x] -= f[x][y] - v;
            col[y] -= f[x][y] - v;
            f[x][y] = v;
        } else {
            int x;
            cin >> x;
            int pre = x;
            for (int j = n - 1; j >= 1; j--) {
                col[j] = col[j - 1];
            }
            for (int i = 0; i < n; i++) {
                f[i].push_front(pre);
                row[i] += pre - f[i].back();
                pre = f[i].back();
                f[i].pop_back();
            }
            col[0] = 0;
            for (int j = 0; j < n; j++) {
                col[0] += f[j][0];
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += (row[i] == n) + (col[i] == n);
        }
        cout << ans << "\n";
    }
    return 0;
}