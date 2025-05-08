#include <bits/stdc++.h>
using namespace std;

int ans[4][1000];

void solve() {
    char s[20]; scanf("%s", s);
    int n = atoi(s + 4);
    int len = strlen(s + 4);
    if (len <= 3) printf("%d\n", ans[len][n]);
    else {
        long long x = 0, y = 1;
        for (int i = 5; i <= len; i++) x = x * 10 + 1, y *= 10;
        x = x * 10000 + 3099; y *= 10000;
        if (n % y < x) printf("1%s\n", s + 4);
        else printf("%s\n", s + 4);
    }
}

int main() {
    for (int i = 1989; i < 1999; i++) ans[1][i % 10] = i;
    for (int i = 1999; i < 2099; i++) ans[2][i % 100] = i;
    for (int i = 2099; i < 3099; i++) ans[3][i % 1000] = i;

    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
