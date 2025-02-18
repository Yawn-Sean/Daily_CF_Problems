#include <bits/stdc++.h>
#define fi first
#define se second
#define int long long

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

signed main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int n, fx, fy;
	string s;
	cin >> n >> s, s = ' ' + s;

	std::vector<int> dx(n + 1, 0), dy(n + 1, 0);
	for (int i = 1; i <= n; i ++) {
		dx[i] = dx[i - 1], dy[i] = dy[i - 1];
		if (s[i] == 'L') dx[i] --;
		else if (s[i] == 'R') dx[i] ++;
		else if (s[i] == 'D') dy[i] --;
		else dy[i] ++;
	}
	cin >> fx >> fy;

	if (dx[n] == fx && dy[n] == fy) {
		cout << 0 << endl;
		return 0;
	}

	const int inf = 9e18;
	int res = inf;
	for (int i = 1; i <= n; i ++) {
		int lo = i, ro = n;
		while (lo <= ro) {
			int mid = lo + ro >> 1;
			if (abs(fx - (dx[n] - dx[mid] + dx[i - 1])) + abs(fy - (dy[n] - dy[mid] + dy[i - 1])) <= mid - i + 1 && 
				(abs(fx - (dx[n] - dx[mid] + dx[i - 1])) + abs(fy - (dy[n] - dy[mid] + dy[i - 1])) & 1) == ((mid - i + 1) & 1)) ro = mid - 1, res = min(res, mid - i + 1);
			else lo = mid + 1;
		}
	}

	if (res == inf) cout << -1 << endl;
	else cout << res << endl;

	return 0;
}
