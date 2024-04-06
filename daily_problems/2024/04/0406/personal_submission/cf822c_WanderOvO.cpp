/*
把区间按照长度分组
枚举第一个区间，假设第一个区间长度为 len1，左右端点为 (l[i], r[i])，根据长度找第二个区间
第二个区间长度 len2 = m - len1
需要找左端点 <= l[i] - len2 的区间中最便宜的，和左端点 > r[i] 的区间中最便宜的
前后缀处理 + 二分即可，但是感觉写起来有点麻
*/

int T;
map<int, vector<int>> pre, suf;
map<int, vector<PII>> group;
int l[N], r[N], c[N], n, m;

void solve1() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i] >> c[i];
        int len = r[i] - l[i] + 1;
        if (group.count(len)) {
            group[len].pb({l[i], i});
        } else {
            vector<PII> v;
            v.pb({l[i], i});
            group[len] = v;
        }
    }
    
    for (auto &it : group) {
        sort(it.y.begin(), it.y.end());
        vector<int> p, s;
        for (auto &seg : it.y) {
            p.pb(c[seg.y]);
            s.pb(c[seg.y]);
        }
        for (int i = 1; i < p.size(); i++) {
            p[i] = min(p[i], p[i - 1]);
        }
        for (int i = s.size() - 2; i >= 0; i--) {
            s[i] = min(s[i + 1], s[i]);
        }
        pre[it.x] = p;
        suf[it.x] = s;
    }
    
    int res = 2e9 + 10;
    bool ok = false;
    for (int i = 1; i <= n; i++) {
        int len1 = r[i] - l[i] + 1;
        int len2 = m - len1;
        if (len2 < 0) continue;
        if (group.count(len2)) {
            int pos1 = upper_bound(group[len2].begin(), group[len2].end(), mp(l[i] - len2, n + 1)) - group[len2].begin() - 1;
            int pos2 = upper_bound(group[len2].begin(), group[len2].end(), mp(r[i], n + 1)) - group[len2].begin();
            int mn = 1e9 + 10;
            bool found = false;
            if (pos1 >= 0 && pos1 < group[len2].size()) {
                ok = true;
                found = true;
                mn = min(mn, pre[len2][pos1]);
            }
            if (pos2 >= 0 && pos2 < group[len2].size()) {
                ok = true;
                found = true;
                mn = min(mn, suf[len2][pos2]);
            }
            if (found)
                res = min(res, mn + c[i]);    
        }
    }
    if (!ok) {
        res = -1;
    }
    cout << res << "\n";
}              