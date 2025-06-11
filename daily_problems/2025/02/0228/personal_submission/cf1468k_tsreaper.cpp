#include <bits/stdc++.h>
#define MAXN 5000
using namespace std;

int n;
char s[MAXN + 5];

bool gao(int X, int Y) {
    int x = 0, y = 0;
    for (int i = 1; i <= n; i++) {
        int xx = x, yy = y;
        if (s[i] == 'U') yy++;
        else if (s[i] == 'D') yy--;
        else if (s[i] == 'L') xx--;
        else xx++;
        if (xx == X && yy == Y) xx = x, yy = y;
        x = xx; y = yy;
    }
    return x == 0 && y == 0;
}

void solve() {
    scanf("%s", s + 1); n = strlen(s + 1);
    int x = 0, y = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'U') y++;
        else if (s[i] == 'D') y--;
        else if (s[i] == 'L') x--;
        else x++;
        if (gao(x, y)) { printf("%d %d\n", x, y); return; }
    }
    printf("0 0\n");
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
