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

    int a, b, c, d, n;
    cin >> a >> b >> c >> d >> n;

    vector<int> nums(n);
    for (auto &x: nums) cin >> x;

    int N = max(b, d), M = a + c;
    vector<string> grid(N, string(M, '.'));

    for (int i = 0; i < b; i ++) {
        for (int j = 0; j < a; j ++) {
            grid[i][j] = '?';
        }
    }

    for (int i = 0; i < d; i ++) {
        for (int j = 0; j < c; j ++) {
            grid[i][a + j] = '?';
        }
    }

    int x, y, dx;
    if (a & 1) x = b - 1, y = 0, dx = -1;
    else x = 0, y = 0, dx = 1;

    int pt = 0;

    for (int i = 0; i < a * b + c * d; i ++) {
        if (i) {
            if (x + dx >= 0 && x + dx < N && grid[x + dx][y] == '?') x += dx;
            else y ++, dx = -dx;
        }

        while (!nums[pt]) pt ++;
        nums[pt] --;
        
        grid[x][y] = 'a' + pt;
    }

    cout << "YES\n";
    for (auto &line: grid) cout << line << '\n';

    return 0;
}