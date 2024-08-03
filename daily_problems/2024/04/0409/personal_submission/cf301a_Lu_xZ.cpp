#include<bits/stdc++.h>
using namespace std;

int n, x, mi = 1e9, ans, cnt;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cin >> n;
	for(int i = 1; i < 2 * n; ++ i) {
		cin >> x;
		if(x < 0) x = -x, ++ cnt;
		ans += x;
		mi = min(mi, x);
	}
	cout << ans - 2 * (n % 2 == 0 && cnt % 2 == 1) * mi;
	return 0;
}
