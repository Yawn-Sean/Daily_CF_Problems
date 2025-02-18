#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;
typedef pair<int, int> pii;

int n, X, m, T, A[MAXN + 5], B[MAXN + 5][3];

int calc(int lim) {
    if (lim == 0) return X + 1;
    vector<pii> vec;
    for (int i = 1; i <= m; i++) if (B[i][2] > A[lim]) vec.push_back({B[i][0], B[i][1]});
    sort(vec.begin(), vec.end());
    
    int ret = X + 1, L = 1, R = 0;
    for (pii p : vec) {
        if (p.first > R) ret += (R - L + 1) * 2, L = p.first;
        R = max(R, p.second);
    }
    ret += (R - L + 1) * 2;
    return ret;
}

int main() {
    scanf("%d%d%d%d", &n, &X, &m, &T);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    sort(A + 1, A + n + 1, greater<int>());
    for (int i = 1; i <= m; i++) for (int j = 0; j < 3; j++) scanf("%d", &B[i][j]);

    int head = 0, tail = n;
    while (head < tail) {
        int mid = (head + tail + 1) >> 1;
        if (calc(mid) <= T) head = mid;
        else tail = mid - 1;
    }
    printf("%d\n", head);
    return 0;
}
