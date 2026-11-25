#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;

	vector<string> strs(n);
	for (auto &x: strs) cin >> x;

	string ans;
	vector<int> chosen, order(n);
	iota(order.begin(), order.end(), 0);

	{
		vector<int> cnt;
		for (auto &s: strs) {
			int c = 0;
			for (auto &x: s) {
				if ((x - '0') % 4 == 2) {
					c ++;
				}
			}
			cnt.emplace_back(c);
		}

		sort(order.begin(), order.end(), [&] (int i, int j) {return cnt[i] > cnt[j];});

		string tmp;
		vector<int> idxs;

		for (int i = 0; i < k; i ++) {
			idxs.emplace_back(order[i]);
			for (auto &x: strs[order[i]]) {
				if ((x - '0') % 4 == 2) {
					tmp += x;
				}
			}
		}

		if (tmp.size() > ans.size()) {
			ans = tmp;
			chosen = idxs;
		}
	}

	{
		vector<int> cnt;
		for (auto &s: strs) {
			int c = 0;
			for (auto &x: s) {
				if ((x - '0') % 2 == 1) {
					c ++;
				}
			}
			cnt.emplace_back(c);
		}

		sort(order.begin(), order.end(), [&] (int i, int j) {return cnt[i] > cnt[j];});

		for (int i = k; i < n; i ++) {
			if (cnt[order[i]] == cnt[order[k - 1]]) {
				for (auto &x: strs[order[i]]) {
					if ((x - '0') % 4 == 0) {
						swap(order[i], order[k - 1]);
						break;
					}
				}
			}
		}

		string tmp;
		char ch = '.';
		vector<int> idxs;

		for (int i = 0; i < k; i ++) {
			idxs.emplace_back(order[i]);
			for (auto &x: strs[order[i]]) {
				if ((x - '0') % 2 == 1) {
					tmp += x;
				}
				else if ((x - '0') % 4 == 0) {
					ch = x;
				}
			}
		}


		if (tmp.size() && ch != '.') tmp += ch;

		if (tmp.size() > ans.size()) {
			ans = tmp;
			chosen = idxs;
		}
	}

	if (ans.size()) {
		for (auto &x: chosen) cout << x + 1 << ' '; cout << '\n';
		cout << ans << '\n';
	}
	else {
		for (int i = 1; i <= k; i ++) cout << i << ' '; cout << '\n';
		cout << "empty\n";
	}

	return 0;
}