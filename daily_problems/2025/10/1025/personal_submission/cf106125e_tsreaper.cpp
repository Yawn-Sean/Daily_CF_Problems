#include <bits/stdc++.h>
#define MAXN 1000
using namespace std;

int n, A[MAXN + 5];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= 125; i++) {
        int best = -1e9, l = 1, r = 1;
        int mn = 0, pos = 0, now = 0;
        for (int j = 1; j <= n; j++) {
            if (A[j] == 0) now++;
            else now--;
            if (now - mn > best) best = now - mn, l = pos + 1, r = j;
            if (now < mn) mn = now, pos = j;
        }
        printf("%d %d\n", l, r); fflush(stdout);

        for (int j = 1; j <= n; j++) scanf("%d", &A[j]);
        int t; scanf("%d", &t);
        if (t >= 70) break;
    }
    return 0;
}
