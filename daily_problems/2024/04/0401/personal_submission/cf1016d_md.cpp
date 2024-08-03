#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    copy_n(istream_iterator<int>(cin), n, begin(a));
    vector<int> b(m);
    copy_n(istream_iterator<int>(cin), m, begin(b));

    auto xor1 = accumulate(begin(a), end(a), 0, bit_xor<int>());
    auto xor2 = accumulate(begin(b), end(b), 0, bit_xor<int>());
    if (xor1 != xor2) {
        cout << "NO\n";
        return 0;
    }

    vector<vector<int>> ret(n, vector<int>(m, 0));
    ret[0] = b;
    for (int i = 1; i < n; ++i) {
        ret[0][0] ^= a[i];
        ret[i][0] = a[i];
    }

    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << ret[i][j] << " \n"[j == m - 1];
        }
    }

    return 0;
}