#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
	cin >> n;
	vector<int> a(n);
	for(int i=0; i<n; i++) cin >> a[i];
	
	int gcd = a[0];
	for(int i: a) gcd = __gcd(gcd, i);
	
	cout << "YES" << endl;
	if(gcd > 1) cout << 0 << endl;
	else {
		vector<int> dp(n, 1e9);
		
		if(a[0] % 2 == 0 && a[1] % 2 == 0) {
			dp[1] = 0;
		} else if(a[0] % 2 == 1 && a[1] % 2 == 1) {
			dp[1] = 1;
		} else {
			dp[1] = 2;
		}
		
		if(a[0] % 2 == 0) {
			dp[0] = 0;
		}
		
		for(int i=2; i<n; i++) {
			if(a[i] % 2 == 0) {
				dp[i] = min(dp[i], dp[i-1]);
				dp[i] = min(dp[i], dp[i-2] + 2 * (a[i-1] % 2));
			} else {
				dp[i] = min(dp[i], dp[i-2] + 2 - (a[i-1] % 2));
				dp[i] = min(dp[i], dp[i-1] + 2);
			}
		}
		
		cout << dp[n-1] << endl;
	}
	
    return 0;
}
