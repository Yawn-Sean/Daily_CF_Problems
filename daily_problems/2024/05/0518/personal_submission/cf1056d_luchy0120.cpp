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

vector<vector<int>> g;
vector<int> cv;
int n;
void dfs(int rt) {
	for (int to : g[rt]) {
		dfs(to);
		cv[rt] += cv[to];
	}
	if (g[rt].size() == 0) {
		cv[rt] = 1;
	}
}


int main() {
	cin >> n;

	g.resize(n+1,vector<int>());
	cv.resize(n+1);
	for (int i = 2;i <= n;++i) {
		int v;cin >> v;
		g[v].push_back(i);
	}
	dfs(1);
	sort(cv.begin() + 1,cv.end());
	for (int i = 1;i <= n;++i) {
		cout << cv[i] << " \n"[i==n];
	}






	return 0;
}