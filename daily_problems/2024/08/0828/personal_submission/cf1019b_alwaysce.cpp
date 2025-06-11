#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	
	auto query = [&](int x) {
		int v1, v2;
		cout << "? " << x << endl;
		cout.flush();
		cin >> v1;
		cout << "? " << x + n / 2 << endl;
		cout.flush();
		cin >> v2;
		return v1 > v2 ? 1 : (v1 == v2 ? 0: -1);
	};
	
	auto answer = [&](int x) {
		cout << "! " << x << endl;
		cout.flush();
	};
	
	if (n % 4) {
		answer(-1);
		return 0;
	}
	
	int l = 1, r = n / 2;
	int target = query(1);
	if (target == 0) {
		answer(1);
	} else {
		while (l <= r) {
			int m = (l + r) / 2;
			int v = query(m);
			if (v == 0) {
				answer(m);
				return 0;
			}
			if (v * target > 0) {
				l = m + 1;
			} else {
				r = m - 1;
			}
		}
		answer(l);
	}
    return 0;
}
