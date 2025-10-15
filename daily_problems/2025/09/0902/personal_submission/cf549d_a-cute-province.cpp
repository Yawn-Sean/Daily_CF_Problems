#include <bits/stdc++.h>
using namespace std;
int n, m;
char s[105][105];
int a[105][105], diff[105][105];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            a[i][j] = (s[i][j] == 'W' ? 1 : -1);

    int ans = 0;
    for (int i = n; i >= 1; i--) {
        for (int j = m; j >= 1; j--) {
            if (diff[i][j] != a[i][j]) {
                int delta = a[i][j] - diff[i][j];
                ans++;
                for (int x = 1; x <= i; x++) {
                    for (int y = 1; y <= j; y++) {
                        diff[x][y] += delta;
                    }
                }
            }
        }
    }
    printf("%d\n", ans);
}
