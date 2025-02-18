#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

i64 mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cout << 2000 << '\n';
	for (int i = 1; i <= 1000; i++) {
		cout << i << ' ' << 1 << ' ' << i << ' ' << 2 << '\n';
	}
	for (int i = 1000; i >= 1; i--) {
		cout << i << ' ' << 1 << ' ' << i << ' ' << 2 << '\n';
	}
    return 0;
}
