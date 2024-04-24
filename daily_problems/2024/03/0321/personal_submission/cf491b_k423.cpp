/**
 * Created by 5cm/s on 2024/03/21 09:39:49.
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

using i64 = int64_t;
using pii = pair<int, int>;

void elysia() {
    i64 n, m, c, h, inf = 1e18;
    cin >> n >> m >> c;
    vector<pii> friends(c);
    for (auto &[x, y]: friends) cin >> x >> y;
    cin >> h;
    vector<pii> hotels(h);
    for (auto &[x, y]: hotels) cin >> x >> y;

    int ans = 0;
    auto check = [&](i64 val) -> bool {
        // x + y - val <= lb <= rt <= x + y + val
        // x - y - val <= lt <= rb <= x - y + val
        i64 lb = -inf, lt = -inf, rt = inf, rb = inf;
        for (auto &[x, y]: friends) {
            chmax(lb, x + y - val), chmax(lt, x - y - val);
            chmin(rt, x + y + val), chmin(rb, x - y + val);
        }
        ans = 0;
        for (auto &[x, y]: hotels) {
            ans++;
            if (x + y >= lb && x + y <= rt && x - y >= lt && x - y <= rb) {
                return true;
            }
        }
        return false;
    };

    i64 lo = 0, hi = 2e9;
    while (lo < hi) {
        i64 mid = (lo + hi) / 2;
        if (check(mid)) hi = mid;
        else lo = mid + 1;
    }
    check(lo);
    cout << lo << endl;
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
