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
	int n, m;cin >> n >> m;

	vector<long long> a(n);
	int cur = 0;
	vector<bool> nvis(n);
	vector<vector<pair<long long,int>>> pt(m+1);
	for (int i = 0;i < n;++i) {
		
		int c;cin >> c;
		long long v; cin >> v;
		if (c == 1) {
			cur++;
			nvis[i] = 1;
		}
		pt[c].push_back({v,i});
		a[i] = v;
		
	}

	for (int j = 2;j <= m;++j) {
		sort(pt[j].begin(),pt[j].end());
	}

	long long cost = 1e18;
	for (int i = max(1,cur);i <= n;++i) {
		int nd = i - cur;
		vector<bool> vis = nvis;
		long long s = 0;
		for (int j = 2;j <= m;++j) {
			int q = pt[j].size() - (i - 1);
			for (int g = 0;g < q; g++) {
				nd--;
				s += pt[j][g].first;
				vis[pt[j][g].second] = 1;
			}
		}
		
		vector<long long> x;
		for (int g = 0;g < n;++g) {
			if (!vis[g]) {
				x.push_back(a[g]);
			}
		}
		nth_element(x.begin(), x.begin() + nd - 1, x.end());
		for (int i = 0;i < nd;++i) {
			s += x[i];
		}
		cost = min(cost, s);
	}
	
	cout << cost << endl;
	

	return 0;
}