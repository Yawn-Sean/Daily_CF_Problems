#include <bits/stdc++.h>
#define MAXN 100
using namespace std;

int B, D, n, m;
char s1[MAXN + 5], s2[MAXN + 5];

int f[MAXN + 5][2];

int main() {
    scanf("%d%d%s%s", &B, &D, s1, s2);
    n = strlen(s1); m = strlen(s2);

    int idx = -1, r1 = 1, r2 = 0;
    while (true) {
        for (int i = 0; i < m; i++) {
            idx++;
            if (idx >= n) r1++, idx = 0;
            bool ok = false;
            for (int j = 0; j < n; j++) if (s1[(idx + j) % n] == s2[i]) {
                r1 += (idx + j) / n;
                idx = (idx + j) % n;
                ok = true;
                break;
            }
            if (!ok) { printf("0\n"); return 0; }
        }
        if (r1 > B) { printf("%d\n", r2 / D); return 0; }
        r2++;
        if (f[idx][0] > 0) break;
        f[idx][0] = r1; f[idx][1] = r2;
    }

    int len = r1 - f[idx][0];
    int ans = f[idx][1] + (B - f[idx][0]) / len * (r2 - f[idx][1]);
    r1 = f[idx][0] + (B - f[idx][0]) / len * len;

    while (true) {
        for (int i = 0; i < m; i++) {
            idx++;
            if (idx >= n) r1++, idx = 0;
            for (int j = 0; j < n; j++) if (s1[(idx + j) % n] == s2[i]) {
                r1 += (idx + j) / n;
                idx = (idx + j) % n;
                break;
            }
        }
        if (r1 > B) { printf("%d\n", ans / D); return 0; }
        ans++;
    }
}
