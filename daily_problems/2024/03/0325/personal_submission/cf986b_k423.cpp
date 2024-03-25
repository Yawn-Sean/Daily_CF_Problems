/**
 * Created by 5cm/s on 2024/03/25 10:41:13.
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

    /**
     * 找到满足条件的最小索引
     */
    template<typename Fn>
    int partition(Fn fn) {
        int k = __lg(n | 1), j = -1;
        T tot{};
        for (int i = 1 << k; i; i >>= 1) {
            if (j + i < n && !fn(j + i, tot + fenw[j + i])) {
                tot += fenw[j += i];
            }
        }
        return j + 1;
    }
};

void elysia() {
    int n;
    cin >> n;
    int64_t inv = 0;
    fenwick<int> fcc(n);
    for (int i = 0, x; i < n; ++i) {
        cin >> x, x--;
        inv += i - fcc.get(x);
        fcc.modify(x, 1);
    }
    if (inv % 2 == n % 2) {
        cout << "Petr" << endl;
    } else {
        cout << "Um_nik" << endl;
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
