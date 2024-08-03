#include<bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++ i)
#define per(i, a, b) for(int i = (a); i >= (b); -- i)
#define pb emplace_back
using namespace std;
using ll = long long;

/*
两个子图的密度分别为pho1，pho2
pho1要变大 -> pho2 > pho1
新图的密度小于 pho2
-> 只选两个点最优
*/

int n, m, w[550];
double ans;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cin >> n >> m;
	for(int i = 1; i <= n; ++ i) cin >> w[i];
	for(int i = 1; i <= m; ++ i) {
		int x, y, z; cin >> x >> y >> z;
		ans = max(ans, 1. * (w[x] + w[y]) / z);
	}
	cout << fixed << setprecision(15) << ans;
	return 0;
}
