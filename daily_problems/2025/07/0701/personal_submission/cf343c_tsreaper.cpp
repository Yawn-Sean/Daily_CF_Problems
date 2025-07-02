#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, m;
long long A[MAXN + 5], B[MAXN + 5];

bool check(long long lim) {
    int j = 1;
    for (int i = 1; i <= n && j <= m; i++) {
        long long R;
        if (A[i] <= B[j]) R = A[i] + lim;
        else {
            long long det = A[i] - B[j];
            if (det > lim) return false;
            R = A[i] + max(lim - det * 2, (lim - det) / 2);
        }
        while (j <= m && B[j] <= R) j++;
    }
    return j > m;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%lld", &A[i]);
    for (int i = 1; i <= m; i++) scanf("%lld", &B[i]);

    long long head = 0, tail = 1e11;
    while (head < tail) {
        long long mid = (head + tail) >> 1;
        if (check(mid)) tail = mid;
        else head = mid + 1;
    }
    printf("%lld\n", head);
    return 0;
}
