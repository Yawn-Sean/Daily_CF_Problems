#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> pos_idx, neg_idx;
	
	bool pos = true, eq = false;
	int cnt = 0;
	string numStr;
			
	while (true) {
		if (eq) {
			cin >> numStr;
			break;
		}
		
		string op;
		cin >> op;
		if (op[0] == '?') {
			if (pos) {
				pos_idx.push_back(cnt++);
			} else {
				neg_idx.push_back(cnt++);
			}
		} else if (op[0] == '+') {
			pos = true;
		}  else if (op[0] == '-') {
			pos = false;
		} else if (op[0] == '=') {
			eq = true;
		}
	}
	

	int target = stoi(numStr);
	int cnt0 = pos_idx.size(), cnt1 = neg_idx.size();
	int hi = cnt0 * target - cnt1;
	int lo = cnt0 - cnt1 * target;
	
	if (lo <= target and target <= hi) {
		int cur = cnt0 - cnt1 * target;
		vector<int> neg_num(cnt1, target), pos_num(cnt0, 1);
		
		for (int i = 0; i < cnt1 and cur < target; i++) {
			int diff = min(target - cur, (target - 1));
			cur += diff;
			neg_num[i] -= diff;
		}
		
		for (int i = 0; i < cnt0 and cur < target; i++) {
			int diff = min(target - cur, (target - 1));
			cur += diff;
			pos_num[i] += diff;
		}
		cout << "Possible\n";
		
		vector<int> ans_value(cnt0 + cnt1), is_pos(cnt0 + cnt1, 0);
		for (int i = 0; i < cnt0; i++) {
			ans_value[pos_idx[i]] = pos_num[i];
			is_pos[pos_idx[i]] = 1;
		}
		
		for (int i = 0; i < cnt1; i++) {
			ans_value[neg_idx[i]] = neg_num[i];
		}
		// {pos} + {pos} - {neg} + {pos} - {neg} = {}
		for (int i = 0; i < cnt0 + cnt1; i++) {
			if (i > 0) {
				if (is_pos[i]) { cout << "+ " << ans_value[i] << " "; }
				else { cout << "- " << ans_value[i] << " "; }
			} else {
				if (is_pos[i]) { cout << ans_value[i] << " "; }
				else { cout << "- " << ans_value[i] << " "; }
			}
		}
		cout << "= " << numStr;
		
	} else {
		cout << "Impossible";
	}
	return 0;
}
