#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n, X, Y;
char s[MAXN + 10];

int f[MAXN + 10][2];

bool check(int len) {
    for (int i = 1, j = len; j <= n; i++, j++) {
        int dx = f[i - 1][0] + f[n][0] - f[j][0];
        int dy = f[i - 1][1] + f[n][1] - f[j][1];
        int rx = abs(X - dx), ry = abs(Y - dy);
        if (rx + ry <= len) return true;
    }
    return false;
}

int main() {
    scanf("%d%s%d%d", &n, s + 1, &X, &Y);
    if (n % 2 != abs(X + Y) % 2 || n < abs(X) + abs(Y)) { printf("-1\n"); return 0; }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 2; j++) f[i][j] = f[i - 1][j];
        if (s[i] == 'U') f[i][1]++;
        else if (s[i] == 'D') f[i][1]--;
        else if (s[i] == 'L') f[i][0]--;
        else f[i][0]++;
    }
    if (f[n][0] == X && f[n][1] == Y) { printf("0\n"); return 0; }

    int head = 1, tail = n;
    while (head < tail) {
        int mid = (head + tail) >> 1;
        if (check(mid)) tail = mid;
        else head = mid + 1;
    }
    printf("%d\n", head);
    return 0;
}
