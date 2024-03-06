/**
 * Created by 5cm/s on 2024/03/05 10:28:54.
 * 诸天神佛，佑我上分！
 **/
#include <bits/stdc++.h>

using namespace std;

#define itr(it) begin(it), end(it)
#define endl '\n'
#define YES() void(cout << "YES\n")
#define NO() void(cout << "NO\n")

template<typename T>
class fenwick {
private:
    vector<T> fenw;
    int n;
public:
    explicit fenwick(int _n) : n(_n), fenw(_n) {
        assert(_n >= 0);
    }

    void modify(int x, T v) {
        for (int i = x; i < n; i |= i + 1)
            fenw[i] += v;
    }

    T get(int x) {
        T v{};
        for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
            v += fenw[i];
        return v;
    }

    T get(int l, int r) {
        return get(r) - get(l - 1);
    }
};

using i64 = int64_t;

void elysia() {
    int n;
    cin >> n;
    map<int, vector<int>> mp;
    vector<int> xs;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        mp[y].emplace_back(x);
        xs.emplace_back(x);
    }
    ranges::sort(xs);
    xs.erase(unique(itr(xs)), xs.end());
    i64 ans = 0;
    int m = xs.size();
    fenwick<int> fcc(m);
    for (auto &[_, xx]: mp | views::reverse) {
        ranges::sort(xx);
        xx.erase(unique(itr(xx)), xx.end());
        for (int &x: xx) {
            x = ranges::lower_bound(xs, x) - xs.begin();
            if (!fcc.get(x, x)) fcc.modify(x, 1);
        }
        xx.emplace_back(m);
        for (int i = 0; i + 1 < xx.size(); ++i) {
            ans += i64(fcc.get(xx[i])) * fcc.get(xx[i], xx[i + 1] - 1);
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
