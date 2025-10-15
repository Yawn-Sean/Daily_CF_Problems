#include <bits/stdc++.h>
#define MAXN 50
using namespace std;

int n, ans[MAXN + 5];
long long K;

long long f[MAXN + 5];

int main() {
    scanf("%d%lld", &n, &K);
    f[0] = 1; f[1] = 1;
    for (int i = 2; i <= n; i++) f[i] = f[i - 1] + f[i - 2];

    for (int i = 1; i <= n; ) {
        if (f[n - i] >= K) {
            ans[i] = i;
            i++;
        } else {
            K -= f[n - i];
            ans[i] = i + 1; ans[i + 1] = i;
            i += 2;
        }
    }

    for (int i = 1; i <= n; i++) printf("%d%c", ans[i], "\n "[i < n]);
    return 0;
}
