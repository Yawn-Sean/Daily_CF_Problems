/**
 * Created by 5cm/s on 2024/03/12 13:55:05.
 * 诸天神佛，佑我上分！
 **/
#include <bits/stdc++.h>

using namespace std;

#define itr(it) begin(it), end(it)
#define endl '\n'
#define YES() void(cout << "YES\n")
#define NO() void(cout << "NO\n")

void elysia() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (auto &it: a) for (int &x: it) cin >> x;
    vector<int> row(n), col(m);

    auto help = [&]() -> bool {
        for (int i = 0; i < n; ++i) {
            if (accumulate(itr(a[i]), 0) < 0) {
                for (int &x: a[i]) x = -x;
                row[i] ^= 1;
                return true;
            }
        }

        for (int j = 0; j < m; ++j) {
            int s = 0;
            for (int i = 0; i < n; ++i) s += a[i][j];
            if (s < 0) {
                for (int i = 0; i < n; ++i) a[i][j] = -a[i][j];
                col[j] ^= 1;
                return true;
            }
        }
        return false;
    };

    while (help());
    cout << count(itr(row), 1);
    for (int i = 0; i < n; ++i) if (row[i]) cout << ' ' << i + 1;
    cout << endl;
    cout << count(itr(col), 1);
    for (int i = 0; i < m; ++i) if (col[i]) cout << ' ' << i + 1;
    cout << endl;
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
