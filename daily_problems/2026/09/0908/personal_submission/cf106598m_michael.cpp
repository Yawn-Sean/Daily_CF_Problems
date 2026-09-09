#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
	string s,t;
	int p,q;
	cin >> s >> t >> p >> q;
	if(p == 0 || q == 0){
		cout << "=\n";
		return;
	}
	string st = s + t;
	string ts = t + s;
	if(st < ts){
		cout << "<\n";
	}else if(st > ts){
		cout << ">\n";
	}else{
		cout << "=\n";
	}
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