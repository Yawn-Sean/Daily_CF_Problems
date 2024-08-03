#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	int n, x; cin >> n >> x;
	vector<array<int,3>> trip(n);
	for (int i = 0; i < n; i++){
		cin >> trip[i][0] >> trip[i][1] >> trip[i][2];
	}

	int res = INT_MAX;
	sort(trip.begin(), trip.end());

	vector<vector<pair<int,int>>> state(x);

	for (auto [l, r, c] : trip){
		int len = r - l + 1;
		if (len >= x) continue;
		//left start l should have l + x - 1 <= r; l <= r + 1 - x
		auto it = upper_bound(state[x - len].begin(), state[x - len].end(), make_pair(r + 1 - x, INT_MAX));
		if (it != state[x - len].begin()) {
			it--;
			res = min(res, c + (*it).second);
		}

		if (!state[len].empty() && state[len].back().second <= c) continue;
		state[len].push_back({l, c});
	}
	if (res == INT_MAX) res = -1;
	cout << res << "\n";



}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    solve();
    return 0;
}