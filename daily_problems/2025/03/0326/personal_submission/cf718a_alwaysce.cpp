#include <bits/stdc++.h>
using i64 = long long;
using namespace std;
i64 mod = 998244353;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, t;
	cin >> n >> t;
	
	
	/*
		找到第一个小数部分比5更大的位置
		[x1x2x3...] . [y1y2...yn]
		
		可以round的次数上限 = t
		
		19.23599999
		t=3
		9 round -> 19.236
			
		5 round一次
		19.24	
	*/
	string s;
	cin >> s;
	
	// 0{} . 0{}
	vector<int> v1 = {0}, v2 = {0};
	bool decimal = true;
	for (auto&c: s) {
		if (c == '.') {
			decimal = false;
		} else {
			if (decimal) {
				v1.emplace_back(c - '0');
			} else {
				v2.emplace_back(c - '0');
			}
		}
	}
	
	int k1 = v1.size(), k2 = v2.size();
	for (int i = 0; i < k2; i++) {
		if (v2[i] >= 5) {
			// 0 ... i-1 | i
			while ((int)v2.size() > i) { v2.pop_back(); }
			v2.back()++; t--;
			break;
		}
	}
	// 第一次之后继续进位
	while (t > 0 && v2.back() >= 5) {
		t--;
		v2.pop_back();
		v2.back()++;
	}
	
	v1.back() += v2[0];
	v2[0] = 0;
	
	while (!v2.empty() && !v2.back()) {
		v2.pop_back();
	}
	for (int i = k1 - 1; i > 0; i--) {
		if (v1[i] == 10) {
			v1[i] = 0;
			v1[i - 1]++;
		}
	}
	
	for (int i = 0; i < k1; i++) {
		if (i || v1[i]) {
			cout << v1[i];
		}
	}
	if (v2.size()) { cout << '.'; }
	
	for (int i = 1; i < (int)v2.size(); i++) {
		cout << v2[i];
	}
	return 0;
}
