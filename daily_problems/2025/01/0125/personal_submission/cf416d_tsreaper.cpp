#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n, ans;
long long A[MAXN + 5];

bool check(int l, int r, int p1, int p2) {
    long long d = A[p2] - A[p1];
    if (d % (p2 - p1)) return false;
    d /= p2 - p1;
    long long v1 = A[p1] - d * (p1 - l), v2 = A[p2] + d * (r - p2);
    if (v1 <= 0 || v2 <= 0) return false;
    if (A[r] > 0 && A[r] != v2) return false;
    return true;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", &A[i]);

    ans = 1;
    long long d;
    for (int i = 1, j = 1, p1 = 0, p2 = 0; i <= n; ) {
        if (A[i] > 0) {
            if (p1 == 0) p1 = i;
            else if (p2 == 0) p2 = i;
        }
        if (p1 > 0 && p2 > 0 && !check(j, i, p1, p2)) {
            ans++;
            j = i;
            p1 = p2 = 0;
            continue;
        } else {
            i++;
        }
    }

    printf("%d\n", ans);
    return 0;
}
