/**
 * Created by 5cm/s on 2024/01/21 15:17:23.
 * 诸天神佛，佑我上分！
 **/
#include <bits/stdc++.h>

using namespace std;

#define itr(it) begin(it), end(it)
#define endl '\n'
#define YES() void(cout << "YES\n")
#define NO() void(cout << "NO\n")

void elysia() {
    int n, l, r, s;
    cin >> n >> l >> r >> s;
    int m = (r - l + 1);
    int mn = (1 + m) * m / 2, mx = (n - m + 1 + n) * m / 2;
    if (s < mn || s > mx) {
        cout << -1 << endl;
        return;
    }
    l--, r--;
    vector<int> p(n);
    iota(p.begin() + l, p.begin() + r + 1, 1);
    s -= mn;
    for (int i = r, j = n; i >= l; --i, --j) {
        int k = min(j - p[i], s);
        s -= k, p[i] += k;
    }
    vector<int> vis(n + 1);
    for (int &x: p) vis[x] = 1;
    for (int i = 0, x = 1; i < n; ++i) {
        if (!p[i]) {
            while (vis[x]) x++;
            vis[p[i] = x] = 1;
        }
        cout << p[i] << " \n"[i == n - 1];
    }
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