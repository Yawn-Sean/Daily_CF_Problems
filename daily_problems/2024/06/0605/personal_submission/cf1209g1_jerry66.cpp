#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef pair<int, int> PII;

const int N = 200100;

int n, p;

int a[N];
map<int, int> cnt;
map<int, PII> pos;
map<int, int> ltn;

void solve()
{
	cin >> n >> p;
	for (int i = 1; i <= n; i ++ ) cin >> a[i], cnt[a[i]] ++ ;
	
	for (int i = 1; i <= n; i ++ ) {
		int num = a[i];
		if (pos[num].x == 0) pos[num].x = i;
		pos[num].y = i;
	}

	vector<PII> v;

	for (auto& [x, p] : pos) {
		v.push_back(p);
		ltn[p.x] = x;
	}

	sort(v.begin(), v.end());
	
	int res = 0;

	int left = v[0].x, right = v[0].y;
	int lidx = 0, ridx = 0;
	for (int i = 1; i < v.size(); i ++ ) {
		if (v[i].x < right) {
			right = max(right, v[i].y);
			ridx = i;
		} else {
			// 断开了
			// 之前这段必须要一样
			// 枚举下变谁就可以了
			int changeMin = 1e9;
			for (int k = lidx; k <= ridx; k ++ ) {
				int d = cnt[ltn[v[k].x]];
				changeMin = min(changeMin, right - left + 1 - d);
			}
			res = res + changeMin;
			left = v[i].x, right = v[i].y;
			lidx = i, ridx = i;
		}
	}

	int changeMin = 1e9;
	for (int k = lidx; k <= ridx; k ++ ) {
		int d = cnt[ltn[v[k].x]];
		changeMin = min(changeMin, right - left + 1 - d);
	}
	res = res + changeMin;

	cout << res << '\n';
}

signed main()
{
	cin.tie(0) -> ios::sync_with_stdio(false);
	solve();
}
