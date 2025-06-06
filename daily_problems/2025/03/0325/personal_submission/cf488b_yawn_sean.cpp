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

    vector<int> nums(n);
    for (auto &x: nums) cin >> x;

    sort(nums.begin(), nums.end());

    if (n == 0) cout << "YES\n1\n1\n3\n3";
    else if (n == 1) {
        int x = nums[0];
        cout << "YES\n" << x << '\n' << 3 * x << '\n' << 3 * x;
    }
    else if (n == 2) {
        int x = nums[0], y = nums[1];
        if (x * 3 >= y)
            cout << "YES\n" << 4 * x - y << '\n' << 3 * x;
        else cout << "NO";
    }
    else if (n == 3) {
        int x = nums[0], y = nums[1], z = nums[2];
        if (z == 3 * x) cout << "YES\n" << x + z - y;
        else if (3 * x >= z && y + z == 4 * x) cout << "YES\n" << 3 * x;
        else if (z % 3 == 0 && x + y == z / 3 * 4) cout << "YES\n" << z / 3;
        else cout << "NO";
    }
    else
        cout << (nums[0] * 3 == nums[3] && nums[1] + nums[2] == nums[0] + nums[3] ? "YES" : "NO");

    return 0;
}