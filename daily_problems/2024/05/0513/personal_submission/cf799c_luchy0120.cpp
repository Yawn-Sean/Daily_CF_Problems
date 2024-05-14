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
	int n; cin >> n;
	int c;cin >> c;
	int d;cin >> d;

	vector<array<int, 2>> cs;
	vector<array<int, 2>> ds;

	for (int i = 0;i < n;++i) {
		int b;int p;cin >> b >> p;
		char tp;cin >> tp;
		if (tp == 'C') {
			cs.push_back({p,b});
		}
		else {
			ds.push_back({ p,b });
		}
	}
	int mc = -1;
	int md = -1;
	for (int i = 0;i < cs.size();++i) {
		if (cs[i][0] <= c) {
			mc = max(mc, cs[i][1]);
		}
	}
	for (int i = 0;i < ds.size();++i) {
		if (ds[i][0] <= d) {
			md = max(md, ds[i][1]);
		}
	}
	int ans = 0;
	if (mc != -1 && md != -1) {
		ans = max(ans, mc+md);
	}

	

	auto ck = [&](vector<array<int, 2>> &ps,int p) {

		sort(ps.begin(), ps.end());
		vector<int> best(ps.size());
		for (int i = 0;i < ps.size();++i) {
			best[i] = ps[i][1];
			if (i > 0) {
				best[i] = max(best[i], best[i-1]);
			}
		}
		int r = 0;
		for (int i = 0;i < ps.size();++i) {
			int ck = p - ps[i][0];

			int idx = upper_bound(ps.begin(), ps.begin()+i, array<int,2>{ck,(int)1e9}) - ps.begin() - 1;
			if (idx >= 0) {
				r = max(r, best[idx] + ps[i][1]);
			}
		}
		return r;
	};


	cout << max(ans,max(ck(ds,d),ck(cs,c)));





	return 0;
}