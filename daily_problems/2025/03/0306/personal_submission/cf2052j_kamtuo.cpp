/*----------------------------------------------------------*/
/* Author : KaMtuo                                          */
/* Email : kamtuo@qq.com                                    */
/* Creation_time : 2025-03-06 20:21                         */
/* Software : Visual Studio Code                            */
/*                                                          */
/*  ██╗  ██╗ █████╗ ███╗   ███╗████████╗██╗   ██╗ ██████╗   */
/*  ██║ ██╔╝██╔══██╗████╗ ████║╚══██╔══╝██║   ██║██╔═══██╗  */
/*  █████╔╝ ███████║██╔████╔██║   ██║   ██║   ██║██║   ██║  */
/*  ██╔═██╗ ██╔══██║██║╚██╔╝██║   ██║   ██║   ██║██║   ██║  */
/*  ██║  ██╗██║  ██║██║ ╚═╝ ██║   ██║   ╚██████╔╝╚██████╔╝  */
/*  ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝     ╚═╝   ╚═╝    ╚═════╝  ╚═════╝   */
/*----------------------------------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t --) {
        int n, m, q;
        cin >> n >> m >> q;
        vector a(n + 1, 0ll), d(n + 1, 0ll), e(m + 1, 0ll), time(q + 1, 0ll); 
        vector idx(n + 1, 0);
        for (int i = 1; i <= n; i ++) {
            cin >> a[i];
            idx[i] = i;
        }
        for (int i = 1; i <= n; i ++) { 
            cin >> d[i];
        }
        for (int i = 1; i <= m; i ++) {
            cin >> e[i];
            e[i] += e[i - 1];
        }
        for (int i = 1; i <= q; i ++) {
            cin >> time[i];
        }
        sort(idx.begin() + 1, idx.end(), [&] (int x, int y) {return d[x] > d[y];});
        LL l = 0x3f3f3f3f3f3f3f3f, r = 0x3f3f3f3f3f3f3f3f;
        vector<std::pair<LL, LL>> nums;
        for (int i = 1; i <= n; i ++) {
            int j = idx[i];
            LL sl = d[j] - a[j], sr = d[j];
            if (sr >= l) {
                l -= a[j];
            } else {
                nums.push_back({l, r});
                r = sr, l = sl;
            }
        }
        nums.push_back({l, r});
        vector ans(nums.size() + 1, 0ll);
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i ++) {
            ans[i + 1] = nums[i].second - nums[i].first;
            ans[i + 1] += ans[i];
        }
        for (int i = 1; i <= q; i ++) {
            int l = 0, r = nums.size();
            while (l < r) {
                int mid = l + r >> 1;
                if (nums[mid].second >= time[i]) r = mid;
                else l = mid + 1;
            }
            LL now = time[i];
            int res = r;
            if (nums[res].first <= time[i]) now = nums[res].first;
            l = 0, r = m;
            while (l < r) {
                int mid = l + r + 1 >> 1;
                if (e[mid] <= now - ans[res]) l = mid;
                else r = mid - 1;
            }
            cout << l << ' ';
        }
        cout << "\n";
    }
    return 0;
}

#endif

/*

*/
