#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, A[MAXN + 5];

int calc(int x) {
    return x + (n + x - 1) / x;
}

int main() {
    scanf("%d", &n);
    int s = sqrt(n), best = s;
    for (int i = max(1, s - 2); i <= min(n, s + 2); i++)
        if (calc(i) < calc(best)) best = i;
    for (int i = 1, j = 1; j <= n; i++) {
        int pos = min(n, i * best);
        while (pos > 0 && A[pos] == 0) A[pos--] = j++;
    }
    for (int i = 1; i <= n; i++) printf("%d%c", A[i], "\n "[i < n]);
    return 0;
}
