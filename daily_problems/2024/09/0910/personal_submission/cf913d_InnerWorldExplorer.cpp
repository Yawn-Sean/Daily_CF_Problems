#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, time;
	cin >> n >> time;
	vector<int> a(n), t(n), idx(n);
	for (int i = 0; i < n; i ++) {
		cin >> a[i] >> t[i];
	}
	iota(idx.begin(), idx.end(), 0);
	sort(idx.begin(), idx.end(), [&](int i, int j){
		return a[i] > a[j];
	});
	int cur = 0, ans = 0;
	priority_queue<int> pq;
	for (auto &i : idx){
		pq.push(t[i]);
		cur += t[i];
		if (cur > time){
			cur -= pq.top();
			pq.pop();
		}
		ans = max(ans, min((int)pq.size(), a[i]));
	}
	sort(idx.begin(), idx.end(), [&](int i, int j){
		return t[i] < t[j];
	});
	cout << ans << "\n" << ans << "\n";
	int cnt = 0;
	for (auto &i : idx){
		if (a[i] >= ans && cnt < ans){
			cnt ++;
			cout << i + 1 << " \n"[cnt != ans - 1];
		}
	}
	return 0;
}
