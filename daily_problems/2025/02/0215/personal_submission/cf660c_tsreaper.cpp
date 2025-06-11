#include <bits/stdc++.h>
#define MAXN ((int) 3e5)
using namespace std;

int n, K, ans1, ans2, A[MAXN + 5];

int main() {
    scanf("%d%d", &n, &K);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);

    ans1 = 1; ans2 = 0;
    for (int i = 1, j = 1, cnt = 0; i <= n; i++) {
        if (A[i] == 0) cnt++;
        while (j <= i && cnt > K) {
            if (A[j] == 0) cnt--;
            j++;
        }
        if (i - j > ans2 - ans1) ans1 = j, ans2 = i;
    }

    printf("%d\n", ans2 - ans1 + 1);
    for (int i = 1; i <= n; i++) {
        if (i >= ans1 && i <= ans2) printf("1");
        else printf("%d", A[i]);
        printf("%c", "\n "[i < n]);
    }
    return 0;
}
