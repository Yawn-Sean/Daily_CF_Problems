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
using namespace std;




int main() {
	int t;cin >> t;
	for (int i = 0;i < t;++i) {
		int n, m, k;cin >> n >> m >> k;
		vector<int> xs;
		vector<long long> totx(n+1);
		unordered_set<int> xst;
		for (int j = 0;j < n;++j) {
			int v;cin >> v;
			xst.insert(v);
			xs.push_back(v);
		}
		vector<int> ys;
		vector<long long> toty(m+1);
		unordered_set<int> yst;

		vector<unordered_map<int, long long>> mpx(n + 1);
		vector<unordered_map<int, long long>> mpy(m + 1);
		for (int j = 0;j < m;++j) {
			int v;cin >> v;
			yst.insert(v);
			ys.push_back(v);
		}
		for (int j = 0;j < k;++j) {
			int xp, yp;cin >> xp >> yp;
			if (yst.count(yp) && xst.count(xp)) {
				continue;
			}
			else if (yst.count(yp)) {
				int idy = lower_bound(ys.begin(), ys.end(), yp) - ys.begin();
				int upx = lower_bound(xs.begin(), xs.end(), xp) - xs.begin();
				
				mpx[upx][idy]++;
				totx[upx]++;
			}
			else {
				int idx = lower_bound(xs.begin(), xs.end(), xp) - xs.begin();
				int upy = lower_bound(ys.begin(), ys.end(), yp) - ys.begin();
				
				mpy[upy][idx]++;
				toty[upy]++;
			}

		}
		long long r = 0;
		for (int j = 0;j <= n;++j) {
			for (auto& ele : mpx[j]) {
				r += (totx[j] - ele.second) * ele.second;
			}
		}
		for (int j = 0;j < m;++j) {
			for (auto& ele : mpy[j]) {
				r += (toty[j] - ele.second) * ele.second;
			}
		}
		cout << (r/2L) << endl;
	}

	return 0;
}