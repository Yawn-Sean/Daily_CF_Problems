/*
所有边按照 g 排序
枚举最大的 g 是谁，然后只从前面这些边里去构造树，在能构造出树的前提下考虑能否最小化 max(s)
倘若前 i 条边恰好足以构造出一颗树，则这颗树必然包含当前这个 g，所以我们尝试最小化最大的 s
假设算出来了最小化最大的 s 是 min_s，则后边仅当遇到 s <= min_s 的边时才会更新答案
考虑不断求 s 的最小瓶颈生成树，则当遇到 s <= min_s 时，可能会更新最小瓶颈生成树
我们把这条边加到树中，树上会得到一个环，删除环上的最大边就好
但本题点数很小，所以可以暴力求新的最小瓶颈树
*/

struct Edge {
    LL u, v, g, s;

    bool operator<(const Edge &o) const {
        if (g == o.g) {
            return s < o.s;
        }
        return g < o.g;
    }
};

LL fa[N];
LL n, m, G, S;
vector<Edge> es;

LL find(LL x) {
    if (x == fa[x]) {
        return x;
    }
    return fa[x] = find(fa[x]);
}

bool together(int x, int y) {
    return find(x) == find(y);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    fa[x] = y;
}

void meibao() {
    cin >> n >> m >> G >> S;
    for (int i = 1; i <= m; i++) {
        LL u, v, g, s;
        cin >> u >> v >> g >> s;
        es.push_back({u, v, g, s});
    }

    sort(es.begin(), es.end());

    LL INF = 3e18;
    LL res = INF;
    vector<Edge> choices;
    vector<Edge> next_choices;
    for (int i = 0; i < m; i++) {
        choices.push_back(es[i]);
        if (choices.size() > 1) {
            for (int j = choices.size() - 2; j >= 0; j--) {
                if (choices[j].s > choices[j + 1].s) {
                    swap(choices[j], choices[j + 1]);
                }
            }
        }

        for (int j = 1; j <= n; j++) {
            fa[j] = j;
        }
        int block_cnt = n;
        LL min_s = 0;
        next_choices.clear();
        for (int j = 0; j < choices.size(); j++) {
            if (!together(choices[j].u, choices[j].v)) {
                merge(choices[j].u, choices[j].v);
                block_cnt--;
                next_choices.push_back(choices[j]);
                min_s = max(min_s, choices[j].s);
            }
        }   

        if (block_cnt == 1) {
            res = min(res, G * es[i].g + S * min_s);
        }
        choices = next_choices;
    }
    if (res == INF) res = -1;
    cout << res << "\n";
}
