#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

i64 inf = 1e18;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	

	/*
		s分成n个回文串是否可能
		如果可能输出方案
	*/
	int n;
	string s;
	cin >> n >> s;
	
	map<char,int> mp;
	for (auto& ch: s) {
		++mp[ch];
	}
	
	vector<char> odds;
	for (auto& [k, v]: mp) {
		if (v & 1) {
			odds.emplace_back(k);
			mp[k]--;
		}
	}
	
	if (odds.empty()) {
		string res;
		for (auto& pr: mp) {
			char k = pr.first;
			int v = pr.second;
			res += string(v / 2, k);
		}
		cout << "1\n";
		cout << res;
		reverse(res.begin(), res.end());
		cout << res;
		return 0;		
	}
	
	for (int i = odds.size(); i <= n; i++) {
		if (n % i == 0) {
			int len = n / i;
			if (len & 1) {
				vector<string> ans(i);
				int target = len / 2;
				for (int idx = 0; idx < i; idx++) {
					char c;
					if (odds.size()) {
						c = odds.back();
						odds.pop_back();
					} else {
						for (auto& pr: mp) {
							char k = pr.first;
							int v = pr.second;
							if (v > 0) {
								c = k;
								mp[c]--;
								break;
							}
						}
					}
					
					string half;
					int cur_len = 0;
					vector<int> to_delete;
					
					for (auto& pr: mp) {
						char k = pr.first;
						int v = pr.second;
						
						int val = min(v / 2, target - cur_len);
						mp[k] -= val * 2;
						if (mp[k] == 0) {
							to_delete.push_back(k);
						}
						half += string(val, k);
						cur_len += val;
						if (cur_len == target) {
							break;
						}
					}
					
					for (auto& x: to_delete) {
						mp.erase(x);
					}
					
					ans[idx] += half;
					ans[idx] += c;
					reverse(half.begin(), half.end());
					ans[idx] += half;
				}
				
				cout << i << '\n';
				for (auto& x: ans) {
					cout << x << ' ';
				}
				return 0;
			}
		}
	}
	return 0;
}
