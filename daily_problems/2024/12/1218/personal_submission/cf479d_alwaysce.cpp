#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1000000007;
i64 mod = 1e9+7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, l, x, y;
	cin >> n >> l >> x >> y;
	
	vector<int> a(n);
	for (auto&x: a) { cin >> x; }
	sort(a.begin(), a.end());
	
	map<int, int> cnt;
	bool has_x = false, has_y = false, has_xy1 = false, has_xy2 = false;	
	int pxy1 = -1, pxy2 = -1;
	for (int i = 0; i < n; i++) {
		int p1 = a[i] - x;
		int p2 = a[i] - y;
		int p3 = a[i] - (y - x);
		int p4 = a[i] - (y + x);
		if (p1 >= 0 and cnt.find(p1) != cnt.end()) {
			has_x = true;
		}
		if (p2 >= 0 and cnt.find(p2) != cnt.end()) {
			has_y = true;
		}
		if (p3 >= 0 and cnt.find(p3) != cnt.end()) {
			// | ... | y-x | .... |
			if (a[i] + x <= l) {
				has_xy1 = true;			
				pxy1 = a[i] + x;
			} else if (a[i] - y >= 0) {
				has_xy1 = true;
				pxy1 = a[i] - y;
			}
		}
		if (p4 >= 0 and cnt.find(p4) != cnt.end()) {
			has_xy2 = true;
			pxy2 = a[i] - y;
		}
		++cnt[a[i]];
	}
	
	if (has_x and has_y) {
		cout << 0;
	} else if (has_x or has_y or has_xy1 or has_xy2) {
		cout << 1 << '\n';
		if (has_x) { cout << y; }
		else if (has_y) { cout << x; }
		else if (has_xy1) {
			cout << pxy1;
		} else {
			cout << pxy2;
		}
	} else {
		cout << 2 << '\n';
		cout << x << ' ' << y;
	}
	return 0;
}
