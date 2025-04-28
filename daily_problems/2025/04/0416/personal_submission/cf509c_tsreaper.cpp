#include <bits/stdc++.h>
#define MAXA 300
using namespace std;

int len, A[MAXA * 2 + 5];

bool tryy(int x, int d, int i) {
    x -= d;
    if (x >= 0 && x <= 9 * (i - 1)) {
        A[i] = d;
        for (int j = 1; j < i; j++) {
            if (x >= 9) A[j] = 9, x -= 9;
            else A[j] = x, x = 0;
        }
        return true;
    } else {
        return false;
    }
}

void gao() {
    int x; scanf("%d", &x);
    for (int i = 1; i <= len; i++) x -= A[i];
    for (int i = 1; i <= len; i++) {
        x += A[i];
        for (int d = A[i] + 1; d <= 9; d++) if (tryy(x, d, i)) return;
    }
    for (len++; ; len++) {
        for (int d = 1; d <= 9; d++) if (tryy(x, d, len)) return;
    }
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        gao();
        for (int i = len; i > 0; i--) printf("%d", A[i]);
        printf("\n");
    }
}
