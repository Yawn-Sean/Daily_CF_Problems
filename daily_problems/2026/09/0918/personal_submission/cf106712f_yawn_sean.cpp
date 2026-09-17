#include <bits/stdc++.h>
// #include "atcoder/all"
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s;
	cin >> s;

	int n = s.size();
	vector<int> nums(3 * n);

	for (int i = 0; i < n; i ++) nums[i] = s[i] - '0';

	for (int i = 1; i < 3 * n; i ++) nums[i] += nums[i - 1];

	int carry = 0;

	for (int i = 0; i < 3 * n; i ++) {
		nums[i] += carry;
		carry = nums[i] / 10;
		nums[i] %= 10;
	}

	cout << nums.back();

	return 0;
}