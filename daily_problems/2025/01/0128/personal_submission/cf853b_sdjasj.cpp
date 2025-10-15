void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> nums(m, vector<int>(4));
    vector<int> d;
    for (int i = 0; i < m; i++) {
        vector<int>& t = nums[i];
        cin >> t[0] >> t[1] >> t[2] >> t[3];
        d.push_back(t[0]);
    }
    sort(nums.begin(), nums.end(), [&](auto& a, auto& b) -> bool {
        return a[0] < b[0];
    });
    sort(d.begin(), d.end());
    d.erase(unique(d.begin(), d.end()), d.end());
    vector<int> maxrv(n + 1, 0x3f3f3f3f);
    int cnt = 0;
    LL res = 0;
    unordered_map<int, LL> fr;
    for (int i = m - 1; i >= 0; i--) {
        int dst = nums[i][2];
        if (dst == 0) continue;
        if (maxrv[dst] == 0x3f3f3f3f) {
            maxrv[dst] = nums[i][3];
            cnt++;
            res += nums[i][3];
        } else if (maxrv[dst] > nums[i][3]) {
            res -= maxrv[dst];
            res += nums[i][3];
            maxrv[dst] = nums[i][3];
        }
        if (cnt == n) {
            fr[nums[i][0]] = res;
            // cout << nums[i][0] << " " << res << endl;
        }
    }
    LL ans = -1;
    res = 0;
    cnt = 0;
    vector<int> maxlv(n + 1, 0x3f3f3f3f);
    for (int i = 0; i < m; i++) {
        int src = nums[i][1];
        if (src == 0) continue;
        if (maxlv[src] == 0x3f3f3f3f) {
            maxlv[src] = nums[i][3];
            cnt++;
            res += nums[i][3];
        } else if (maxlv[src] > nums[i][3]) {
            res -= maxlv[src];
            res += nums[i][3];
            maxlv[src] = nums[i][3];
        }
        if (cnt == n) {
            int dstDay = nums[i][0] + k + 1;
            auto it = lower_bound(d.begin(), d.end(), dstDay);
            if (it == d.end()) {
                continue;
            }
            int day = *it;
            // cout << nums[i][0] << " " << dstDay << " " << day << endl;
            if (fr.count(day)) {
                if (ans == -1) {
                    ans = res + fr[day];
                } else {
                    ans = min(ans, res + fr[day]);
                }
                
            }
        }        
    }
    cout << ans << endl;
}