/**
 * Created by 5cm/s on 2024/02/27 09:43:39.
 * 诸天神佛，佑我上分！
 **/
#include <bits/stdc++.h>

using namespace std;

#define itr(it) begin(it), end(it)
//#define endl '\n'
#define YES() void(cout << "Yes\n")
#define NO() void(cout << "No\n")

using i64 = int64_t;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

bool halt = false;

#ifdef MEGURINE
i64 p, _n, _k, idle;

bool ask(i64 l, i64 r) {
    cout << l << ' ' << r << endl;
    idle++;
    assert(idle <= 4500);
    bool ok = p >= l && p <= r;
    ok ? YES() : NO();
    p += rng() % (2 * _k + 1) - _k;
    p = max(i64(1), min(p, _n));
    halt = l == r && ok;
    return ok;
}

#else
bool ask(i64 l, i64 r) {
    cout << l << ' ' << r << endl;
    string s;
    cin >> s;
    halt = l == r && s == "Yes";
    return s == "Yes";
}
#endif


void elysia() {
    i64 n, k;
    cin >> n >> k;
#ifdef MEGURINE
    _n = n, _k = k, p = rng() % n + 1;
    cout << "initial: " << n << ' ' << k << ' ' << p << endl;
#endif
    i64 lo = 1, hi = n;
    do {
        while (lo + 4 * k < hi) {
            i64 mid = (lo + hi) / 2;
            if (ask(lo, mid)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
            lo = max(lo - k, i64(1)), hi = min(n, hi + k);
        }
        if (halt) break;
        if (lo == hi) {
            ask(lo, hi);
            break;
        }
        i64 guess = rng() % (hi - lo + 1) + lo;
#ifdef MEGURINE
        cout << "guess: " << guess << endl;
#endif
        if (!ask(guess, guess)) {
            lo = max(lo - k, i64(1)), hi = min(n, hi + k);
        }
    } while (!halt);
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