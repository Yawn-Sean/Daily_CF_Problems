#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

const int N = (int)1E6 + 1, MOD = 998244353;

long long binpow(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n;
	cin >> n;

	vector<int> cnt(N);
	vector<vector<int>> gifts;
	for (int i = 0; i < n; i ++){
		int ct;
		cin >> ct;
		vector<int> gift(ct);
		for (auto &x: gift){
			cin >> x;
			cnt[x] ++;
		}
		gifts.push_back(gift);
	}
	long long inv_mod = binpow(n, MOD - 2, MOD);
	long long ans = 0;
	for (int i = 0; i < n; i ++){
		int inv_sz = binpow((int)gifts[i].size(), MOD - 2, MOD);
		for (auto &x : gifts[i]){
			ans += 1LL * cnt[x] * inv_sz % MOD * inv_mod % MOD % MOD;
			if (ans >= MOD) ans -= MOD;
		}
	}
	cout << 1LL * inv_mod * ans % MOD << endl;
	return 0;
}
