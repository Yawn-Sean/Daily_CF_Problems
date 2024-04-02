// link https://codeforces.com/contest/739/submission/254682023

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n + 1);
    vector<pair<int, int>> fa(n + 1), top(n + 1);
    vector<vector<pair<int, int>>> mp(n + 1);
    vector<int> cf(n + 1);
    for (int i = 1; i <= n; i++)cin >> arr[i];
    for (int i = 1; i < n; i++) {
        int f, v;
        cin >> f >> v;
        mp[f].emplace_back(i + 1, v);
        fa[i + 1] = {f, v};
    }
    // 树剖
    vector<int> dfn(n + 1), siz(n + 1, 1), son(n + 1), mir(n + 1), dep(n + 1);
    siz[0] = 0;
    int tot = 0;
    function<void(int)> dfs1 = [&](int len) {
        for (auto [to, w]: mp[len]) {
//            debug(len, to, w);
            dep[to] = dep[len] + 1;
            dfs1(to);
            siz[len] += siz[to];
            if (siz[to] > siz[son[len]]) {
                son[len] = to;
            }
        }
    };
    function<void(int)> dfs2 = [&](int now) {
        dfn[now] = ++tot;
        mir[tot] = now;
        auto f = fa[now].first;
        if (son[f] == now) {
            top[now] = top[f];
            top[now].second += fa[now].second;
        } else {
            top[now] = {now, 0};
        }
        if (son[now]) {
            dfs2(son[now]);
        }
        for (auto [i, j]: mp[now]) {
            if (i == son[now])continue;
            dfs2(i);
        }
    };
    function<int(int, int, int)> check = [&](int l, int r, int c) {
        while (l < r) {
            int mid = (l + r + 1) / 2;
//            debug(mid);
            auto node = mir[mid];
            if (top[node].second < c) l = mid;
            else r = mid - 1;
        }
        return mir[l];
    };
    function<int(int, int)> lca = [&](int len, int cost) {
//        if(cost<0)
 
        int now = len;
        while (now) {
            if (cost >= top[now].second) {
                cost -= top[now].second;
                now = top[now].first;
                if (cost < fa[now].second) {
                    return fa[now].first;
                }
                cost -= fa[now].second;
                now = fa[now].first;
            } else {
                return check(dfn[top[now].first], dfn[now], top[now].second - cost);
            }
        }
        return now;
    };
    function<void(int)> dfs = [&](int now) {
        for (auto [i, j]: mp[now]) {
            debug(i);
            cf[fa[i].first]++;
            auto lc = lca(fa[i].first, arr[i] - fa[i].second);
//            debug(i, fa[i].first, lc, arr[i] - fa[i].second);
            cf[lc]--;
            dfs(i);
            cf[now] += cf[i];
        }
    };
    dfs1(1);
    dfs2(1);
    dfs(1);
    for (int i = 1; i <= n; i++)cout << cf[i] << " ";
}
