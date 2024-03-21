#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    constexpr long long inf = 1e18;

    long long n, l;
    cin >> n >> l;

    int len = max(n, __lg(l) + 1);

    vector<long long> c(len, inf);
    copy_n(istream_iterator<long long>(cin), n, begin(c));

    for (int i = 1; i < len; ++i) {
        c[i] = min(c[i], c[i-1] * 2ll);
    }

    long long ans = inf;
    long long acc = 0;
    for (int i = len - 1; i >= 0; --i) {
        if ((l >> i) & 1) {
            acc += c[i];
        }
        ans = min(ans, acc + c[i]);
    }
    ans = min(ans, acc);
    cout << ans << endl;

    return 0;
}