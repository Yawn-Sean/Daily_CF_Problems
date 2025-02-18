#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

using i64 = long long;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, b;
	cin >> n >> b;
	i64 t, d, ht = 0;
	deque<i64> q;
	vector<i64> ans;
	while (n -- ) {
		cin >> t >> d;
		while (!q.empty() && q.front() <= t) q.pop_front();
		if (t < ht) {
			if ((int)q.size() == b + 1) ans.push_back(-1);
			else {
				i64 tm = ht + d;
				ans.push_back(tm);
				q.push_back(tm);
				ht = tm;
			}
		} else {
			i64 tm = t + d;
			ans.push_back(tm);
			q.push_back(tm);
			ht = tm;
		}
	}
	for (auto &t : ans){
		cout << t << " ";
	}
	cout << endl;
	return 0;
}
