#include <bits/stdc++.h>
#define MAXN 500
#define EPS (1e-12)
using namespace std;

int n, m, A[MAXN + 10];

vector<int> e[MAXN + 10], v[MAXN + 10];

bool check(long double f) {
    for (int sn = 1; sn <= n; sn++) for (int i = 0; i < e[sn].size(); i++) {
        int fn = e[sn][i];
        if (A[sn] + A[fn] - v[sn][i] * f >= 0) return true;
    }
    return false;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    for (int i = 1; i <= m; i++) {
        int x, y, z; scanf("%d%d%d", &x, &y, &z);
        e[x].push_back(y); v[x].push_back(z);
        e[y].push_back(x); v[y].push_back(z);
    }

    if (m == 0) { printf("0\n"); return 0; }
    long double head = 0, tail = 2e6;
    while (tail - head > EPS) {
        long double mid = (head + tail) / 2;
        if (check(mid)) head = mid;
        else tail = mid;
    }
    printf("%.12Lf\n", (head + tail) / 2);
    return 0;
}
