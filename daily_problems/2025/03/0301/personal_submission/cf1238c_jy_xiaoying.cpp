#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/1238/C
//格式化： ctrl+shift+ a

int h,n;

void f() {
	cin>>h>>n;
	vector<int> nums(n+1,0);
	for(int i=n; i>0; i--) {
		cin>>nums[i];
	}

	vector<int> dp(n + 1, 0);
	for (int i = 2; i <= n; i ++) {
		if (nums[i - 1] == nums[i - 2] + 1)
			dp[i] = dp[i - 2];
		else
			dp[i] = dp[i - 1] + 1;
	}

	cout << dp[n] << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	int t;
	cin>>t;
	while(t--) {
		f();
	}

	return 0;
}
