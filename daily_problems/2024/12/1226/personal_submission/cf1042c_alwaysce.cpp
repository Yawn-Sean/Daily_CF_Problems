#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 1e9+7;
int inf = 2e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	vector<int> nums(n);
	for (auto& x: nums) {
		cin >> x;
	}
	
	vector<int> neg, pos, zero;
	for (int i = 0; i < n; i++) {
		if (nums[i] > 0) {
			pos.push_back(i);
		} else if (nums[i] < 0) {
			neg.push_back(i);
		} else {
			zero.push_back(i);
		}
	}
	
	sort(neg.begin(), neg.end(), [&](int i, int j){
		return nums[i] > nums[j];
	});
	
	while (neg.size() > 1) {
		int i1 = neg.back();
		neg.pop_back();
		int i2 = neg.back();
		neg.pop_back();
		pos.push_back(i2);
		cout << 1 << ' ' << i1 + 1 << ' ' << i2 + 1 << '\n'; 		
	}
	
	while (pos.size() > 1) {
		int i1 = pos.back();
		pos.pop_back();
		int i2 = pos.back();
		pos.pop_back();
		pos.push_back(i2);
		cout << 1 << ' ' << i1 + 1 << ' ' << i2 + 1 << '\n';
	}
	
	while (zero.size() > 1) {
		int i1 = zero.back();
		zero.pop_back();
		int i2 = zero.back();
		zero.pop_back();
		zero.push_back(i2);
		cout << 1 << ' ' << i1 + 1 << ' ' << i2 + 1 << '\n';
	}
	
	if (neg.size() == 0) {
		if (zero.size() > 0 and pos.size() > 0) {
			cout << 2 << ' ' << zero[0] + 1 << '\n';
		}
	} else {
		if (zero.size()) {
			cout << 1 << ' ' << neg[0] + 1 << ' ' << zero[0] + 1 << '\n';
			if (pos.size() > 0) {
				cout << 2 << ' ' << zero[0] + 1 << '\n';
			}
		} else {
			cout << 2 << ' ' << neg[0] + 1 << '\n';
		}
	}
	return 0;
}
