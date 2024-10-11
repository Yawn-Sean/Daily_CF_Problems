#include <bits/stdc++.h>
#define MAXN ((int) 5e5)
#define MOD ((int) 1e9 + 7)
using namespace std;
typedef pair<int, int> pii;

int n, m, K;
long long ans, A[MAXN + 10];

long long P[MAXN + 10];
int root[MAXN + 10];

int findroot(int x) {
    if (root[x] != x) root[x] = findroot(root[x]);
    return root[x];
}

int main() {
    scanf("%d%d%d", &n, &m, &K);
    for (int i = 1; i <= n; i++) scanf("%lld", &A[i]);

    P[0] = 1;
    for (int i = 1; i <= n; i++) P[i] = P[i - 1] * 2 % MOD;

    unordered_map<long long, vector<pii>> mp;
    for (int i = 1; i <= m; i++) {
        int x, y; scanf("%d%d", &x, &y);
        mp[A[x] ^ A[y]].push_back({x, y});
    }

    for (int i = 1; i <= n; i++) root[i] = i;
    ans = ((1LL << K) - mp.size()) % MOD * P[n] % MOD;
    for (auto &entry : mp) {
        int cnt = n;
        for (pii p : entry.second) {
            int x = findroot(p.first), y = findroot(p.second);
            if (x == y) continue;
            root[x] = y;
            cnt--;
        }
        ans = (ans + P[cnt]) % MOD;
        for (pii p : entry.second) {
            root[p.first] = p.first;
            root[p.second] = p.second;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
