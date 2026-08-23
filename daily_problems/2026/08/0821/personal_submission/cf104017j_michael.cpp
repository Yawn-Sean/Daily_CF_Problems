#include <bits/stdc++.h>
using namespace std;

#define ll long long

int gcd(int a,int b){
	while(a % b != 0){
		int tmp = a % b;
		a = b;
		b = tmp;
	}
	return b;
}

void solve(){
	int w,l;
	cin >> w >> l;
	set<int> s = {2};
	vector<int> candidate = {gcd(w,l-2),gcd(w - 1,l - 1),gcd(w - 2,l)};
	for(auto x : candidate){
		for(int i = 1; i <= 100000; ++i){
			if(i * i > x) break;
			if(x % i == 0) s.insert(i),s.insert(x / i);
		}
	}
	cout << s.size();
	for(auto x : s) cout << ' ' << x;
	cout << '\n';
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