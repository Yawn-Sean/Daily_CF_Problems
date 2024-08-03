#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
using namespace std;

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a%b);
}


int main() {
	int m, a, b;cin >> m >> a >> b;
	using ll = long long;
	int inf = 1e9 + 7;
	vector<int> dp(a + b, inf);
	dp[0] = 0;
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push({0,0});
	while (q.size()) {
		auto [h, p] = q.top();q.pop();
		if (h != dp[p]) {
			continue;
		}
		if (p - b >= 0 && dp[p - b] > h) {
			dp[p - b] = h;
			q.push({h, p-b});
		}
		if (p<b && dp[p + a] > max(p + a, h)) {
			dp[p + a] = max(p + a, h);
			q.push({dp[p+a], p+a});
		}
	}
	ll s = 0;
	for (int i = 0;i < min(a + b, m + 1);++i) {
		s += max(m - dp[i] + 1, 0);
	}


	if (m >= a + b) {
		int f = gcd(a, b);
		int num = m / f - (a + b) / f  + 1;

		s += (ll)(m + 1) * num;

		s -= (ll)(m / f + (a + b) / f) * (m / f - (a + b) / f + 1) * f / 2;

	}
	cout << s;




	return 0;
}