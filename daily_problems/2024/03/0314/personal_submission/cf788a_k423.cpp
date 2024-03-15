/**
 * Created by 5cm/s on 2024/03/14 10:10:24.
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
    int n;
    cin >> n;
    vector<i64> a(n);
    for (i64 &x: a) cin >> x;
    i64 ans = 0;
    for (int k = 0; k < 2; ++k) {
        i64 cur = 0;
        for (int i = k; i + 1 < n; ++i) {
            i64 x = abs(a[i + 1] - a[i]);
            if ((i - k) % 2) x = -x;
            cur = max(cur + x, x);
            ans = max(ans, cur);
        }
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
