/**
 * Created by 5cm/s on 2024/03/19 09:23:27.
 * 诸天神佛，佑我上分！
 **/
#include <bits/stdc++.h>

using namespace std;

#define itr(it) begin(it), end(it)
#define endl '\n'
#define YES() void(cout << "YES\n")
#define NO() void(cout << "NO\n")

using i64 = int64_t;

void elysia() {
    i64 x, y, p, q;
    cin >> x >> y >> p >> q;
    if (p == q && x < y || !p && x) {
        cout << -1 << endl;
        return;
    }
    if (y == 0) {
        cout << q << endl;
        return;
    }
    i64 z = q / gcd(q, y);
    i64 lo = max(i64(1), (y - 1) / q + 1), hi = 9e18 / q;
    while (lo < hi) {
        i64 mid = (lo + hi) / 2;
        i64 a = mid * p, b = mid * q;
        if (a - x <= b - y && (b - a) - (y - x) <= b - y) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    cout << lo * q - y << endl;
}

int main() {
#ifdef MEGURINE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    clock_t start = clock();
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    cout << fixed << setprecision(12);
    while (T--) elysia();
#ifdef MEGURINE
    cout << "\nRunning Time: " << double(clock() - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
    return 0;
}
