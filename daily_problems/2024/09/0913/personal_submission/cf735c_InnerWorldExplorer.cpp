#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	long long n, cur = 2, prev = 1;
	cin >> n;
	int ans = 0;
	while (cur <= n){
		long long tmp = prev;
		prev = cur;
		cur += tmp;
		ans ++;
	}
	cout << ans << endl;
	return 0;
}
