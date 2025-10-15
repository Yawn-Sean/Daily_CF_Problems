#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	/*	For each index i , you can find out 
 	the perfect hero to conquer as many monsters as you want.
	*/
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (auto& x: a) { cin >> x; }
		
		int m;
		cin >> m;
		vector<int> p(m), s(m);
		
		// v[i]: 能够砂i个怪的最大伤害值
		// 如果连续砂x个怪的最大数值不够了说明需要新建一段
		// v[1]>=v[2]>=...>=v[n]
		vector<int> v(n + 1, 0);
		for (int i = 0; i < m; i++) { 
			cin >> p[i] >> s[i];
			v[s[i]] = max(v[s[i]], p[i]); // 后缀最大值
		}
		for (int i = n - 1; i >= 1; i--) {
			v[i] = max(v[i], v[i + 1]);
		}
		
		int start = 0, cur = 0, ans = 1;
		for (int i = 0; i < n; i++) {
			if (v[1] < a[i]) {
				ans = -1;
				break;
			}
			cur = max(cur, a[i]);
			if (v[i - start + 1] < cur) {
				start = i;
				ans++;
				cur = a[i];
			}
		}

		cout << ans << '\n';
	}
	
	return 0;
}
