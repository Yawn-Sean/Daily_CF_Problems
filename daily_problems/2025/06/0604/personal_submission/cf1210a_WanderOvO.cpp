/*
假设编号为 i 的点，需要和 j 点数的面建立关联
有 6^7 = 3e5 种可能的关联情况
假设枚举了一种关联情况，那么每条边应该放什么点数已经完全确定了
把所有边该放置的点数扔到 set 里去重，就是最多可放置的
*/

int n, m;
PII edges[N];
int id[N], res;

void dfs(int u) {
    if (u == n + 1) {
        set<PII> st;
        for (int i = 1; i <= m; i++) {
            int cnt1 = id[edges[i].x], cnt2 = id[edges[i].y];
            if (cnt1 > cnt2) {
                swap(cnt1, cnt2);
            }
            st.insert({cnt1, cnt2});
        }
        res = max(res, (int)st.size());
        return;
    }

    for (int i = 1; i <= 6; i++) {
        id[u] = i;
        dfs(u + 1);
    }
    
}

void meibao() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> edges[i].x >> edges[i].y;
    }

    res = 0;
    dfs(1);

    cout << res << "\n";
}
