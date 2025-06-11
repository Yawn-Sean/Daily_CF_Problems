#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	long long n, k;
	cin >> n >> k;
	for (int i = 1; i <= k; i ++){
		if (n % i != i - 1){
			return cout << "NO" << endl, 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}
