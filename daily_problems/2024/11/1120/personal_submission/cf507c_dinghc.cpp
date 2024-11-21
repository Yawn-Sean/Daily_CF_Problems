#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int h;
    int64 n;
    cin >> h >> n;
    auto dfs = [&] (auto&& dfs, int64 left, int64 right, int height, int dir) -> int64 {
        if (height == 0) return 0;
        int64 mid = (right - left) / 2 + left;
        int indir = n <= mid ? 0 : 1;
        int64 res = 1;
        if (indir != dir) res += (1LL << height) - 1;
        if (n <= mid) {
            res += dfs(dfs, left, mid, height - 1, 1);
        } else {
            res += dfs(dfs, mid, right, height - 1, 0);
        }
        return res;
    };
    cout << dfs(dfs, 1, 1LL << h, h, 0) << "\n";
    return 0;
}
