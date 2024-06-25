#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;
 
int n, A[MAXN + 10];
int Y;
 
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]), A[i]--;
    for (int i = 2; i <= n; i++) {
        int det = abs(A[i] - A[i - 1]);
        if (det == 0) {
            printf("NO\n"); return 0;
        } else if (det == 1) {
            continue;
        } else if (Y > 0 && det != Y) {
            printf("NO\n"); return 0;
        } else {
            Y = det;
        }
    }
 
    Y = max(Y, 1);

    for (int i = 2; i <= n; i++) {
        int det = abs(A[i] - A[i - 1]);
        if (det == 1) {
            if (Y > 1 && A[i] / Y != A[i - 1] / Y) { printf("NO\n"); return 0; }
        }
    }

    printf("YES\n%d %d\n", (int) 1e9, Y);
    return 0;
}
