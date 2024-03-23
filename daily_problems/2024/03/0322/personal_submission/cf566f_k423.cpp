/**
 * Created by 5cm/s on 2024/03/22 11:07:37.
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
    vector<int> a(n);
    for (int &x: a) cin >> x;
    int m = ranges::max(a);
    vector<int> f(m + 1);
    for (int &x: a) f[x] = 1;
    for (int i = m - 1; i; --i) {
        if (!f[i]) continue;
        for (int j = i + i; j <= m; j += i) {
            f[i] = max(f[i], f[j] + 1);
        }
    }
    cout << ranges::max(f) << endl;
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
