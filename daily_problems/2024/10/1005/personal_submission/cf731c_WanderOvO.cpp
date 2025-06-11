/*
每次给出 l, r，我们合并这两个袜子所在的集合，表示这两个袜子所在集合里面的颜色应该一样
最后把集合都遍历一遍，看看哪个颜色最多，把其他的都改成这个颜色即可
*/

int n, m, k, c[N];
vector<vector<int>> e(N);
bool vis[N];
int tot_cnt;
map<int, int> cnt;

void dfs(int u) {
    vis[u] = true;
    tot_cnt++;
    cnt[c[u]]++;
    for (auto v : e[u]) {
        if (!vis[v]) {
            dfs(v);
        }
    }
}

void meibao() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for (int i = 1; i <= m; i++) {
        int l, r;
        cin >> l >> r;
        e[l].pb(r);
        e[r].pb(l);
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            cnt.clear();
            tot_cnt = 0;
            dfs(i);
            int mxcnt = 0;
            for (auto &it : cnt) {
                mxcnt = max(mxcnt, it.y);
            }
            res += tot_cnt - mxcnt;
        }
    }
    cout << res << "\n";
}   
