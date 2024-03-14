/**
 * Created by 5cm/s on 2024/03/13 20:16:27.
 * 诸天神佛，佑我上分！
 **/
#include <bits/stdc++.h>

using namespace std;

#define itr(it) begin(it), end(it)
#define endl '\n'
#define YES() void(cout << "YES\n")
#define NO() void(cout << "NO\n")

void elysia() {
    int n, m = 0;
    cin >> n;
    vector<string> g(n);
    vector<vector<int>> f;
    for (int i = 0, j, k; i < n; ++i) {
        string &s = g[i];
        cin >> s >> k;
        while (k--) {
            cin >> j, j--;
            f.resize(m = max(m, j + int(s.size())));
            f[j].emplace_back(i);
        }
    }
    string t(m, 'a');
    for (int i = 0, j = 0; i < m; i++, j = max(j, i)) {
        for (int id: f[i]) {
            while (j < i + g[id].size()) {
                t[j] = g[id][j - i];
                j++;
            }
        }
    }
    cout << t << endl;
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
