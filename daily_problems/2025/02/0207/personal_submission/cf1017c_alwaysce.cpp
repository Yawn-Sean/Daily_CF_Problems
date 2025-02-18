#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 1e9+7;
int inf = 1e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;

	int seg = int(sqrt(n));
	if (n % seg > 0) {
		for (int i = n % seg; i > 0; i--) {
			cout << i << ' ';
		}
	}

	for (int i = n / seg + n % seg; i <= n; i += n / seg) {
		int cnt = i;
		for (int j = n / seg; j > 0; j--) {
			cout << cnt-- << ' ';
		}
	}
	return 0;
}
