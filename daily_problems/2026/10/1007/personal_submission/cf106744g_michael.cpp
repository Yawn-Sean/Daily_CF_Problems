#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
	ll n,k;
	cin >> n >> k;
	ll sum = k * (k + 1) / 2;
	ll rmn = n % sum;
	ll ansCnt = n / sum;
	vector<ll> ans(k,ansCnt);
	for(int i = k; i > 0; --i){
		if(rmn >= i){
			ans[i - 1]++;
			rmn -= i;
		}
	}
	for(const auto &a : ans) cout << a << " ";
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