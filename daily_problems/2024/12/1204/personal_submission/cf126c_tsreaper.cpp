#include <bits/stdc++.h>
#define MAXN 2000
using namespace std;

int n, ans;
char MAP[MAXN + 5][MAXN + 5];

int R[MAXN + 5], C[MAXN + 5];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%s", MAP[i] + 1);
    for (int i = 1; i < n; i++) for (int j = n; j > i; j--) {
        MAP[i][j] ^= R[i] ^ C[j];
        if (MAP[i][j] == '1') {
            ans++;
            R[i] ^= 1; C[j] ^= 1;
            MAP[i][i] ^= 1; MAP[j][j] ^= 1;
        }
    }
    for (int i = 1; i <= n; i++) R[i] = C[i] = 0;
    for (int i = n; i > 1; i--) for (int j = 1; j < i; j++) {
        MAP[i][j] ^= R[i] ^ C[j];
        if (MAP[i][j] == '1') {
            ans++;
            R[i] ^= 1; C[j] ^= 1;
            MAP[i][i] ^= 1; MAP[j][j] ^= 1;
        }
    }
    for (int i = 1; i <= n; i++) if (MAP[i][i] == '1') ans++;
    printf("%d\n", ans);
    return 0;
}
