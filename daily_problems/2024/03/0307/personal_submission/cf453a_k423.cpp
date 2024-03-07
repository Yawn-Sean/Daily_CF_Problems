/**
 * Created by 5cm/s on 2024/03/07 10:09:35.
 * 诸天神佛，佑我上分！
 **/
#include <bits/stdc++.h>

using namespace std;

#define itr(it) begin(it), end(it)
#define endl '\n'
#define YES() void(cout << "YES\n")
#define NO() void(cout << "NO\n")

using ld = long double;

ld qPow(ld a, int b) {
    ld ret = 1;
    while (b) {
        if (b & 1) ret = ret * a;
        b >>= 1;
        a = a * a;
    }
    return ret;
}


void elysia() {
    int m, n;
    cin >> m >> n;
    // (k^m-(k-1)^m)*k
    ld pre = 0, cur = 1, ans = 0;
    for (int k = 1; k <= m; ++k) {
        cur = qPow(ld(k) / m, n);
        ans += (cur - pre) * k;
        pre = cur;
    }
    cout << ans << endl;
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
//    cin >> T;
    cout << fixed << setprecision(12);
    while (T--) elysia();
#ifdef MEGURINE
    cout << "\nRunning Time: " << double(clock() - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
    return 0;
}
