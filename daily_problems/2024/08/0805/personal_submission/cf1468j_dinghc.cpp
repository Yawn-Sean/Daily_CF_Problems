#include <bits/stdc++.h>

using namespace std;
using li = long long;
constexpr int N = 200'000;

struct union_find {
    vector<int> parent;
    vector<int> rank;
    union_find(int n) : parent(n), rank(n) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }
    int find(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find(parent[v]);
    }
    void merge(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (rank[a] < rank[b])
                swap(a, b);
            parent[b] = a;
            if (rank[a] == rank[b])
                rank[a]++;
        }
    }
};

struct Edge {
    int u, v, w;
    bool operator<(Edge const& other) {
        return w < other.w;
    }
};

Edge edges[N];

li kruskal(int n, int m) {
    li cost = 0;
    union_find dsu(n);
    sort(edges, edges + m);
    for (int i = 0; i < m; i++) {
        Edge e = edges[i];
        if (dsu.find(e.u) != dsu.find(e.v)) {
            cost += e.w;
            dsu.merge(e.u, e.v);
        }
    }
    return cost;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        int mn_cst = INT_MAX;
        for (int i = 0, x, y, s; i < m; i++) {
            scanf("%d%d%d", &x, &y, &s);
            x--, y--;
            edges[i].u = x;
            edges[i].v = y;
            edges[i].w = max(0, s - k);
            mn_cst = min(mn_cst, abs(k - s));
        }
        li ans = kruskal(n, m);
        if (ans > 0) {
            printf("%lld\n", ans);
        } else {
            printf("%d\n", mn_cst);
        }
    }
    return 0;
}

