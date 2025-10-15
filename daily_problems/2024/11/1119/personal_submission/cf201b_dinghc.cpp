#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int64> cx(n, 0);
    vector<int64> cy(m, 0);
    int64 a = 0, b1 = 0, b2 = 0, c = 0;
    for (int i = 0, e; i < n; i++) {
        int xi = i * 4 + 2;
        for (int j = 0; j < m; j++) {
            int yj = j * 4 + 2;
            cin >> e;
            a += e;
            b1 += 1LL * e * 2 * xi;
            b2 += 1LL * e * 2 * yj;
            c += 1LL * e * xi * xi;
            c += 1LL * e * yj * yj;
        }
    }
    auto solve = [&] (int64 a, int64 b) -> int64 {
        if (a == 0) return 0;
        int64 x = b / (8 * a);
        return abs(8 * a * x - b) <= abs(8 * a * (x + 1) - b) ? x : x + 1;
    };
    int64 x = solve(a, b1) * 4;
    int64 y = solve(a, b2) * 4;
    cout << a * (x * x + y * y) - b1 * x - b2 * y + c << "\n";
    cout << x / 4 << " " << y / 4 << "\n";
    return 0;
}
