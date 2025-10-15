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
// I came, I divide, I conquer!

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    for (int i = 0; i < 2; i ++) {
        swap(x1, y1);
        for (int j = 0; j < 2; j ++) {
            swap(x2, y2);
            for (int k = 0; k < 2; k ++) {
                swap(x3, y3);
                if (y1 == y2 && y2 == y3 && x1 + x2 + x3 == y1) {
                    cout << y1 << '\n';
                    vector<string> grid(y1, string(y1, ' '));
                    for (int i = 0; i < x1; i ++) {
                        for (int j = 0; j < y1; j ++) {
                            grid[i][j] = 'A';
                        }
                    }
                    for (int i = x1; i < x1 + x2; i ++) {
                        for (int j = 0; j < y1; j ++) {
                            grid[i][j] = 'B';
                        }
                    }
                    for (int i = x1 + x2; i < x1 + x2 + x3; i ++) {
                        for (int j = 0; j < y1; j ++) {
                            grid[i][j] = 'C';
                        }
                    }
                    for (auto &s: grid) cout << s << '\n';
                    return 0;
                }
                if (y1 == y2 + y3 && x2 == x3 && x1 + x2 == y1) {
                    cout << y1 << '\n';
                    vector<string> grid(y1, string(y1, ' '));
                    for (int i = 0; i < x1; i ++) {
                        for (int j = 0; j < y1; j ++) {
                            grid[i][j] = 'A';
                        }
                    }
                    for (int i = x1; i < x1 + x2; i ++) {
                        for (int j = 0; j < y2; j ++) {
                            grid[i][j] = 'B';
                        }
                    }
                    for (int i = x1; i < x1 + x2; i ++) {
                        for (int j = y2; j < y2 + y3; j ++) {
                            grid[i][j] = 'C';
                        }
                    }
                    for (auto &s: grid) cout << s << '\n';
                    return 0;
                }
                if (y2 == y1 + y3 && x1 == x3 && x1 + x2 == y2) {
                    cout << y2 << '\n';
                    vector<string> grid(y2, string(y2, ' '));
                    for (int i = 0; i < x2; i ++) {
                        for (int j = 0; j < y2; j ++) {
                            grid[i][j] = 'B';
                        }
                    }
                    for (int i = x2; i < x1 + x2; i ++) {
                        for (int j = 0; j < y1; j ++) {
                            grid[i][j] = 'A';
                        }
                    }
                    for (int i = x2; i < x1 + x2; i ++) {
                        for (int j = y1; j < y1 + y3; j ++) {
                            grid[i][j] = 'C';
                        }
                    }
                    for (auto &s: grid) cout << s << '\n';
                    return 0;
                }
                if (y3 == y1 + y2 && x1 == x2 && x1 + x3 == y3) {
                    cout << y3 << '\n';
                    vector<string> grid(y3, string(y3, ' '));
                    for (int i = 0; i < x3; i ++) {
                        for (int j = 0; j < y3; j ++) {
                            grid[i][j] = 'C';
                        }
                    }
                    for (int i = x3; i < x1 + x3; i ++) {
                        for (int j = 0; j < y1; j ++) {
                            grid[i][j] = 'A';
                        }
                    }
                    for (int i = x3; i < x1 + x3; i ++) {
                        for (int j = y1; j < y1 + y2; j ++) {
                            grid[i][j] = 'B';
                        }
                    }
                    for (auto &s: grid) cout << s << '\n';
                    return 0;
                }
            }
        }
    }
    cout << "-1";

    return 0;
}