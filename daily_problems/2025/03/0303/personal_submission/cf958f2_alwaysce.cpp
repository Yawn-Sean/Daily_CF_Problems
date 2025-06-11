#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 mod = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    /*
    
    */
    
    int n, m;
    cin >> n >> m;
    vector<int> color(n);
    for (int i = 0; i < n; i++) {
        cin >> color[i];
    }
    int tot = 0;
    vector<int> need(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> need[i];
        if (need[i] > 0) {
            ++tot;
        }
    }

    int l = 0, ok_cnt = 0;
    int ans = 1e9;
    vector<int> cnt(m + 1);
    vector<int> ok(m + 1, 0);

    for (int r = 0; r < n; r++) {
        ++cnt[color[r]];
        // [l, r]区间内颜色数量满足要求的前提下 尽量缩小区间长度
        if (!ok[color[r]] && cnt[color[r]] >= need[color[r]]) {
            ok[color[r]] = 1;
            if (need[color[r]] > 0) {
                ++ok_cnt;
            }
        }

        if (ok_cnt == tot) {
            while (l < r && cnt[color[l]] > need[color[l]]) {
                --cnt[color[l]];
                ++l;
            }
            ans = min(ans, r - l + 1);
        }
    }

    cout << (ans == 1e9 ? -1 : ans - accumulate(need.begin(), need.end(), 0) ) << '\n';
    return 0;
}
