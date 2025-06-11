#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

const int MOD = 1E9 + 7;

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int a, b;
	cin >> a >> b;
	cout << (1LL * b * (b - 1) / 2 % MOD * ((1LL * a * (a + 1) / 2 % MOD) * b % MOD + a) % MOD) % MOD << endl;
	return 0;
}
