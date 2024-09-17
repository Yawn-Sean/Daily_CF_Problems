#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n, s;
	cin >> n >> s;
	vector<int> a(n);
	vector<int> yes(n + 1);
	for (auto &x : a){
		cin >> x;
	}
	int ans = 0;
	if (a[s - 1] != 0) {
		ans ++;
		a[s - 1] = 0;
	}

	int z = 0;
	for (int i = 0; i < n; i ++){
		if (i + 1 != s && a[i] == 0) z ++;
		yes[a[i]] += 1;
	}
	ans += z;
	int i = 1, j = n;
	while (i < j){
		if (yes[i] == 0){
			if (z) {
				z --;
				i ++;
				continue;
			}
			if (yes[j] != 0) {
				yes[j] --;
				yes[i] ++;
				ans ++;
				i ++;
			}else{
				j --;
			}
		}else{
			i ++;
		}
	}
	cout << ans << endl;
	return 0;
}
