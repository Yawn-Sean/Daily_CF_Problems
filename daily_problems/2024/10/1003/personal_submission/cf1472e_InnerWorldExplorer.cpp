#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> h(n), w(n);
	for (int i = 0; i < n; i ++){
		cin >> h[i] >> w[i];
		if (h[i] > w[i])
			swap(h[i], w[i]);
	}
	vector<int> ans(n, -2), pos(n);
	iota(pos.begin(), pos.end(), 0);
	sort(pos.begin(), pos.end(), [&](int i, int j){
		return h[i] < h[j] || (h[i] == h[j] && w[i] > w[j]);
	});
	int mn = 1e9 + 1, idx = -1;
	for (auto &x : pos){
		if (w[x] <= mn){
			mn = w[x];
			idx = x;
		}else{
			ans[x] = idx;
		}
	}
	for (auto &x : ans){
		cout << x + 1 << ' ';
	}
	cout << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;
	cin >> t;
	while (t --){
		solve();
	}
	return 0;
}
