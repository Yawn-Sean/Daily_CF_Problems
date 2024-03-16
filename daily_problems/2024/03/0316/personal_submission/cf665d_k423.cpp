/**
 * Created by 5cm/s on 2024/03/16 10:22:15.
 * 诸天神佛，佑我上分！
 **/
#include <bits/stdc++.h>

using namespace std;

#define itr(it) begin(it), end(it)
#define endl '\n'
#define YES() void(cout << "YES\n")
#define NO() void(cout << "NO\n")

void elysia() {
    int n, k = 0;
    cin >> n;
    vector<int> a(n);
    for (int &x: a) cin >> x, k += x == 1;
    sort(itr(a));
    int m = n == 1 ? a[n - 1] * 2 : a[n - 1] + a[n - 2];
    vector<int> pri, fac(m + 1);
    for (int i = 2; i <= m; ++i) {
        if (!fac[i]) pri.emplace_back(i), fac[i] = i;
        for (auto p: pri) {
            if (p * i > m) break;
            fac[p * i] = p;
            if (fac[i] == p) break;
        }
    }
    vector<int> ans(k, 1);
    if (k > 1) {
        for (int &x: a) {
            if (x != 1 && fac[x + 1] == x + 1) {
                ans.emplace_back(x);
                break;
            }
        }
    } else {
        int v1 = 0, v2 = 0;
        for (int i = 0; !v1 && i < n; ++i) {
            for (int j = i + 1; !v1 && j < n; ++j) {
                if (fac[a[i] + a[j]] == a[i] + a[j]) {
                    v1 = a[i], v2 = a[j];
                }
            }
        }
        if (v1) {
            ans = {v1, v2};
        } else {
            ans = {a[0]};
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " \n"[i + 1 == ans.size()];
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
//    cin >> T;
    cout << fixed << setprecision(12);
    while (T--) elysia();
#ifdef MEGURINE
    cout << "\nRunning Time: " << double(clock() - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
    return 0;
}
