#include <bits/stdc++.h>
#define MAXN 250000
#define MAXP 20
using namespace std;
typedef pair<int, int> pii;

int n, A[MAXN * 2];
long long ans;

pii rmq[MAXP][MAXN * 2];
int nxt[MAXN * 2][MAXP];

int query(int l, int r) {
    int p = __lg(r - l + 1);
    return max(rmq[p][l], rmq[p][r - (1 << p) + 1]).second;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[n - i]);
    
    for (int i = 0; i < n; i++) A[n + i] = A[i];
    for (int i = 0; i < n * 2; i++) rmq[0][i] = pii(i + A[i], i);
    for (int p = 1, len = 2; p < MAXP; p++, len *= 2) for (int i = 0, j = len - 1; j < n * 2; i++, j++)
        rmq[p][i] = max(rmq[p - 1][i], rmq[p - 1][i + len / 2]);

    for (int p = 0; p < MAXP; p++) nxt[n * 2 - 1][p] = n * 2 - 1;
    for (int i = n * 2 - 2; i >= 0; i--) {
        int r = min(n * 2 - 1, i + A[i]);
        nxt[i][0] = query(i + 1, r);
        for (int p = 1; p < MAXP; p++) nxt[i][p] = nxt[nxt[i][p - 1]][p - 1];
    }

    for (int i = 0; i < n; i++) {
        if (A[i] >= n - 1) { ans++; continue; }
        for (int p = MAXP - 1, now = i; p >= 0; p--) {
            int t = nxt[now][p];
            if (t + A[t] - i < n - 1) {
                ans += 1 << p;
                now = t;
            }
        }
        ans += 2;
    }
    printf("%lld\n", ans);
    return 0;
}
