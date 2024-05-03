#include <bits/stdc++.h>
#define MAXN ((int) 3e5)
using namespace std;

int n, m, A[MAXN + 10];

bool check(int lim) {
    for (int i = 1, now = 0; i <= n; i++) {
        int t = (A[i] + lim) % m;
        if (t >= A[i]) {
            if (now > t) return false;
            now = max(now, A[i]);
        } else {
            if (now > t) now = max(now, A[i]);
        }
    }
    return true;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);

    int head = 0, tail = m - 1;
    while (head < tail) {
        int mid = (head + tail) >> 1;
        if (check(mid)) tail = mid;
        else head = mid + 1;
    }
    printf("%d\n", head);
    return 0;
}
