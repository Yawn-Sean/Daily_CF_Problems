#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(MAXN);
    while (n--) {
        int s, r;
        cin >> s >> r;
        arr[s].push_back(r);
    }
    int ml = 0;
    vector<int> res(MAXN); //科目
    for (int i = 1; i <= m; ++i) {
        ranges::sort(arr[i], greater{}); //学科i最高分
        int l = arr[i].size();
        ml = max(l, ml);
        int sum = 0;
        for (int j = 0; j < l; ++j) {
            sum += arr[i][j];
            if (sum > 0) {
                res[j+1] += sum;
            } else {
                break;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= ml; ++i) {
        ans = max(ans, res[i]);
        if (res[i] == 0) {
            break;
        }
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << solve();
    return 0;
}