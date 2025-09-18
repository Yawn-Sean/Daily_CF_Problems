#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> pts(n);
    for (auto &[x, y]: pts) cin >> x >> y;

    long long total_area = 0;
    for (int i = 2; i < n; i ++) {
        int dx1 = pts[i - 1].first - pts[0].first, dy1 = pts[i - 1].second - pts[0].second;
        int dx2 = pts[i].first - pts[0].first, dy2 = pts[i].second - pts[0].second;
        total_area += 1ll * dx1 * dy2 - 1ll * dy1 * dx2;
    }

    __int128_t total_triangle_area = 0, one = 1;

    long long pref_x = 0, pref_y = 0, suff_x = 0, suff_y = 0;
    for (auto &[x, y]: pts) suff_x += x, suff_y += y;

    for (int i = 0; i < n; i ++) {
        auto [x, y] = pts[i];
        suff_x -= x, suff_y -= y;
        total_triangle_area += one * (1ll * i * x - pref_x) * (suff_y - 1ll * (n - i - 1) * y) - one * (1ll * i * y - pref_y) * (suff_x - 1ll * (n - i - 1) * x);
        pref_x += x, pref_y += y;
    }

    cout << fixed << setprecision(15) << (long double)1 * total_triangle_area / total_area;

    return 0;
}
