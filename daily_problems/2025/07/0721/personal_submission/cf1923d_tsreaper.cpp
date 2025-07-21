#include <bits/stdc++.h>
#define MAXN ((int) 3e5)
using namespace std;

int n, A[MAXN + 5];

long long f[MAXN + 5];
int prv[MAXN + 5], nxt[MAXN + 5];

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    A[n + 1] = 0;

    for (int i = 1; i <= n; i++) f[i] = f[i - 1] + A[i];
    for (int i = 1; i <= n; i++) {
        if (A[i] != A[i - 1]) prv[i] = i - 1;
        else prv[i] = prv[i - 1];
    }
    for (int i = n; i > 0; i--) {
        if (A[i] != A[i + 1]) nxt[i] = i + 1;
        else nxt[i] = nxt[i + 1];
    }

    for (int i = 1; i <= n; i++) {
        if (A[i] < A[i - 1] || A[i] < A[i + 1]) { printf("1%c", "\n "[i < n]); continue; }
        int ans = n + 1;

        if (prv[i - 1] > 0 && f[i - 1] > A[i]) {
            int head = 1, tail = prv[i - 1];
            while (head < tail) {
                int mid = (head + tail + 1) >> 1;
                if (f[i - 1] - f[mid - 1] > A[i]) head = mid;
                else tail = mid - 1;
            }
            ans = min(ans, i - head);
        }

        if (nxt[i + 1] <= n && f[n] - f[i] > A[i]) {
            int head = nxt[i + 1], tail = n;
            while (head < tail) {
                int mid = (head + tail) >> 1;
                if (f[mid] - f[i] > A[i]) tail = mid;
                else head = mid + 1;
            }
            ans = min(ans, head - i);
        }

        if (ans > n) ans = -1;
        printf("%d%c", ans, "\n "[i < n]);
    }
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
