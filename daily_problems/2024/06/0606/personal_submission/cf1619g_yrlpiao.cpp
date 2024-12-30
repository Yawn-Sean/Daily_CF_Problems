#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <array>
using namespace std;
#define ar3 array<int, 3>
#define ar2 array<int, 2>

ar3 arr[1 << 20];
int fa[1 << 20] {};
int n, k;
map<int, set<ar2>> mp1, mp2;
int find(int x) {
	return fa[x] == x ? x : find(fa[x]);
}
void fun(auto& mp) {
	for (auto& x : mp) {
		auto& y = x.second;
		int f = 0;
		ar2 pe;
		for (ar2 r : y) {
			if (f) {
				if (abs(r[0] - pe[0]) <= k) {
					int u = find(pe[1]);
					int v = find(r[1]);
					fa[u] = v;
					arr[v][2] = min(arr[v][2], arr[u][2]);
				}
			}
			pe = r;
			f = 1;
		}
	}
}

void yrlpSolve() {
	cin >> n >> k;
	mp1.clear(), mp2.clear();
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &arr[i][0], &arr[i][1], &arr[i][2]);
		mp1[arr[i][0]].insert({arr[i][1], i});
		mp2[arr[i][1]].insert({arr[i][0], i});
	}
	iota(fa, fa + n, 0);
	fun(mp1); fun(mp2);
	vector<int> v;
	for (int i = 0; i < n; i++) {
		if (fa[i] == i) {
			v.push_back(arr[i][2]);
		}
	}
	sort(v.begin(), v.end());
	int s = v.size();
	int ans = s - 1;
	for (int i = 0; i < s; i++) {
		ans = min(ans, max(v[i], s - i - 2));
	}
	cout << ans << endl;
    return; 
}

signed main() {
    int T = 1; cin >> T;
    while (T--) yrlpSolve();
}
