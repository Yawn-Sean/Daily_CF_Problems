#include <bits/stdc++.h>
#define MAXS ((int) 2e5)
using namespace std;

int n, m;
char s[MAXS + 10];
long long ans;

void solve() {
    scanf("%d%s", &n, s + 1); m = strlen(s + 1);

    int R = 1, C = 1;
    for (int i = 1; i <= m; i++) {
        if (s[i] == 'D') R++;
        else C++;
    }
    if (R == 1 || C == 1) { printf("%d\n", n); return; }

    ans = 0;
    bool flag = true;
    int r = 1;
    for (int i = 1; i <= m; i++) {
        if (s[i] == 'D') flag = false, r++;
        else {
            if (flag) ans += n - 1;
            else ans += R - r;
        }
    }

    flag = true;
    int c = 1;
    for (int i = 1; i <= m; i++) {
        if (s[i] == 'R') flag = false, c++;
        else {
            if (flag) ans += n - 1;
            else ans += C - c;
        }
    }

    printf("%lld\n", 1LL * n * n - ans);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
