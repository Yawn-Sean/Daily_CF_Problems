#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, k;
	cin >> n >> k;
	
	// 1. 每次调用次数+0/+2 一开始一定会调用一次
	if (k % 2 == 0) {
		cout << -1;
		return 0;
	}
	
	vector<int> ans(n);
	iota(ans.begin(), ans.end(), 1);
	
	k /= 2;
	// 2. [l,m)和[m, r)构造 内部有序但是[l, r)不是有序的
	function<void(int,int)> op = [&](int l, int r) {
		if (k == 0 or r - l == 1) {
			return;
		}
		k--;
		int m = (l + r) / 2;
		swap(ans[m - 1], ans[m]);
		op(l, m);
		op(m, r);
	};
	
	op(0, n);
	if (k > 0) {
		cout << -1;
	} else {
		for (auto& x: ans) {
			cout << x << ' ';
		}
	}
    return 0;
    
}
