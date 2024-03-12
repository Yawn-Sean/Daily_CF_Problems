/**
 * Created by 5cm/s on 2024/03/11 11:24:25.
 * 诸天神佛，佑我上分！
 **/
#include <bits/stdc++.h>

using namespace std;

#define itr(it) begin(it), end(it)
#define endl '\n'
#define YES() void(cout << "YES\n")
#define NO() void(cout << "NO\n")

class DSU {
    vector<int> fa, sz;
public:
    explicit DSU(int n) : fa(n), sz(n, 1) { iota(begin(fa), end(fa), 0); }

    int find(int i) { return i == fa[i] ? i : (fa[i] = find(fa[i])); }

    void join(int i, int j) {
        int a = find(i), b = find(j);
        if (a == b) return;
        if (sz[a] < sz[b]) swap(a, b);
        fa[b] = a, sz[a] += sz[b];
    }

    int operator[](const int i) { return find(i); }

    int size(int i) { return sz[find(i)]; }

    void reset(int n) {
        fa.resize(n), sz.resize(n);
        iota(begin(fa), end(fa), 0);
        fill(begin(sz), end(sz), 1);
    }
};

void elysia() {
    int n;
    cin >> n;
    vector<int> p(n + 1);
    DSU dsu(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> p[i], dsu.join(i, p[i]);
    bool flag = false;
    for (int i = 1; i <= n; ++i) {
        if (dsu[i] == i) {
            if (dsu.size(i) == 1) {
                YES();
                for (int j = 1; j <= n; ++j) {
                    if (j != i) {
                        cout << i << ' ' << j << endl;
                    }
                }
                return;
            } else if (dsu.size(i) == 2 && !flag) {
                flag = true;
                bool ok = true;
                for (int j = 1; j <= n; ++j) {
                    if (dsu[j] == j) ok &= dsu.size(j) % 2 == 0;
                }
                if (!ok) continue;
                YES();
                vector<int> id;
                for (int j = 1; j <= n; ++j) {
                    if (dsu[j] == i) {
                        if (j != i) {
                            cout << i << ' ' << j << endl;
                        }
                        id.emplace_back(j);
                    }
                }
                for (int j = 1; j <= n; ++j) {
                    if (dsu[j] == j && i != j) {
                        for (int t = dsu.size(j), v = j; t; --t, v = p[v]) {
                            cout << id[t & 1] << ' ' << v << endl;
                        }
                    }
                }
                return;
            }
        }
    }
    NO();
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
