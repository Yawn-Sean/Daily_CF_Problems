#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MOD = 1e9 + 7;
const int MAX = 200;
int saved[MAX + 1][MAX + 1];

void init(){
	for(int mx = 1; mx <= MAX; ++mx){
		vector<int> dp(mx + 1,0),ndp(mx + 1,0);
		dp[0] = 1;
		for(int step = 1; step <= MAX * 2; ++step){
			fill(ndp.begin(),ndp.end(),0);
			for(int j = 0; j <= mx; ++j){	
				if(dp[j] == 0) continue;
				if(j > 0){
					ndp[j - 1] += dp[j];
					if(ndp[j - 1] >= MOD) ndp[j - 1] -= MOD;
				}
				if(j < mx){
					ndp[j + 1] += dp[j];
					if(ndp[j + 1] >= MOD) ndp[j + 1] -= MOD;
				}
			}
			swap(dp,ndp);
			if(step % 2 == 0){
				saved[mx][step / 2] = dp[0];
			}
		}
	}

	for(int i = MAX; i > 0; --i){
		for(int j = 0; j <= MAX; ++j){
			saved[i][j] = (saved[i][j] - saved[i - 1][j] + MOD) % MOD;
		}
	}
}

void solve(){
	int l,h;
	cin >> l >> h;
	cout << saved[h][l] << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}
	cout << flush;
	return 0;
}