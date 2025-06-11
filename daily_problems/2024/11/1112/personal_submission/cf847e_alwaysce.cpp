#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 mod = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	string s;
	cin >> n >> s;
	
	vector<int> as, pc;
	for (int i = 0; i < n; i++) {
		if (s[i] == '*') { as.push_back(i); }
		else if (s[i] == 'P') { pc.push_back(i); }
	}
	
	int l = 0, r = 2 * n + 1, k = as.size();
	int ans = r;
	while (l < r) {
		int mid = (l + r) / 2;
		int idx = 0;
		
		for (auto& p: pc) {
			if (abs(as[idx] - p) > mid) { continue; }
			
			int left = max(0, p - as[idx]);
			// <- -> -> | -> <- <-
			// 2left + right = mid / 2right + left = mid
			int right = p + max((mid - left) / 2, (mid - left * 2));
			while (idx < k and as[idx] <= right) {
				idx++;
			}
			if (idx == k) {
				break;
			}
		}
		
		if (idx == k) {
			ans = mid;
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	cout << ans;
    return 0;
}
