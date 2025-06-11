#include <bits/stdc++.h>
#define MAXN 1000
#define EPS (1e-12)
using namespace std;
typedef long double db;

int n;
db P;

long long C[MAXN + 5][4];

db calc(int m) {
    db ret = 0;
    ret += 0.5 * C[n - m][2] * C[m][1] / C[n][3];
    ret += 1.0 * C[n - m][1] * C[m][2] / C[n][3];
    ret += 1.0 * C[m][3] / C[n][3];
    return ret;
}

int main() {
    scanf("%d%Lf", &n, &P);
    
    for (int i = 0; i <= n; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i && j <= 3; j++) C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }

    int head = 0, tail = n;
    while (head < tail) {
        int mid = (head + tail) >> 1;
        if (calc(mid) + EPS >= P) tail = mid;
        else head = mid + 1;
    }
    printf("%d\n", head);
    return 0;
}
