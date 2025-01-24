#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	
	auto ask = [&](int pos) {
		int mx = -1, num = -1;
		
		for (int i = 0; i <= 9; i++) {
			for (int j = 0; j < 4; j++) {
				if (j == pos) {
					cout << i;
				} else {
					cout << 1;
				}
			}
			cout << endl;
			
			int bull, cow;
			cin >> bull >> cow;
			if (bull > mx) {
				mx = bull;
				num = i;
			}
		}
		return num;
	};
	
	vector<int> ans;
	for (int p = 0; p < 4; p++) {
		ans.emplace_back(ask(p));
	}
	for (auto&x:ans) {
		cout << x;
	}
	cout << endl;
	return 0;
}
