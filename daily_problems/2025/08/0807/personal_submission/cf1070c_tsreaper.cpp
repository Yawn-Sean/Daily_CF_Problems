#include <bits/stdc++.h>
#define MAXN ((int) 1e6)
using namespace std;

int n, m, K;
long long ans;

long long tree[2][MAXN + 5];

int lb(int x) { return x & (-x); }

void add(long long *tree, int pos, long long val) {
    for (; pos <= n; pos += lb(pos)) tree[pos] += val;
}

long long query(long long *tree, int pos) {
    long long ret = 0;
    for (; pos; pos -= lb(pos)) ret += tree[pos];
    return ret;
}

int search(long long *tree, long long target) {
    int ret = 0;
    for (int p = __lg(n); p >= 0; p--) {
        int nxt = ret | (1 << p);
        if (nxt <= n && tree[nxt] < target) target -= tree[ret = nxt];
    }
    return ret;
}

int main() {
    scanf("%*d%d%d", &K, &m);

    map<int, vector<array<int, 3>>> mp;
    for (int i = 1; i <= m; i++) {
        int l, r, c, p; scanf("%d%d%d%d", &l, &r, &c, &p);
        n = max(n, p);
        mp[l].push_back({c, p, 1});
        mp[r + 1].push_back({c, p, -1});
    }

    int last = 1;
    for (auto &p : mp) {
        int len = p.first - last;
        if (query(tree[0], n) < K) ans += len * query(tree[1], n);
        else {
            int pos = search(tree[0], K);
            int rem = K - query(tree[0], pos);
            ans += len * (query(tree[1], pos) + 1LL * rem * (pos + 1));
        }
        last = p.first;

        auto &vec = p.second;
        for (auto &arr : vec) {
            add(tree[0], arr[1], arr[0] * arr[2]);
            add(tree[1], arr[1], 1LL * arr[0] * arr[1] * arr[2]);
        }
    }
    printf("%lld\n", ans);
    return 0;
}
