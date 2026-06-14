#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s1, s2;
	cin >> s1 >> s2;

	vector<int> v1, v2;
	for (auto &c: s1) v1.emplace_back(c - '0');
	for (auto &c: s2) v2.emplace_back(c - '0');

	reverse(v1.begin(), v1.end());
	reverse(v2.begin(), v2.end());

	while (v1.size() < v2.size()) v1.emplace_back(0);
	while (v2.size() < v1.size()) v2.emplace_back(0);

	v1.emplace_back(0);
	v2.emplace_back(0);

	int k = v1.size();

	vector<int> total(k, 0);
	int chosen = -1;

	for (int i = 0; i < k - 1; i ++) {
		if (v1[i] + v2[i] + total[i] >= 10) chosen = i;

		total[i] += v1[i] + v2[i];
		total[i + 1] += total[i] / 10;
		total[i] %= 10;
	}

	while (v1.size() > chosen + 1) v1.pop_back();
	while (v2.size() > chosen + 1) v2.pop_back();

	reverse(v1.begin(), v1.end());
	reverse(v2.begin(), v2.end());

	auto res = max(v1, v2);

	vector<int> ans;

	for (int i = 0; i < res.size(); i ++) {
		if (i + 1 < res.size()) ans.emplace_back(9 - res[i]);
		else ans.emplace_back(10 - res[i]);
	}
	
	if (ans.size() && ans.back() == 10) {
		ans.back() = 0;
		ans.end()[-2] ++;
	}

	reverse(ans.begin(), ans.end());
	while (!ans.empty() && ans.back() == 0) ans.pop_back();
	reverse(ans.begin(), ans.end());

	if (ans.empty()) cout << 0;
	else for (auto &x: ans) cout << x;

	return 0;
}