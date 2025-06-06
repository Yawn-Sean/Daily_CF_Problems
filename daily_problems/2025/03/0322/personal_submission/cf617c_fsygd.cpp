#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int n, X1, Y1, X2, Y2, X, Y;
long long dist1[2010], dist2[2010], suffix[2010], ans;
int idx[2010];

bool cmp(int A, int B) {
    return dist1[A] < dist1[B];
}

int main() {
    scanf("%d%d%d%d%d", &n, &X1, &Y1, &X2, &Y2);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &X, &Y);
        dist1[i] = (long long)(X - X1) * (X - X1) + (long long)(Y - Y1) * (Y - Y1);
        dist2[i] = (long long)(X - X2) * (X - X2) + (long long)(Y - Y2) * (Y - Y2);
        idx[i] = i;
    }
    sort(idx + 1, idx + n + 1, cmp);
    for (int i = n; i >= 1; --i) suffix[i] = max(suffix[i + 1], dist2[idx[i]]);
    ans = suffix[1];
    for (int i = 0; i <= n; ++i) ans = min(ans, dist1[idx[i]] + suffix[i + 1]);
    printf("%lld\n", ans);
    return 0;
}