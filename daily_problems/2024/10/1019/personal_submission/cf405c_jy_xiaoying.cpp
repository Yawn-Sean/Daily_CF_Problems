//链接：https://codeforces.com/problemset/problem/405/C

#include<bits/stdc++.h>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, ans = 0;
	cin >> n;

	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < n; j ++) {
			int x;
			cin >> x;
			if (i == j) ans ^= x;
		}
	}

	int q;
	cin >> q;

	while (q --) {
		int t, x;
		cin >> t;
		if (t == 3) cout << ans;
		else {
			cin >> x;
			ans ^= 1;
		}
	}

	return 0;
}
