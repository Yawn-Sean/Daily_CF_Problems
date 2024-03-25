/**
 * Created by 5cm/s on 2024/03/23 13:41:58.
 * 诸天神佛，佑我上分！
 **/
#include <bits/stdc++.h>

using namespace std;

#define itr(it) begin(it), end(it)
#define endl '\n'
#define YES() void(cout << "YES\n")
#define NO() void(cout << "NO\n")

using ld = long double;

void elysia() {
    int n, r;
    cin >> n >> r;
    vector<pair<int, ld>> p;
    while (n--) {
        int x;
        ld y = r;
        cin >> x;
        for (auto [a, b]: p) {
            if (abs(a - x) <= r * 2) {
                y = max(y, b + sqrt(ld(r * r * 4 - (a - x) * (a - x))));
            }
        }
        p.emplace_back(x, y);
        cout << y << " \n"[n == 0];
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
