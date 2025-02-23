#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1000000007;
i64 mod = 1e9+7;


int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		
		vector<int> cur;
		for (int x = 0; x < n; x++) {
			if (a[x] == 1) {
				cur.push_back(1);
			} else {
				while (cur.back() != a[x] - 1) {
					cur.pop_back();
				}
				cur.back()++;
			}
			int m = cur.size();
			cout << cur[0];
			for (int i = 1; i < m; i++) {
				cout << '.' << cur[i];
			}
			cout << '\n';
		}
	}
	
	
	return 0;
}
