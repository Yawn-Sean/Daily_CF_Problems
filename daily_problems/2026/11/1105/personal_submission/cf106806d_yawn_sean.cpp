#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> nums(n);
	for (auto &x: nums) cin >> x;

	sort(nums.begin(), nums.end());

	long long cur = 0;
	bool flg = false;

	for (auto &x: nums) {
		if (cur >= x) flg = true;
		cur += x;
	}

	cout << (flg ? "possible" : "impossible");

	return 0;
}