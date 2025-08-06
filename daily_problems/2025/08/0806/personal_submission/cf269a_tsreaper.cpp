#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;
typedef pair<int, int> pii;

int n;
pii A[MAXN + 5];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d%d", &A[i].first, &A[i].second);
    sort(A + 1, A + n + 1);

    long long rem = A[1].second;
    for (int i = 2; i <= n; i++) {
        long long p = 1;
        for (int j = 1; j <= A[i].first - A[i - 1].first && p <= rem; j++) p *= 4;
        rem = (rem + p - 1) / p;
        long long t = min(1LL * A[i].second, rem);
        rem += A[i].second - t;
    }

    long long p = 1;
    for (int i = 1; ; i++) {
        p *= 4;
        if (p >= rem) { printf("%d\n", A[n].first + i); break; }
    }
    return 0;
}
