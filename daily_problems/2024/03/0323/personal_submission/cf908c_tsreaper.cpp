#include <bits/stdc++.h>
#define MAXN 1000
using namespace std;

int n, R, X[MAXN + 10];
double Y[MAXN + 10];

int main() {
    scanf("%d%d", &n, &R);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &X[i]);
        Y[i] = R;
        for (int j = 1; j < i; j++) {
            int dx = abs(X[i] - X[j]);
            double dy = sqrt(4 * R * R - dx * dx);
            Y[i] = max(Y[i], Y[j] + dy);
        }
        printf("%.12f%c", Y[i], "\n "[i < n]);
    }
    return 0;
}
