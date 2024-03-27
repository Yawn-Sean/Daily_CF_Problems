/**
 * Created by 5cm/s on 2024/03/26 14:53:06.
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
    int n, m, q;
    cin >> n >> m >> q;
    DSU dsu(n + m);
    vector<vector<int>> row(n), col(m);
    while (q--) {
        int x, y;
        cin >> x >> y, x--, y--;
        dsu.join(x, y + n);
        row[x].emplace_back(y);
        col[y].emplace_back(x);
    }
    int ans = -1;
    for (auto &it: row) {
        ans += it.empty();
        for (int i = 0; i + 1 < it.size(); ++i) {
            dsu.join(it[i] + n, it[i + 1] + n);
        }
    }
    for (auto &it: col) {
        ans += it.empty();
        for (int i = 0; i + 1 < it.size(); ++i) {
            dsu.join(it[i], it[i + 1]);
        }
    }
    for (int i = 0; i < n + m; ++i) {
        if (dsu[i] == i && !(i < n ? row[i] : col[i - n]).empty()) {
            ans++;
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
