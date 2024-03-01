/**
 * Created by 5cm/s on 2024/01/21 15:34:16.
 * 诸天神佛，佑我上分！
 **/
#include <bits/stdc++.h>

using namespace std;

#define itr(it) begin(it), end(it)
#define endl '\n'
#define YES() void(cout << "YES\n")
#define NO() void(cout << "NO\n")


constexpr int N = 1e7;
int f[N + 2];
// 约数的和
int __init__ = []{
    memset(f, -1, sizeof f);
    vector<int> pri, fac(N + 1);
    vector<int> f1(N + 1), f2(N + 1);
    f1[1] = 0, f2[1] = 1;
    for (int i = 2; i <= N; ++i) {
        if (!fac[i]) {
            pri.emplace_back(i), fac[i] = i;
            f1[i] = 1, f2[i] = i + 1;
        }
        for (auto p: pri) {
            if (p * i > N) break;
            fac[p * i] = p;
            f1[p * i] = i % p ? i : f1[i], f2[p * i] = f2[i] * p + 1;
            if (fac[i] == p) {
                f1[p * i] = f1[i];
                f2[p * i] = f2[i] * p + 1;
                break;
            } else {
                f1[p * i] = i;
                f2[p * i] = p + 1;
            }
        }
    }
    vector<int> d(N + 1, 1);
    for (int i = 1; i <= N; ++i) {
        int &x = d[i] = d[f1[i]] * f2[i];
        if (x <= N && f[x] == -1) f[x] = i;
    }
    return 0;
}();

void elysia() {
    int n;
    cin >> n;
    cout << f[n] << endl;
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