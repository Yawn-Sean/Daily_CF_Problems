#include <bits/stdc++.h>
#define MAXN 100
using namespace std;

int n, K;
char MAP[4][MAXN + 5];

int main() {
    scanf("%d%d", &n, &K);
    for (int i = 0; i < 4; i++) for (int j = 0; j < n; j++) MAP[i][j] = '.';
    if (K & 1) {
        MAP[1][n / 2] = '#';
        K--;
        for (int i = 1; i <= 2; i++) for (int j = 1; j < n / 2 && K > 0; j++, K -= 2)
            MAP[i][j] = MAP[i][n - 1 - j] = '#';
    } else {
        for (int j = 1; j < n - 1 && K > 0; j++, K -= 2) MAP[1][j] = MAP[2][j] = '#';
    }
    printf("YES\n");
    for (int i = 0; i < 4; i++) printf("%s\n", MAP[i]);
    return 0;
}
