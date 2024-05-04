// 0504
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    std::cin >> n >> k;
    vector<int> a(n);
    copy_n(istream_iterator<int>(cin), n, begin(a));

    int min_val = INT_MAX;
    int ret = 0;
    for (int i = 0; i < n - k; ++i) {
        if (a[i + k] - a[i] < min_val) {
            min_val = a[i + k] - a[i];
            ret = (a[i] + a[i + k]) / 2;
        }
    }
    cout << ret << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 0;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}