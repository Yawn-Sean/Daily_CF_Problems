#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
	int n;
	cin >> n;
	vector<pair<int,int>> arr(n);
	for(auto &[x,y] : arr) cin >> x >> y;
	vector<int> idx(n);
	iota(idx.begin(),idx.end(),0);
	sort(idx.begin(),idx.end(),[&](int a,int b){return arr[a] < arr[b];});

	cout << 2 * n - 1 << '\n';
	for(int i = 0; i < n; ++i) cout << idx[i] + 1 << ' ';
	for(int i = n - 2; i >= 0; --i) cout << idx[i] + 1 << ' ';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	// cin >> t;
	while(t--){
		solve();
	}
	cout << flush;
	return 0;
}