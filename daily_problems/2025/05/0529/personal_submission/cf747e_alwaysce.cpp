#include <bits/stdc++.h>
using i64 = long long;
using namespace std;
i64 mod = 998244353;
/*
	A
		B
			C
			D
				E
	

*/
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string s;
	cin >> s;
	
	vector<string> words;
	vector<int> nums;
	int i = 0;
	string cur;

	while (i < (int)s.size()) {
		cur = "";
		while (i < (int)s.size() && isalpha(s[i])) {
			cur += s[i];
			i++;
		}
		words.push_back(cur);
		cur = "";
		i += 1;
		while (i < (int)s.size() && isdigit(s[i])) {
			cur += s[i];
			i++;
		}
		nums.push_back(stoi(cur));
		i += 1;
	}
	
	int m = words.size();
	vector<vector<string>> ans;
	vector<int> stk{10000000};
	for (int i = 0; i < m; i++) {
		while (stk.back() == 0) {
			stk.pop_back();
		}
		if (stk.size() - 1 == ans.size()) {
			ans.push_back(vector<string>());
		}
		ans[stk.size() - 1].push_back(words[i]);
		stk.back() -= 1;
		stk.push_back(nums[i]);
	}
	
	cout << ans.size() << endl;
	for (int i = 0; i < (int)ans.size(); i++) {
		for (auto& w: ans[i]) {
			cout << w << ' ';
		}
		cout << endl;
	}
	
	return 0;
}
