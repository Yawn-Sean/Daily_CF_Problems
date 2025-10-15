#include <bits/stdc++.h>
#define MAXA 255
using namespace std;

int A[MAXA + 5];

int main() {
    int n, K; scanf("%d%d", &n, &K);
    memset(A, -1, sizeof(A));
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        int ans = A[x];
        if (ans < 0) {
            int y = max(0, x - K + 1);
            if (A[y] < 0) {
                for (int i = y; i <= x; i++) A[i] = y;
            } else {
                for (y = x; A[y] < 0; y--);
                if (x - A[y] < K) {
                    y++;
                    for (int i = y; i <= x; i++) A[i] = A[i - 1];
                } else {
                    y++;
                    for (int i = y; i <= x; i++) A[i] = y;
                }
            }
            ans = A[x];
        }
        printf("%d%c", ans, "\n "[i < n]);
    }
    return 0;
}
