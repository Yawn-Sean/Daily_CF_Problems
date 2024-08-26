#include <bits/stdc++.h>
#define MAXN 1000
using namespace std;

int n, Y[MAXN + 10];

bool check(int xa, int xb) {
    int K = (Y[xb] - Y[xa]) / (xb - xa);
    int x = -1;
    for (int i = 2; i <= n; i++) {
        if (1LL * (i - 1) * K + Y[1] == Y[i]) continue;
        else {
            if (x == -1) x = i;
            else if (1LL * (i - x) * K + Y[x] == Y[i]) continue;
            else return false;
        }
    }
    return x > 0;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &Y[i]), Y[i] *= 2;
    if (check(1, 2) || check(1, 3) || check(2, 3)) printf("Yes\n");
    else printf("No\n");
    return 0;
}
