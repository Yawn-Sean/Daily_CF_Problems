#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i ++){
		cin >> a[i];
	}
	int l = 0, r = n - 1;
	while (l < n - 1 && a[l] < a[l + 1]) {
		l ++;
	}
	while (r > 0 && a[r] < a[r - 1]){
		r --;
	}
	string ans;
	if ((l + 1) % 2 && (n - r) % 2){
		ans = "Alice";
	}else if ((l + 1) % 2 == 0 && (n - r) % 2 == 0) {
		ans = "Bob";
	}else{
		ans = "Alice";
	}
	cout << ans << endl;
	return 0;
}
