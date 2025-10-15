#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, K, A[MAXN + 5], B[MAXN + 5];

bool check(int t) {
    for (int i = n - t + 1, j = n; i <= n; i++, j--) if (A[i] + B[j] < K) return false;
    return true;
}

int main() {
    scanf("%d%d", &n, &K);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &B[i]);
    
    sort(A + 1, A + n + 1); sort(B + 1, B + n + 1);
    int head = 1, tail = n;
    while (head < tail) {
        int mid = (head + tail + 1) >> 1;
        if (check(mid)) head = mid;
        else tail = mid - 1;
    }
    printf("1 %d\n", head);
    return 0;
}
