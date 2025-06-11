#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// Note that all strings have the same length n.
	// Strings come in pairs.
	
	// 奇数的中间一个可以随便挑选 = k对 + 1个
	// 偶数= k对
	int n, k;
	cin >> k >> n;
	
	map<string, vector<int>> mp;	
	for (int i = 0; i < k; i++) {
		string s;
		int x;
		cin >> s >> x;
		mp[s].push_back(x);
	}
	
	// s[i], rev(s[i]) 构成一对
	// aaa * 1, abb+bba, xyx
	i64 ans = 0;
	set<string> seen;
	
	vector<i64> odds, evens;
	
	for (auto& pr: mp) {
		string s = pr.first;
		if (seen.find(s) != seen.end()) {
			continue;
		}
		seen.insert(s);
		
		string rev_s = s;
		reverse(rev_s.begin(), rev_s.end());
		// cout << s << ' ' << rev_s << '\n';
		if (rev_s == s) {
			// 这里只能至多有一个奇数 其他都是偶数
			sort(pr.second.rbegin(), pr.second.rend());
			int l1 = pr.second.size();
			i64 add = 0, even_mx = 0, odd_mx = -1e9;
			for (int i = 0; i < l1; i ++) {
				add += pr.second[i];
				if (i % 2 == 0) {
					odd_mx = max(odd_mx, add);
				} else {
					even_mx = max(even_mx, add);
				}
			}	
			odds.push_back(odd_mx);
			evens.push_back(even_mx);
		} else if (rev_s != s && mp.find(rev_s) != mp.end()) {
			// 这里增加的长度肯定是偶数
			seen.insert(rev_s);
			sort(pr.second.rbegin(), pr.second.rend());
			sort(mp[rev_s].rbegin(), mp[rev_s].rend());
			
			int l1 = pr.second.size(), l2 = mp[rev_s].size();
			for (int i = 0; i < min(l1, l2); i++) {
				i64 add = pr.second[i] + mp[rev_s][i];
				if (add > 0) { ans += add; }
				else { break; }
			}
		}
	}
	
	ans += accumulate(evens.begin(), evens.end(), 0ll);
	
	int m = odds.size();
	i64 base = ans;
	for (int j = 0; j < m; j++) {
		// cout << odds[j] << ' ' << evens[j] << '\n';
		i64 tmp = base + odds[j] - evens[j];
		ans = max(ans, tmp);
	}
	cout << ans;
	return 0;
}
