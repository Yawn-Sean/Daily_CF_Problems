#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"
#include "atcoder/maxflow"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a, b, c;
    cin >> a >> b >> c;

    vector<int> blocked(a * b * c, 0);

    auto f = [&] (int x, int y, int z) -> int {
        return (x * b + y) * c + z;
    };

    int k;
    cin >> k;

    while (k --) {
        int x, y, z;
        cin >> x >> y >> z;
        x --, y --, z --;
        blocked[f(x, y, z)] = 1;
    }

    atcoder::mf_graph<int> mf(a * b * c + 2);
    int cnt = a * b * c, src = a * b * c, dst = src + 1;

    vector<array<int, 3>> dirs;

    for (int i = -2; i <= 2; i ++) {
        for (int j = -2; j <= 2; j ++) {
            if (abs(i) + abs(j) == 3) {
                dirs.push_back({0, i, j});
                dirs.push_back({i, 0, j});
                dirs.push_back({i, j, 0});
            }
        }
    }

    for (int i = 0; i < a; i ++) {
        for (int j = 0; j < b; j ++) {
            for (int k = 0; k < c; k ++) {
                if (!blocked[f(i, j, k)]) {
                    if ((i + j + k) % 2) {
                        mf.add_edge(src, f(i, j, k), 1);
                        for (auto &[di, dj, dk]: dirs) {
                            int ni = i + di;
                            int nj = j + dj;
                            int nk = k + dk;
                            if (ni >= 0 && ni < a && nj >= 0 && nj < b && nk >= 0 && nk < c && !blocked[f(ni, nj, nk)])
                                mf.add_edge(f(i, j, k), f(ni, nj, nk), 1);
                        }
                    }
                    else mf.add_edge(f(i, j, k), dst, 1);
                }
                else cnt --;
            }
        }
    }

    cout << cnt - mf.flow(src, dst);

    return 0;
}