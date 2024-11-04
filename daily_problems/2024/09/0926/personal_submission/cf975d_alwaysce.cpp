#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, a, b;
	cin >> n >> a >> b;
	
	map<i64,int> mp1;
	map<pair<i64,i64>, int> mp2;
	
	i64 ans = 0;
	for (int i = 0; i < n; i++) {
		int x, vx, vy;
		cin >> x >> vx >> vy;
		
		ans += mp1[-1ll * a * vx + vy];
		ans -= mp2[{vx, vy}];
		
		mp1[-1ll * a * vx + vy]++;
		mp2[{vx, vy}]++;
	}
	cout << ans * 2;
	return 0;
}
