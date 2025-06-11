#include <bits/stdc++.h>
using namespace std;

int A[3], B[3], X[6];

int main() {
    for (int i = 0; i < 3; i++) scanf("%d", &A[i]);
    for (int i = 0; i < 3; i++) scanf("%d", &B[i]);
    for (int i = 0; i < 6; i++) scanf("%d", &X[i]);

    int ans = 0;
    if (A[1] < 0) ans += X[0];
    if (A[1] > B[1]) ans += X[1];
    if (A[2] < 0) ans += X[2];
    if (A[2] > B[2]) ans += X[3];
    if (A[0] < 0) ans += X[4];
    if (A[0] > B[0]) ans += X[5];
    printf("%d\n", ans);
    return 0;
}
