#include <bits/stdc++.h>

using namespace std;
using int64 = long long;
constexpr int N = 300'000;
int a[2][N];
int64 si[2][N + 1];
int64 fw[2][N + 1];
int64 bw[2][N + 1];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[0][i];
    }
    for (int i = 0; i < n; i++) {
        cin >> a[1][i];
    }
    si[0][0] = 0;
    si[1][0] = 0;
    fw[0][0] = 0;
    bw[1][0] = 0;
    for (int i = 1; i <= n; i++) {
        si[0][i] = si[0][i - 1] + a[0][i - 1];
        si[1][i] = si[1][i - 1] + a[1][i - 1];
        fw[0][i] = fw[0][i - 1] + 1LL * a[0][i - 1] * (i - 1);
        bw[1][i] = bw[1][i - 1] + 1LL * a[1][i - 1] * (i - 1);
    }
    fw[1][n] = 0;
    bw[0][n] = 0;
    for (int i = n - 1; i >= 0; i--) {
        fw[1][i] = fw[1][i + 1] + 1LL * a[1][i] * (n * 2 - i - 1);
        bw[0][i] = bw[0][i + 1] + 1LL * a[0][i] * (n * 2 - i - 1);
    }
    int64 ans = 0LL, curr = 0LL;
    for (int i = 0, j = 0, flip = 0; i < n; i++, flip ^= 1) {
        if (i % 2 == 0) {
            int64 t1 = fw[0][n] - fw[0][i] + 1LL * (si[0][n] - si[0][i]) * (j - i);
            int64 t2 = fw[1][i] + 1LL * (si[1][n] - si[1][i]) * (j - i);
            ans = max(ans, t1 + t2 + curr);
        } else {
            int64 t1 = bw[1][n] - bw[1][i] + 1LL * (si[1][n] - si[1][i]) * (j - i);
            int64 t2 = bw[0][i] + 1LL * (si[0][n] - si[0][i]) * (j - i);
            ans = max(ans, t1 + t2 + curr);
        }
        curr += 1LL * a[0 ^ flip][i] * (j++);
        curr += 1LL * a[1 ^ flip][i] * (j++);
    }
    cout << ans << "\n";
    return 0;
}

