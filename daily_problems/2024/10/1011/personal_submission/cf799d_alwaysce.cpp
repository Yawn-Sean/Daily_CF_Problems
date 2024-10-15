#include <bits/stdc++.h>
using i64 = long long;
using ui64 = unsigned long long;
using namespace std;

i64 mod = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int a, b, h, w, n;
	cin >> a >> b >> h >> w >> n;
	
	vector<int> nums(n);
	for (auto& v: nums) { cin >> v; }
	
	sort(nums.begin(), nums.end());
	reverse(nums.begin(), nums.end());
	n = min(n, 34);
	
	int inf = 100;
	auto bfs = [&](int x, int y) {
		map<pair<int,int>, int> mp;
		mp[{x, y}] = 0;
		
		for (int i = 0; i < n; i++) {
			vector<pair<int,int>> pairs;
			for (auto prs: mp) {
				pairs.push_back(prs.first);
			}
			
			for (auto& pr: pairs) {
				int x = pr.first, y = pr.second;
				
				int nx = (x + nums[i] - 1) / nums[i];
				int ny = (y + nums[i] - 1) / nums[i];
				
				if (mp.find({nx, y}) == mp.end()) {
					mp[{nx, y}] = mp[{x, y}] + 1;
				}
				if (mp.find({x, ny}) == mp.end()) {
					mp[{x, ny}] = mp[{x, y}] + 1;
				}
			}
		}
		
		return mp.find({1, 1}) == mp.end() ? inf : mp[{1, 1}];
	};
	
	int ans = bfs((a + w - 1) / w, (b + h - 1) / h);
	ans = min(ans, bfs((a + h - 1) / h, (b + w - 1) / w));
	cout << ((ans < inf) ? ans : -1);
	return 0;
}
