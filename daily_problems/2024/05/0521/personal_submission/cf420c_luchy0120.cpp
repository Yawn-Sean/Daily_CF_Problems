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
using namespace std;


int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;cin >> n;
	int p;cin >> p;

	vector<int> d(n + 1);
	vector<unordered_map<int,int>> g(n+1);
	for (int i = 0;i < n;++i) {
		int x; int y;cin >> x >> y;
		d[x]++;
		d[y]++;
		g[x][y]++;
		g[y][x]++;
	}
	vector<array<int, 2>> ps;
	for (int i = 1;i <= n;++i) {
		ps.push_back({ d[i], i });
	}
	sort(ps.begin(),ps.end());
	int j = n;
	long long r = 0;
	vector<int> st(n+1);
	int sz = 0;
	for (int i = 0;i < n;++i) {
		int cur = ps[i][0];
		int x = ps[i][1];

		
		while (j-1 >= 0 && ps[j - 1][0] + cur >= p) {
			--j;
			st[ps[j][1]]++;
			sz++;
		}
		if (st[x] > 0) {
			st[x]--;
			sz--;
		}
		r += sz;

		for (auto &y : g[x]) {
			if (st[y.first]) {
				r--;
			}
			if (-y.second + d[y.first] + cur >= p) {
				r++;
			}
		}
		if (j <= i) {
			st[x]++;
			sz++;
		}

	}


	cout << r / 2;








	return 0;
}