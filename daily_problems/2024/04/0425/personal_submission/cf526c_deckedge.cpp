#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pi pair<int, int>
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int64_t c, hr, hb, wr, wb, res = 0;
    cin >> c >> hr >> hb >> wr >> wb;
    int i;
    if (wr > wb) {
        swap(wr, wb);
        swap(hr, hb);
    }

    if (wb > sqrt(c)) {
        for (i = 0; i <= c / wb; i++) {
            res = max(res, i * hb + (c - i * wb) / wr * hr);
        }
    } else {
        if (hr * 1.0 / wr > hb * 1.0 / wb) {
            swap(wr, wb), swap(hr, hb);
        }
        for (i = 0; i <= wb; i++) {
            res = max(res, i * hr + (c - i * wr) / wb * hb);
        }
    }

    cout << res << '\n';
    return 0;
}

