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


	vector<array<int,2>> d(n + 1);

	for (int i = 1;i <= n;++i) {
		int x; int y;cin >> x >> y;
		d[i] = { x,y };
	}
	vector<int> r;
	if (d[d[1][0]][0] == d[1][1] || d[d[1][0]][1] == d[1][1]) {

		r.push_back(1);
		r.push_back(d[1][0]);
		r.push_back(d[1][1]);

	}
	else {
		r.push_back(1);
		r.push_back(d[1][1]);
		r.push_back(d[1][0]);

	}
	
	for (int j = 1;j < n - 2;++j) {
		r.push_back(d[r[j]][0] + d[r[j]][1] - r.back());
	}

	for (int u : r) {
		cout << u << " ";
	}








	return 0;
}