#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve()
{	
	int n; cin >> n;
	ll sum = 0, mx = -1;
	for(int i = 1; i <= n; i++) {
		ll t; cin >> t;
		sum += t;
		mx = max(mx, t);
	}

	cout << min(sum - mx, sum / 3);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 1; 
	// cin >> t;
	while(t--) {
		solve();
	}

	return 0;
}
