#include <bits/stdc++.h>

using namespace std;
constexpr int N = 100;
char grid[4][N];

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        grid[0][i] = grid[1][i] = grid[2][i] = grid[3][i] = '.';
    }
    for (int j = 1; k >= 2 && j <= 2; j++) {
        for (int i = 1; k >= 2 && i < n / 2; i++) {
            grid[j][i] = grid[j][n - i - 1] = '#';
            k -= 2;
        }
    }
    if (k) {
        grid[1][n / 2] = '#';
        if (--k) {
            grid[2][n / 2] = '#';
        }
    }
    printf("YES\n");
    for (int i = 0; i < 4; i++) {
        grid[i][n] = '\0';
        printf("%s\n", grid[i]);
    }
    return 0;
}

