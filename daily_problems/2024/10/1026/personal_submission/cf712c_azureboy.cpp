#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
	int y, x;
	cin >> y >> x;
	int ans = 0;
	int a, b, c;
	a = b = c = x;
	while (1)
	{
		vector<int>v = {a, b, c};
		sort(v.begin(), v.end());
		a = v[0], b = v[1], c = v[2];
		a = min(y, b + c - 1);
		ans++;
		if (a == y && b == y && c == y)break;
	}
	cout << ans << "\n";
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	//cin >> T;
	while (T--)
	{
		solve();
	}
	return 0;
}
