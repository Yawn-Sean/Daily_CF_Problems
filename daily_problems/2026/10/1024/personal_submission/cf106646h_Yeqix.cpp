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
    n <<= 1;
    i64 ans = 0;
    vector<i64> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        ans -= b[i];
    }

    priority_queue<i64> que;
    for (int i = 1; i <= n; i++) {
        que.push(a[i] + b[i]);
        if (i & 1) {
            ans += que.top();
            que.pop();
        }
    }

    cout << ans;
    return 0;
}
