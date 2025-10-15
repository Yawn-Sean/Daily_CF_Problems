#include <bits/stdc++.h>
#define MAXN 100
using namespace std;

int n, X, Y;
char s[MAXN + 5];

int main() {
    scanf("%d%d%s", &X, &Y, s + 1); n = strlen(s + 1);
    if (X == 0 && Y == 0) { printf("Yes\n"); return 0; }
    
    int dx = 0, dy = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'U') dy++;
        else if (s[i] == 'D') dy--;
        else if (s[i] == 'L') dx--;
        else dx++;
        if (X == dx && Y == dy) { printf("Yes\n"); return 0; }
    }
    if (dx == 0 && dy == 0) { printf("No\n"); return 0; }

    long long K = 1e9;
    if (dx) K = min(K, 1LL * (abs(X) - 200) / abs(dx));
    if (dy) K = min(K, 1LL * (abs(Y) - 200) / abs(dy));
    K = max(K, 0LL);
    long long x = K * dx, y = K * dy;
    for (int r = 1; r <= 500; r++) {
        for (int i = 1; i <= n; i++) {
            if (s[i] == 'U') y++;
            else if (s[i] == 'D') y--;
            else if (s[i] == 'L') x--;
            else x++;
            if (X == x && Y == y) { printf("Yes\n"); return 0; }
        }
    }
    printf("No\n");
    return 0;
}
