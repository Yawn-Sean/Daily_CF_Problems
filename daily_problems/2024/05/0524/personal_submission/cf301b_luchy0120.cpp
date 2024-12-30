#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
#include <set>
#include <cmath>
#include <array>
#include <unordered_set>
#include <queue>
#include <fstream>
using namespace std;

const int N = 101;

int a[N][N];

int main() {

	int n, d;cin >> n >> d;

	vector<int> a(n + 1);
	for (int j = 2;j <= n - 1;++j) {
		cin >> a[j];
	}
	vector<array<int, 2>> ds(n+1);
	for (int i = 1;i <= n ;++i) {
		int x; int y;cin >> x >> y;
		ds[i] = { x, y };
	}
	priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> q;
	q.push({ 0,1 });

	vector<int> dp(n + 1,1e9);
	dp[1] = 0;

	while (q.size()) {
		auto c = q.top();q.pop();
		int dis = c[0];
		int  u = c[1];
		if (dis != dp[u]) {
			continue;
		}
		for (int i = 1;i <= n;++i) {
			if (i == u) {
				continue;
			}
			if (dis + d*abs(ds[u][0] - ds[i][0]) + d*abs(ds[u][1] - ds[i][1]) - a[i] < dp[i]) {
				dp[i] = dis + d*abs(ds[u][0] - ds[i][0]) + d*abs(ds[u][1] - ds[i][1]) - a[i];
				q.push({dp[i], i});
			}
		}
	}
	cout << dp[n] << endl;






	return 0;
}