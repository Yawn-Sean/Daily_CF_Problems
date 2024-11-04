#include <bits/stdc++.h>
using i64 = long long;
using ui64 = unsigned long long;
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	while (t--) {
		i64 n;
		cin >> n;
		vector<int> nums(n);
		for (auto& v: nums) { cin >> v; }
	
		// linked list
		vector<int> pre(n), suf(n);
		iota(pre.begin(), pre.end(), -1);
		iota(suf.begin(), suf.end(), 1);
		
		// 环形链表
		pre[0] = n - 1;
		suf[n - 1] = 0;
		
		vector<int> del(n), ans;
		queue<int> q;
		for (int i = 0; i < n; i++) {
			q.push(i);
		}
		while (not q.empty()) {
			int cur = q.front();
			q.pop();
			if (del[cur]) continue;
			
			int nxt = suf[cur];
			if (__gcd(nums[cur], nums[nxt]) == 1) {
				ans.push_back(nxt);
				del[nxt] = 1;
				pre[suf[nxt]] = pre[nxt];
				suf[pre[nxt]] = suf[nxt];
				q.push(cur);
			}
		}
		cout << ans.size() << ' ';
		for (auto& v: ans) {
			cout << v + 1 << ' ';
		}
		cout << '\n';
	}
	return 0;
}
