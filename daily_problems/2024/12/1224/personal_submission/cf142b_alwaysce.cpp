#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 1e9+7;
int inf = 2e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	if (n == 1 or m == 1) {
		cout << n * m;
	} else if (n == 2 or m == 2) {
		int mx = max(n, m);
		cout << (mx / 4) * 4 + min(mx % 4, 2) * 2;
	} else {
		cout << (n * m + 1) / 2;
	}
	return 0;
}
