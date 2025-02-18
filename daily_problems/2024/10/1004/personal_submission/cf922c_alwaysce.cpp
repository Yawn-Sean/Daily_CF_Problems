#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

i64 mod = 998244353;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	i64 n, k;
	cin >> n >> k;
	
	if (k > 100) {
		cout << "No\n";
		return 0;
	}
	
	set<i64> seen;
	for (int i = 1; i <= k; i++) {
		seen.insert(n % i);	
	}
	
	cout << (((i64)seen.size() == k) ? "Yes\n" : "No\n");
	return 0;
}
