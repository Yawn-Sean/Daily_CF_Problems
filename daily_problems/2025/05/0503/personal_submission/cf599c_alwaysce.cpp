#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 inf = 1e18;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x: a) { cin >> x; }

    vector<int> b = a;
    sort(b.begin(), b.end());

    int ans = 0;
    i64 cur = 0;
    for (int i = 0; i < n; i++) {
        cur += b[i] - a[i];
        ans += (cur == 0);
    }
    cout << ans << endl;
    return 0;
}
