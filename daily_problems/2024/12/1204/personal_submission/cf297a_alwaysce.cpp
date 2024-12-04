#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1000000007;
i64 mod = 1e9+7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string a, b;
	cin >> a >> b;
	
	int c1 = 0, c2 = 0;
	for (auto& c: a) {
		c1 += (c - '0');
	}
	for (auto& c: b) {
		c2 += (c - '0');
	}
	// 可以把偶数的1的第一个移到后面
	cout << (((c1 >= c2) or (c1&1 and c1+1==c2) ) ? "YES" : "NO");
	return 0;
}
