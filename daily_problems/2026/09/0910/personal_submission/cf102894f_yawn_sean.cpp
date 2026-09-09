#include <bits/stdc++.h>
// #include "atcoder/all"
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")

using namespace std;

const int M = 1e6 + 5;
const long long inf = 4e18;
long long saved[M][2];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;

	vector<int> caps(n);
	for (auto &x: caps) cin >> x;

	vector<pair<int, int>> groups(k);
	for (auto &[x, y]: groups) cin >> x;
	for (auto &[x, y]: groups) cin >> y;

	sort(caps.rbegin(), caps.rend());
	sort(groups.rbegin(), groups.rend());

	long long ans = 0, pt = 0;
	priority_queue<int> pq;

	for (auto &[x, y]: groups) {
		while (pt < n && caps[pt] >= x) pt ++;
		pq.push(-y), ans += y;
		if (pq.size() > pt) ans += pq.top(), pq.pop();
	}

	cout << ans;

	return 0;
}