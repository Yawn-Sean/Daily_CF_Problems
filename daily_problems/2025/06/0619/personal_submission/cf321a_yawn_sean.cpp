#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

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

    int a, b;
    cin >> a >> b;

    map<char, pair<int, int>> dirs;
    dirs['U'] = {0, 1};
    dirs['D'] = {0, -1};
    dirs['L'] = {-1, 0};
    dirs['R'] = {1, 0};

    string s;
    cin >> s;

    int x = 0, y = 0;
    for (auto &c: s) {
        auto [dx, dy] = dirs[c];
        x += dx, y += dy;
    }

    int cur_x = 0, cur_y = 0;

    auto check = [&] () -> bool {
        int step = 0;
        if (x) step = (a - cur_x) / x;
        if (y) step = (b - cur_y) / y;
        return step >= 0 && cur_x + step * x == a && cur_y + step * y == b;
    };

    for (auto &c: s) {
        auto [dx, dy] = dirs[c];
        if (check()) return cout << "Yes", 0;
        cur_x += dx, cur_y += dy;
    }

    cout << "No";

    return 0;
}