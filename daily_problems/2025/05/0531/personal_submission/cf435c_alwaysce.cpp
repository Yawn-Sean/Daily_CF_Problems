#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
int const inf = 1e9 + 7;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> pos(n + 1);
    int tot = 0;
    for (int i = 1; i <= n; i++) {
        cin >> pos[i];
        tot += pos[i];
    }

    for (int i = 1; i <= n; i++) {
        pos[i] = (i % 2 == 0 ? pos[i - 1] + pos[i] : pos[i - 1] - pos[i]);
    }

    int mn = *min_element(pos.begin(), pos.end());
    int mx = *max_element(pos.begin(), pos.end());
    for (int i = 0; i <= n; i++) {
        pos[i] -= mn;
    }

    vector<vector<char>> ans(mx - mn, vector<char>(tot, ' '));
    int cur_j = 0;
    for (int i = 0; i < n; i++) {
        int lo = pos[i], hi = pos[i + 1];
        if (lo < hi) {
            for (int j = 0; j < pos[i + 1] - pos[i]; j++) {
                ans[pos[i] + j][cur_j + j] = '\\';
            }
            cur_j += hi - lo;
        } else {
            for (int j = 0; j < pos[i] - pos[i + 1]; j++) {
                ans[pos[i] - j - 1][cur_j + j] = '/';
            }
            cur_j += lo - hi;
        }
    }

    for (auto& row: ans) {
        for (auto& c: row) {
            cout << c;
        }
        cout << '\n';
    }

    
    return 0;
}
