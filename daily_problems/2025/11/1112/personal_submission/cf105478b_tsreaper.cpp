#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, ans;
char s[MAXN + 5];

void solve() {
    scanf("%d%s", &n, s + 1);
    ans = 0;
    for (int i = 1, j = 0; i <= n; i++) if (s[i] != '?') {
        ans++;
        if (j > 0) {
            int len = i - j - 1;
            if (len == 1) {
                if (s[i] != s[j]) ans++;
            } else if (len > 1) {
                ans++;
            }
        }
        j = i;
    }
    printf("%d\n", ans);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
