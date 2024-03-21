/**
 * Created by 5cm/s on 2024/03/18 10:10:54.
 * 诸天神佛，佑我上分！
 **/
#include <bits/stdc++.h>

using namespace std;

#define itr(it) begin(it), end(it)
#define endl '\n'
#define YES() void(cout << "YES\n")
#define NO() void(cout << "NO\n")

using i64 = int64_t;
using ld = long double;

struct vec {
    i64 x, y;

    vec(i64 x = 0, i64 y = 0) : x(x), y(y) {}

    vec &operator-=(const vec &p) {
        x -= p.x, y -= p.y;
        return *this;
    }

    vec operator-(const vec &p) const { return {x - p.x, y - p.y}; }

    i64 operator^(const vec &p) const { return x * p.y - y * p.x; }

    i64 abs2() const { return x * x + y * y; }

    long double abs() const { return sqrt(ld(abs2())); }

    bool operator<(const vec &p) const {
        return x == p.x ? y < p.y : x < p.x;
    }
};

void elysia() {
    int n;
    cin >> n;
    vector<vec> p(n);
    for (auto &v: p) cin >> v.x >> v.y;
    p.emplace_back(p[0]);
    p.emplace_back(p[1]);
    ld ans = 1e18;
    for (int i = 1; i <= n; ++i) {
        ans = min(ans, ((p[i - 1] - p[i]) ^ (p[i + 1] - p[i])) / (p[i + 1] - p[i - 1]).abs() / 2);
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
    cout << fixed << setprecision(10);
    while (T--) elysia();
#ifdef MEGURINE
    cout << "\nRunning Time: " << double(clock() - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
    return 0;
}
