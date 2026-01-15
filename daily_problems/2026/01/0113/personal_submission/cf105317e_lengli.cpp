#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MAXM = 70;
const int LOG = 20;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> spf(MAXM + 1);
    for (int i = 0; i <= MAXM; i++) spf[i] = i;

    vector<int> primes;
    for (int i = 2; i <= MAXM; i++) {
        if (spf[i] == i) {
            primes.push_back(i);
            for (int j = i; j <= MAXM; j += i) {
                spf[j] = i;
            }
        }
    }

    int k = primes.size(); 

    vector<int> mask(MAXM + 1, 0);
    for (int i = 0; i < k; i++) {
        mask[primes[i]] = 1 << i;
    }
    for (int i = 2; i <= MAXM; i++) {
        if (spf[i] < i) {
            mask[i] = mask[i / spf[i]] ^ mask[spf[i]];
        }
    }

    int n;
    ll L;
    cin >> n >> L;

    int FULL = 1 << k;
    vector<int> dp(FULL, 100);
    vector<ll> rem(FULL, 1);

    dp[0] = 1;

    for (int s = 0; s < FULL; s++) {
        for (int j = 0; j < k; j++) {
            if (s & (1 << j)) continue;

            int ns = s | (1 << j);
            int x = dp[s];
            ll y = rem[s];

            if (y * primes[j] <= L) {
                y *= primes[j];
            } else {
                x++;
                y = primes[j];
            }

            if (x < dp[ns] || (x == dp[ns] && y < rem[ns])) {
                dp[ns] = x;
                rem[ns] = y;
            }
        }
    }

    dp[0] = 0;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums[i] = mask[x];
    }

    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> depth(n, 0), parent(n, -1);
    queue<int> q;
    q.push(0);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) {
            if (v == parent[u]) continue;
            parent[v] = u;
            depth[v] = depth[u] + 1;
            nums[v] ^= nums[u];
            q.push(v);
        }
    }

    vector<vector<int>> up(LOG, vector<int>(n, -1));
    up[0] = parent;

    for (int i = 1; i < LOG; i++) {
        for (int j = 0; j < n; j++) {
            if (up[i - 1][j] >= 0) {
                up[i][j] = up[i - 1][up[i - 1][j]];
            }
        }
    }

    auto lca = [&](int x, int y) {
        if (depth[x] > depth[y]) swap(x, y);

        int d = depth[y] - depth[x];
        for (int i = 0; i < LOG; i++) {
            if (d & (1 << i)) {
                y = up[i][y];
            }
        }

        if (x == y) return x;

        for (int i = LOG - 1; i >= 0; i--) {
            if (up[i][x] != up[i][y]) {
                x = up[i][x];
                y = up[i][y];
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

        int w = lca(u, v);
        int val = nums[u] ^ nums[v] ^ nums[w];
        if (w > 0) val ^= nums[parent[w]];

        cout << dp[val] << '\n';
    }

    return 0;
}
