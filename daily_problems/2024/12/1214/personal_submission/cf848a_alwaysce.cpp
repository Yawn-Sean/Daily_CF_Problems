#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1000000007;
i64 mod = 1e9+7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int k;
	cin >> k;
	/*
		最小的代价正好=k
	*/
	
	vector<int> ans;
	for (int rep = 1000; rep > 1; rep--) {
		while (k >= rep * (rep - 1) / 2) {
			k -= rep * (rep - 1) / 2;
			ans.push_back(rep);
		}
	}
	
	if ((int)ans.size() > 0) {
		for (int i = 0; i < (int)ans.size(); i++) {
			for (int j = 0; j < ans[i]; j++) {
				cout << (char)('a' + i);			
			}
		}
	} else {
		cout << 'a';
	}
	return 0;
}
