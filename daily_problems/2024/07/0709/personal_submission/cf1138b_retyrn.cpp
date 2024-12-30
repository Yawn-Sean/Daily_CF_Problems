int n;

void solve() {
    // 相当于选取的1的总数等于b中的总和
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    vector<vector<int>> cnt(4);
    int sum = 0;
    for (int i = 0; i < n; i ++) {
        int u = (s1[i] - '0') << 1 | (s2[i] - '0');
        cnt[u].push_back(i + 1);
        sum += (s2[i] - '0');
    }
    
    // 选取n/2个数 使得1的总数为sum
    int t = 0, need = n / 2;
    if (need > 0) {
        need -= min(need, sz(cnt[0]));
    }
    if (need > 0) {
        t += min(need, sz(cnt[1]) + sz(cnt[2]));
        need -= min(need, sz(cnt[1]) + sz(cnt[2]));
    }
    if (need > 0) {
        t += min(need, sz(cnt[3])) * 2;
        need -= min(need, sz(cnt[3]));
    }
    if (t > sum) {
        cout << -1 << endl;
        return;
    }
    
    t = 0, need = n / 2;
    if (need > 0) {
        t += min(need, sz(cnt[3])) * 2;
        need -= min(need, sz(cnt[3]));
    }
    if (need > 0) {
        t += min(need, sz(cnt[1]) + sz(cnt[2]));
        need -= min(need, sz(cnt[1]) + sz(cnt[2]));
    }
    if (need > 0) {
        need -= min(need, sz(cnt[0]));
    }
    if (t < sum) {
        cout << -1 << endl;
        return;
    }
    
    // 凑的出
    if (sum % 2 == 1 and sz(cnt[1]) == 0 and sz(cnt[2]) == 0) {
        cout << -1 << endl;
        return;
    }
    vector<int> res;
    if (sum % 2 == 1) {
        if (sz(cnt[1]) & 1) {
            res.push_back(cnt[1].back());
            cnt[1].pop_back();
        }
        else {
            res.push_back(cnt[2].back());
            cnt[2].pop_back();
        }
        sum -= 1;
    }
    
    int two = min(sum / 2, sz(cnt[3]));
    while (two > 0 and two + (sum - two * 2) + sz(cnt[0]) < n / 2) {
        two -= 1;
        if (sum - two * 2 > sz(cnt[1]) + sz(cnt[2])) break;
    }
    
    if (sum - two * 2 <= sz(cnt[1]) + sz(cnt[2]) and sum - two * 2 + sz(cnt[0]) + two + sz(res) >= n / 2) {
        int one = sum - two * 2;
        while (two > 0) {
            res.push_back(cnt[3].back());
            two --;
            cnt[3].pop_back();
        }
        while (one > 0 and sz(cnt[1])) {
            res.push_back(cnt[1].back());
            one --;
            cnt[1].pop_back();
        }
        while (one > 0 and sz(cnt[2])) {
            res.push_back(cnt[2].back());
            one --;
            cnt[2].pop_back();
        }
        while (sz(res) < n / 2) {
            res.push_back(cnt[0].back());
            cnt[0].pop_back();
        }
        cout << res << endl;
        return;
    }
    cout << -1 << endl;
}