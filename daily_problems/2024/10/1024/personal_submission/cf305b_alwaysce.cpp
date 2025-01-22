#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	i64 p,q;
	cin >> p >> q;
	
	int n;
	cin >> n;
	vector<i64> a(n);
	for (auto& x: a) { cin >> x; }
	
	// pn=an, qn=1
	// 反推
	// pn-1/qn-1 = an-1 + 1/(pn/qn)
	// ...
	// 得到关系
	/*
		pn-1 = an-1 * pn + qn
		qn-1 = pn
	*/
	
	// vector<i64> pn(n), qn(n);
	// pn[n - 1] = a[n - 1];
	// qn[n - 1] = 1ll;
// 	
	// for (int i = n - 2; i >= 0; i--) {
		// pn[i] = a[i] * pn[i + 1] + qn[i + 1];
		// qn[i] = pn[i + 1];
	// }
// 	
	// if (pn[0] * q == qn[0] * p) {
		// cout << "YES\n";
	// } else {
		// cout << "NO\n";
	// }
	
	
	// 正推 p/q
	vector<i64> vec;
	while (q) {
		vec.push_back(p / q);
		p %= q;
		// (q, p%q)
		swap(p, q);
	}
	
	if (n > 1 and a[n - 1] == 1) {
		a.pop_back(); // + 1/1
		n--; 
		a.back()++;
	}
	
	if ((int)vec.size() == n) {
		for (int i = 0; i < n; i++) {
			if (a[i] != vec[i]) {
				cout << "NO\n";
				return 0;
			}
		}
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
	return 0;
}
