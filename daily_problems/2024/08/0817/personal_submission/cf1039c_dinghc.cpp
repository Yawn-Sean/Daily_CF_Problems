#include <bits/stdc++.h>

using namespace std;
using li = long long;
constexpr int MOD = 1'000'000'007;
constexpr int N = 500'000;
li c[N];
int pw[N + 1];

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
    bool merge(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
        return true;
    }
    void reset(int a) {
        parent[a] = a;
        rank[a] = 0;
    }
};

int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; i++) {
        scanf("%I64d", &c[i]);
    }
    pw[0] = 1;
    for (int i = 1; i <= n; i++) {
        pw[i] = 2 * pw[i - 1] % MOD;
    }
    unordered_map<li, vector<pair<int, int>>> mp;
    for (int i = 0, u, v; i < m; i++) {
        scanf("%d%d", &u, &v);
        u--, v--;
        mp[c[u] ^ c[v]].emplace_back(u, v);
    }
    union_find dsu(n);
    int ans = (1LL << k) % MOD * pw[n] % MOD;
    for (auto&[key, edges] : mp) {
        int cnt = n;
        for (auto&[u, v] : edges) {
            if (dsu.merge(u, v)) {
                cnt--;
            }
        }
        ans = (ans + MOD - (pw[n] - pw[cnt] + MOD) % MOD) % MOD;
        for (auto&[u, v] : edges) {
            dsu.reset(u);
            dsu.reset(v);
        }
    }
    printf("%d\n", ans);
    return 0;
}

