/**
 * Created by 5cm/s on 2024/03/14 10:23:19.
 * 诸天神佛，佑我上分！
 **/
#include <bits/stdc++.h>

using namespace std;

#define itr(it) begin(it), end(it)
//#define endl '\n'
#define YES() void(cout << "YES\n")
#define NO() void(cout << "NO\n")

#ifdef MEGURINE
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int X, Y, P, Q, idle;

int ask(int i, int j) {
    idle++;
    cout << "? " << i << ' ' << j << endl;
    assert(i < X || i > P || j < Y || j > Q);
    int ret = min(abs(i - X), abs(i - P)) + min(abs(j - Y), abs(j - Q));
    cout << "# " << ret << endl;
    return ret;
}

void bingo(int x, int y, int p, int q) {
    cout << "! " << x << ' ' << y << ' ' << p << ' ' << q << endl;
    cout << "idle = " << idle;
    assert(x == X && y == Y && p == P && q == Q);
    assert(idle <= 40);
}
#else
int ask(int i, int j) {
    cout << "? " << i << ' ' << j << endl;
    int ret;
    cin >> ret;
    return ret;
}

void bingo(int x, int y, int p, int q) {
    cout << "! " << x << ' ' << y << ' ' << p << ' ' << q << endl;
}
#endif

void elysia() {
    int sz = 1e9;
#ifdef  MEGURINE
//    X = rng() % (sz - 2) + 1, Y = rng() % (sz - 2) + 1;
//    P = rng() % (sz - X) + X, Q = rng() % (sz - Y) + Y;
    tie(X, Y, P, Q) = tuple(2, 3, 4, 5);
    cout << "expect: " << X << ' ' << Y << ' ' << P << ' ' << Q << endl;
    idle = 0;
#endif
    int d = ask(1, 1);
    int x = 1;
    for (int k = 1 << 29; k; k >>= 1) {
        if (x + k >= sz || x + k - 1 >= d) continue;
        int d2 = ask(x + k, 1);
        if (d - d2 == x - 1 + k) x += k;
    }
    int y = d - x + 2, p = sz - (ask(sz, 1) - y + 1), q = sz - (ask(1, sz) - x + 1);
    bingo(x, y, p, q);
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
