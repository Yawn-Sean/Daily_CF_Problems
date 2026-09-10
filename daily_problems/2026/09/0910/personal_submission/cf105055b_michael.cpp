#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
	int n,k;
	cin >> n >> k;

	string s;
	cin >> s;
	int m = 0;
	for(char c : s) m = (2 * m + c - '0') % 3;
	if(n % 2 == 0 && m) cout << "GIOVANA\n";
	else cout << "JULIA\n";
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