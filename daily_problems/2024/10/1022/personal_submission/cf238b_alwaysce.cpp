#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
int inf = 1e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	/*
		f(ai, aj) = ai + aj 在同一组内
		或者 ai + aj + h 在不同组内
	*/
	int n, h;
	cin >> n >> h;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	int mn1 = inf, mn2 = inf, mn3 = inf;
	int mx1 = 0, mx2 = 0;
	
	for (auto& x: a) {
		if (x <= mn1) {
			swap(mn2, mn3);
			swap(mn1, mn2);
			mn1 = x;
		} else if (x <= mn2) {
			swap(mn2, mn3);
			mn2 = x;
		} else if (x < mn3) {
			mn3 = x;
		}
		
		if (x >= mx1) {
			swap(mx1, mx2);
			mx1 = x;
		} else if (x > mx2) {
			mx2 = x;
		}
	}

	int ans1 = (mx1 + mx2) - (mn1 + mn2);
	int ans2 = max(mx1 + mx2, mn1 + mx1 + h) - min(mn2 + mn3, mn1 + mn2 + h);
	if (ans1 <= ans2) {
		cout << ans1 << '\n';
		for (int i = 0; i < n; i++) {
			cout << "1 ";
		}
	} else {
		cout << ans2 << '\n';
		bool find = false;
		for (int i = 0; i < n; i++) {
			if (!find and a[i] == mn1) {
				find = true;
				cout << "2 ";
			} else {
				cout << "1 ";
			}
		}
		
	}
    return 0;
}
