#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int x, y;
    cin >> x >> y;

    vector<pair<int, int>> pts;

    for (int i = 0; i < n - 1; i ++) {
        int nx, ny;
        cin >> nx >> ny;

        pts.emplace_back(nx - x, ny - y);
        x = nx, y = ny;
    }

    if (n == 1) {
        cout << "YES\n";
        cout << "1 0\n";
        cout << "0 1\n";
        return 0;
    }

    stable_sort(pts.begin(), pts.end(), [&] (pair<int, int> x, pair<int, int> y) {
        return 1ll * x.first * y.second < 1ll * x.second * y.first;
    });

    auto [x1, y1] = *pts.begin();
    auto [x2, y2] = *pts.rbegin();

    int vx, vy;

    if (1ll * x1 * x2 + 1ll * y1 * y2 >= 0)
        vx = x1 + x2, vy = y1 + y2;
    else {
        int vx1 = y1, vy1 = -x1;
        if (1ll * vx1 * x2 + 1ll * vy1 * y2 < 0) vx1 = -vx1, vy1 = -vy1;
        int vx2 = y2, vy2 = -x2;
        if (1ll * vx2 * x1 + 1ll * vy2 * y1 < 0) vx2 = -vx2, vy2 = -vy2;
        vx = vx1 + vx2, vy = vy1 + vy2;
    }

    for (auto &[x, y]: pts) {
        if (1ll * vx * x + 1ll * vy * y <= 0) {
            return cout << "NO", 0;
        }
    }

    cout << "YES\n";
    cout << vx << ' ' << vy << '\n';
    cout << -vy << ' ' << vx << '\n';

    return 0;
}