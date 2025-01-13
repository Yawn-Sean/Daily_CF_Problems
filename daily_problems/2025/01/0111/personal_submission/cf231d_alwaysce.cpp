#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int x, y, z;
	cin >> x >> y >> z;
	
	int x1,y1,z1;
	cin >> x1>>y1>>z1;
	
	/*
		S1 (0,0,0) (x1,0,0) (0,y1,0)
		S2
		S3
		...
		能够看见一个平面的条件是?
		在外面
	*/
	int ans = 0;
	vector<int> nums(6);
	for (auto& v: nums) { cin >> v; }
	// 下面zox
	if (y < 0) {
		ans += nums[0];
	}
	// 上面
	if (y > y1) {
		ans += nums[1];
	}
	// 后面
	if (z < 0) {
		ans += nums[2];
	}
	if (z > z1) {
		ans += nums[3];
	}
	// 左面
	if (x < 0) {
		ans += nums[4];
	}
	if (x > x1) {
		ans += nums[5];
	}
	cout << ans;
	return 0;
}
