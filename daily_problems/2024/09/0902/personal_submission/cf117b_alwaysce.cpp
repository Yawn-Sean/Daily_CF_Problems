#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a, b, mod;
	cin >> a >> b >> mod;
	
	int x = 1e9, v = 0;
	x %= mod;
	for (int i = 0; i <= min(a, mod); i++) {
		if (v > b) {
			string s = to_string(i);
			s = string(9 - s.size(), '0') + s;
			cout << "1 " << s;
			return 0;
		}
		v = (v + mod - x) % mod;
	}
	cout << 2;
    return 0;
}
