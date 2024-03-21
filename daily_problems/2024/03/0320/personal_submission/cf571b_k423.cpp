/**
 * Created by 5cm/s on 2024/03/20 09:53:53.
 * 诸天神佛，佑我上分！
 **/
#include <bits/stdc++.h>

using namespace std;

#define itr(it) begin(it), end(it)
#define endl '\n'
#define YES() void(cout << "YES\n")
#define NO() void(cout << "NO\n")

template<typename T>
T chmax(T &a, T b) { return a > b ? a : (a = b); }

template<typename T>
T chmin(T &a, T b) { return a < b ? a : (a = b); }

void elysia() {
    int n, k, inf = 2e9 + 1;
    cin >> n >> k;
    vector<int> a(n);
    for (int &x: a) cin >> x;
    ranges::sort(a);
    int m = n / k, s = n % k, t = k - s;
    vector f(t + 1, inf);
    f[0] = 0;
    for (int i = 0; i <= s; ++i) {
        for (int j = 0; j < t; ++j) {
            int id = i * (m + 1) + j * m;
            chmin(f[j + 1], f[j] + a[id + m - 1] - a[id]);
        }
        if (i < s) {
            vector h(t + 1, inf);
            for (int j = 0; j <= t; ++j) {
                int id = i * (m + 1) + j * m;
                chmin(h[j], f[j] + a[id + m] - a[id]);
            }
            h.swap(f);
        }
    }
    cout << f[t] << endl;
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
