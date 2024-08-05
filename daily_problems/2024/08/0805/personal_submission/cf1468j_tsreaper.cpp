#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
#define MAXM ((int) 2e5)
using namespace std;

int n, m, K;

vector<array<int, 3>> small, big;
int root[MAXN + 10];

int findroot(int x) {
    if (root[x] != x) root[x] = findroot(root[x]);
    return root[x];
}

void solve() {
    scanf("%d%d%d", &n, &m, &K);
    small.clear(); big.clear();
    for (int i = 1; i <= m; i++) {
        int x, y, z; scanf("%d%d%d", &x, &y, &z);
        if (z < K) small.push_back({z, x, y});
        else big.push_back({z, x, y});
    }

    sort(small.begin(), small.end());
    sort(big.begin(), big.end());
    if (big.empty()) { printf("%d\n", K - small.back()[0]); return; }

    for (int i = 1; i <= n; i++) root[i] = i;
    int cnt = 0;
    for (auto &arr : small) {
        int x = findroot(arr[1]), y = findroot(arr[2]);
        if (x == y) continue;
        root[y] = x; cnt++;
    }
    if (cnt == n - 1) { printf("%d\n", min(K - small.back()[0], big[0][0] - K)); return; }

    long long ans = 0;
    for (auto &arr : big) {
        int x = findroot(arr[1]), y = findroot(arr[2]);
        if (x == y) continue;
        ans += arr[0] - K;
        root[y] = x;
    }
    printf("%lld\n", ans);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
