#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, A; scanf("%d%d%*d", &n, &A);
    unordered_map<long long, unordered_map<int, int>> mp;
    for (int i = 1; i <= n; i++) {
        int x, y; scanf("%*d%d%d", &x, &y);
        mp[1LL * A * x - y][x]++;
    }
    long long ans = 0;
    for (auto &p : mp) {
        long long tot = 0;
        for (auto &q : p.second) tot += q.second;
        for (auto &q : p.second) ans += 1LL * q.second * (tot - q.second);
    }
    printf("%lld\n", ans);
    return 0;
}
