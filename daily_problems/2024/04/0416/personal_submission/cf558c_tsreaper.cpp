#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
#define MAXP 20
#define INF ((int) 1e9)
using namespace std;

int n;
vector<int> A[MAXN + 10];

int gao(int len) {
    int now = 0, cnt[MAXP + 5] = {0};
    for (int i = 1; i <= n; i++) {
        int t = A[i].size();
        if (t < len) return INF;
        for (int j = 0; j < len; j++) if (A[i][j] != A[1][j]) return INF;
        for (int j = len; j < t; j++) if (A[i][j] == 1) { t = j; break; }
        now += (int) A[i].size() - t;
        cnt[t - len]++;
    }
    int ret = INF;
    for (int p = 0; p < MAXP; p++) {
        int t = now;
        for (int j = 0; j < MAXP; j++) t += cnt[j] * abs(p - j);
        ret = min(ret, t);
    }
    return ret;
}

int main() {
    scanf("%d", &n);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        for (; x; x >>= 1) A[i].push_back(x & 1), ans++;
        reverse(A[i].begin(), A[i].end());
    }
    for (int len = 1; len <= A[1].size(); len++) ans = min(ans, gao(len));
    printf("%d\n", ans);
    return 0;
}
