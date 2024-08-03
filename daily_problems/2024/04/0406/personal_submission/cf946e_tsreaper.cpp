#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n;
char s[MAXN + 10];

void solve() {
    scanf("%s", s + 1); n = strlen(s + 1);
    int msk = 0;
    for (int i = 1; i <= n; i++) msk ^= 1 << (s[i] - '0');
    if (n % 2 == 0) for (int i = n; i > 0; i--) {
        msk ^= 1 << (s[i] - '0');
        for (int j = s[i] - '0' - 1; j >= (i == 1 ? 1 : 0); j--) {
            int now = msk ^ (1 << j);
            int cnt = __builtin_popcount(now);
            if (cnt <= n - i) {
                for (int l = 1; l < i; l++) printf("%c", s[l]);
                printf("%d", j);
                for (int l = n - i - cnt; l > 0; l--) printf("9");
                for (int l = 9; l >= 0; l--) if (now >> l & 1) printf("%d", l);
                printf("\n");
                return;
            }
        }
    }
    for (int i = 1; i <= (n - 1) / 2 * 2; i++) printf("9");
    printf("\n");
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
