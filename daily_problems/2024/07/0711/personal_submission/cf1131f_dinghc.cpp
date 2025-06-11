#include <bits/stdc++.h>

constexpr int MXN = 150'000;

int parent[MXN + 1], rank[MXN + 1], left[MXN + 1], right[MXN + 1], nxt[MXN + 1];

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
            std::swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
        nxt[right[b]] = left[a];
        left[a] = left[b];
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        left[i] = i;
        right[i] = i;
        rank[i] = 1;
    }
    for (int i = 0, u, v; i < n - 1; i++) {
        scanf("%d %d", &u, &v);
        merge(u, v);
    }
    int u = left[find(n)];
    for (int i = 1; i <= n; i++) {
        printf("%d ", u);
        u = nxt[u];
    }
    printf("\n");
    return 0;
}

