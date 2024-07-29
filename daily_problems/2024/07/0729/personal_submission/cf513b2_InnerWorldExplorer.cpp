#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	long long n, m;
	cin >> n >> m;
	int l = 0, r = n - 1;
	vector<int> ans(n);
	for (int i = 1; i < n; i ++){
		if (m <= (1LL << (n - i - 1))) ans[l ++] = i;
		else {
			ans[r --] = i;
			m -= (1LL << (n - i - 1));
		}
	}
	ans[l] = n;
	for (int i = 0; i < n; i ++) {
		cout << ans[i] << " \n"[i == n - 1];
	}
	return 0;
}
