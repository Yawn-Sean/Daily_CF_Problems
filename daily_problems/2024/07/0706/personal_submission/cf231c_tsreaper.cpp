#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, K, ans1, ans2, A[MAXN + 10];

int main() {
    scanf("%d%d", &n, &K);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    
    sort(A + 1, A + n + 1);
    long long sm = 0;
    int cnt = 0;
    for (int i = 1, j = 1; i <= n; i++) {
        sm += 1LL * cnt * (A[i] - A[i - 1]);
        cnt++;
        while (j < i && sm > K) {
            sm -= (A[i] - A[j]);
            cnt--;
            j++;
        }
        if (cnt > ans1) ans1 = cnt, ans2 = A[i];
    }
    printf("%d %d\n", ans1, ans2);
    return 0;
}
