#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string s;
	cin >> s;
	int n = (int)s.size();
	set<int> opos, zpos;
	for (int i = 0; i < n; i ++) {
		char c = s[i];
		if (c == '0') zpos.insert(i);
		else opos.insert(i);
	}
	bool bad = true;
	vector<vector<int>> ans(1, vector<int>());
	while (true) {
		if (zpos.empty()) {
			cout << -1 << endl;
			return 0;
		}
		if (bad) {
			if (ans.back().empty()) {
				auto it = zpos.begin();
				ans.back().push_back(*it);
				zpos.erase(it);
			}else{
				int pos = ans.back().back();
				auto it = zpos.upper_bound(pos);
				if (it == zpos.end()){
					cout << -1 << endl;
					return 0;
				}else{
					ans.back().push_back(*it);
					zpos.erase(it);
				}
			}
			if (opos.empty()) break;
		} else {
			int pos = ans.back().back();
			auto it = opos.upper_bound(pos);
			if (it == opos.end()){
				ans.push_back(vector<int>());
			}else{
				ans.back().push_back(*it);
				opos.erase(it);
			}
		}
		bad = !bad;
	}

	if (zpos.size()){
		for (auto it = zpos.begin(); it != zpos.end(); it ++){
			ans.push_back(vector<int>{*it});
		}
	}
	cout << ans.size() << endl;
	for (int i = 0; i < (int)ans.size(); i ++){
		cout << ans[i].size() << ' ';
		for (int j = 0; j < (int)ans[i].size(); j ++){
			cout << ans[i][j] + 1 << " \n"[j == ans[i].size() - 1];
		}
	}
	return 0;
}
