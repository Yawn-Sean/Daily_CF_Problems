#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> nums(m);
    for (auto& x: nums) {
        cin >> x;
        x--;
    }

    vector<int> vis(n + 1, -1), ans(n, -1);

    for (int i = 1; i < m; i++) {
        int pos = nums[i - 1];
        int step = (nums[i] - nums[i - 1] + n - 1) % n + 1;
        if (vis[step] != -1 && vis[step] != pos) {
            cout << -1;
            return 0;
        }
        if (ans[pos] != -1 && ans[pos] != step) {
            cout << -1;
            return 0;
        }
        vis[step] = pos;
        ans[pos] = step;
    }

    int pt = 1;
    for (int i = 0; i < n; i++) {
        if (ans[i] == -1) {
            while (vis[pt] != -1) {
                pt++;
            }
            vis[pt] = i;
            ans[i] = pt;
        }
    }
    for (auto& x: ans) {
        cout << x << ' ';
    }
    cout << '\n';
    return 0;
}
