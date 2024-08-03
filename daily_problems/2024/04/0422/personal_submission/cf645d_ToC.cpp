// https://codeforces.com/contest/645/submission/257712907
vector<int> g[MAXN];
int deg[MAXN];
map<PII, int> e2i;

void sol()
{
    scanf("%d%d", &n, &m);
    int u, v;
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        deg[v]++;
        e2i[{u, v}] = i;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (deg[i] == 0)
            q.push(i);
    if (q.size() > 1) {
        puts("-1");
        return ;
    }
    vector<int> res;
    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        res.push_back(t);
        for (auto &nbd : g[t]) {
            if (--deg[nbd] == 0)
                q.push(nbd);
        }
        if (q.size() > 1) {
            puts("-1");
            return ;
        }
    }
    int p = -1;
    for (int i = 0; i < res.size() - 1; i++) {
        PII e {res[i], res[i + 1]};
        auto it = e2i.lower_bound(e);
        p = max(p, it->second);
    }
    printf("%d\n", p);
}
