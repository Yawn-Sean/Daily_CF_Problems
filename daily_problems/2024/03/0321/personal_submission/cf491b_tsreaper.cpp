#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
#define MAXM ((int) 1e5)
#define INF ((long long) 1e18)
using namespace std;

int n, m, A[MAXN + 10][2], B[MAXN + 10][2];

vector<int> calc(long long lim) {
    long long U = -INF, D = INF, L = -INF, R = INF;
    for (int i = 1; i <= n; i++) {
        U = max(U, A[i][0] - A[i][1] - lim);
        D = min(D, A[i][0] - A[i][1] + lim);
        L = max(L, A[i][0] + A[i][1] - lim);
        R = min(R, A[i][0] + A[i][1] + lim);
    }
    if (U > D || L > R) return {};

    vector<int> ret;
    for (int i = 1; i <= m; i++)
        if (U <= B[i][0] - B[i][1] && D >= B[i][0] - B[i][1] && L <= B[i][0] + B[i][1] && R >= B[i][0] + B[i][1])
            ret.push_back(i);
    return ret;
}

int main() {
    scanf("%*d%*d%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d%d", &A[i][0], &A[i][1]);
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) scanf("%d%d", &B[i][0], &B[i][1]);

    long long head = 0, tail = 2e9;
    while (head < tail) {
        long long mid = (head + tail) >> 1;
        if (calc(mid).size() > 0) tail = mid;
        else head = mid + 1;
    }

    printf("%lld\n%d\n", head, calc(head)[0]);
    return 0;
}
