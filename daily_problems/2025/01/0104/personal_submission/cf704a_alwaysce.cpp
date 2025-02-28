#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 1e9+7;
int inf = 2e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, q;
	cin >> n >> q;
	
	vector<int> cnt(n + 1), unread(n + 1), tmp;
	int ans = 0, idx = 0;
	
	while (q--) {
		int tp, x;
		cin >> tp >> x;
		
		if (tp == 1) {
			ans++;
			cnt[x]++;
			tmp.push_back(x);
		} else if (tp == 2) {
			ans -= cnt[x];
			cnt[x] = 0;
			unread[x] = tmp.size();
		} else {
			while (idx < x) {
				if (idx >= unread[tmp[idx]]) {
					ans--;
					cnt[tmp[idx]]--;
				}		
				++idx;
			}		
		}
		cout << ans << '\n';
	}	

	return 0;
}
