#include <bits/stdc++.h>
#define MAXN 5000
using namespace std;

int n, ans1, ans2, A[MAXN + 5];

int f[MAXN + 5];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);

    int base = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) if (A[j] > A[i]) f[i]++;
        base += f[i];
    }
    ans1 = 1e9;
    for (int i = 1; i <= n; i++) {
        int now = base;
        for (int j = i + 1; j <= n; j++) {
            int tmp = now - f[j] + (j - i - f[j]);
            if (tmp < ans1) ans1 = tmp, ans2 = 1;
            else if (tmp == ans1) ans2++;
            if (A[j] > A[i]) now++;
            else now--;
        }
        for (int j = i + 1; j <= n; j++) if (A[i] > A[j]) f[j]--;
    }
    printf("%d %d\n", ans1, ans2);
    return 0;
}
