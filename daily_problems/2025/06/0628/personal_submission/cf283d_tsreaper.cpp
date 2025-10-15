#include <bits/stdc++.h>
#define MAXN 5000
using namespace std;

int n, ans;
long long A[MAXN + 5];

int f[MAXN + 5], two[MAXN + 5];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &A[i]);
        for (; A[i] % 2 == 0; A[i] /= 2) two[i]++;
    }

    ans = n;
    for (int i = 1; i <= n; i++) {
        f[i] = i - 1;
        for (int j = 1; j < i; j++) if (A[j] % A[i] == 0) {
            bool good = false;
            if (two[i] > 0) {
                if (two[j] > 0) {
                    if (i - j - 1 >= two[i]) good = true;
                    if (two[j] <= two[i] && i - j == two[i] - two[j]) good = true;
                } else {
                    if (i - j >= two[i]) good = true;
                }
            } else {
                good = true;
            }
            if (good) f[i] = min(f[i], f[j] + i - j - 1);
        }
        ans = min(ans, f[i] + n - i);
    }
    printf("%d\n", ans);
    return 0;
}
