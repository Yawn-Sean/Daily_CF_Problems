/**
 * Created by 5cm/s on 2024/03/19 09:55:55.
 * 诸天神佛，佑我上分！
 **/
#include <bits/stdc++.h>

using namespace std;

#define itr(it) begin(it), end(it)
#define endl '\n'
#define YES() void(cout << "YES\n")
#define NO() void(cout << "NO\n")

constexpr int N = 1e6;
vector<int> pri, fac(N + 1);
int __sieve__ = []() {
    for (int i = 2; i <= N; ++i) {
        if (!fac[i]) pri.emplace_back(i), fac[i] = i;
        for (auto p: pri) {
            if (p * i > N) break;
            fac[p * i] = p;
            if (fac[i] == p) break;
        }
    }
    return 0;
}();

void elysia() {
    int n, q;
    cin >> n >> q;
    map<int, int> cur, initial, d, initial_d;
    auto Add = [&](map<int, int> &mp, int x, int del) {
        while (x > 1) {
            int p = fac[x];
            while (p == fac[x]) x /= p, mp[p] += del;
            if (!mp[p]) mp.erase(p);
        }
    };
    function<void(int)> f = [&](int x) {
        int _x = x;
        while (x > 1) {
            int p = fac[x], c = 0;
            while (p == fac[x]) x /= p, c++;
            Add(d, cur[p] + 1, -1);
            cur[p] += c;
            Add(d, cur[p] + 1, 1);
        }
    };
    f(n);
    initial = cur, initial_d = d;
    while (q--) {
        int op;
        cin >> op;
        if (op == 2) {
            cur = initial, d = initial_d;
        } else {
            int x;
            cin >> x;
            f(x);
            bool ok = true;
            for (auto [p, c]: d) {
                if (!cur.count(p) || cur[p] < c) {
                    ok = false;
                    break;
                }
            }
            ok ? YES() : NO();
        }
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
