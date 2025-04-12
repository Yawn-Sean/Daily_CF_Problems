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
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
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

    auto f = [&] (int score1, int score2, int set1, int set2) -> int {
        return ((score1 * 201 + score2) * 4 + set1) * 4 + set2;
    };

    vector<int> dp(201 * 201 * 4 * 4, -2);
    dp[f(0, 0, 0, 0)] = -1;

    queue<int> q;
    q.push(f(0, 0, 0, 0));

    while (!q.empty()) {
        int cur = q.front(), u = cur;
        q.pop();
        int set2 = u % 4;
        u /= 4;
        int set1 = u % 4;
        u /= 4;
        int score2 = u % 201, score1 = u / 201;

        if (set1 + 1 <= 3 && set2 < 3) {
            int set_score = (set1 + set2 < 4 ? 25 : 15);

            if (score1 + set_score <= 200) {
                for (int i = 0; i <= set_score - 2; i ++) {
                    if (score2 + i <= 200) {
                        int ncur = f(score1 + set_score, score2 + i, set1 + 1, set2);
                        if (dp[ncur] == -2) {
                            dp[ncur] = cur;
                            q.push(ncur);
                        }
                    }
                }
            }

            for (int i = set_score + 1; i <= 200; i ++) {
                if (score1 + i > 200 || score2 + i - 2 > 200) break;
                int ncur = f(score1 + i, score2 + i - 2, set1 + 1, set2);
                if (dp[ncur] == -2) {
                    dp[ncur] = cur;
                    q.push(ncur);
                }
            }
        }

        if (set1 < 3 && set2 + 1 <= 3) {
            int set_score = (set1 + set2 < 4 ? 25 : 15);

            if (score2 + set_score <= 200) {
                for (int i = 0; i <= set_score - 2; i ++) {
                    if (score1 + i <= 200) {
                        int ncur = f(score1 + i, score2 + set_score, set1, set2 + 1);
                        if (dp[ncur] == -2) {
                            dp[ncur] = cur;
                            q.push(ncur);
                        }
                    }
                }
            }

            for (int i = set_score + 1; i <= 200; i ++) {
                if (score1 + i - 2 > 200 || score2 + i > 200) break;
                int ncur = f(score1 + i - 2, score2 + i, set1, set2 + 1);
                if (dp[ncur] == -2) {
                    dp[ncur] = cur;
                    q.push(ncur);
                }
            }
        }
    }

    int t;
    cin >> t;

    while (t --) {
        int x, y;
        cin >> x >> y;

        int cx = -1, cy = -1;

        for (int i = 0; i < 3; i ++) {
            if (dp[f(x, y, 3, i)] != -2) {
                cx = 3, cy = i;
                break;
            }
        }

        if (cx == -1) {
            for (int i = 2; i >= 0; i --) {
                if (dp[f(x, y, i, 3)] != -2) {
                    cx = i, cy = 3;
                    break;
                }
            }
        }

        if (cx == -1) cout << "Impossible\n";
        else {
            cout << cx << ':' << cy << '\n';

            vector<pair<int, int>> sets;
            int cur = f(x, y, cx, cy);

            for (int i = 0; i < cx + cy; i ++) {
                int prev = dp[cur];
                int scores = (cur - prev) / 16;
                sets.emplace_back(scores / 201, scores % 201);
                cur = prev;
            }

            reverse(sets.begin(), sets.end());
            
            for (auto &[x, y]: sets)
                cout << x << ':' << y << ' ';
            cout << '\n';
        }
    }

    return 0;
}