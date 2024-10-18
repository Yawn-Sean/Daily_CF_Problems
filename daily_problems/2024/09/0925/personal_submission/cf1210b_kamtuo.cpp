/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-09-25 19:04 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector a(n, 0ll), b(n, 0ll), nums(n, 0ll), tot(n, 0ll);
    vector cnt(n, 0);
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
        nums[i] = a[i];
    }
    for (int i = 0; i < n; i ++) cin >> b[i];
    sort(nums.begin(), nums.end());
    int len = unique(nums.begin(), nums.end()) - nums.begin();
    auto find = [&] (LL x) -> int {
        return lower_bound(nums.begin(), nums.begin() + len, x) - nums.begin();
    };
    for (int i = 0; i < n; i ++) {
        int now = find(a[i]);
        cnt[now] ++;
        tot[now] += b[i];
    }
    // debug("tot:", tot);
    auto check = [&] (LL x, LL y) -> bool {
        for (int i = 0; i < 60; i ++) {
            if ((x >> i) % 2 == 0 && (y >> i) % 2) return false;
        }
        return true;
    };
    vector to(len, vector<int> ());
    for (int i = 0; i < len; i ++) {
        for (int j = 0; j < len; j ++) {
            if (check(nums[i], nums[j])) {
                to[i].push_back(j);
            }
        }
    }
    LL ans = 0;
    vector st(len, 0);
    for (int i = 0; i < len; i ++) {
        if (cnt[i] > 1) {
            for (int j = 0; j < to[i].size(); j ++) {
                if (st[to[i][j]] == 0) ans += tot[to[i][j]];
                st[to[i][j]] = 1;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}

#endif

/*

*/
