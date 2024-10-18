#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

i64 inf = 1e18;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	
	vector<i64> dp(10, -inf);
	dp[0] = 0;
	
	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;
		
		vector<vector<i64>> cards(4);
		for (int j = 0; j < num; j++) {
			int c;
			i64 d;
			cin >> c >> d;
			cards[c].push_back(d);
		}
		for (int c = 1; c <= 3; c++) {
			sort(cards[c].begin(), cards[c].end());
		}
		
		// p[x]: 打x张牌的最大值
		// mx[x]: 打x张牌的牌面最大值
		vector<i64> p(4, -1), mx(4, -1), ndp(10, -inf);
		p[0] = 0;
		mx[0] = 0;
		
		// {}, {1}{2}{3}, {1,2}{1,1}, {1,1,1}
		i64 m1 = cards[1].size(), m2 = cards[2].size(), m3 = cards[3].size();
		if (m1 > 2) {
			p[3] = cards[1][m1 - 1] + cards[1][m1 - 2] + cards[1][m1 - 3];
			mx[3] = cards[1][m1 - 1];
		}
		
		if (m1 > 1) {
			p[2] = cards[1][m1 - 1] + cards[1][m1 - 2];
			mx[2] = cards[1][m1 - 1];
		}
		
		if (m1 > 0) {
			p[1] = cards[1][m1 - 1];
			mx[1] = cards[1][m1 - 1];
			
			if (m2 > 0) {
				if (cards[1][m1 - 1] + cards[2][m2 - 1] > p[2]) {
					p[2] = cards[1][m1 - 1] + cards[2][m2 - 1];
					mx[2] = max(mx[2], max(cards[1][m1 - 1], cards[2][m2 - 1]));
				}
			}
		}
		
		if (m2 > 0) {
			if (cards[2][m2 - 1] > p[1]) {
				p[1] = cards[2][m2 - 1];
				mx[1] = cards[2][m2 - 1];	
			}
		}
		
		if (m3 > 0) {
			if (cards[3][m3 - 1] > p[1]) {
				p[1] = cards[3][m3 - 1];	
				mx[1] = cards[3][m3 - 1];
			}
		}
		
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k <= 3; k++) {
				if (p[k] != -1) {
					i64 pp = (j + k >= 10) ? mx[k] : 0;
					ndp[(j + k) % 10] = max(ndp[(j + k) % 10], dp[j] + pp + p[k]);
				}
			}
		}
		for (int j = 0; j < 10; j++) {
			dp[j] = ndp[j];
		}
	}
	
	cout << *max_element(dp.begin(), dp.end()) << '\n';
	return 0;
}
