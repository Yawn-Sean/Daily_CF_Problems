#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 998244353;

double EPS = 1e-7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) { 
		cin >> a[i];
	}
	
	auto getline = [&](int x1, int y1, int x2, int y2) {
		double k = 1.0 * (y2 - y1) / (x2 - x1);
		double b = 1.0 * y1 - k * x1;
		return make_pair(k, b);	
	};
	
	auto check = [&](int x1, int y1, int x2, int y2) {
		// L1 through (x1, y1) and (x2, y2)
		auto l1 = getline(x1, y1, x2, y2);
		vector<pair<int,int>> p2;
		
		for (int i = 1; i <= n; i++) {
			if (i == x1 or i == x2) continue;
			double y = 1.0 * i * l1.first + l1.second;
			if (fabs(y - 1.0 * a[i]) > EPS) {
				p2.push_back({i, a[i]});
			}
		}
		
		if (p2.size() == 0) { return false; }
		if (p2.size() > 0 and p2.size() < 2) { return true; }
		
		auto l2 = getline(p2[0].first, p2[0].second, p2[1].first, p2[1].second);
		for (int i = 2; i < (int)p2.size(); i++) {
			double y = 1.0 * p2[i].first * l2.first + l2.second;
			if (fabs(y - 1.0 * p2[i].second) > EPS) {
				return false;
			}
		}
		return (fabs(l1.first - l2.first) <= EPS);
	};
	
	// test 01
	bool f1 = check(1, a[1], 2, a[2]);
	
	// test 02
	bool f2 = check(1, a[1], 3, a[3]);
	
	// test 12
	bool f3 = check(2, a[2], 3, a[3]);
	
	if (f1 or f2 or f3) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
	return 0;
}
