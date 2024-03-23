/**
 * Created by 5cm/s on 2024/03/22 10:28:59.
 * 诸天神佛，佑我上分！
 **/
#include <bits/stdc++.h>

using namespace std;

#define itr(it) begin(it), end(it)
//#define endl '\n'
#define YES() void(cout << "YES\n")
#define NO() void(cout << "NO\n")

int ask(int x1, int y1, int x2, int y2) {
    cout << "? " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    int ret;
    cin >> ret;
    return ret;
}

void bingo(int x1, int y1, int x2, int y2) {
    cout << "! " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
}

void elysia() {
    int n;
    cin >> n;
    vector<int> xs, ys;
    for (int i = 1; i <= n; ++i) {
        if (ask(i, 1, i, n) % 2) {
            xs.emplace_back(i);
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (ask(1, i, n, i) % 2) {
            ys.emplace_back(i);
        }
    }
    assert(xs.size() == 2 || ys.size() == 2);
    if (xs.size() == 2 && ys.size() == 2) {
        if (ask(xs[0], ys[0], xs[0], ys[0]) % 2 == 0) ranges::reverse(xs);
        bingo(xs[0], ys[0], xs[1], ys[1]);
    } else if (xs.size() == 2) {
        assert(ys.size() == 0);
        int lo = 1, hi = n;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (ask(xs[0], 1, xs[0], mid) % 2) hi = mid;
            else lo = mid + 1;
        }
        bingo(xs[0], lo, xs[1], lo);
    } else {
        assert(xs.size() == 0 || ys.size() == 2);
        int lo = 1, hi = n;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (ask(1, ys[0], mid, ys[0]) % 2) hi = mid;
            else lo = mid + 1;
        }
        bingo(lo, ys[0], lo, ys[1]);
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
