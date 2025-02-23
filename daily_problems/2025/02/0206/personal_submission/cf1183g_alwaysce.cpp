#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 1e9+7;
int inf = 1e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		vector<int> cnt1(n+1), cnt2(n+1);
		for (int i = 0; i < n; i++) {
			int a, f;
			cin >> a >> f;
			if (f == 1) {
				++cnt1[a];
			} else {
				++cnt2[a];
			}
		}
		
		// 答案就是已有糖果的种类数		
		map<int, vector<int> > mp;
		for (int i = 1; i <= n; i++) {
			int tot = cnt1[i]+cnt2[i];
			if (tot>0) {
				// 种类, f1个数 (种类不重要)
				mp[tot].push_back(cnt1[i]);
			}
		} 
		
		// 接下来是怎么选择fi=1尽可能多的
		// 倒着枚举 需求数量 x
		// 维护一个堆 堆里按照fi=1升序排序
		priority_queue<int> pq;
		int fans = 0;
		int ans = 0;

		// 枚举可能的 种类数
		for (int kind = n; kind >= 1; kind--) {
			if (mp.find(kind) != mp.end()) { 	
				// cout << k << '\n';
				for (auto& v: mp[kind]) {
					pq.push(v);			
				}
			}
			
			if (!pq.empty()) {
				// cout << kind << '\n';
				fans += min(kind, pq.top());
				ans += kind;
				pq.pop();
			}			
		}
		
		cout << ans << ' ' << fans << '\n';
	}
	
	return 0;
}
