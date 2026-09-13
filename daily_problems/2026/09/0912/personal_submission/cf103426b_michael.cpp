#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;

void solve(){
	int n;
	cin >> n;
	vector<vector<int>> arr(n-1,vector<int>(n));
	for(int i = 0; i < n - 1; ++i){
		for(int j = 0; j < n; ++j){
			cin >> arr[i][j];
		}
	}
	vector<int> cnt(n + 1,0);
	for(int i = 0; i < n; ++i){
		set<int> s;
		for(int k = 0; k < n; ++k) s.insert(k+1);	
		for(int j = 0; j < n - 1; ++j){
			if(!s.erase(arr[j][i])) break;
		}
		if(s.size() == 1){
			cnt[*s.begin()]++;
		}
	}
	int ans = 0;
	ll sum = 1;
	for(int i = 1; i <= n; ++i){
		if(cnt[i] > 0){
			sum = sum * cnt[i] % mod;
			ans++;
		}
	}
	
	for(int i = 1; i <= n - ans; ++i) sum = sum * i % mod;
	cout << ans << " " << sum << '\n';
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