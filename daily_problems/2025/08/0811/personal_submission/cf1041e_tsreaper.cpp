#include <bits/stdc++.h>
constexpr int MAXN = 1000;
using namespace std;

int n, A[MAXN + 5], cnt[MAXN + 5];

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int x, y; scanf("%d%d", &x, &y);
        if (x > y) swap(x, y);
        if (x == n || y != n) { printf("NO\n"); return 0; }
        cnt[x]++;
    }

    A[1] = n;
    for (int i = n - 1, j = 1, k = 1; i > 0; i--) {
        if (cnt[i]) {
            j += cnt[i];
            A[j] = i;
        } else {
            while (k <= j && A[k]) k++;
            if (k > j) { printf("NO\n"); return 0; }
            A[k] = i;
        }
    }
    
    printf("YES\n");
    for (int i = 1; i < n; i++) printf("%d %d\n", A[i], A[i + 1]);
    return 0;
}
