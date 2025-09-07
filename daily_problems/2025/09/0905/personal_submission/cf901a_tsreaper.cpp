#include <bits/stdc++.h>
#define MAXH ((int) 1e5)
using namespace std;

int h, A[MAXH + 5];

bool check() {
    for (int i = 1; i < h; i++) {
        if (A[i] > 1 && A[i + 1] > 1) return false;
    }
    return true;
}

int main() {
    scanf("%d", &h);
    for (int i = 0; i <= h; i++) scanf("%d", &A[i]);
    if (check()) printf("perfect\n");
    else {
        printf("ambiguous\n0");
        for (int i = 1, t = 1; i <= h; i++) {
            for (int j = 1; j <= A[i]; j++) printf(" %d", t);
            t += A[i];
        }
        printf("\n0");
        for (int i = 1, x = 1, y = 1; i <= h; i++) {
            for (int j = 1; j <= A[i] / 2; j++) printf(" %d", x);
            for (int j = A[i] / 2 + 1; j <= A[i]; j++) printf(" %d", y);
            x += A[i - 1]; y += A[i];
        }
        printf("\n");
    }
    return 0;
}
