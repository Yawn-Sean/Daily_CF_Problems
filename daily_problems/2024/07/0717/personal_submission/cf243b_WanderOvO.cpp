/*
考虑枚举 (u, v) 这条边，然后枚举 u 和 v 的邻点
然后两边求一个交集看看
是否枚举量可以降一下
对于 u 和 v，至多只需要找出 max(2 * h, 2 * t) 个邻点(不包括 u, v)
最差的情况就是这些点都和 u, v 同时相邻，则只要对半分即可
*/

int T;
int n, m, h, t, d[N];
vector<vector<int>> e(N);
vector<PII> origin_e;
int st[N];

void solve1() {
    cin >> n >> m >> h >> t;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        e[u].pb(v);
        e[v].pb(u);
        origin_e.pb({u, v});
        d[u]++;
        d[v]++;
    }
    bool ok = false;
    for (int i = 0; i < m; i++) {
        int u = origin_e[i].x, v = origin_e[i].y;
        
        if (min(d[u], d[v]) < min(h, t)) {
            continue;
        }
        
        vector<int> adj_u, adj_v;
        for (auto &ver : e[u]) {
            if (ver != v) {
                adj_u.pb(ver);
                st[ver] += 1;
            }
            if (adj_u.size() >= max(2 * h, 2 * t)) {
                break;
            }
        }
        for (auto &ver : e[v]) {
            if (ver != u) {
                adj_v.pb(ver);
                st[ver] += 2;
            }
            if (adj_v.size() >= max(2 * h, 2 * t)) {
                break;
            }
        }
        vector<int> only_u_list, only_v_list, both_list;
        int only_u = 0, only_v = 0;
        int both_cnt = 0;
        for (auto &ver : adj_u) {
            if (st[ver] == 3) {
                both_list.pb(ver);
                both_cnt++;
            } else {
                only_u_list.pb(ver);
                only_u++;
            }
        }
        for (auto &ver : adj_v) {
            if (st[ver] == 2) {
                only_v_list.pb(ver);
                only_v++;
            }
        }
        
        vector<int> all_adj;
        for (auto &ver : only_u_list) {
            all_adj.pb(ver);
        }
        for (auto &ver : both_list) {
            all_adj.pb(ver);
        }
        for (auto &ver : only_v_list) {
            all_adj.pb(ver);
        }

        int all_cnt = all_adj.size();
        for (auto &ver : all_adj) {
            st[ver] = 0;
        }
        if (all_cnt < h + t) {
            continue;
        }
        
        vector<int> choose_u, choose_v;
        for (int j = 0; j < h && j < only_u + both_cnt; j++) {
            choose_u.pb(all_adj[j]);
        }
        for (int j = all_cnt - 1, cnt = 0; j >= only_u && cnt < t; j--, cnt++) {
            choose_v.pb(all_adj[j]);
        }
        if (choose_u.size() == h && choose_v.size() == t) {
            ok = true;
            cout << "YES\n";
            cout << u << " " << v << "\n";
            for (auto &ver : choose_u) {
                cout << ver << " ";
            }
            cout << "\n";
            for (auto &ver : choose_v) {
                cout << ver << " ";
            }
            cout << "\n";
            break;
        }
        choose_u.clear();
        choose_v.clear();
        for (int j = 0; j < t && j < only_u + both_cnt; j++) {
            choose_u.pb(all_adj[j]);
        }
        for (int j = all_cnt - 1, cnt = 0; j >= only_u && cnt < h; j--, cnt++) {
            choose_v.pb(all_adj[j]);
        }
        if (choose_u.size() == t && choose_v.size() == h) {
            ok = true;
            cout << "YES\n";
            cout << v << " " << u << "\n";
            for (auto &ver : choose_v) {
                cout << ver << " ";
            }
            cout << "\n";
            for (auto &ver : choose_u) {
                cout << ver << " ";
            }
            cout << "\n";
            break;
        }
    }
    if (!ok) {
        cout << "NO\n";
    }
}     