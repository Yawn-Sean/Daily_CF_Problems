#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
namespace rgs = ranges;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a = {1, 1};
    for (int i = 2; i <= n; i++) {
        vector<int> b;
        b.push_back(i);
        int m = a.size();
        for (int j = 0; j < m; j++) {
            b.push_back(a[j]);
            b.push_back(i);
            if (j == m / 2 - 1) {
                b.push_back(i);
            }
        }
        swap(a, b);
    }

    cout << a.size() << "\n";
    for (const auto& v : a) {
        cout << v << " ";
    }
    return 0;
}