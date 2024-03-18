/**
 * Created by 5cm/s on 2024/03/18 09:58:43.
 * 诸天神佛，佑我上分！
 **/
#include <bits/stdc++.h>

using namespace std;

#define itr(it) begin(it), end(it)
#define endl '\n'
#define YES() void(cout << "YES\n")
#define NO() void(cout << "NO\n")

void elysia() {
    int n, q, m;
    cin >> n >> q >> m;
    vector<int> a(n);
    for (int &x: a) cin >> x;
    vector<array<int, 3>> ops(q);
    for (auto &[op, l, r]: ops) cin >> op >> l >> r, --l, --r;
    reverse(itr(ops));
    while (m--) {
        int id;
        cin >> id, --id;
        for (auto &[op, l, r]: ops) {
            if (id < l || id > r) continue;
            if (op == 1) {
                id = (id - l + (r - l)) % (r - l + 1) + l;
            } else {
                id = r + l - id;
            }
        }
        cout << a[id] << " \n"[m == 0];
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
