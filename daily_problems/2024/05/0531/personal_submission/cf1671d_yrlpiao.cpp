#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
#define int long long

void yrlpSolve() {
    int n, x; cin >> n >> x;
    int mi = INT_MAX, mx = INT_MIN;
    vector<int> a(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i) ans += abs(a[i] - a[i - 1]);
        mi = min(mi, a[i]);
        mx = max(mx, a[i]);
    }
    ans += min({(mi - 1) * 2, a[0] - 1, a[n - 1] - 1});
    ans += max(0LL, min({(x - mx) * 2, x - a[0], x - a[n - 1]}));
    cout << ans << endl;
    return; 
}

signed main() {
    int T = 1; cin >> T;
    while (T--) yrlpSolve();
}
