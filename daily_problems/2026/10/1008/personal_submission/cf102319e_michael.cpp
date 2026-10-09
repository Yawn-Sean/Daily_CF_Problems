#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
	int n,k;
	cin >> n >> k;
	string s(n,'0');
	for(int i = 0; i < 3; ++i) s[i] = '1';
	int pos = 0;
	for(int i = 3; i < n; ++i){
		s[i] = '1';
		cout << "? " << s << endl;
		int x;
		cin >> x;
		if(x){
			pos = i;
			break;
		}
	}
	for(int i = 0; i < pos; ++i){
		s[i] = '0';
		cout << "? " << s << endl;
		int x;
		cin >> x;
		if(!x) s[i] = '1';
	}
	string t = s;
	t[pos] = '0';
	for(int i = pos + 1; i < n; ++i){
		t[i] = '1';
		cout << "? " << t << endl;
		int x;
		cin >> x;
		if(x) s[i] = '1';
		t[i] = '0';
	}
	cout << "! " << s;
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