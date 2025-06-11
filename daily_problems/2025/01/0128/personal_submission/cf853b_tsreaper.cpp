#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
#define INF ((long long) 1e18)
using namespace std;

int n, m, K;
long long ans;
array<int, 4> A[MAXN + 5];

struct S {
    int cnt;
    long long sm;
    multiset<int> ms[MAXN + 5];

    S(): cnt(0), sm(0) {}

    void add(int pos, int val) {
        if (ms[pos].empty()) cnt++;
        else sm -= *(ms[pos].begin());
        ms[pos].insert(val);
        sm += *(ms[pos].begin());
    }

    void del(int pos, int val) {
        sm -= *(ms[pos].begin());
        ms[pos].erase(ms[pos].find(val));
        if (ms[pos].empty()) cnt--;
        else sm += *(ms[pos].begin());
    }
} L, R;

int main() {
    scanf("%d%d%d", &n, &m, &K);
    for (int i = 1; i <= m; i++) for (int j = 0; j < 4; j++) scanf("%d", &A[i][j]);
    sort(A + 1, A + m + 1);

    ans = INF;
    for (int i = 1; i <= m; i++) if (A[i][1] == 0) R.add(A[i][2], A[i][3]);
    for (int i = 1, j = 1; i <= m; i++) {
        if (A[i][2] == 0) L.add(A[i][1], A[i][3]);
        while (j <= m && A[j][0] - A[i][0] <= K) {
            if (A[j][1] == 0) R.del(A[j][2], A[j][3]);
            j++;
        }
        if (L.cnt == n && R.cnt == n) ans = min(ans, L.sm + R.sm);
    }

    if (ans < INF) printf("%lld\n", ans);
    else printf("-1\n");
    return 0;
}
