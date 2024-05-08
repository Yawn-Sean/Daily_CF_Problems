#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = std::pair<int, int>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 c, hr, hb, wr, wb;
    std::cin >> c >> hr >> hb >> wr >> wb;

    i64 ans = 0;
    for (i64 i = 0; i * i <= c; ++i) {
        i64 res_r = 0;
        i64 res_b = 0;
        if (c - i * wr > 0) {
            res_r = i * hr + (c - i * wr) / wb * hb;
        }

        if (c - i * wb > 0) {
            res_b = i * hb + (c - i * wb) / wr * hr;
        }
        ans = max({ ans, res_r, res_b });
    }

    cout << ans << endl;

    return 0;
}