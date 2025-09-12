#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;
typedef pair<int, int> pii;
typedef long double db;

int n;
pii A[MAXN + 5];

db tmp[MAXN + 5];

int calc(db tim) {
    for (int i = 1; i <= n; i++) tmp[i] = A[i].first + tim * A[i].second;
    int ret = 0;
    db mn = 1e200;
    for (int i = n; i > 0; i--) {
        if (mn <= tmp[i]) ret++;
        mn = min(mn, tmp[i]);
    }
    return ret;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d%d", &A[i].first, &A[i].second);
    sort(A + 1, A + n + 1);

    int mn = 2e9, cnt = 0;
    for (int i = n; i > 0; i--) {
        if (mn < A[i].second) cnt++;
        mn = min(mn, A[i].second);
    }

    db head = 0, tail = 2e9;
    for (int t = 1; t <= 100; t++) {
        db mid = (head + tail) / 2;
        if (calc(mid) == cnt) tail = mid;
        else head = mid;
    }
    printf("%.6Lf\n", (head + tail) / 2);
    return 0;
}
