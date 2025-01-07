#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, m;
long long XA, XB;
array<long long, 2> A[MAXN + 5];
array<long long, 3> B[MAXN + 5];

double calc(int p, int q) {
    return
        sqrt(XA * XA + A[p][0] * A[p][0]) + sqrt((XB - XA) * (XB - XA) +
        (B[q][0] - A[p][0]) * (B[q][0] - A[p][0])) +
        B[q][1];
}

int main() {
    scanf("%d%d%lld%lld", &n, &m, &XA, &XB);
    for (int i = 1; i <= n; i++) scanf("%lld", &A[i][0]), A[i][1] = i;
    sort(A + 1, A + n + 1);
    for (int i = 1; i <= m; i++) scanf("%lld", &B[i][0]);
    for (int i = 1; i <= m; i++) scanf("%lld", &B[i][1]), B[i][2] = i;
    sort(B + 1, B + m + 1);

    double best = 1e300;
    int ans1, ans2;
    for (int i = 1; i <= m; i++) {
        int head = 1, tail = n;
        while (tail - head > 5) {
            int mid1 = head + (tail - head) / 3;
            int mid2 = head + (tail - head) / 3 * 2;
            if (calc(mid1, i) > calc(mid2, i)) head = mid1;
            else tail = mid2;
        }
        while (head <= tail) {
            double d = calc(head, i);
            if (d < best) best = d, ans1 = A[head][1], ans2 = B[i][2];
            head++;
        }
    }
    printf("%d %d\n", ans1, ans2);
    return 0;
}
