#include <bits/stdc++.h>
#define MAXM ((int) 1e6)
#define MAXLEN ((int) 1e6)
#define MOD ((int) 1e9 + 7)
using namespace std;

int n, m, A[MAXM + 10];
char s[MAXLEN + 10];

int f[MAXLEN + 10];
bool flag[MAXLEN + 10];

int main() {
    scanf("%d%d%s", &n, &m, s + 1);
    int len = strlen(s + 1);
    for (int i = 1; i <= m; i++) scanf("%d", &A[i]);
    sort(A + 1, A + m + 1);

    f[1] = 0;
    for (int i = 1; i < len; i++) {
        int j = f[i];
        while (j > 0 && s[i + 1] != s[j + 1]) j = f[j];
        f[i + 1] = j;
        if (s[i + 1] == s[j + 1]) f[i + 1]++;
    }

    for (int i = f[len]; i > 0; i = f[i]) flag[i] = true;
    for (int i = 2; i <= m; i++) {
        int t = A[i] - A[i - 1];
        if (t >= len) continue;
        t = len - t;
        if (!flag[t]) { printf("0\n"); return 0; }
    }

    int rem = n;
    for (int i = 1; i <= m; i++) {
        int t = min(len, A[i] - A[i - 1]);
        if (i == 1) t = len;
        rem -= t;
    }
    long long ans = 1;
    for (int i = 1; i <= rem; i++) ans = ans * 26 % MOD;
    printf("%lld\n", ans);
    return 0;
}
