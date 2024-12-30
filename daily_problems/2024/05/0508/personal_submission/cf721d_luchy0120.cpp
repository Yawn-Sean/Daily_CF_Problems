#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
#include <set>
#include <cmath>
#include <array>
#include <unordered_set>
#include <queue>
using namespace std;


int main() {
	int n, k;long long x;cin >> n >> k >> x;

	vector<pair<long long,int>> a(n);
	int sign = 1;
	int z = 0;
	for (int i = 0;i < n;++i) {
		long long v; cin >> v;
		if (v < 0) {
			sign *= -1;
		}
		a[i] = {v, i};
	}
	auto cmp = [&](pair<long long, int>& x, pair<long long, int>& y) {
		return abs(x.first) > abs(y.first);
	};

	sort(a.rbegin(), a.rend(), cmp);
	if (sign > 0) {
		
		long long q = min<long long>(k, abs(a[0].first) / x + 1);
		k -= q;
		if (a[0].first >= 0) {
			a[0].first -= q * x;
		}
		else {
			a[0].first += q * x;
		}
		
	}
	
	priority_queue<pair<long long, int>, vector<pair<long long, int>>, decltype(cmp)> q(cmp);
	for (int i = 0;i < n;++i) {
		q.push(a[i]);
	}
	while (k-- > 0) {
		auto c = q.top();
		q.pop();
		if (c.first >= 0) {
			c.first += x;
			q.push(c);
		}
		else {
			c.first -= x;
			q.push(c);
		}
	}
	vector<long long> v(n);
	while (q.size()) {
		auto c = q.top();
		q.pop();
		v[c.second] = c.first;
	}

	for (int i = 0;i < n;++i) {
		cout << v[i] << " \n"[i == n - 1];
	}

	return 0;
}