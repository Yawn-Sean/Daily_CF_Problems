#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	int n, m; cin >> n >> m;
	int c; cin >> c;
	vector<array<int,2>> hotels(c);
	for (int i = 0; i < c; i++){
		cin >> hotels[i][0] >> hotels[i][1];
	}
	int h; cin >> h;
	vector<array<int,2>> restaurants(h);
	for (int i = 0; i < h; i++){
		cin >> restaurants[i][0] >> restaurants[i][1];
	}

	int addMi = INT_MAX, minusMi = INT_MAX;
	int addMx = INT_MIN, minusMx = INT_MIN;

	for (auto &[x, y] : hotels){
		addMi = min(addMi, x + y);
		minusMi = min(minusMi, x - y);
		addMx = max(addMx, x + y);
		minusMx = max(minusMx, x - y);
	}

	int res = INT_MAX, idx = -1;

	for (int i = 0; i < h; i++){
		auto [x, y] = restaurants[i];

		int dist = max({x + y - addMi, x - y - minusMi, minusMx - x + y, addMx - x - y});
		//cout << dist << "---\n";
		if (dist < res){
			res = dist;
			idx = i;
		}
	}
	cout << res <<" "<< idx + 1 << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    solve();
    return 0;
}