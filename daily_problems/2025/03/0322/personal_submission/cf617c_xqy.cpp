#include <bits/stdc++.h>
using LL = long long;
using namespace std;

void solve() {
	
	int n;
	cin >> n;
	
	int x1,y1,x2,y2;
	cin >> x1 >> y1 >> x2 >> y2;

	auto get = [&] (int x1,int y1,int x2,int y2) {
		LL dist = 1LL * (x1 - x2) * (x1 - x2) + 1LL * (y1 - y2) * (y1 - y2);
		return dist;
	};

	vector<pair<int,int>> cond(n + 1);
	for (int i = 0 ; i < n ; ++i) {
		cin >> cond[i].first >> cond[i].second;
	}
	cond[n] = make_pair(x1 , y1);

	LL ans = 1E18;
	for (int i = 0 ; i < n + 1 ; ++i) {
		LL r1 = get(cond[i].first , cond[i].second , x1 , y1) , r2 = 0;
		for (int j = 0 ; j < n ; ++j) {
			if (i == j) continue;
			if (get(cond[j].first , cond[j].second , x1 , y1) <= r1) continue;
			else r2 = max(r2 , get(cond[j].first , cond[j].second , x2 , y2));
		}
		ans = min(ans , r1 + r2);
	}

	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while (t--) {
		solve();
	}

	return 0;
}
