#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAXM = 2e5;
vector<int> primes;
vector<bool> is_comp(MAXM,false);

vector<int> mu(MAXM);

void init(){
	mu[1] = 1;
	for(int i = 2; i < MAXM; ++i){
		if(!is_comp[i]){
			primes.push_back(i);
			mu[i] = -1;
		}
		for(const auto& p : primes){
			if(p * i >= MAXM) break;
			is_comp[p * i] = true;
			if(i % p == 0){
				mu[i * p] = 0;
				break;
			}
			mu[i * p] = -mu[i];
		}
	}
}

ll count_squareFree(ll x){
	ll res = 0;
	ll d = 1;
	while(d * d <= x){
		res += mu[d] * (x / (d * d));
		d++;
	}
	return res;
}

void solve(){
	ll n;
	cin >> n;
	ll l = 1,r = 4e10;
	while(l <= r){
		ll mid = (l + r) / 2;
		if(count_squareFree(mid) >= n){
			r = mid - 1;
		}else{
			l = mid + 1;
		}
	}
	cout << l << '\n';
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