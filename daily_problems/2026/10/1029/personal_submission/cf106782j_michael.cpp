#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
	int n,c;
	cin >> n >> c;
	vector<int> ocs(n);
	for(auto &x : ocs) cin >> x;
	int i = n;
	ll ans = 0;
	while(i > 0){
		while(i > 0 && ocs[i - 1] == 0){
			i--;
		}
		if(!i) break;

		if(ocs[i - 1] >= c){
			ans += 1ll * (ocs[i - 1] / c) * (i * 2);
			ocs[i - 1] %= c;
		}else{
			ans += i * 2;
			int tmp = c;
			while(i > 0 && tmp > 0){
				if(ocs[i - 1] > 0){
					if(ocs[i - 1] >= tmp){
						ocs[i - 1] -= tmp;
						tmp = 0;
					}else{
						tmp -= ocs[i - 1];
						ocs[i - 1] = 0;
					}
				}
				if(!ocs[i - 1]) i--;
			}
		}
	}
	cout << ans << '\n';
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