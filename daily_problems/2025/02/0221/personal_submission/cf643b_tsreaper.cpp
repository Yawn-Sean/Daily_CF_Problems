#include <bits/stdc++.h>
#define MAXN 1000
using namespace std;

int n, K, A, B, C, D;

int main() {
    scanf("%d%d%d%d%d%d", &n, &K, &A, &B, &C, &D);
    if (n == 4 || K < n + 1) { printf("-1\n"); return 0; }

    vector<int> vec;
    for (int i = 1; i <= n; i++) if (i != A && i != B && i != C && i != D) vec.push_back(i);
    
    printf("%d %d ", A, C);
    for (int x : vec) printf("%d ", x);
    printf("%d %d\n", D, B);

    printf("%d %d ", C, A);
    for (int x : vec) printf("%d ", x);
    printf("%d %d\n", B, D);

    return 0;
}
