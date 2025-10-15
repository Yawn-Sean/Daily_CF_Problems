#include <bits/stdc++.h>

using namespace std;
using int64 = long long;
constexpr int64 INF = LONG_LONG_MAX;
constexpr int N = 100'000;
int xs[N], ys[N];

int64 euclidean(int p, int q) {
    return 1LL * (xs[p] - xs[q]) * (xs[p] - xs[q]) + 1LL * (ys[p] - ys[q]) * (ys[p] - ys[q]);
}

int64 det(int p, int q, int r) {
    return abs((1LL * xs[p] * ys[q] - 1LL * ys[p] * xs[q])
        - (1LL * xs[p] * ys[r] - 1LL * ys[p] * xs[r]) 
        + (1LL * xs[q] * ys[r] - 1LL * ys[q] * xs[r]));
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &xs[i], &ys[i]);
    }
    int p = 0, q = 1;
    pair<int64, int> d1 {euclidean(p, q), q};
    pair<int64, int> d2 {INF, -1};
    for (int i = 2; i < n; i++) {
        int64 area = det(p, q, i);
        if (area == 0) {
            d1 = min(d1, make_pair(euclidean(p, i), i));
        } else {
            d2 = min(d2, make_pair(area, i));
        }
    }
    printf("%d %d %d\n", p + 1, d1.second + 1, d2.second + 1);
    return 0;
}

