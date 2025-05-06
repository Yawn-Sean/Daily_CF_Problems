#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve();
#define endl '\n'
signed main (){ 
	std::ios::sync_with_stdio(false);std::cin.tie(0);
	int t = 1;
	// cin >> t;  //atc默认关闭，cf按需开启
	while(t --)
		solve();
}
void solve(){
	int n, m, k;
	cin >> n >> m >> k;
	vector<int > a(n, 0);
	for(auto &c : a)
		cin >> c;
	if(n % 2 == 0){
		puts("0"); return;
	}
	int minx = 1e9;
	for(int i = 0; i < n; i += 2)
		minx = min(minx, a[i]);
	int ans = min(m / (n / 2 + 1) * k, minx);
	cout << ans << endl;
}
