#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, X[MAXN + 5], Y[MAXN + 5];

int quad(int x, int y) {
    if (x > 0 && y >= 0) return 0;
    if (x <= 0 && y > 0) return 1;
    if (x < 0 && y <= 0) return 2;
    return 3;
}

long long cross(int xa, int ya, int xb, int yb) {
    return 1LL * xa * yb - 1LL * xb * ya;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d%d", &X[i], &Y[i]);
    if (n == 1) { printf("YES\n1 0\n0 1\n"); return 0; }

    vector<array<int, 3>> vec;
    for (int i = 1; i < n; i++) {
        int dx = X[i + 1] - X[i], dy = Y[i + 1] - Y[i];
        if (dx == 0 && dy == 0) { printf("NO\n"); return 0; }
        if (quad(dx, dy) >= 2) vec.push_back({1, 0, 1});
        vec.push_back({dx, dy, 1});
        vec.push_back({-dx, -dy, -1});
    }
    sort(vec.begin(), vec.end(), [&](auto &a, auto &b) {
        int qa = quad(a[0], a[1]), qb = quad(b[0], b[1]);
        if (qa != qb) return qa < qb;
        long long c = cross(a[0], a[1], b[0], b[1]);
        if (c != 0) return c > 0;
        return a[2] < b[2];
    });
    int cnt = 0;
    for (auto &arr : vec) {
        cnt += arr[2];
        if (cnt == n - 1) {
            printf("YES\n%d %d\n%d %d\n", arr[1], -arr[0], arr[0], arr[1]);
            return 0;
        }
    }

    vec.clear(); cnt = 0;
    for (int i = 1; i < n; i++) {
        int dx = X[i + 1] - X[i], dy = Y[i + 1] - Y[i];
        if (quad(dx, dy) <= 1) vec.push_back({(int) 1e9, -1, 1});
        vec.push_back({dx, dy, 1});
        vec.push_back({-dx, -dy, -1});
    }
    sort(vec.begin(), vec.end(), [&](auto &a, auto &b) {
        int qa = quad(a[0], a[1]), qb = quad(b[0], b[1]);
        if (qa != qb) return qa > qb;
        long long c = cross(a[0], a[1], b[0], b[1]);
        if (c != 0) return c < 0;
        return a[2] < b[2];
    });
    cnt = 0;
    for (auto &arr : vec) {
        cnt += arr[2];
        if (cnt == n - 1) {
            printf("YES\n%d %d\n%d %d\n", -arr[1], arr[0], arr[0], arr[1]);
            return 0;
        }
    }

    printf("NO\n");
    return 0;
}
