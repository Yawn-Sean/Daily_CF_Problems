#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int M = 70;

    vector<int> pr(M + 1);
    for (int i = 0; i <= M; i++) pr[i] = i;

    vector<int> primes;
    for (int i = 2; i <= M; i++) {
        if (pr[i] == i) {
            primes.push_back(i);
            for (int j = i; j <= M; j += i)
                pr[j] = i;
        }
    }

    vector<int> msks(M + 1, 0);
    for (int i = 0; i < 19; i++)
        msks[primes[i]] = 1 << i;

    for (int i = 2; i <= M; i++) {
        if (pr[i] < i) {
            msks[i] = msks[i / pr[i]] ^ msks[pr[i]];
        }
    }
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        nums[i] = msks[nums[i]];
    }

    vector<vector<int>> path(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        --u; --v;             
        path[u].push_back(v);
        path[v].push_back(u);
    }

    vector<int> depth(n, 0), parent(n, -1);
    queue<int> q;
    q.push(0);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : path[u]) {
            if (v == parent[u]) continue;
            parent[v] = u;
            depth[v] = depth[u] + 1;
            nums[v] ^= nums[u];
            q.push(v);
        }
    }
    const int LOG = 20;
    vector<vector<int>> nth_parent(LOG, vector<int>(n, -1));
    nth_parent[0] = parent;

    for (int i = 0; i < LOG - 1; i++) {
        for (int j = 0; j < n; j++) {
            if (nth_parent[i][j] >= 0)
                nth_parent[i + 1][j] = nth_parent[i][nth_parent[i][j]];
        }
    }

    auto lca = [&](int x, int y) {
        if (depth[x] > depth[y]) swap(x, y);

        int d = depth[y] - depth[x];
        while (d) {
            int v = d & -d;
            int k = __builtin_ctz(v);
            y = nth_parent[k][y];
            d -= v;
        }

        if (x == y) return x;

        for (int i = LOG - 1; i >= 0; i--) {
            if (nth_parent[i][x] != nth_parent[i][y]) {
                x = nth_parent[i][x];
                y = nth_parent[i][y];
            }
        }
        return parent[x];
    };

    int Q;
    cin >> Q;
    while (Q--) {
        int u, v;
        cin >> u >> v;
        --u; --v;

        int L = lca(u, v);
        int val = nums[u] ^ nums[v] ^ nums[L];
        if (L > 0) val ^= nums[parent[L]];

        cout << (val ? 1 : 0) << '\n';
    }

    return 0;
}
