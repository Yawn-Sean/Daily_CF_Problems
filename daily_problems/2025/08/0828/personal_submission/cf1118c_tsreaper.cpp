#include <bits/stdc++.h>
#define MAXN 20
using namespace std;
typedef pair<int, int> pii;

int n, ans[MAXN + 5][MAXN + 5];

int main() {
    scanf("%d", &n);
    
    unordered_map<int, int> cnt;
    for (int i = 1; i <= n * n; i++) {
        int x; scanf("%d", &x);
        cnt[x]++;
    }
    priority_queue<pii> pq;
    for (auto &p : cnt) pq.push({p.second, p.first});

    auto gao = [&](int i, int j, int v) {
        pii p = pq.top(); pq.pop();
        if (p.first < v) return false;
        p.first -= v;
        if (p.first > 0) pq.push(p);
        ans[i][j] = ans[i][n + 1 - j] = ans[n + 1 - i][j] = ans[n + 1 - i][n + 1 - j] = p.second;
        return true;
    };

    if (n & 1) {
        for (int i = 1; i <= n / 2; i++) for (int j = 1; j <= n / 2; j++) {
            if (gao(i, j, 4)) continue;
            printf("NO\n"); return 0;
        }
        for (int i = 1; i <= n / 2; i++) {
            if (gao(i, n / 2 + 1, 2)) continue;
            printf("NO\n"); return 0;
        }
        for (int j = 1; j <= n / 2; j++) {
            if (gao(n / 2 + 1, j, 2)) continue;
            printf("NO\n"); return 0;
        }
        if (!gao(n / 2 + 1, n / 2 + 1, 1)) {
            printf("NO\n"); return 0;
        }
    } else {
        for (int i = 1; i <= n / 2; i++) for (int j = 1; j <= n / 2; j++) {
            if (gao(i, j, 4)) continue;
            printf("NO\n"); return 0;
        }
    }

    printf("YES\n");
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) printf("%d%c", ans[i][j], "\n "[j < n]);
    return 0;
}
