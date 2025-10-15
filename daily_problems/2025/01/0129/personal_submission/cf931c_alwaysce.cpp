#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	
	vector<int> x(n);
	int mn = 1e9, mx = -1e9;
	for (auto& v: x) { 
		cin >> v;
		mn = min(mn, v);
		mx = max(mx, v);
	}
	
	// 没有操作的需要
	if (mx <= mn + 1) {
		cout << n << '\n';
		for (auto&v: x) {
			cout << v << ' ';
		}
		return 0;
	}
	
	int add = 0, ans = 0;
	int cnt1 = 0, cnt2 = 0, cnt3 = 0;
	int ans_cnt1 = 0, ans_cnt2 = 0, ans_cnt3 = 0;
	for (auto& v: x) {
		add += (v - mn);
		if (v == mn) { ++cnt1; }
		else if (v == mn + 1) { ++cnt2; }
		else { ++cnt3; }
	}
	
	/*
		nx - mn <= 2
		
		1. 相同值尽可能少
		2. 均值一样(sum eq)
		3. 最大最小值不会超出上下限
		
		mn, mn + 1, mn + 2
		cnt1, cnt2, cnt3
		
		调整cnt1, cnt2, cnt3的个数
		add = 总共需要累加的
	*/
	
	for (int num3 = add / 2; num3 >= 0; num3--) {		
		int ncnt3 = num3;
		int ncnt2 = add - 2 * num3;
		int ncnt1 = n - ncnt3 - ncnt2;
		if (ncnt1 < 0 || ncnt2 < 0 || ncnt3 < 0) {
			continue;
		}
		int diff = n - min(ncnt1, cnt1) - min(ncnt2, cnt2) - min(ncnt3, cnt3);
		if (diff > ans) {
			ans = diff;
			ans_cnt1 = ncnt1;
			ans_cnt2 = ncnt2;
			ans_cnt3 = ncnt3;
		}
	}
	
	cout << n - ans << '\n';
	for (int i = 0; i < ans_cnt1; i++) { cout << mn << ' '; }
	for (int i = 0; i < ans_cnt2; i++) { cout << mn + 1 << ' '; }
	for (int i = 0; i < ans_cnt3; i++) { cout << mn + 2 << ' '; }
	
	return 0;
}
