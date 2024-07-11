#include <bits/stdc++.h>
#define MAXN 3000
using namespace std;

int n, m;
long long ans;

vector<int> e[MAXN + 10];
int cnt[MAXN + 10][MAXN + 10];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int x, y; scanf("%d%d", &x, &y);
        e[x].push_back(y);
    }

    for (int x = 1; x <= n; x++) for (int y : e[x]) for (int z : e[y]) cnt[x][z]++;
    for (int x = 1; x <= n; x++) for (int z = 1; z <= n; z++) if (x != z) ans += 1LL * cnt[x][z] * (cnt[x][z] - 1) / 2;
    printf("%lld\n", ans);
    return 0;
}
