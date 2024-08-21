#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<int> ans(2 * n, n);
	for (int i = 1, l = 0, r = n - 1; i <= n; i += 2, l ++, r --){
		ans[l] = ans[r] = i;
		if (i < n)
			ans[l + n] = ans[r + n - 1] = i + 1;
	}
	for (int i = 0; i < 2 * n; i ++){
		cout << ans[i] << " \n"[i == 2 * n - 1];
	}
	return 0;
}
