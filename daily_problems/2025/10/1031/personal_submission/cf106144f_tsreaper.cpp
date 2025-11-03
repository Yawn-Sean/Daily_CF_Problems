#include <bits/stdc++.h>
using namespace std;

void solve() {
    int sg[] = {-1, -1, 0, 1, -1, 0, 1, 2};
    int n; scanf("%d", &n);
    int t = 0;
    for (int i = 1; i <= n; i++) {
        char s[10]; scanf("%s", s);
        int msk = 0;
        for (int j = 0; j < 6; j++) if (s[j] != '=')
            msk = msk << 1 | (s[j] == 'x' ? 1 : 0);
        t ^= sg[msk];
    }
    if (t) printf("Monocarp\n");
    else printf("Polycarp\n");
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
