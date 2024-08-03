#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using PII = pair<int, int>;
using PDI = pair<double, int>;
using PLI = pair<ll, int>;
using PLL = pair<ll, ll>;
using PSI = pair<string, int>;
using PSS = pair<string, string>;
using PDD = pair<double, double>;
#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	unordered_map<int, vector<int>> mp;
	vector<PII> max_s;
	for (int i = 1; i <= n; i++) {
		int id, cost; cin >> id >> cost;
		mp[id].emplace_back(cost);
	}
	for (auto& x : mp) max_s.push_back({ x.second.back(), x.first });
	sort(max_s.rbegin(), max_s.rend());
	int q; cin >> q;
	while (q--) {
		int k; cin >> k;
		unordered_set<int> h;
		for (int i = 0; i < k; i++) {
			int num; cin >> num;
			h.insert(num);
		}
		int maxn = -1, pre_max = -1, id = -1;
		for (auto &x : max_s) {
			if (h.count(x.second)) continue;
			if (maxn == -1) pre_max = maxn, maxn = x.first, id = x.second;
			else if (pre_max == -1) {
				pre_max = x.first;
				break;
			}
		}
		if (maxn == -1) cout << "0 0" << endl;
		else {
			vector<int>& nums = mp[id];
			auto j = lower_bound(nums.begin(), nums.end(), pre_max);
			cout << id << " " << *j << endl;
		}
	}
	return 0;
}
