// https://codeforces.com/contest/1286/submission/265098252
int n, m, k;
// 根、首个不重复的值
int root, val;  
vector<int> g[MAXN];
// seq[i]是Tree(i)中所有{值, 下标}
vector<PII> seq[MAXN];  
// siz[i]是Tree(i)中结点数量，c[i]是比Tree(i)中节点值小于a[i]的结点数量
int siz[MAXN], c[MAXN]; 
int res[MAXN];
int dfs1(int par, int cur) {
    int t = 1;
    for (auto &chd : g[cur]) {
        if (chd == par) continue;
        t += dfs1(cur, chd);
    }
    return siz[cur] = t;
}
void dfs2(int par, int cur) {
    for (auto &chd : g[cur]) {
        if (chd == par) continue;
        dfs2(cur, chd);
    }

    auto &v = seq[cur];
    if (g[cur].size() == 1) {
        val = 1;
        v.push_back({val, cur});
    } else {
        // 保证各个子树合并后没有重复元素
        int offset = 0;
        for (auto &chd : g[cur]) {
            if (chd == par) continue;
            int tmp = 0;
            for (auto &e : seq[chd]) {
                v.push_back({e.first + offset, e.second});
                tmp = max(tmp, e.first + offset);
            }
            offset = tmp;
        }
        sort(v.begin(), v.end());
        int cnt = c[cur];
        if (cnt == 0) {
            for (int i = 0; i < v.size(); i++) 
                v[i].first += 1;
            v.push_back({1, cur});
        } else if (cnt == v.size()) {
            v.push_back({v.back().first + 1, cur});
        } else {
            int l = v[cnt - 1].first, r = v[cnt].first;
            if (l + 1 == r) {
                for (int i = cnt; i < v.size(); i++) 
                    v[i].first += 1;
            }
            v.push_back({l + 1, cur});
        }
        
    }
}
void sol()
{
    cin >> n;
    int par, cnt;
    for (int i = 1; i <= n; i++) {
        cin >> par >> cnt;
        g[par].push_back(i), g[i].push_back(par);
        c[i] = cnt;
        if (par == 0) root = i;
    }
    dfs1(0, root);
    for (int i = 1; i <= n; i++) {
        if (c[i] > siz[i] - 1) {
            cout << "NO\n";
            return ;
        }
    }
    dfs2(0, root);
    for (auto &[v, i] : seq[root]) {
        res[i] = v;
    }
    cout << "YES\n";
    for (int i = 1; i <= n; i++) cout << res[i] << " ";
    cout << '\n';
}
