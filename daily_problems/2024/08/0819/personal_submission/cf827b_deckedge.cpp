#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < b; i++)

inline int read() {
	int x;
	cin >> x;
	return x;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = read(), k = read();
	n--;
	int res = n / k * 2;
	if (n % k == 1) {
		res += 1;
	} else if (n % k > 1) {
		res += 2;
	}

	cout << res << '\n';
	rep(i, 2, k + 1) {
		cout << 1 << ' ' << i << '\n';
	}
	n++;
	rep(i, k + 1, n + 1) {
		cout << i - k << ' ' << i << '\n';
	}

	return 0;
}