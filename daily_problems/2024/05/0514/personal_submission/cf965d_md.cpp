// 0514
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = std::pair<int, int>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int w, l;
    std::cin >> w >> l;
    vector<int> a(w);
    copy_n(istream_iterator<int>(std::cin), w - 1, next(begin(a)));
    
    partial_sum(begin(a), end(a), begin(a));

    int ret = numeric_limits<int>::max();
    for (int i = 0; i < w - l; ++i) {
        ret = min(ret, a[i + l] - a[i]);
    }

    cout << ret << endl;

    return 0;
}