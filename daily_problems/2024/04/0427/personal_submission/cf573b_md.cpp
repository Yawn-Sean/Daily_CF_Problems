#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = std::pair<int, int>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    vector<int> heights(n);
    copy_n(istream_iterator<int>(cin), n, begin(heights));

    heights[0] = heights.back() = 1;
    for (int i = 1; i < n; ++i) {
        heights[i] = min(heights[i], heights[i-1] + 1);
    }

    int ret = 1;
    for (int i = n - 2; i >= 0; --i) {
        heights[i] = min(heights[i], heights[i + 1] + 1);
        ret = max(ret, heights[i]);
    }

    cout << ret << endl;

    return 0;
}