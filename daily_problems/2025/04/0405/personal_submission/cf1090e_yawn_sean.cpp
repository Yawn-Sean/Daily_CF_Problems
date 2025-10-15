#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/convolution"
// #include "atcoder/dsu"
// #include "atcoder/fenwicktree"
// #include "atcoder/lazysegtree"
// #include "atcoder/math"
// #include "atcoder/maxflow"
// #include "atcoder/mincostflow"
// #include "atcoder/modint"
// #include "atcoder/scc"
// #include "atcoder/segtree"
// #include "atcoder/string"
// #include "atcoder/twosat"
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<bool> cur(64, 0);
    for (int i = 0; i < n; i ++) {
        string s;
        cin >> s;
        int pos = (s[1] - '1') * 8 + (s[0] - 'a');
        cur[pos] = 1;
    }

    vector<pair<int, int>> dirs;
    for (int i = -2; i <= 2; i ++) {
        for (int j = -2; j <= 2; j ++) {
            if (abs(i) + abs(j) == 3) {
                dirs.emplace_back(i, j);
            }
        }
    }

    vector<pair<int, int>> ops;
    
    for (int i = n; i < 64; i ++) {
        if (cur[i]) {
            int start = i, end;
            for (int j = 0; j < n; j ++) {
                if (!cur[j]) {
                    end = j;
                    break;
                }
            }

            vector<int> prev(64, -2);
            prev[end] = -1;

            queue<int> q; q.push(end);

            while (!q.empty()) {
                int u = q.front();
                int x = u / 8, y = u % 8;
                q.pop();
                for (auto &[dx, dy]: dirs) {
                    if (x + dx >= 0 && x + dx < 8 && y + dy >= 0 && y + dy < 8) {
                        int nu = (x + dx) * 8 + (y + dy);
                        if (prev[nu] == -2) {
                            prev[nu] = u;
                            q.push(nu);
                        }
                    }
                }
            }

            vector<int> saved = {start};
            while (true) {
                int p = prev[saved.back()];
                if (p == -1) break;

                if (!cur[p]) {
                    int v = p;
                    while (!saved.empty()) {
                        int u = saved.back();
                        saved.pop_back();
                        ops.emplace_back(u, v);
                        swap(cur[u], cur[v]);
                        v = u;
                    }
                }
                saved.emplace_back(p);
            }
        }
    }

    auto output = [&] (int msk) -> void {
        cout << (char)('a' + msk % 8) << (char)('1' + msk / 8);
    };

    cout << ops.size() << '\n';
    for (auto &[x, y]: ops) {
        output(x);
        cout << '-';
        output(y);
        cout << '\n';
    }

    return 0;
}