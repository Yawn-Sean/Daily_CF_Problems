#include <bits/stdc++.h>

using namespace std;
constexpr int N = 100'000;
int R[N+1], C[N+1];

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    R[0] = 0;
    for (int i = 0, x; i < n; i++) {
        scanf("%d", &x);
        R[i + 1] = R[i] + x % 2;
    }
    C[0] = 0;
    for (int i = 0, x; i < n; i++) {
        scanf("%d", &x);
        C[i + 1] = C[i] + x % 2;
    }
    for (int i = 0, r1, c1, r2, c2; i < q; i++) {
        scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
        if (r1 > r2) swap(r1, r2);
        if (c1 > c2) swap(c1, c2);
        if ((R[r2] - R[r1 - 1] == 0 || R[r2] - R[r1 - 1] == r2 - r1 + 1) 
            && (C[c2] - C[c1 - 1] == 0 || C[c2] - C[c1 - 1] == c2 - c1 + 1)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}

