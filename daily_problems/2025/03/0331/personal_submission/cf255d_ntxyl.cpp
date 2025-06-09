#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define int long long
#define all(v) v.begin(), v.end()
//#define x first
//#define y second

using namespace std;
typedef pair<int, int> PII;

const int N = 1e5 + 10;

void solve() {
	int n, c, x, y;
	cin >> n >> x >> y >> c;
	auto check = [&](int m)->bool{
		int res = 2 * m * m + 2 * m + 1;
        if (m > x - 1) res -= (m - (x - 1)) * (m - (x - 1));
        if (m > n - x) res -= (m - (n - x)) * (m - (n - x));
        if (m > y - 1) res -= (m - (y - 1)) * (m - (y - 1));
        if (m > n - y) res -= (m - (n - y)) * (m - (n - y));
        
        if (m > (x - 1) + (y - 1))
            res += (m - ((x - 1) + (y - 1)) - 1) * (m - ((x - 1) + (y - 1))) / 2;
        if (m > (x - 1) + (n - y))
            res += (m - ((x - 1) + (n - y)) - 1) * (m - ((x - 1) + (n - y))) / 2;
        if (m > (n - x) + (y - 1))
            res += (m - ((n - x) + (y - 1)) - 1) * (m - ((n - x) + (y - 1))) / 2;
        if (m > (n - x) + (n - y))
            res += (m - ((n - x) + (n - y)) - 1) * (m - ((n - x) + (n - y))) / 2;

		return res >= c;
	};
	int l = 0, r = 2 * n;
	while (l < r) {
		int mid = l + r >> 1;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	cout << l << endl;
}
signed main() {
	fastio;
	int T;
	T = 1;
	// cin >> T;
	while (T--) solve();

	return 0;
}
