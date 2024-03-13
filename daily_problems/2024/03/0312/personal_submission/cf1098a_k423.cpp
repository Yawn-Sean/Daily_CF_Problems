/**
 * Created by 5cm/s on 2024/03/12 15:01:32.
 * 诸天神佛，佑我上分！
 **/
#include <bits/stdc++.h>

using namespace std;

#define itr(it) begin(it), end(it)
#define endl '\n'
#define YES() void(cout << "YES\n")
#define NO() void(cout << "NO\n")

void elysia() {
    int n;
    cin >> n;
    vector<int> p(n, -1), s(n), f(n, 1e9 + 1);
    for (int i = 1; i < n; ++i) cin >> p[i], p[i]--;
    for (int &x: s) cin >> x;
    int64_t ans = s[0];
    for (int i = n - 1; i; --i) {
        if (s[i] == -1) {
            if (f[i] > 1e9) {
                s[i] = s[p[i]];
            } else if (f[i] < s[p[i]]) {
                ans = -1;
                break;
            } else {
                s[i] = f[i];
            }
        } else {
            f[p[i]] = min(f[p[i]], s[i]);
        }
    }
    if (ans >= 0) {
        for (int i = 1; i < n; ++i)
            ans += s[i] - s[p[i]];
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
