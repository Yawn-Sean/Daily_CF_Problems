#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAX = 1e6 + 1;
vector<int> phi(MAX);

void init(){
	iota(phi.begin(),phi.end(),0);
	for(int i = 2; i < MAX; ++i){
		if(phi[i] == i){
			for(int j = i; j < MAX; j += i){
				phi[j] = phi[j] / i * (i - 1);
			}
		}
	}
}

int gcd(int a,int b){
	while(a % b > 0){
		int c = a % b;
		a = b;
		b = c;
	}
	return b;
}

void solve(){
	int n,m;
	cin >> n >> m;
	if(gcd(n,m) == 1){
		cout << phi[m] << '\n';
	}else{
		cout << -1 << '\n';
	}
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