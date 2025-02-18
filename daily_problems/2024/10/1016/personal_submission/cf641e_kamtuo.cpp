/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-10-16 14:47 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector a(n + 1, 0), t(n + 1, 0), x(n + 1, 0);
    vector<int> nums, time;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i] >> t[i] >> x[i];
        nums.push_back(x[i]);
        time.push_back(t[i]);
    }
    sort(nums.begin(), nums.end());
    sort(time.begin(), time.end());
    auto find_x = [&] (int now) -> int {
        return lower_bound(nums.begin(), nums.end(), now) - nums.begin() + 1;
    };
    auto find_t = [&] (int now) -> int {
        return lower_bound(time.begin(), time.end(), now) - time.begin() + 1;
    };
    vector cnt(n + 1, 0);
    int mid = sqrt(n);
    vector pre(n + 1, vector<std::pair<int, int>> ());
    for (int i = 1; i <= n; i ++) {
        cnt[find_x(x[i])] ++;
    }
    vector tr(mid + 2, vector (n + 1, 0));
    vector to(n + 1, 0);
    int idx = 0;
    for (int i = 1; i <= n; i ++) {
        if (cnt[find_x(x[i])] > mid && to[find_x(x[i])] == 0) {
            to[find_x(x[i])] = ++ idx;
        }
    }
    auto lowbit = [&] (int x) -> int {
        return x & -x;
    };
    auto add = [&] (int now, int x, int val) {
        for (int i = x; i <= n; i += lowbit(i)) tr[now][i] += val;
    };
    auto query = [&] (int now, int x) -> int {
        int res = 0;
        for (int i = x; i; i -= lowbit(i)) res += tr[now][i];
        return res;
    };
    for (int i = 1; i <= n; i ++) {
        int j = find_x(x[i]);
        // debug("j:", j);
        // cout << cnt[j] << "\n";
        if (cnt[j] > mid) {
            // debug("to[j]:", to[j]);
            if (a[i] == 1) {
                add(to[j], find_t(t[i]), 1); 
            } else if (a[i] == 2) {
                add(to[j], find_t(t[i]), -1); 
            } else {
                cout << query(to[j], find_t(t[i])) << "\n";
            }
        } else {
            if (a[i] == 3) {
                int ans = 0;
                for (int k = 0; k < pre[j].size(); k ++) {
                    if (pre[j][k].second <= t[i]) ans += pre[j][k].first;
                }
                cout << ans << "\n";
            } else {
                if (a[i] == 1) {
                    pre[j].push_back({1, t[i]});
                } else {
                    pre[j].push_back({-1, t[i]});
                }
            }
        }
    }
    return 0;
}

#endif

/*

*/
