#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    vector<int> chain;
    vector<int> leaves;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] > 1) chain.push_back(i);
        else leaves.push_back(i);
    }
    if (chain.empty()) {
        printf("NO\n");
        return 0;
    }
    vector<vector<int>> g(n);
    int edges = 0;
    auto add_edge = [&] (int u, int v) {
        if (u > v) swap(u, v);
        g[u].push_back(v);
        a[u]--, a[v]--;
        edges++;
    };
    int k = chain.size();
    for (int i = 1; i < k; i++) {
        add_edge(chain[i], chain[i - 1]);
    }
    int ans = k - 1;
    int m = leaves.size();
    if (m == 1) {
        if (a[chain[0]] > 0) {
            add_edge(leaves[0], chain[0]);
            ans += 1;
        }
    } else if (m > 1) {
        if (a[chain[0]] > 0) {
            add_edge(leaves[0], chain[0]);
            ans += 1;
        }
        if (a[chain.back()] > 0) {
            add_edge(leaves[1], chain.back());
            ans += 1;
        }
    }
    int u = 2;
    for (int curr = 0; curr < k && u < m; curr++) {
        while (a[chain[curr]] > 0 && u < m) {
            add_edge(chain[curr], leaves[u++]);
        }
    }
    if (u < m) {
        printf("NO\n");
    } else {
        printf("YES %d\n", ans);
        printf("%d\n", edges);
        for (int i = 0; i < n; i++) {
            for (auto& v : g[i]) {
                printf("%d %d\n", i + 1, v + 1);
            }
        }
    }
    return 0;
}

