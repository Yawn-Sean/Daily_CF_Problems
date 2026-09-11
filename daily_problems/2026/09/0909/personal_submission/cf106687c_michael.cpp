#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
	int a,b,c;
	cin >> a >> b >> c;
	int mn = min({a,b,c});
	if(mn == a){
		cout << b * c << '\n';
		for(int i = 1; i <= b; ++i){
			for(int j = 1; j <= c; ++j){
				cout << (i + j) % a + 1 << " " << i << " " << j << '\n';
			}
		}
	}else if(mn == b){
		cout << a * c << '\n';
		for(int i = 1; i <= a; ++i){
			for(int j = 1; j <= c; ++j){
				cout << i << " " << (i + j) % b + 1 << " " << j << '\n';
			}
		}
	}else{
		cout << a * b << '\n';
		for(int i = 1; i <= a; ++i){
			for(int j = 1; j <= b; ++j){
				cout << i << " " << j << " " << (i + j) % c + 1 << '\n';
			}
		}
	}
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