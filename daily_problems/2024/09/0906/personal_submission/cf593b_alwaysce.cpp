#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, x1, x2;
	cin >> n >> x1 >> x2;
	
	vector<pair<i64,i64>> tmp;
	for (int i = 0; i < n; i++) {
		int k, b;
		cin >> k >> b;
		tmp.push_back({1ll*k*x1 + b, 1ll*k*x2 + b});
	}
	sort(tmp.begin(), tmp.end());
	
	for (int i = 1; i < n; i++) {
		if (tmp[i].second < tmp[i - 1].second) {
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
    return 0;
}
