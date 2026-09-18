#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
	int n,k;
	cin >> n >> k;
	string s;
	cin >> s;
	string ans;
	for(int i = 0; i < n; ++i){
		if(k & 1){
			k -= (s[i] == '+' ? 1 : -1);
			ans += '#';
		}else{
			ans += '.';
		}
		k >>= 1;
	}
	cout << (k == 0 ? ans : "-1") << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}
	cout << flush;
	return 0;
}