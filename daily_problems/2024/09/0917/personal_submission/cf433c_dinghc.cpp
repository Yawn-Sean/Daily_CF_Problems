#include <bits/stdc++.h>

using namespace std;
constexpr int N = 100'000;
int a[N];
vector<int> b[N + 1];
long long cost[N + 1];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    long long tot = 0LL;
    scanf("%d", &a[0]);
    for (int i = 1; i < m; i++) {
        scanf("%d", &a[i]);
        if (a[i] != a[i - 1]) {
            b[a[i]].push_back(a[i - 1]);
            b[a[i - 1]].push_back(a[i]);
            tot += abs(a[i] - a[i - 1]);
            cost[a[i]] += abs(a[i] - a[i - 1]);
            cost[a[i - 1]] += abs(a[i] - a[i - 1]);
        }
    }
    long long ans = tot;
    for (int x = 1; x <= n; x++) {
        int k = b[x].size();
        if (k == 0) continue;
        ranges::sort(b[x]);
        int y = b[x][k / 2];
        long long curr = tot - cost[x];
        for (int i = 0; i < k; i++) {
            curr += abs(b[x][i] - y);
        }
        ans = min(ans, curr);
    }
    printf("%lld\n", ans);
    return 0;
}

