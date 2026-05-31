#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k;
	cin >> n >> k;
	vector<i64> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	int cnt0 = 0, cnt1 = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] % k == 0) {
			cnt0++;
		} else {
			cnt1++;
		}
	}

	if (cnt1 == 0) {
		cout << "Rami";
	} else if (cnt1 <= 2) {
		cout << "Oussama\n";
	} else {
		if ((cnt0 & 1) ^ (cnt1 & 1)) {
			cout << "Rami\n";
		} else {
			cout << "Oussama\n";
		}
	}

	return 0;
}