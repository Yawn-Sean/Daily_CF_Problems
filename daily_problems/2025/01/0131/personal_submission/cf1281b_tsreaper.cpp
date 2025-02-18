#include <bits/stdc++.h>
#define MAXN 5000
using namespace std;

int n, m;
char s1[MAXN + 5], s2[MAXN + 5];

int f[MAXN + 5];

void solve() {
    scanf("%s%s", s1 + 1, s2 + 1);
    n = strlen(s1 + 1); m = strlen(s2 + 1);
    if (strcmp(s1 + 1, s2 + 1) < 0) { printf("%s\n", s1 + 1); return; }

    f[n - 1] = n;
    for (int i = n - 2; i > 0; i--)
        if (s1[i + 1] < s1[f[i + 1]]) f[i] = i + 1;
        else f[i] = f[i + 1];

    for (int i = 1; i < n; i++) {
        swap(s1[i], s1[f[i]]);
        if (strcmp(s1 + 1, s2 + 1) < 0) { printf("%s\n", s1 + 1); return; }
        swap(s1[i], s1[f[i]]);
    }
    printf("---\n");
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
