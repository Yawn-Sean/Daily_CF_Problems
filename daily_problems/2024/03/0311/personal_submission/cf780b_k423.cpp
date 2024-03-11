/**
 * Created by 5cm/s on 2024/03/11 11:18:58.
 * 诸天神佛，佑我上分！
 **/
#include <bits/stdc++.h>

using namespace std;

#define itr(it) begin(it), end(it)
#define endl '\n'
#define YES() void(cout << "YES\n")
#define NO() void(cout << "NO\n")

using ld = long double;

void elysia() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int &x: a) cin >> x;
    for (int &x: b) cin >> x;
    ld lo = 0, hi = 1e9;
    for (int k = 0; k < 80; ++k) {
        ld mid = (lo + hi) / 2;
        ld l = -1e18, r = 1e18;
        for (int i = 0; i < n; ++i) {
            l = max(l, ld(a[i]) - b[i] * mid);
            r = min(r, ld(a[i]) + b[i] * mid);
        }
        if (l > r) lo = mid;
        else hi = mid;
    }
    cout << lo << endl;
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
