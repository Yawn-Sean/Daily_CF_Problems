#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

void solve() {
	int n, l, r, s;
	cin >> n >> l >> r >> s;
	int x = r - l + 1;
	int lb = x * (1 + x) / 2;
	int rb = (n + 1) * n / 2 - (n - x + 1) * (n - x) / 2;
	if (s < lb || s > rb) {
		cout << -1 << endl;
		return;
	}
	vector<int> vis(n + 1);
	for (int i = 1; i <= x; i ++){
		vis[i] = 1;
	}
	int i = x, j = n, cur = lb;
	while (cur != s){
		int inc = min(j - i, s - cur);
		cur += inc;
		vis[i + inc] = 1;
		j = i + inc - 1;
		vis[i] = 0;
		i --;
	}
	vector<int> out, in;
	for (int i = 1; i <= n; i ++){
		if (vis[i]){
			in.push_back(i);
		}else{
			out.push_back(i);
		}
	}

	for (int i = 1, j = 0, k = 0; i <= n; i ++){
		if (i >= l && i <= r){
			cout << in[j ++] << " ";
		}else{
			cout << out[k ++] << " ";
		}
	}
	cout << endl;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t --) {
		solve();
	}
	return 0;
}
